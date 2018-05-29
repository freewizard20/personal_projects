<template>
  <div class="test">
    <span v-html="title2"></span>
    <input type='text' v-model='title'><br />
    <h1>{{title}}</h1>
    <p v-if="showName">{{user.firstName}}</p>
    <p v-else>Nobody</p>
    <p v-text="user.firstName"></p>
    <ul>
      <li v-for="item in items">{{item.title}}</li>
    </ul>
    <button v-on:click="greet('hello world')">Say Greeting</button>
  <br>
    <input type='text' v-on:keyup="pressKey" v-on:keyup.enter="enterhit">
  <br>
  <label>first name: </label><input type="text" v-model="user.firstName">
  <br>
  <label>last name: </label><input type="text" v-model="user.lastName">
  <h3>{{fullName}}</h3>
  <h2>{{msg}}</h2>
  </div>
</template>

<script>
export default {
  name : 'test',
  props: {
    msg: {
      type: String,
      default:'jinhyuk jeon'
    }
  },
  data() {
    return{
      title2:'<h2>mytitle</h2>',
      title:'hello world',
      user: {
        firstName : 'Dan',
        lastName : 'freewizard'
      },
      showName: false,
      items: [
        {title:'Item one'},
        {title:'Item two'},
        {title:'Item three'}
      ]
    }
  },
  methods: {
    greet: function(gree){
      alert(gree);
    },
    pressKey: function(e){
      console.log(e.target.value);
    },
    enterhit: function(){
      console.log("you hit enter");
    }
  },
    computed: {
      fullName:function(){
        return this.user.firstName+ ' ' +this.user.lastName;
      }
    }


}

</script>

<style scoped>

</style>
