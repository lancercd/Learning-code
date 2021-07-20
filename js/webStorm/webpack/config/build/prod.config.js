const webpack = require('webpack');
const UglifyjsWebpackPlugin = require('uglifyjs-webpack-plugin');
const webpackMerge = require('webpack-merge');
const baseConfig = require('./base.config');


module.exports = webpackMerge.merge(baseConfig,{
    plugins: [
        new webpack.BannerPlugin('最终版权归lancercd所有'),
        new UglifyjsWebpackPlugin()
    ]
});