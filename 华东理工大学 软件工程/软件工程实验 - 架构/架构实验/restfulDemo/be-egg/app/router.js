'use strict';

/**
 * @param {Egg.Application} app - egg application
 */

module.exports = app => {
  const { router, controller } = app;
  router.get('/api/getTodos', controller.demo.getTodos);
  router.post('/api/addTodo', controller.demo.addTodo);
  router.post('/api/finishTodo', controller.demo.finishTodo);
  router.post('/api/delTodo', controller.demo.delTodo);
};
