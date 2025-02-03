#include "ofApp.h"
#include <random>
#include <vector>
#include <algorithm>

std::vector<int> randomNumbers(5);
bool sorted = false;
//--------------------------------------------------------------
void ofApp::setup() {
	generateRandomNumbers();
}

void ofApp::generateRandomNumbers() {
	unsigned seed = 123;
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> dis(10, 100);

	randomNumbers.clear();
	for (int i = 0; i < 5; ++i) {
		randomNumbers.push_back(ofRandom(10, 101));
	}
	sorted = false;
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofDrawBitmapString("Press keys to control:", 20, 30);
	ofDrawBitmapString("b - Bubble Sort", 20, 50);
	ofDrawBitmapString("i - Insertion Sort", 20, 70);
	ofDrawBitmapString("m - Merge Sort", 20, 90);
	ofDrawBitmapString("q - Quick Sort", 20, 110);
	ofDrawBitmapString("r - Regenerate numbers", 20, 130);

	std::cout << "Random Numbers: ";
	for (auto num : randomNumbers) {
		std::cout << num << " ";
	}
	std::cout << std::endl;

	ofSetColor(255, 0, 0);
	///ofDrawBitmapString("Hello World!", 100, 100);

	std::vector<ofPoint> positions = {
		ofPoint(100, 500), ofPoint(200, 500), ofPoint(300, 500),
		ofPoint(400, 500), ofPoint(500, 500)
	};



	for (int i = 0; i < 5; ++i) {

		if (i % 2 == 0)
			ofSetColor(0, 0, 225);
		else
			ofSetColor(225, 150, 0);

		ofDrawCircle(positions[i].x, positions[i].y, randomNumbers[i]);
	}
}

void ofApp::bubbleSort()
{
	for (size_t i = 0; i < randomNumbers.size() - 1; ++i) {
		for (size_t j = 0; j < randomNumbers.size() - i - 1; ++j) {
			if (randomNumbers[j] > randomNumbers[j + 1]) {
				std::swap(randomNumbers[j], randomNumbers[j + 1]);
			}
		}
	}
	sorted = true;
}



int ofApp::partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;


	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}


void ofApp::quickSort(std::vector<int>& arr, int low, int high)
{
	if (low < high) {

		int pi = partition(arr, low, high);


		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'b')
	{
		bubbleSort();
	}
	else if (key == 'i')
	{
		for (size_t i = 1; i < randomNumbers.size(); ++i) {
			int key = randomNumbers[i];
			size_t j = i - 1;
			while (j <  randomNumbers.size() && randomNumbers[j] > key) {
				randomNumbers[j + 1] = randomNumbers[j];
				if (j == 0) break;
				j--;
			}
			randomNumbers[j + 1] = key;
		}
		sorted = true;
	}
	else if (key == 'r')
	{
		///this is a new radnom
		///test 2
		randomNumbers.clear();
		for (int i = 0; i < 5; i++) {
			randomNumbers.push_back(ofRandom(10, 101));
		}

	}
	else if (key == 'q')
	{
		quickSort(randomNumbers, 0, randomNumbers.size() - 1);
		sorted = true;
	}

}






//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
