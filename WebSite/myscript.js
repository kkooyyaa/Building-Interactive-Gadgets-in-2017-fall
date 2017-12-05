$.ajaxSetup({timeout:100});

var latch = false;

function readUrlAV (form) {
    TextVar = form.inputbox.value;
	VideoVar = "http://"+TextVar+":8080/video";
	AudioVar = "http://"+TextVar+":8080/audio.opus";
	document.getElementById("video").setAttribute('data', VideoVar);
	document.getElementById("audio").setAttribute('data', AudioVar);
}
function testarArduino (form) {
    TextVar = myform2.inputbox.value;
	ArduinoVar = "http://" + TextVar + ":80";
	$.get( ArduinoVar, { "cm3": 7000 })	;
	{Connection: close};
}

document.onkeydown = checkKeyDown;
document.onkeyup = checkKeyUp;

function upArrow(){
    TextVar = myform2.inputbox.value;
    ArduinoVar = "http://" + TextVar + ":80";
    $.get( ArduinoVar, { "cm1": 1000 }) ;
    {Connection: close};
    latch = true;

}
function downArrow(){
    TextVar = myform2.inputbox.value;
    ArduinoVar = "http://" + TextVar + ":80";
    $.get( ArduinoVar, { "cm2": 1000 }) ;
    {Connection: close};
    latch = true;
}
function leftArrow(){
    TextVar = myform2.inputbox.value;
    ArduinoVar = "http://" + TextVar + ":80";
    $.get( ArduinoVar, { "cm3": 1000 }) ;
    {Connection: close};
    latch = true;
}
function rightArrow(){
    TextVar = myform2.inputbox.value;
    ArduinoVar = "http://" + TextVar + ":80";
    $.get( ArduinoVar, { "cm4": 1000 }) ;
    {Connection: close};
    latch = true;

}

function checkKeyDown(e) {

    e = e || window.event;

    if (e.keyCode == '38') {
        // up arrow
		if (latch == false) {
            this.upArrow();
		}
    }
    else if (e.keyCode == '40') {
        // down arrow
		if (latch == false) {
			this.downArrow();
		}
    }
    else if (e.keyCode == '37') {
       // left arrow
	   if (latch == false) {
		    this.leftArrow();
		}

	}
    else if (e.keyCode == '39') {
       // right arrow
	   if (latch == false) {
			this.rightArrow();
		}
	}
}

function checkKeyUp(e) {
    e = e || window.event;

    if ((e.keyCode == '38')||(e.keyCode == '40')||(e.keyCode == '37')||(e.keyCode == '39')) {
        // up arrow
		setTimeout(doNothing, 200);
    }
}

function doNothing(){
	TextVar = myform2.inputbox.value;
		ArduinoVar = "http://" + TextVar + ":80";
		$.get( ArduinoVar, { "cm5": 1000 })	;
		{Connection: close};
		latch = false;
}

