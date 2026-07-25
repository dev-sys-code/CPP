#include <iostream>
#include <cstdint>

#pragma pack(push, 1)
struct PacketHeader {
    uint16_t id;
    uint16_t status;
    uint32_t payload;
};
#pragma pack(pop)

int main() {
    uint8_t rawMemory[8]{0};
    PacketHeader* header = reinterpret_cast<PacketHeader*>(rawMemory);
    header->id = 0x1337;
    header->status = 0x0001;
    header->payload = 42069;

    std::cout << "ID: 0x" << std::hex << header->id << "\n";
    std::cout << "Status: 0x" << header->status << "\n";
    std::cout << "Payload: " << std::dec << header->payload << "\n";

    return 0;
}
