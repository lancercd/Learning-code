const webpackMerge = require('webpack-merge');
const baseConfig = require('./base.config');

module.exports = webpackMerge.merge(baseConfig, {
    devServer: {
        //为哪一个文件夹提供本地服务， 默认是跟文件夹, 这里我们填写'./dist
        contentBase: './dist',
        //是否实时进行监听 (页面是否实时刷新)
        inline: true,
        // port: 8080,
        //在SPA页面中，依赖HTML5的history模式
        // historyApiFallback:
    }
});