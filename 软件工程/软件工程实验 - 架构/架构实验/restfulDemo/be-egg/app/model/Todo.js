'use strict';

module.exports = app => {
  const { STRING, INTEGER } = app.Sequelize;

  const Todo = app.model.define('todo_list', {
    id: { type: STRING, primaryKey: true },
    text: STRING(50),
    finished: INTEGER(1),
  },{
    timestamps: false, //自动增加创建时间 
    tableName: 'todo_list' //设置表名称
  });

  return Todo;
};