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
  /// \brief This overrides  the poll function from IOInterface it then
  /// constructs a olc pixel game engine and the uses it to send commands
  // adn draw system state
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
  /// \brief This hooks into the engine
  /// \return required to be true buy engine
  bool OnUserCreate() override;
  /// \brief This hooks into the engine
  /// \param fElapsedTime Time elasped since last frame
  /// \return if false app closes
  bool OnUserUpdate(float fElapsedTime) override;
  /// \brief This hooks into the engine
  /// \return This seems to work as true
  bool OnUserDestroy() override;
  /// \brief Draws table composite and its children recursively
  /// \param table table composite to draw
  /// \param offset offset to draw at
  /// \param yoffset offset to draw at
  void drawTableDebug(TableComposite* table,int offset,int yoffset);

};

#endif //COS214_PROJECT__IOINTERFACEGUI_H
