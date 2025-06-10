<template>
	<view class="qiun-columns">
		<view class="qiun-padding">
			<view class="qiun-tip" @tap="loadData()">更新温湿度曲线</view>
		</view>
		
		<view>区域图</view>
		<view class="qiun-charts">
			<!--#ifdef MP-ALIPAY -->
			<canvas canvas-id="canvasArea" id="canvasArea" class="charts" :width="cWidth*pixelRatio" :height="cHeight*pixelRatio" :style="{'width':cWidth+'px','height':cHeight+'px'}" @touchstart="touchIt($event,'canvasArea')"></canvas>
			<!--#endif-->
			<!--#ifndef MP-ALIPAY -->
			<canvas canvas-id="canvasArea" id="canvasArea" class="charts" @touchstart="touchIt($event,'canvasArea')"></canvas>
			<!--#endif-->
		</view>
		<view>横屏图表</view>
		<view class="qiun-charts-rotate">
			<!--#ifdef MP-ALIPAY -->
			<canvas canvas-id="canvasLineB" id="canvasLineB" class="charts-rotate" :style="{'width':cWidth2*pixelRatio+'px','height':cHeight2*pixelRatio+'px', 'transform': 'scale('+(1/pixelRatio)+')','margin-left':-cWidth2*(pixelRatio-1)/2+'px','margin-top':-cHeight2*(pixelRatio-1)/2+'px'}" @touchstart="touchIt($event,'canvasLineB')"></canvas>
			<!--#endif-->
			<!--#ifndef MP-ALIPAY -->
			<canvas canvas-id="canvasLineB" id="canvasLineB" class="charts-rotate" @touchstart="touchIt($event,'canvasLineB')"></canvas>
			<!--#endif-->
		</view>
	</view>
</template>

