/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"

//==============================================================================
B259wfAudioProcessor::B259wfAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
  : AudioProcessor(BusesProperties()
#if ! JucePlugin_IsMidiEffect
#if ! JucePlugin_IsSynth
    .withInput("Input", AudioChannelSet::stereo(), true)
#endif
    .withOutput("Output", AudioChannelSet::stereo(), true)
#endif
  )
#endif
{

  mFoldParam = new AudioParameterFloat(
    "fold",
    "Fold",
    0.0f,
    1.0f,
    0.0f
  );

  mOffsetParam = new AudioParameterFloat(
    "offset",
    "Offset",
    -1.0f,
    1.0f,
    0.0f
  );

  mFilterParam = new AudioParameterFloat(
    "filter",
    "Filter",
    0.0f,
    1.0f,
    1.0f
  );

  addParameter(mFoldParam);
  addParameter(mOffsetParam);
  addParameter(mFilterParam);

}

B259wfAudioProcessor::~B259wfAudioProcessor()
{
}

//==============================================================================
const String B259wfAudioProcessor::getName() const
{
  return JucePlugin_Name;
}

bool B259wfAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool B259wfAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool B259wfAudioProcessor::isMidiEffect() const
{
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double B259wfAudioProcessor::getTailLengthSeconds() const
{
  return 0.0;
}

int B259wfAudioProcessor::getNumPrograms()
{
  return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
              // so this should be at least 1, even if you're not really implementing programs.
}

int B259wfAudioProcessor::getCurrentProgram()
{
  return 0;
}

void B259wfAudioProcessor::setCurrentProgram(int index)
{
}

const String B259wfAudioProcessor::getProgramName(int index)
{
  return {};
}

void B259wfAudioProcessor::changeProgramName(int index, const String& newName)
{
}

//==============================================================================
void B259wfAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
  for (auto &w : mWaveFolders)
    w.init(sampleRate);
}

void B259wfAudioProcessor::releaseResources()
{
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool B259wfAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
#if JucePlugin_IsMidiEffect
  ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
    && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
    return false;

  // This checks if the input layout matches the output layout
#if ! JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}
#endif

void B259wfAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
  ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  // In case we have more outputs than inputs, this code clears any output
  // channels that didn't contain input data, (because these aren't
  // guaranteed to be empty - they may contain garbage).
  // This is here to avoid people getting screaming feedback
  // when they first compile a plugin, but obviously you don't need to keep
  // this code if your algorithm always overwrites all the output channels.
  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());

  const float fold = *mFoldParam;
  const float offset = *mOffsetParam;
  const float filter = *mFilterParam;

  for (int channel = 0; channel < jmin(totalNumInputChannels, 2); ++channel)
  {
    auto* channelData = buffer.getWritePointer(channel);

    mWaveFolders[channel].setFold(fold);
    mWaveFolders[channel].setOffset(offset);
    mWaveFolders[channel].setLowPass(filter);

    mWaveFolders[channel].compute(buffer.getNumSamples(), buffer.getReadPointer(channel), buffer.getWritePointer(channel));
    
  }
}

//==============================================================================
bool B259wfAudioProcessor::hasEditor() const
{
  return true;
}

AudioProcessorEditor* B259wfAudioProcessor::createEditor()
{
  return new GenericAudioProcessorEditor(this);
}

//==============================================================================
void B259wfAudioProcessor::getStateInformation(MemoryBlock& destData)
{
  destData.ensureSize(kNumParams * sizeof(float));
  float* dataPtr = static_cast<float*>(destData.getData());

  *dataPtr++ = float(*mFoldParam);
  *dataPtr++ = float(*mOffsetParam);
  *dataPtr++ = float(*mFilterParam);
}

void B259wfAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
  const float* dataPtr = static_cast<const float*>(data);

  if (sizeInBytes < kNumParams * sizeof(float))
    return;

  *mFoldParam   = float(*dataPtr++);
  *mOffsetParam = float(*dataPtr++);
  *mFilterParam = float(*dataPtr++);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
  return new B259wfAudioProcessor();
}
