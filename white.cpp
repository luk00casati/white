#include <SFML/Audio.hpp>
#include <vector>

int main(){
    unsigned int sampleRate = 44100;
    unsigned int bufferSize = 44100; 

    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::vector<sf::Int16> samples(bufferSize);

    for (unsigned int i = 0; i < bufferSize; ++i) {
        samples[i] = rand() % (sampleRate/2);
    }
    buffer.loadFromSamples(samples.data(), bufferSize, 1, sampleRate);
    sound.setBuffer(buffer);
    //sound.setVolume(0.9);
    sound.play();
    sound.setLoop(true);
    while (sound.getStatus() == sf::Sound::Playing) {NULL;}
    return 0;
}
