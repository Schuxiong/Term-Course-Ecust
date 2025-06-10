<template>
	<view class="uni-common-mt">
		<view class="uni-list">
			<!-- :data-newsid="item.post_id"  :表示参数为动态，data- 语法（任意类型数据）item.post_id 中post_id是服务器返回数据中的一个参数 -->
			<view class="uni-list-cell" hover-class="uni-list-cell-hover" v-for="(item,index) in devhistory" :key="index">
				
				<view class="uni-media-list" v-if="item.data.infostring">
					<view class="uni-media-list-body">
						<view class="uni-media-list-text-top">温度:&nbsp;{{item.data.infostring.T}}'C&nbsp;湿度:&nbsp;{{item.data.infostring.H}}%</view>
						<view class="uni-media-list-text-bottom uni-ellipsis">UTC时间: {{item.timestamp}}</view>
					</view>
				</view>
			</view>
		</view>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				devhistory:null
			}
		},
		onLoad:function(e){
			console.log("devId:"+e.devid);
			if(undefined != e.devid){
				uni.showLoading({
					title: '数据加载中...',
					mask: false
				});
				uni.request({//向云端服务发送请求获取设备最新信息(最多30条历史数据)
					url: this.globalVal.default_url.devHistory,
					method: 'POST',
					data: {
						deviceId:e.devid
					},
					success: res => {
						console.log("resp:"+res);
						if(200 == res.statusCode){
							if(undefined == res.data.error_code){
								this.devhistory = res.data.deviceDataHistoryDTOs;
								
							}
						}
						
					},
					fail: () => {},
					complete: () => {
						uni.hideLoading();
					}
				});
			}
		},
		methods:{
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
