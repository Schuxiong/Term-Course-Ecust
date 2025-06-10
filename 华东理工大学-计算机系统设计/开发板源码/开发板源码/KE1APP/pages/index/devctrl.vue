<template>
	<view class="uni-common-mt">
		<view class="logo-content">
			<image class="logo" src="/static/ke1.png"></image>
		</view>
		<view class="uni-form-item uni-column">
			<view class="with-fun">
				<input class="uni-input inputText" placeholder="输入设备ID号" type="text" :value="devid" maxlength="36" @input="devIdInput"/>
			</view>
		</view>
		<view class="line"></view>
		
		<view class="uni-form-item uni-column">
			<view class="with-fun">
				<input class="uni-input inputText" placeholder="输入命令码" type="number" maxlength="2" @input="cmdCodeInput"/>
			</view>
		</view>
		<view class="line"></view>
		<view class="uni-form-item uni-column">
			<view class="with-fun">
				<input class="uni-input inputText" placeholder="输入命令字符(不支持中文)" type="text" maxlength="32" @input="cmdStrInput"/>
			</view>
		</view>
		
		<view class="line"></view>
		<view class="uni-padding-wrap uni-common-mt">
			<button type="primary" :disabled="btnAddDisable" @tap="sendCmd">{{btnInfo}}</button>
		</view>
		
	</view>
</template>

<script>export default {
		data() {
			return {
				devid:'你获取的设备注册Id号',
				cmdcode:0,
				cmdstr:'',
				cntDown:null,
				maxTime:0,
				btnInfo:"命令下发",
				btnAddDisable:true
			}
		},
		onLoad:function(e){
			
		},
		methods:{
			devIdInput(e){
				console.log("devIdInput");
				this.devid = e.target.value;
				if(36 == this.devid.length){
					this.btnAddDisable = false;
				}else{
					this.btnAddDisable = true;
				}
			},
			cmdCodeInput(e){
				console.log("cmdCodeInput");
				this.cmdcode = e.target.value;
				if(0 < this.cmdcode.length){
					this.btnAddDisable = false;
				}else{
					this.btnAddDisable = true;
				}
			},
			cmdStrInput(e){
				console.log("cmdStrInput");
				this.cmdstr = e.target.value;
				if(0 < this.cmdstr.length){
					this.btnAddDisable = false;
				}else{
					this.btnAddDisable = true;
				}
			},
			sendCmd(){
				console.log("sendCmd");
				if(36 != this.devid.length){
					uni.showToast({
						icon:'none',
						title: '设备ID号错误,请先注册！'
					});
					return;
				}
				if(0 != this.maxTime){
					console.log("sendCmd busy");
					return;
				}
				//{"cmdstring":"{"L1":0,"L2":0}","cmdlen":15,"cmdcode":3}
				let cmdpara = {
					cmdstring:this.cmdstr,
					cmdlen:this.cmdstr.length,
					cmdcode:this.cmdcode
				}
				let cmdstr = JSON.stringify(cmdpara);
				console.log("cmdstr:"+cmdstr);
				
				uni.request({
					url: this.globalVal.default_url.devCmd,
					method: 'POST',
					data: {
						deviceId:this.devid,
						cmdInfo:cmdstr
					},
					success: res => {
						uni.showToast({//向云端服务发送命令下发请求
							title: '命令下发成功!请检查设备端',
							icon:"none",
							duration:3000
						});
						this.btnAddDisable = true;
						this.maxTime = 60;
						this.countDownFun();
					},
					fail: () => {},
					complete: () => {}
				});
			},
			countDownFun(){
				console.log("countDown start...");
				this.cntDown = setInterval(()=>{
					if(0 == this.maxTime){
						this.btnInfo = "命令下发"
						clearInterval(this.interval);
						this.interval = null;
						this.btnAddDisable = false;
						return;
					}else{
						this.maxTime--;
						this.btnInfo = this.maxTime+"秒";
					}
					//console.log(this.btnInfo);
				},1000);
			}
		},
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
	
</style>
