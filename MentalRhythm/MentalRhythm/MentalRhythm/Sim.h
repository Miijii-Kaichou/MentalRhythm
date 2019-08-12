#pragma once

#include <iostream>
#include <string>
#include <future>
#include <atomic>
#include <mutex>

using namespace std;

class Sim {
public:
	void Start();
	bool MatchingStreak(std::string a, std::string b);
	static Sim* Get(); //Singleton

private:
	//Singleton
	Sim() { init(); }
	void init() {
		std::cout << "Simulation has initiated" << std::endl;
	}
	static atomic<Sim*> pinstance;
	static mutex m_;

	//The amount of notes you have to play
	std::string noteStreak;
};