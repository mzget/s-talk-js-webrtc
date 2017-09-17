/**
 * React,React-native webrtc peer implementation...
 * 
 * Copyright 2017 Ahoo Studio.co.th.
 */

import { EventEmitter } from "events";

import { IPC_Handler, PeerConstructor, AbstractPeerConnection } from "./AbstractPeerConnection";
import { IMessageExchange } from "./WebrtcSignaling";

export namespace AbstractPeer {
    export abstract class BasePeer implements IPC_Handler {
        // const twilioIceServers = [
        //     { url: 'stun:global.stun.twilio.com:3478?transport=udp' }
        // ];
        // configuration.iceServers = twilioIceServers;
        configuration = {
            iceServers: [
                {
                    urls: ["stun:stun.l.google.com:19302"
                        , 'stun:stun1.l.google.com:19302',
                        'stun:stun2.l.google.com:19302',
                        'stun:stun3.l.google.com:19302',
                        'stun:stun4.l.google.com:19302']
                },
            ]
        };

        id: string;
        pc: RTCPeerConnection;
        channels: any;
        debug: boolean;
        readonly type: string;
        pcEvent: EventEmitter;
        parentsEmitter: EventEmitter;
        receiveChannel;
        pcPeers;
        browserPrefix: string;
        nick;
        offer: boolean;
        stream: MediaStream;
        audioTracks: MediaStreamTrack[];
        videoTracks: MediaStreamTrack[];

        enableDataChannels: boolean = true;

        send_event: (messageType: string, payload?: any, optional?: { to: string }) => void;
        logError = (error) => {
            console.log(error);
        };

        /**
         * reture PeerConnection
         * @param socket 
         * @param stream 
         * @param options 
         */
        constructor(config: PeerConstructor) {
            if (!config.stream) {
                throw new Error("Missing stream!!!");
            }

            this.stream = config.stream;
            this.debug = config.debug;
            this.id = config.peer_id;
            this.pcPeers = config.pcPeers;
            this.parentsEmitter = config.emitter;
            this.send_event = config.sendHandler;
            this.offer = config.offer;

            this.restartIce = this.restartIce.bind(this);
            this.onCreateOfferSuccess = this.onCreateOfferSuccess.bind(this);
        }

        abstract initPeerConnection(stream: MediaStream, iceConfig: any);

        removeStream(stream: MediaStream) {
            this.pc.removeStream(stream);
        }

        addStream(stream: MediaStream) {
            this.pc.addStream(stream);
        }

        onSetSessionDescriptionError(error) {
            console.warn('Failed to set session description: ' + error.toString());
        }
        onCreateSessionDescriptionError(error) {
            console.warn('Failed to create session description: ' + error.toString());
        }

        // Simulate an ice restart.
        restartIce() {
            let self = this;
            if (self.debug)
                console.log('pc createOffer restart');

            self.offer = true;
            let offerOptions = { iceRestart: true };
            self.pc.createOffer(self.onCreateOfferSuccess, self.onCreateSessionDescriptionError, offerOptions);
        }
        onCreateOfferSuccess(desc: RTCSessionDescription) {
            let self = this;
            if (self.debug)
                console.log('createOffer Success');

            self.pc.setLocalDescription(desc, function () {
                if (self.debug)
                    console.log('setLocalDescription Success');

                // Waiting for all ice. and then send offer.
                if (self.pc.iceGatheringState == "complete") {
                    self.sendOffer();
                }
            }, self.onSetSessionDescriptionError);
        }
        createOffer() {
            let self = this;

            this.pc.createOffer(self.onCreateOfferSuccess, self.onCreateSessionDescriptionError);
        }
        createAnswer(message: IMessageExchange) {
            let self = this;
            self.pc.createAnswer(function (answer) {
                if (self.debug)
                    console.log('createAnswer Success');

                self.pc.setLocalDescription(answer, function () {
                    if (self.debug)
                        console.log('setLocalDescription Success');

                    self.pcEvent.emit(AbstractPeerConnection.PeerEvent, "createAnswer Success");
                    self.send_event(AbstractPeerConnection.ANSWER, self.pc.localDescription, { to: message.from });
                }, self.onSetSessionDescriptionError);
            }, self.onCreateSessionDescriptionError);
        }
        sendOffer() {
            let self = this;

            if (!self.offer) return;
            self.offer = false;

            self.pcEvent.emit(AbstractPeerConnection.PeerEvent, "createOffer Success");
            self.send_event(AbstractPeerConnection.OFFER, self.pc.localDescription, { to: self.id });
        }
        abstract handleMessage(message: IMessageExchange);
        abstract getStats(mediaTrack: MediaStreamTrack, secInterval: number): Promise<any>;
    }
}