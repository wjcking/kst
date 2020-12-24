require.config({
    //By default load any module IDs from js/
    baseUrl: '../controllers',
    //except, if the module ID starts with "pb"
    paths: {
        pb: 'pb'
    },
    shim: {
        'world': {
            deps: ['animalWorld'],
            exports: 'world'
        },
        //require([第一个参数和文件路径有关])
        'humanWorld': {
    //         deps: ['humanWorld'],
            exports: 'human'
        }
    }
});
//page load
//require([第一个参数和文件路径有关])
require(['cat', 'dog', 'world', 'humanWorld'], function (cat, dog, world, human) {

    cat.say();
    cat.mine();
    dog.say();
    dog.mine("touch-dog missons everydays");
    world.world();
    human(); 
});