/* eslint valid-jsdoc: "off" */

'use strict';

/**
 * @param {Egg.EggAppInfo} appInfo app info
 */
module.exports = appInfo => {
  /**
   * built-in config
   * @type {Egg.EggAppConfig}
   **/
  const config = exports = {};

  // use for cookie sign key, should change to your own and keep security
  config.keys = appInfo.name + '_1635228270273_4326';

  // add your middleware config here
  config.middleware = [];

  // add your user config here
  const userConfig = {
    // myAppName: 'egg',
  };

  config.sequelize = {
    baseDir: 'model',
    dialect: 'mysql',
    host: '127.0.0.1',
    // host: '101.34.61.87',
    port: '3306',
    user: 'root',
    password: 'root',
    database: 'todos',
  };

  config.cors = {
    origin: '*',
    allowMethods: 'GET,POST,DELETE'
  }

  config.security = {
    csrf: {
      useSession: false,
      sessionName: 'csrfToken',
      ignore: ctx => {
        // 跨域请求忽略csrf验证
        if (ctx.request.url.indexOf('/api') !== -1) {
          return true
        } else {
          return false
        }
      }
    },
    // cors
    domainWhiteList: ['*']
  }

  return {
    ...config,
    ...userConfig,
  };
};
