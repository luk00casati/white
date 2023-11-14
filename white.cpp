#include <SFML/Audio.hpp>
#include <vector>
#include <random>

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    const unsigned int sampleRate = 44100;
    const unsigned int bufferSize = 44100;

    const int difference = 2000;
    const int lower_bound = sampleRate - difference;
    const int upper_bound = sampleRate + difference;

    std::uniform_int_distribution<> distribution(lower_bound, upper_bound);

    sf::SoundBuffer buffer;
    sf::Sound sound;
    std::vector<sf::Int16> samples(bufferSize);

    for (unsigned int i = 0; i < bufferSize; ++i) {
        samples[i] = distribution(gen);
    }
    buffer.loadFromSamples(samples.data(), bufferSize, 1, sampleRate);
    sound.setBuffer(buffer);
    //sound.setVolume(0.9);
    sound.play();
    sound.setLoop(true);
    while (sound.getStatus() == sf::Sound::Playing) {NULL;}
    return 0;
}
