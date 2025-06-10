const {createProxyMiddleware} = require('http-proxy-middleware')

module.exports = function(app) {
  app.use(
    createProxyMiddleware('/api1', {
      target: 'http://127.0.0.1:7001',  // egg.js
      changeOrigin: true,
      pathRewrite: {
        '^/api1/getTodos': '/api/getTodos',
        '^/api1/addTodo': '/api/addTodo',
        '^/api1/finishTodo': '/api/finishTodo',
        '^/api1/delTodo': '/api/delTodo',
      }
    })
  ),
  app.use(
    createProxyMiddleware('/api2', {
      target: 'http://127.0.0.1:8080',  // tomcat
      changeOrigin: true,
      pathRewrite: {
        '^/api2/getTodos': '/api/getTodos',
        '^/api2/addTodo': '/api/addTodo',
        '^/api2/finishTodo': '/api/finishTodo',
        '^/api2/delTodo': '/api/delTodo',
      }
    })
  )
}