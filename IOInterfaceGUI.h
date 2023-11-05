//
// Created by maili on 2023/11/03.
//

#ifndef COS214_PROJECT__IOINTERFACEGUI_H
#define COS214_PROJECT__IOINTERFACEGUI_H


#include "IOInterface.h"
#include "olcPixelGameEngine/olcPixelGameEngine.h"
#include "olcPixelGameEngine/olcSoundWaveEngine.h"

class IOInterfaceGUI: public IOInterface,olc::PixelGameEngine{
public:
  void poll() override;
private:
  olc::Sprite* spriteSheet;
  olc::Decal* spriteSheetDecal;
  olc::Sprite* backGround;
  olc::Decal* backgroundDecal;
  olc::sound::WaveEngine soundEngine;
  olc::sound::Wave maitreDSound;
  olc::sound::Wave clock;
  olc::sound::Wave chef1;
  olc::sound::Wave waiter;
  bool toggleDebug = true;
  bool OnUserCreate() override;
  bool OnUserUpdate(float fElapsedTime) override;
  bool OnUserDestroy() override;
  void drawTableDebug(TableComposite* table,int offset,int yoffset);

};

#endif //COS214_PROJECT__IOINTERFACEGUI_H
