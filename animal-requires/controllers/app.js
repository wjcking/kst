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
        'human': {
             //deps: ['human'],
            exports: 'human'
        }
    }
});
//var vue = "outside";    document.writeln(vue);
//page load when
require(['cat', 'dog', 'world', 'human'], function (cat, dog, world, human) {

    cat.say();
    cat.mine();
    dog.say();
    dog.mine("touch-dog missons everydays");
    world.world();
    human();
    alert(human);
});