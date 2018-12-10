// A playlist is considered a repeating playlist if any of the songs contain a pointer 
// to a previous song in the playlist. Otherwise, the playlist will end with the last song which points to NULL.
// Implement a function isRepeatingPlaylist that returns true if a playlist is repeating or false if it is not.
// For example, the following code prints "true" as both songs point to each other.
// Song* first = new Song("Hello");
// Song* second = new Song("Eye of the tiger"); 
// first->next(second);
// second->next(first);
// std::cout << std::boolalpha << first->isRepeatingPlaylist();
// https://www.testdome.com/questions/cpp/playlist/18029?visibility=1

#include <stdexcept>
#include <iostream>
#include <map>

class Song
{
public:
    Song(std::string name): name(name), nextSong(NULL) {}
    
    void next(Song* song)
    {
        this->nextSong = song;
    }

    bool isRepeatingPlaylist()
    {
        //throw std::logic_error("Waiting to be implemented");
        Song* current = this;
        std::map<std::string, int> countMap;
		for (; current != NULL; current = current->nextSong) {
			auto result = countMap.insert(std::pair<std::string, int>(current->name, 1));
			if (result.second == false)
			{
				return true;
			}
		}
		
		return false;
    }

private:
    const std::string name;
    Song* nextSong;
};

#ifndef RunTests
int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");
    
    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isRepeatingPlaylist();
}
#endif