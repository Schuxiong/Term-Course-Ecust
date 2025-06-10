import Vue from 'vue'
import App from './App'
import globalVal from '@/myjs/global_val.js'
Vue.config.productionTip = false
Vue.prototype.globalVal = globalVal

App.mpType = 'app'

const app = new Vue({
    ...App
})
app.$mount()
