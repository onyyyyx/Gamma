#include "bench.h"
#include <ion.h>
#include <poincare/init.h>
#include <kandinsky.h>
#include "command_list.h"

namespace Ion {
namespace Device {
namespace Bench {

constexpr CommandHandler handles[] = {
  CommandHandler("ADC", Command::ADC),
  CommandHandler("BACKLIGHT", Command::Backlight),
  CommandHandler("CHARGE", Command::Charge),
  CommandHandler("DISPLAY", Command::Display),
  CommandHandler("EXIT", Command::Exit),
  CommandHandler("KEYBOARD", Command::Keyboard),
  CommandHandler("LED", Command::LED),
  CommandHandler("MCU_SERIAL", Command::MCUSerial),
  CommandHandler("PING", Command::Ping),
  CommandHandler("PRINT", Command::Print),
  CommandHandler("RESET", Command::Reset),
  CommandHandler("SLEEP", Command::Sleep),
  CommandHandler("STOP", Command::Stop),
  CommandHandler("STANDBY", Command::Standby),
  CommandHandler("VBLANK", Command::VBlank),
  CommandHandler("WRITE_EXTERNAL", Command::WriteExternal),
  CommandHandler(nullptr, nullptr)
};

constexpr const CommandList sCommandList = CommandList(handles);

constexpr int kMaxCommandLength = 255;

void run() {
  // Init the pool! Used in printFloatToText
  Poincare::Init();
  KDContext * ctx = KDIonContext::sharedContext();
  ctx->fillRect(KDRect(0,0,Ion::Display::Width,Ion::Display::Height), KDColorWhite);
  ctx->drawString("BENCH", KDPoint((320-50)/2, (240-18)/2));
  char command[kMaxCommandLength];
  while (true) {
    Ion::Console::readLine(command, kMaxCommandLength);
    const CommandHandler * ch = sCommandList.dispatch(command);
    if (ch != nullptr && ch->function() == Command::Exit) {
      break;
    }
  }
}

}
}
}
