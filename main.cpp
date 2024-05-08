#include <cpr/body.h>
#include <cpr/cprtypes.h>
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <format>
#include <spdlog/spdlog.h>
#include <unistd.h>

void send_discord_message(std::string chat_id, std::string text) {
    nlohmann::json body = {
        {"content", text},
        {"tts", false}
    };

    cpr::Response r = cpr::Post(
        cpr::Url{std::format("https://discord.com/api/v8/channels/{}/messages", chat_id)},
        cpr::Header{{"Content-Type", "application/json"}},
        cpr::Header{{"Authorization", DISCORD_TOKEN}},
        cpr::Body{body.dump()}
    );

    if (r.status_code != 200) {
        spdlog::error("Request failed with error: {}", r.text);
        return;
    }

    spdlog::info("Succeed!");
}

int main(int, char**){
    for (int iteration = 1; iteration <= 5; iteration++) {
        send_discord_message(
            "1092423113725198380",
            std::format("Сова никогда не спит #{}", iteration)
        );

        sleep(1);
    }
}
