FaustB259wf : UGen
{
  *ar { | in1, gain(0.0), lowpass(0.0), offset(0.0) |
      ^this.multiNew('audio', in1, gain, lowpass, offset)
  }

  *kr { | in1, gain(0.0), lowpass(0.0), offset(0.0) |
      ^this.multiNew('control', in1, gain, lowpass, offset)
  } 

  checkInputs {
    if (rate == 'audio', {
      1.do({|i|
        if (inputs.at(i).rate != 'audio', {
          ^(" input at index " + i + "(" + inputs.at(i) + 
            ") is not audio rate");
        });
      });
    });
    ^this.checkValidInputs
  }

  name { ^"FaustB259wf" }
}

