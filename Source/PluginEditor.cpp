/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DrawImageAndRectAlphaPluginExAudioProcessorEditor::DrawImageAndRectAlphaPluginExAudioProcessorEditor (DrawImageAndRectAlphaPluginExAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (640, 480);
    
    background = juce::ImageCache::getFromMemory(BinaryData::akiba_jpg, BinaryData::akiba_jpgSize);
}

DrawImageAndRectAlphaPluginExAudioProcessorEditor::~DrawImageAndRectAlphaPluginExAudioProcessorEditor()
{
}

//==============================================================================
void DrawImageAndRectAlphaPluginExAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.drawImageAt(background, 0, 0);
    
    auto x1 = 640/10*2, y1 = 480/10*2, x2 = 640 - x1*2, y2 = 480 - y1*2;

    //g.setColour (juce::Colours::black);
    g.setColour (juce::Colour ((juce::uint8)0, (juce::uint8)0, (juce::uint8) 0 , (float) 0.7f ));
    g.fillRect(x1, y1, x2, y2);
    g.setColour (juce::Colours::red);
    g.drawRect(x1, y1, x2, y2);

}

void DrawImageAndRectAlphaPluginExAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
