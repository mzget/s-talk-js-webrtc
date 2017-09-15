//@ts-check
import * as React from 'react';
import { View, StyleSheet, Dimensions } from 'react-native'
import InCallManager from 'react-native-incall-manager';
import { StalkWebRtcFactory, AbstractWEBRTC, AbstractPeerConnection } from "stalk-js-webrtc/react-native";

import { PeerStatus } from "../components/WithPeerStatus";

export default (Comp) => {
    return class Communication extends React.Component {
        webrtc;

        static navigationOptions = {
            header: null,
        }
        constructor(props) {
            super(props);
            this.state = {
                ...this.props.navigation.state.params,
                ready: false,
                isFront: true,
                mute: false,
                selfViewSrc: null,
                remote: null,
                peer: null,
                showSelfView: true,
                time: 0,
            }
            console.log(this.state);
            this.toggleLoudspeaker = this.toggleLoudspeaker.bind(this)
            this.switchVideoType = this.switchVideoType.bind(this)
            this.toggleSelfCamera = this.toggleSelfCamera.bind(this)
            this.removeVideo = this.removeVideo.bind(this);
            this.disconnect = this.disconnect.bind(this);
            this.onPeerCreated = this.onPeerCreated.bind(this);
            this.connectionClose = this.connectionClose.bind(this);
            this.initSocket();
        }
        initSocket(){
            let self = this;
            let rtcConfig = {
                signalingUrl: 
                //'https://sandbox.simplewebrtc.com:443',
                `https://chitchats.ga:8888`,
                // 'http://192.168.1.105:8888', 
                socketOptions: { transports: ['websocket'], 'force new connection': true },
                debug: true
            };
            StalkWebRtcFactory.WebRtcFactory.getObject(rtcConfig).then(webrtc => {
                self.webrtc = webrtc;

                if (!!self.webrtc) {
                    self.webrtc.webrtcEvents.on(AbstractWEBRTC.ON_CONNECTION_READY, (socker_id) => {
                        let mediaContrains = self.getMediaConstraint(self.webrtc.userMedia);
                        // {
                        //     audio: true, //video: false
                        //     video: {
                        //         mandatory: {
                        //             minWidth: 640, // Provide your own width, height and frame rate here
                        //             minHeight: 360,
                        //             minFrameRate: 24,
                        //         }
                        //     }
                        // };
                        self.webrtc.userMedia.stopLocalStream();
                        self.webrtc.userMedia.startLocalStream(mediaContrains, true)
                            .then(function (stream) {
                                self.setState({ selfViewSrc: stream.toURL(), ready: true });
                                self.webrtc.join(self.state.roomName || "test");
                            }).catch(error => {
                                console.warn("startLocalStream: ",error);
                                alert(error);
                            });
                    });
                    self.webrtc.webrtcEvents.on(AbstractPeerConnection.PEER_STREAM_ADDED, (peer) => {
                        InCallManager.setForceSpeakerphoneOn(true)
                        this.timer = setInterval(() => this.setState({ time: this.state.time + 1 }), 1000);
                        console.log(AbstractPeerConnection.PEER_STREAM_ADDED, peer.stream);
                        self.setState({ remote: peer.stream.toURL() });
                    });
                    self.webrtc.webrtcEvents.on(AbstractPeerConnection.PEER_STREAM_REMOVED, () => {
                        console.log("peer removed...");
                        this.clearTimer()
                        self.removeVideo();
                    });
                    self.webrtc.webrtcEvents.on(AbstractPeerConnection.CONNECTIVITY_ERROR, (peer) => {
                        console.log(AbstractPeerConnection.CONNECTIVITY_ERROR, peer);
                    });
                    self.webrtc.webrtcEvents.on(AbstractPeerConnection.ON_ICE_CONNECTION_FAILED, (data) => {
                        console.log(AbstractPeerConnection.ON_ICE_CONNECTION_FAILED, data);
                    });
                    self.webrtc.webrtcEvents.on(AbstractWEBRTC.JOIN_ROOM_ERROR, (err) => console.log("joinRoom fail", err));
                    self.webrtc.webrtcEvents.on(AbstractWEBRTC.JOINED_ROOM, (roomName) => console.log("joinedRoom", roomName));
                    self.webrtc.webrtcEvents.on(AbstractPeerConnection.CREATED_PEER, self.onPeerCreated);
                    self.webrtc.webrtcEvents.on(AbstractWEBRTC.ON_CONNECTION_CLOSE, self.connectionClose);
                }
            }).catch(err => {
                console.warn("Fuck!", err);
            });
        }
        clearTimer() {
            clearInterval(this.timer)
            this.setState({ time: 0 })
        }
        getMediaConstraint(userMedia =undefined){
            let mediaConst = {
                audio: {
                    volume: 0.2 
                        // userMedia == undefined ? 
                        // this.webrtc.userMedia.volumeController.getVolume() :
                        // userMedia.volumeController.getVolume()
                }, //video: false
                video: {
                    mandatory: {
                        minWidth: 640, // Provide your own width, height and frame rate here
                        minHeight: 360,
                        minFrameRate: 24,
                    }
                }
            };
            return mediaConst;
        }
        componentWillUnmount() {
            this.clearTimer()
            this.disconnect();
        }

        removeVideo() {
            this.setState({ remote: null });
        }

        disconnect() {
            this.webrtc.leaveRoom();
            this.webrtc.disconnect();
        }

        toggleLoudspeaker() {
            let mute = !this.state.mute
            this.setState({ mute })
            let tracks = this.webrtc.userMedia.getLocalStream().getAudioTracks();
            if (tracks.length > 0) {
                tracks.forEach((element, index, array) => {
                    element.enabled = !mute;
                })
                InCallManager.setMicrophoneMute(!mute);
            }
        }

        toggleSelfCamera() {
            this.setState({ showSelfView: !this.state.showSelfView })
        }

        switchVideoType() {
            let self = this
            const isFront = !this.state.isFront;
            self.webrtc.userMedia.stopLocalStream();
            self.setState({ isFront });

            let mediaContrains = self.getMediaConstraint(self.webrtc.userMedia);
            // {
            //     audio: true,
            //     video: {
            //         mandatory: {
            //             minWidth: 640, // Provide your own width, height and frame rate here
            //             minHeight: 360,
            //             minFrameRate: 30,
            //         }
            //     }
            // }
            self.webrtc.userMedia.stopLocalStream();
            self.webrtc.userMedia.startLocalStream(mediaContrains, isFront).then(function (stream) {
                let peers = self.webrtc.peerManager.getPeers();
                self.setState({ selfViewSrc: stream.toURL() });
                peers.forEach((peer, index) => {
                    peer.addStream(stream);
                })
            }).catch(error => {
                console.warn(error);
                alert(error);
            });
        }

        onPeerCreated(peer) {
            console.log("onPeerCreated", peer.pcEvent);
            this.setState(prev => ({ ...prev, peer: peer }));
        }

        connectionClose() {
            console.log("connection close");
            if(this.webView)
                this.webView.postMessage("Post message from react native");
        }

        render() {
            return (
                <View style={styles.container} >
                    <Comp communication={this} navigate={this.props.navigation} />
                </View>
            )
        }
    }
}


const styles = StyleSheet.create({
    container: {
        flex: 1,
        justifyContent: 'flex-start',
        backgroundColor: '#F5FCFF',
    },
});