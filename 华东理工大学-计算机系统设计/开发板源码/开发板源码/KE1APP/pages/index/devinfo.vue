<template>
	<view class="uni-common-mt">
		<view class="uni-form-item uni-column">
			<view class="with-fun">
				<input class="uni-input inputText" placeholder="输入设备ID号" type="text" :value="devid" maxlength="36" @input="devIdInput"/>
			</view>
		</view>
		<view class="line"></view>
		<view>
			最新上送的信息:{{userinfo}}
		</view>
		<view>
			温度: {{termperature}}'C  湿度: {{humidity}}%
		</view>
		<view class="line"></view>
		<view class="uni-padding-wrap uni-common-mt">
			<button type="primary" :disabled="btnAddDisable" @tap="getInfo">信息查询</button>
		</view>
		<view class="line"></view>
		<view class="uni-padding-wrap uni-common-mt">
			<button type="primary" :disabled="btnAddDisable" @tap="getHistoryInfo">历史信息查询</button>
		</view>
		<view class="line"></view>
		<view class="uni-padding-wrap uni-common-mt">
			<button type="primary" @tap="viewInChart">图表查看</button>
		</view>
		
		<view class="jsonText">
			{{devinfo}}
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				devid:'4e83c49c-0a88-4b18-a781-9ebd9306a972',
				devinfo:null,
				userinfo:null,
				termperature:null,
				humidity:null,
				btnAddDisable:false
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
			getInfo(){
				uni.showLoading({
					title: '数据加载中...',
					mask: false
				});
				uni.request({//向云端服务发送请求获取设备最新信息
					url: this.globalVal.default_url.devInfo,
					method: 'POST',
					data: {
						deviceId:this.devid
					},
					success: res => {
						console.log(res);
						if(200 == res.statusCode){
							this.devinfo = JSON.stringify(res.data);
							if(undefined == res.data.error_code){
								this.userinfo = res.data.services[0].data.infostring;
								let val = JSON.parse(this.userinfo);
								this.termperature = val.T;
								this.humidity = val.H;
								
								console.log("温度: "+val.T+"C"+" 湿度: "+val.H+"%");
							}
							
						}
					},
					fail: () => {},
					complete: () => {
						uni.hideLoading();
					}
				});
			},
			getHistoryInfo(){
				uni.navigateTo({
					url: 'devhistory?devid='+this.devid,
					success: res => {},
					fail: () => {},
					complete: () => {}
				});
			},
			viewInChart(){
				uni.navigateTo({
					url: 'uchart',
					success: res => {},
					fail: () => {},
					complete: () => {}
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
	.jsonText{
		word-wrap:break-word;
	}
</style>
