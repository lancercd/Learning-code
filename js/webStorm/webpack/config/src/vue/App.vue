<template>
  <div>
    <h2 class="title">{{message}}</h2>
    <button @click="btnClick">按钮</button>
    <h2>{{name}}</h2>
  </div>
</template>

<script>
export default {
  name: "App",
  data() {
    return {
      message: 'hello Vue',
      name: 'lancercd'
    }
  },
  methods: {
    btnClick() {
      console.log('按钮点击');
    }
  }
}
</script>

<style scoped>
.title{
  border: 1px solid aliceblue;
}
</style>