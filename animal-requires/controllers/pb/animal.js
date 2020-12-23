define([], function () {
    'use strict';

    function _showName(name) {
        document.writeln(name);
    }

    function mine(para) {
        document.writeln(para);
    }

    return {
        mine: mine,
        say(words) {
            document.writeln(words);
        },
        showName(name) { //练习私有方法
            _showName(name);
        }
    }
});