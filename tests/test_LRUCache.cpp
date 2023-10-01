#include "catch.hpp"
#include "LRUCache.h" // ���������� ���� ���������� LRU ����

TEST_CASE("LRU Cache Test", "[LRUCache]") {
    int hitCount = 0;
    std::cout << "2 5" << "\n";
    std::cout << "1 2 3 2 1" << "\n";

    LRUCache<int, int> cache(2); // ������� LRU ��� � �������� 2
    REQUIRE(cache.get(1) == -1); // �������, ��� ������� � ������ 1 ����������� � ����

    hitCount += (cache.get(1) == -1) ? 0 : 1;
    cache.put(1, 1); // ��������� ������� � ������ 1
    hitCount += (cache.get(2) == -1) ? 0 : 1;
    cache.put(2, 2); // ��������� ������� � ������ 2

    REQUIRE(cache.get(1) == 1); 
    REQUIRE(cache.get(2) == 2); 

    cache.put(3, 3); 

    hitCount += (cache.get(3) == -1) ? 0 : 1;
    REQUIRE(cache.get(2) == 2); 
    REQUIRE(cache.get(3) == 3);
    REQUIRE(cache.get(1) == -1);

    cache.put(2, 2);

    hitCount += (cache.get(2) == -1) ? 0 : 1;
    REQUIRE(cache.get(2) == 2);
    REQUIRE(cache.get(3) == 3);

    cache.put(1, 1);

    hitCount += (cache.get(1) == -1) ? 0 : 1;
    REQUIRE(cache.get(1) == 1);
    REQUIRE(cache.get(2) == 2);

    REQUIRE(hitCount == 1);
    std::cout << hitCount << std::endl;
}