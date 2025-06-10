<template>
	<view class="uni-common-mt">
		<view class="logo-content">
			<image class="logo" src="/static/scan_icon.png" @tap="scanDev"></image>
		</view>
		
		<view class="uni-form-item uni-column">
			<view class="with-fun">
				<input class="uni-input inputText" placeholder="输入模组IMEI号" type="number" :value="imei" maxlength="15" @input="imeiInput"/>
			</view>
		</view>
		
		<view class="line"></view>
		<view class="uni-padding-wrap uni-common-mt">
			<button type="primary" :disabled="btnAddDisable" @tap="regDev">注册添加设备</button>
		</view>
		
		<view class="devIdText">
			设备ID号:<br>
			<text style="color: #0A98D5;">{{devid}}</text>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				imei:"",/* 通过AT命令AT+CGSN=1获取 IMEI号并填入*/
				devid:'注册设备后服务器返回的设备id',/* 注册设备后服务器返回的设备id */
				devname:'',
				btnAddDisable:true,
				btnRenameDisable:true,
				btnInfoDisable:true
			}
		},
		onLoad() {
			if(process.env.NODE_ENV === 'development'){
			    console.log('开发环境')
			}else{
			    console.log('生产环境')
			}
		},
		methods: {
			scanDev(){
				uni.scanCode({//启动摄像头扫描模组二维码获取IMEI号
					success: (res) => {
						var result;
						console.log('条码类型：' + res.scanType);
						console.log('条码内容：' + res.result);
						if(res.result.length>15){
							result = res.result.substring(0,15);
						}else{
							result = res.result;
						}
						console.log('result：' + result);
						this.imei = result;
						this.btnAddDisable = false;
					},
					fail: (err) => {
						console.log(err);
						// #ifdef MP
						uni.getSetting({
							success: (res) => {
								let authStatus = res.authSetting['scope.camera'];
								if (!authStatus) {
									uni.showModal({
										title: '授权失败',
										content: this.i18n.content_note.text_app_name+'需要使用您的相机，请在设置界面打开相关权限',
										success: (res) => {
											if (res.confirm) {
												uni.openSetting()
											}
										}
									})
								}
							}
						})
						// #endif
					}
				});
			},
			imeiInput(e){
				console.log("imeiInput");
				this.imei = e.target.value;
				if(15 == this.imei.length){
					this.btnAddDisable = false;
				}else{
					this.btnAddDisable = true;
				}
			},
			nameInput(e){
				console.log("nameInput");
				this.devname = e.target.value;
				if(5 < this.devname.length){
					this.btnRenameDisable = false;
				}else{
					this.btnRenameDisable = true;
				}
			},
			regDev(){
				console.log("regDev URL:"+this.globalVal.default_url.devReg);
				uni.showLoading({
					title: '注册中...',
					mask: false
				});
				var errcode = 1;
				var errmsg = "失败";
				uni.request({//向云端服务发送设备注册请求
					url: this.globalVal.default_url.devReg,
					method: 'POST',
					data: {
						imei:this.imei
					},
					success: res => {
						console.log(res);
						if(200 == res.statusCode){
							errcode = res.data.errcode;
							if(0 == errcode){
								errmsg = "注册成功";
								this.devid = res.data.deviceId;
								this.devname = res.data.deviceName;
								this.btnInfoDisable = false;
							}else{
								errmsg = res.data.errmsg;
							}
						}
					},
					fail: () => {},
					complete: () => {
						uni.hideLoading();
						uni.showToast({
							title: errmsg,
							icon:"none",
							duration:2500
						});
					}
				});
			}
			
		}
	}
</script>

<style>
	.logo-content {
		text-align: center;
		margin-top: 200upx;
		margin-bottom: 100upx;
	}
	
	.logo {
		height: 120upx;
		width: 120upx;
	}
	
	.line {
		width: 90%;
		height: 1px;
		margin-left: 30upx;
		margin-right: 30upx;
		background-color: #cccccc;
		margin-top: 1px;
	}
	
	.inputText {
		margin-left: 30upx;
	}
	.devIdText{
		margin-left: 30upx;
		margin-right: 30upx;
	}
</style>