<script>
	import uCharts from '../../components/u-charts/u-charts.js';
	var _self;
	var canvasObj = {};
	export default {
		data() {
			return {
				devid:'4e83c49c-0a88-4b18-a781-9ebd9306a972',
				cWidth: '',
				cHeight: '',
				cWidth2: '', //横屏图表
				cHeight2: '', //横屏图表
				pixelRatio: 1,
				
			}
		},
		onLoad() {
			_self = this;
			this.cWidth = uni.upx2px(750);
			this.cHeight = uni.upx2px(500);
			this.cWidth2 = uni.upx2px(700);
			this.cHeight2 = uni.upx2px(1100);
		},
		onReady() {
			this.loadData();
		},
		methods: {
			loadData(){
				uni.showLoading({
					title: 'load data...',
					mask: false
				});
				uni.request({
					url: this.globalVal.default_url.devHistory,
					method: 'POST',
					data: {
						deviceId:this.devid
					},
					success: res => {
						console.log(res);
						if(200 == res.statusCode){
							if(undefined == res.data.error_code){
								let devhistory = res.data.deviceDataHistoryDTOs;
								//.data.deviceDataHistoryDTOs["0"].data.infostring
								this.refreshData(devhistory);
							}
						}
						
					},
					fail: () => {
						console.log("load data failed!!!");
					},
					complete: () => {
						uni.hideLoading();
					}
				});
			},
			refreshData(historyList){
				let Area = {
					categories: [],
					series: [{
						"type":"area",
						"show":true,
						"pointShape":"circle",
						"name":"湿度",
						"legendShape":"triangle",
						"data":[],
						"color":"#facc14",
						"area":[66.44999999999999,5,157.14999999999998,23]
						},
						{
						"type":"area",
						"show":true,
						"pointShape":"circle",
						"name":"温度",
						"legendShape":"triangle",
						"data":[],
						"color":"#2fc25b",
						"area":[157.14999999999998,5,247.84999999999997,23]
						}]
				};
				
				let count = 0;
				for (let index in historyList) {
					let infostring = historyList[index].data.infostring;
					if(undefined == infostring) continue;
					let temperature = infostring.T;
					let humidity = infostring.H;
					if(undefined != temperature && 0 < temperature){
						var utc_datetime = historyList[index].timestamp;
						var local_date = this.utc2beijing(utc_datetime)
						console.log(temperature+"/"+humidity+local_date.toDateString());
						let time = local_date.getHours()+""+local_date.getMinutes()+""+local_date.getSeconds();
						//Area.categories.push(time);
						Area.categories[count] = time;
						Area.series[0].data[count] = humidity;
						Area.series[1].data[count] = temperature;
						count++;
					}
					if(7 == count) {
						console.log(Area.categories);
						console.log(Area.series);
						this.showArea("canvasArea", Area);
						this.showLineB("canvasLineB", Area);
						break;
					}	
				}
			},
			touchIt(e,id) {
				canvasObj[id].touchLegend(e, {
				animation : false
				});
				canvasObj[id].showToolTip(e, {
					format: function (item, category) {
						if(typeof item.data === 'object'){
							return category + ' ' + item.name + ':' + item.data.value 
						}else{
							return category + ' ' + item.name + ':' + item.data 
						}
					}
				});
			},
			showArea(canvasId, chartData) {
				canvasObj[canvasId] = new uCharts({
					$this:_self,
					canvasId: canvasId,
					type: 'area',
					fontSize:11,
					padding:[0,15,10,15],
					legend:{
						show:true,
						position:'top',
						float:'center',
						itemGap:30,
						padding:5,
						lineHeight:18,
						margin:0,
					},
					dataLabel:false,
					dataPointShape:true,
					background:'#FFFFFF',
					pixelRatio:_self.pixelRatio,
					categories: chartData.categories,
					series: chartData.series,
					animation: false,
					xAxis: {
						type:'grid',
						gridColor:'#CCCCCC',
						gridType:'dash',
						dashLength:8,
						boundaryGap:'justify'//两端不留白配置
					},
					yAxis: {
						gridType:'dash',
						gridColor:'#CCCCCC',
						dashLength:8,
						splitNumber:5,
					},
					width: _self.cWidth*_self.pixelRatio,
					height: _self.cHeight*_self.pixelRatio,
					extra: {
						area:{
							type: 'curve',
							opacity:0.2,
							addLine:true,
							width:2
						}
					}
				});
			},
			showLineB(canvasId, chartData) {
				canvasObj[canvasId] = new uCharts({
					$this: _self,
					canvasId: canvasId,
					type: 'line',
					fontSize: 11,
					padding:[15,15,0,15],
					legend:{
						show:true,
						padding:5,
						lineHeight:11,
						margin:5,
					},
					background: '#FFFFFF',
					pixelRatio: _self.pixelRatio,
					rotate: true, //开启图表横屏
					// #ifdef MP-ALIPAY
					rotateLock: true, //百度及支付宝需要锁定旋转
					// #endif
					categories: chartData.categories,
					animation: false,
					series: chartData.series,
					xAxis: {
						disableGrid: true,
					},
					yAxis: {
						//disabled:true
					},
					width: _self.cWidth2 * _self.pixelRatio,
					height: _self.cHeight2 * _self.pixelRatio,
					dataLabel: true,
					dataPointShape: true,
					extra: {
						lineStyle: 'curve'
					},
				});
			},
			insertStr(soure, start, newStr){
			   return soure.slice(0, start) + newStr + soure.slice(start);
			},
			utc2beijing(utc_datetime) {
			    // 转为正常的时间格式 年-月-日T时:分:秒Z
				console.log("Org:"+utc_datetime);
				var new_datetime = this.insertStr(this.insertStr(this.insertStr(this.insertStr(utc_datetime,4,"-"),7,"-"), 13, ":"), 16, ":");
				console.log("UTC:"+new_datetime);
			    // 处理成为时间戳
			    timestamp = new Date(Date.parse(new_datetime));
			    timestamp = timestamp.getTime();
			    timestamp = timestamp/1000;
			
			    // 增加8个小时，北京时间比utc时间多八个时区
			    var timestamp = timestamp+8*60*60;
			    // 时间戳转为时间
			    var beijing_datetime = new Date(parseInt(timestamp) * 1000);
			    return beijing_datetime; // 2017-03-31 16:02:06
			}
		}
	}
</script>

<style>
	
	page {
		background: #F2F2F2;
		width: 750upx;
		overflow-x: hidden;
	}
	
	.qiun-columns {
		display: flex;
		flex-direction: column !important;
	}
	
	.qiun-padding {
		padding: 2%;
		width: 96%;
	}
	
	.qiun-tip {
		display: block;
		width: auto;
		overflow: hidden;
		padding: 15upx;
		height: 30upx;
		line-height: 30upx;
		margin: 10upx;
		background: #ff9933;
		font-size: 30upx;
		border-radius: 8upx;
		justify-content: center;
		text-align: center;
		border: 1px solid #dc7004;
		color: #FFFFFF;
	}
	
	/* 通用样式 */
	.qiun-charts {
		width: 750upx;
		height: 500upx;
		background-color: #FFFFFF;
	}
	
	.charts {
		width: 750upx;
		height: 500upx;
		background-color: #FFFFFF;
	}
	/* 横屏样式 */
	.qiun-charts-rotate {
		width: 700upx;
		height: 1100upx;
		background-color: #FFFFFF;
		padding: 25upx;
	}
	
	.charts-rotate {
		width: 700upx;
		height: 1100upx;
		background-color: #FFFFFF;
	}
</style>
