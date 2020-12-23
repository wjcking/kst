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
            // use the global 'Backbone' as the module name.
            exports: 'world'
        }
    }
});
//var vue = "outside";    document.writeln(vue);
//page load when
require(['cat', 'dog', 'world'], function (cat, dog, world) {
 
    cat.say();
    cat.mine();
    dog.say();
    dog.mine("touch-dog missons everydays");
    world.world();
});