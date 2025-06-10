<template>
	<view class="uni-common-mt">
		<view class="logo-content">
			<view @tap="ledSwitch">
				<image v-if="ledsta" class="logo" src="/static/led-variant-on.png"></image>
				<image v-else class="logo" src="/static/led-variant-off.png"></image>
			</view>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				devid:'你获取的设备注册Id号',
				cmdstr:"led",
				cmdcode:0,
				ledsta:false
				
			}
		},
		onLoad() {
	
		},
		methods: {
			ledSwitch(){
				//{"cmdstring":"saasdsa","cmdlen":15,"cmdcode":3}
				if(36 != this.devid.length){
					uni.showToast({
						icon:'none',
						title: '设备ID号错误,请先注册！'
					});
					return;
				}
				let cmdpara = {
					cmdstring:this.cmdstr,
					cmdlen:this.cmdstr.length,
					cmdcode:this.cmdcode
				}
				let cmdstr = JSON.stringify(cmdpara);
				console.log("cmdstr:"+cmdstr);
				if(this.ledsta){
					this.ledsta = false;
				}else{
					this.ledsta = true;
				}
				uni.showLoading({
					title: 'led swtich...',
					mask: false
				});
				uni.request({
					url: this.globalVal.default_url.devCmd,
					method: 'POST',
					data: {
						deviceId:this.devid,
						cmdInfo:cmdstr
					},
					success: res => {
						console.log(res);
					},
					fail: () => {
						console.log("led swtich failed!!!");
					},
					complete: () => {
						uni.hideLoading();
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
</style>
