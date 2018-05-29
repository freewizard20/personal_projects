// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import vueResource from 'vue-resource'
import App from './App'
import vueRouter from 'vue-router'
import users from './components/users'
import test from './components/test'
Vue.use(vueResource)
Vue.use(vueRouter)

const router = new vueRouter({
  mode : 'history',
  base: __dirname,
  routes:[
    {path:'/',component:users},
    {path:'/test',component:test}
  ]
});
/* eslint-disable no-new */
new Vue({
  router,
  template: `
  <div id="app">
    <ul>
      <li><router-link to="/">Users</router link></li>
      <li><router-link to="/test">test</router link></li>
    </ul>
    <router-view></router-view>
  </div>
  `,
}).$mount('#app')
