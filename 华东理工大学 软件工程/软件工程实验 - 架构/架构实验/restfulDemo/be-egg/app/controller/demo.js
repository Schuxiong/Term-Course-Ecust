'use strict';

const Controller = require('egg').Controller;

class DemoController extends Controller {

  async getTodos() {
    // 请求数据库
    const res = await this.ctx.model.Todo.findAll()
    // 返回结果
    this.ctx.status = 200
    this.ctx.body = res
  }

  async addTodo() {
    // 获取 request 参数
    
    const params = this.ctx.request.body
    console.log('init_data',params)
    const data = JSON.parse(params.data)
    console.log('add data----', data)

    // 请求数据库
    const res = await this.ctx.model.Todo.create(
      {
        'id': data.id,
        'text': data.text,
        'finished': data.finished,
      }
    )

    console.log('insert result----', res)

    // 返回结果
    if (res) {
      this.ctx.status = 200
      this.ctx.body = res
    } else {
      this.ctx.status = 400
      this.ctx.body = 'bad request'
    }
  }

  async finishTodo() {
    const params = this.ctx.request.body
    const data = JSON.parse(params.data)
    console.log('finish data----', data)

    const res = await this.ctx.model.Todo.update(
      { 'finished': data.finished },
      {
        where: { 'id': data.id }
      }
    )
    console.log('update result----', res)
    if (res) {
      this.ctx.status = 200
      this.ctx.body = res
    } else {
      this.ctx.status = 400
      this.ctx.body = 'bad request'
    }
  }

  async delTodo() {
    const params = this.ctx.request.body
    const data = JSON.parse(params.data)
    console.log('delete data----', data)

    const res = await this.ctx.model.Todo.destroy(
      {
        where: { 'id': data.id }
      }
    )
    console.log('delete result----', res)
    if (res) {
      this.ctx.status = 200
      this.ctx.body = res
    } else {
      this.ctx.status = 400
      this.ctx.body = 'bad request'
    }
  }
}

module.exports = DemoController;