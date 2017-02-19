
function major(value){
//	debugger;
	$.ajax({
		url:window.location.href + '/' + value + '/4/maj',
	})
	.done(function(){
//		alert('yay');
	})
	.fail(function(){
//		alert('failed to make go');
	})
};

function minor(value){
//	debugger;
	$.ajax({
		url:window.location.href + '/' + value + '/4/min',
	})
	.done(function(){
//		alert('yay');
	})
	.fail(function(){
//		alert('failed to make go');
	})
};
