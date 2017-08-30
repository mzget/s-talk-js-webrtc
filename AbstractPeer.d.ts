/// <reference types="node" />
/**
 * React,React-native webrtc peer implementation...
 *
 * Copyright 2017 Ahoo Studio.co.th.
 */
import { EventEmitter } from "events";
import { AbstractPeerConnection } from "./";
export declare namespace AbstractPeer {
    abstract class BasePeer implements AbstractPeerConnection.IPC_Handler {
        id: string;
        pc: RTCPeerConnection;
        channels: any;
        pcEvent: EventEmitter;
        readonly debug: boolean;
        readonly type: string;
        parentsEmitter: EventEmitter;
        receiveChannel: any;
        pcPeers: any;
        browserPrefix: string;
        nick: any;
        offer: boolean;
        enableDataChannels: boolean;
        send_event: (messageType: string, payload?: any, optional?: {
            to: string;
        }) => void;
        logError: (error: any) => void;
        /**
         * reture PeerConnection
         * @param socket
         * @param stream
         * @param options
         */
        constructor(config: AbstractPeerConnection.PeerConstructor);
        initPeerConnection(stream: MediaStream): void;
        removeStream(stream: MediaStream): void;
        addStream(stream: MediaStream): void;
        onSetSessionDescriptionError(error: any): void;
        onCreateSessionDescriptionError(error: any): void;
        createOffer(): void;
        createAnswer(message: any): void;
        handleMessage(message: any): void;
    }
}
