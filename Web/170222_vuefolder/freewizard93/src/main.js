import Vue from 'vue'
import App from './App.vue'
import Test from './test.vue'

var vueconsole = new Vue({
  el: '#app',
  data : {
    sdsd : "appfirettt"
  },
  template : `
  <h1>{{sdsd}}</h1>
  `
});

var vueresult = new Vue({
  el:'#test',
  data : {
    msg : "tempppplattttee",
    samjeon : true
  },
  methods : {
    testmethod : function(){
      console.log("came from testmethod");
    },
    fre : function(){
      console.log("methodddd");
      return "hello world";
    }
  },
  template: `
  <div>
  <div>
  <h6 v-on:click="fre()">sdasd</h6>
  </div>
  
  <input type="checkbox" v-model="samjeon">
  <h1 v-if="samjeon==true" id="test2">{{msg}}teasdmplatetest freewizard{{sdsdsd}}</h1>
  <img src="src/assets/logo.png">
  </div>
  `,
  computed:{
    sdsdsd : function(){
      var tmp = vueconsole.sdsd;
      jeon = vueconsole.sdsd;
      return tmp;
    }
  }
});

function testmethod(){
  console.log("came from independent testethod");
}

$(".hello").css("background-color","blue");
vueconsole.sdsd = testttt;
vueresult.msg = "jeonjinhyuk";