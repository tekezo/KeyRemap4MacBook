#include <sys/systm.h>

#include "remap.hpp"
#include "RemapUtil.hpp"
#include "config.hpp"
#include "keycode.hpp"

namespace org_pqrs_KeyRemap4MacBook {
  // ----------------------------------------------------------------------
  // Modifiers -> Modifiers
  void
  remap_commandl2control(const RemapParams &params)
  {
    if (! config.remap_commandl2control) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::COMMAND_L, ModifierFlag::CONTROL_L);
  }

  void
  remap_commandl2option(const RemapParams &params)
  {
    if (! config.remap_commandl2option) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::COMMAND_L, ModifierFlag::OPTION_L);
  }

  void
  remap_shiftl2control(const RemapParams &params)
  {
    if (! config.remap_shiftl2control) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::SHIFT_L, ModifierFlag::CONTROL_L);
  }

  void
  remap_controll2command(const RemapParams &params)
  {
    if (! config.remap_controll2command) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::CONTROL_L, ModifierFlag::COMMAND_L);
  }

  void
  remap_option2command(const RemapParams &params)
  {
    if (! config.remap_option2command) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::OPTION_L, ModifierFlag::COMMAND_L);
  }

  void
  remap_option2shift(const RemapParams &params)
  {
    if (! config.remap_option2shift) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::OPTION_L, ModifierFlag::SHIFT_L);
  }

  void
  remap_optionr2command(const RemapParams &params)
  {
    if (! config.remap_optionr2command) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::OPTION_R, ModifierFlag::COMMAND_L);
  }

  void
  remap_optionr2control(const RemapParams &params)
  {
    if (! config.remap_optionr2control) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::OPTION_R, ModifierFlag::CONTROL_L);
  }

  void
  remap_optionr2fn(const RemapParams &params)
  {
    if (! config.remap_optionr2fn) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::OPTION_R, ModifierFlag::FN);
    RemapUtil::toFN(params);
  }

  void
  remap_optionr2space(const RemapParams &params)
  {
    if (! config.remap_optionr2space) return;

    RemapUtil::modifierToKey(params, ModifierFlag::OPTION_R, KeyCode::SPACE);
  }

  void
  remap_optionr2semicolon(const RemapParams &params)
  {
    if (! config.remap_optionr2semicolon) return;

    RemapUtil::modifierToKey(params, ModifierFlag::OPTION_R, KeyCode::SEMICOLON);
  }

  void
  remap_optionr2enter(const RemapParams &params)
  {
    if (! config.remap_optionr2enter) return;

    RemapUtil::modifierToKey(params, ModifierFlag::OPTION_R, RemapUtil::getEnterKeyCode(params));
  }

  void
  remap_shift2fn(const RemapParams &params)
  {
    if (! config.remap_shift2fn) return;

    RemapUtil::modifierToModifier(params, ModifierFlag::SHIFT_R, ModifierFlag::FN);
    RemapUtil::toFN(params);
  }

  void
  remap_fn2command(const RemapParams &params)
  {
    if (! config.remap_fn2command) return;

    if (RemapUtil::isModifierOn(params, ModifierFlag::FN)) {
      RemapUtil::fnToNormal(params);
    }
    RemapUtil::modifierToModifier(params, ModifierFlag::FN, ModifierFlag::COMMAND_L);
  }

  void
  remap_fn2control(const RemapParams &params)
  {
    if (! config.remap_fn2control) return;

    if (RemapUtil::isModifierOn(params, ModifierFlag::FN)) {
      RemapUtil::fnToNormal(params);
    }
    RemapUtil::modifierToModifier(params, ModifierFlag::FN, ModifierFlag::CONTROL_L);
  }

  void
  remap_fn2option(const RemapParams &params)
  {
    if (! config.remap_fn2option) return;

    if (RemapUtil::isModifierOn(params, ModifierFlag::FN)) {
      RemapUtil::fnToNormal(params);
    }
    RemapUtil::modifierToModifier(params, ModifierFlag::FN, ModifierFlag::OPTION_L);
  }

  void
  remap_fn2shift(const RemapParams &params)
  {
    if (! config.remap_fn2shift) return;

    if (RemapUtil::isModifierOn(params, ModifierFlag::FN)) {
      RemapUtil::fnToNormal(params);
    }
    RemapUtil::modifierToModifier(params, ModifierFlag::FN, ModifierFlag::SHIFT_L);
  }

  // ----------------------------------------------------------------------
  // Keys -> Modifiers, Keys -> Keys
  void
  remap_spaces_special(const RemapParams &params)
  {
    if (! config.remap_spaces_special) return;

    if (allFlagStatus.makeFlags(params) != ModifierFlag::COMMAND_R) return;

    if (*(params.key) == KeyCode::A) {
      *(params.key) = KeyCode::KEY_1;
    } else if (*(params.key) == KeyCode::S) {
      *(params.key) = KeyCode::KEY_2;
    } else if (*(params.key) == KeyCode::D) {
      *(params.key) = KeyCode::KEY_3;
    } else if (*(params.key) == KeyCode::F) {
      *(params.key) = KeyCode::KEY_4;
    } else if (*(params.key) == KeyCode::G) {
      *(params.key) = KeyCode::KEY_5;
    } else if (*(params.key) == KeyCode::H) {
      *(params.key) = KeyCode::KEY_6;
    } else if (*(params.key) == KeyCode::J) {
      *(params.key) = KeyCode::KEY_7;
    } else if (*(params.key) == KeyCode::K) {
      *(params.key) = KeyCode::KEY_8;
    } else if (*(params.key) == KeyCode::L) {
      *(params.key) = KeyCode::KEY_9;
    } else {
      return;
    }

    allFlagStatus.controlL.temporary_increase();
    allFlagStatus.optionL.temporary_increase();
    allFlagStatus.shiftL.temporary_increase();
  }

  void
  remap_homeposition_functionkey(const RemapParams &params)
  {
    if (! config.remap_homeposition_functionkey) return;

    if (allFlagStatus.makeFlags(params) != ModifierFlag::COMMAND_R) return;

    if (*(params.key) == KeyCode::A) {
      *(params.key) = KeyCode::F1;
    } else if (*(params.key) == KeyCode::S) {
      *(params.key) = KeyCode::F2;
    } else if (*(params.key) == KeyCode::D) {
      *(params.key) = KeyCode::F3;
    } else if (*(params.key) == KeyCode::F) {
      *(params.key) = KeyCode::F4;
    } else if (*(params.key) == KeyCode::G) {
      *(params.key) = KeyCode::F5;
    } else if (*(params.key) == KeyCode::H) {
      *(params.key) = KeyCode::F6;
    } else if (*(params.key) == KeyCode::J) {
      *(params.key) = KeyCode::F7;
    } else if (*(params.key) == KeyCode::K) {
      *(params.key) = KeyCode::F8;
    } else if (*(params.key) == KeyCode::L) {
      *(params.key) = KeyCode::F9;
    }

    if (! config.option_homeposition_functionkey_add_cmd) {
      allFlagStatus.commandR.temporary_decrease();
    }
  }

  void
  remap_deleteshift2tilde(const RemapParams &params)
  {
    if (! config.remap_deleteshift2tilde) return;

    // DELETE + Shift => ~ (== ` + Shift)
    if (allFlagStatus.shiftL.isHeldDown() || allFlagStatus.shiftR.isHeldDown()) {
      RemapUtil::keyToKey(params, KeyCode::DELETE, KeyCode::BACKQUOTE);
    }
  }

  void
  remap_qwerty2colemak(const RemapParams &params)
  {
    if (! config.remap_qwerty2colemak) return;

    // see http://colemak.com/
    RemapUtil::keyToKey(params, KeyCode::E, KeyCode::F);
    RemapUtil::keyToKey(params, KeyCode::R, KeyCode::P);
    RemapUtil::keyToKey(params, KeyCode::T, KeyCode::G);
    RemapUtil::keyToKey(params, KeyCode::Y, KeyCode::J);
    RemapUtil::keyToKey(params, KeyCode::U, KeyCode::L);
    RemapUtil::keyToKey(params, KeyCode::I, KeyCode::U);
    RemapUtil::keyToKey(params, KeyCode::O, KeyCode::Y);
    RemapUtil::keyToKey(params, KeyCode::P, KeyCode::SEMICOLON);
    RemapUtil::keyToKey(params, KeyCode::S, KeyCode::R);
    RemapUtil::keyToKey(params, KeyCode::D, KeyCode::S);
    RemapUtil::keyToKey(params, KeyCode::F, KeyCode::T);
    RemapUtil::keyToKey(params, KeyCode::G, KeyCode::D);
    RemapUtil::keyToKey(params, KeyCode::J, KeyCode::N);
    RemapUtil::keyToKey(params, KeyCode::K, KeyCode::E);
    RemapUtil::keyToKey(params, KeyCode::L, KeyCode::I);
    RemapUtil::keyToKey(params, KeyCode::SEMICOLON, KeyCode::O);
    RemapUtil::keyToKey(params, KeyCode::N, KeyCode::K);
  }

  void
  remap_return2option(const RemapParams &params)
  {
    if (! config.remap_return2option) return;

    RemapUtil::keyToModifier(params, KeyCode::RETURN, ModifierFlag::OPTION_L);
  }

  void
  remap_return2semicolon(const RemapParams &params)
  {
    if (! config.remap_return2semicolon) return;

    RemapUtil::keyToKey(params, KeyCode::RETURN, KeyCode::SEMICOLON);
  }

  void
  remap_shift2escape(const RemapParams &params)
  {
    if (! config.remap_shift2escape) return;

    RemapUtil::modifierToKey(params, ModifierFlag::SHIFT_R, KeyCode::ESCAPE);
  }

  void
  remap_space2shift(const RemapParams &params)
  {
    if (! config.remap_space2shift) return;

    static bool useSpaceAsShift = false;

    if (*(params.key) != KeyCode::SPACE && *(params.eventType) == KeyEvent::DOWN) {
      useSpaceAsShift = true;
    }

    if (*(params.key) == KeyCode::SPACE) {
      // Space => ShiftL (if type SpaceKey only, works as SpaceKey)
      unsigned int origEventType = *(params.eventType);
      RemapUtil::keyToModifier(params, KeyCode::SPACE, ModifierFlag::SHIFT_L);

      if (origEventType == KeyEvent::DOWN) {
        useSpaceAsShift = false;

      } else if (origEventType == KeyEvent::UP) {
        if (useSpaceAsShift == false) {
          unsigned int flags = allFlagStatus.makeFlags(params);
          listFireExtraKey.add(FireExtraKey::TYPE_AFTER, KeyEvent::DOWN, flags, KeyCode::SPACE, CharCode::SPACE);
          listFireExtraKey.add(FireExtraKey::TYPE_AFTER, KeyEvent::UP, flags, KeyCode::SPACE, CharCode::SPACE);
        }
      }
    } else if (config.option_space2shift_shift2space) {
      if (params.ex_origKey == KeyCode::SHIFT_L) {
        useSpaceAsShift = true;
        // use Shift_L as SpaceKey
        RemapUtil::modifierToKey(params, ModifierFlag::SHIFT_L, KeyCode::SPACE);
      }
    }
  }

  void
  remap_enter2command(const RemapParams &params)
  {
    if (! config.remap_enter2command) return;

    RemapUtil::keyToModifier(params, RemapUtil::getEnterKeyCode(params), ModifierFlag::COMMAND_L);
  }

  void
  remap_enter2control(const RemapParams &params)
  {
    if (! config.remap_enter2control) return;

    RemapUtil::keyToModifier(params, RemapUtil::getEnterKeyCode(params), ModifierFlag::CONTROL_L);
  }

  void
  remap_enter2option(const RemapParams &params)
  {
    if (! config.remap_enter2option) return;

    RemapUtil::keyToModifier(params, RemapUtil::getEnterKeyCode(params), ModifierFlag::OPTION_L);
  }

  void
  remap_enter2fn(const RemapParams &params)
  {
    if (! config.remap_enter2fn) return;

    RemapUtil::keyToModifier(params, RemapUtil::getEnterKeyCode(params), ModifierFlag::FN);
    RemapUtil::toFN(params);
  }

  void
  remap_enter2return(const RemapParams &params)
  {
    if (! config.remap_enter2return) return;

    RemapUtil::keyToKey(params, RemapUtil::getEnterKeyCode(params), KeyCode::RETURN);
  }

  void
  remap_enter2space(const RemapParams &params)
  {
    if (! config.remap_enter2space) return;

    RemapUtil::keyToKey(params, RemapUtil::getEnterKeyCode(params), KeyCode::SPACE);
  }

  void
  remap_enter2semicolon(const RemapParams &params)
  {
    if (! config.remap_enter2semicolon) return;

    RemapUtil::keyToKey(params, RemapUtil::getEnterKeyCode(params), KeyCode::SEMICOLON);
  }

  void
  remap_backquote2command(const RemapParams &params)
  {
    if (! config.remap_backquote2command) return;

    RemapUtil::modifierToKey(params, ModifierFlag::COMMAND_L, KeyCode::BACKQUOTE);
    RemapUtil::keyToModifier(params, KeyCode::BACKQUOTE, ModifierFlag::COMMAND_L);
  }

  void
  remap_escape2tilde(const RemapParams &params)
  {
    if (! config.remap_escape2tilde) return;

    RemapUtil::keyToKey(params, KeyCode::ESCAPE, KeyCode::BACKQUOTE);
    RemapUtil::keyToKey(params, KeyCode::BACKQUOTE, KeyCode::ESCAPE);
  }

  void
  remap_escape2return(const RemapParams &params)
  {
    if (! config.remap_escape2return) return;

    RemapUtil::keyToKey(params, KeyCode::ESCAPE, KeyCode::RETURN);
  }

  void
  remap_escape2rightclick(const RemapParams &params)
  {
    if (! config.remap_escape2rightclick) return;

    if (params.ex_origKey != KeyCode::ESCAPE) return;

    RemapUtil::keyToKey(params, KeyCode::ESCAPE, KeyCode::KEYPAD_5);

    if (*(params.eventType) == KeyEvent::DOWN) {
      allFlagStatus.controlL.increase();
    } else if (*(params.eventType) == KeyEvent::UP) {
      allFlagStatus.controlL.decrease();
    }
  }

  void
  remap_semicolon2return(const RemapParams &params)
  {
    if (! config.remap_semicolon2return) return;

    RemapUtil::keyToKey(params, KeyCode::SEMICOLON, KeyCode::RETURN);
  }

  void
  remap_drop_funcshift(const RemapParams &params)
  {
    if (! config.remap_drop_funcshift) return;

    if (allFlagStatus.shiftL.isHeldDown() || allFlagStatus.shiftR.isHeldDown()) {
      if (*(params.key) == KeyCode::F1 ||
          *(params.key) == KeyCode::F2 ||
          *(params.key) == KeyCode::F3 ||
          *(params.key) == KeyCode::F4 ||
          *(params.key) == KeyCode::F5 ||
          *(params.key) == KeyCode::F6 ||
          *(params.key) == KeyCode::F7 ||
          *(params.key) == KeyCode::F8 ||
          *(params.key) == KeyCode::F9 ||
          *(params.key) == KeyCode::F10 ||
          *(params.key) == KeyCode::F11 ||
          *(params.key) == KeyCode::F12) {
        *(params.ex_dropKey) = true;
      }
    }
  }

  void
  remap_tab2expose(const RemapParams &params)
  {
    if (! config.remap_tab2expose) return;

    // Tab => F9 (if no Modifier)
    if (allFlagStatus.makeFlags(params) != 0) return;
    RemapUtil::keyToKey(params, KeyCode::TAB, KeyCode::F9);
  }

  void
  remap_keypad2spaces(const RemapParams &params)
  {
    if (! config.remap_keypad2spaces) return;

    if (config.option_keypad2spaces_modifier_command) {
      if (! allFlagStatus.commandL.isHeldDown() &&
          ! allFlagStatus.commandR.isHeldDown()) return;
    }
    if (config.option_keypad2spaces_modifier_control) {
      if (! allFlagStatus.controlL.isHeldDown() &&
          ! allFlagStatus.controlR.isHeldDown()) return;
    }
    if (config.option_keypad2spaces_modifier_option) {
      if (! allFlagStatus.optionL.isHeldDown() &&
          ! allFlagStatus.optionR.isHeldDown()) return;
    }
    if (config.option_keypad2spaces_modifier_shift) {
      if (! allFlagStatus.shiftL.isHeldDown() &&
          ! allFlagStatus.shiftR.isHeldDown()) return;
    }

    // 789      123
    // 456  to  456
    // 123      789
    RemapUtil::keyToKey(params, KeyCode::KEYPAD_1, KeyCode::KEYPAD_7);
    RemapUtil::keyToKey(params, KeyCode::KEYPAD_2, KeyCode::KEYPAD_8);
    RemapUtil::keyToKey(params, KeyCode::KEYPAD_3, KeyCode::KEYPAD_9);

    RemapUtil::keyToKey(params, KeyCode::KEYPAD_7, KeyCode::KEYPAD_1);
    RemapUtil::keyToKey(params, KeyCode::KEYPAD_8, KeyCode::KEYPAD_2);
    RemapUtil::keyToKey(params, KeyCode::KEYPAD_9, KeyCode::KEYPAD_3);
  }

  void
  remap_hhkmode(const RemapParams &params)
  {
    if (! config.remap_hhkmode) return;

    if (! allFlagStatus.fn.isHeldDown()) return;

    allFlagStatus.keypad = false;

    // [ => up
    if (params.ex_origKey == KeyCode::BRACKET_LEFT) {
      *(params.key) = KeyCode::CURSOR_UP;
      allFlagStatus.cursor = true;
      allFlagStatus.fn.temporary_decrease();
    }
    // ; => left
    if (params.ex_origKey == KeyCode::SEMICOLON || params.ex_origKey == KeyCode::KEYPAD_MINUS) {
      *(params.key) = KeyCode::CURSOR_LEFT;
      allFlagStatus.cursor = true;
      allFlagStatus.fn.temporary_decrease();
    }
    // ' => right
    if (params.ex_origKey == KeyCode::QUOTE) {
      *(params.key) = KeyCode::CURSOR_RIGHT;
      allFlagStatus.cursor = true;
      allFlagStatus.fn.temporary_decrease();
    }
    // / => down
    if (params.ex_origKey == KeyCode::SLASH || params.ex_origKey == KeyCode::KEYPAD_PLUS) {
      *(params.key) = KeyCode::CURSOR_DOWN;
      allFlagStatus.cursor = true;
      allFlagStatus.fn.temporary_decrease();
    }
    // L => PageUp
    if (params.ex_origKey == KeyCode::L || params.ex_origKey == KeyCode::KEYPAD_3) {
      *(params.key) = KeyCode::PAGEUP;
    }
    // . => PageDown
    if (params.ex_origKey == KeyCode::DOT || params.ex_origKey == KeyCode::KEYPAD_DOT) {
      *(params.key) = KeyCode::PAGEDOWN;
    }
    // K => HOME
    if (params.ex_origKey == KeyCode::K || params.ex_origKey == KeyCode::KEYPAD_2) {
      *(params.key) = KeyCode::HOME;
    }
    // , => End
    if (params.ex_origKey == KeyCode::COMMA) {
      *(params.key) = KeyCode::END;
    }
  }

  void
  remap_emacsmode(const RemapParams &params)
  {
    if (! config.remap_emacsmode) return;

    if (allFlagStatus.controlL.isHeldDown()) {
      bool cancel_control = false;

      // Control+D -> FORWARD_DELETE
      if (config.option_emacsmode_controlD && *(params.key) == KeyCode::D) {
        *(params.key) = KeyCode::FORWARD_DELETE;
        cancel_control = true;
      }
      // Control+H -> DELETE
      if (config.option_emacsmode_controlH && *(params.key) == KeyCode::H) {
        *(params.key) = KeyCode::DELETE;
        cancel_control = true;
      }
      // Control+I -> TAB
      if (config.option_emacsmode_controlI && *(params.key) == KeyCode::I) {
        *(params.key) = KeyCode::TAB;
        cancel_control = true;
      }
      // Control+M -> RETURN
      if (config.option_emacsmode_controlM && *(params.key) == KeyCode::M) {
        *(params.key) = KeyCode::RETURN;
        cancel_control = true;
      }
      // Control+[ -> ESCAPE
      if (config.option_emacsmode_controlLeftbracket && *(params.key) == KeyCode::BRACKET_LEFT) {
        *(params.key) = KeyCode::ESCAPE;
        cancel_control = true;
      }
      // Control+P -> UP
      if (config.option_emacsmode_controlPNBF && *(params.key) == KeyCode::P) {
        *(params.key) = KeyCode::CURSOR_UP;
        allFlagStatus.cursor = true;
        cancel_control = true;
      }
      // Control+N -> DOWN
      if (config.option_emacsmode_controlPNBF && *(params.key) == KeyCode::N) {
        *(params.key) = KeyCode::CURSOR_DOWN;
        allFlagStatus.cursor = true;
        cancel_control = true;
      }
      // Control+B -> LEFT
      if (config.option_emacsmode_controlPNBF && *(params.key) == KeyCode::B) {
        *(params.key) = KeyCode::CURSOR_LEFT;
        allFlagStatus.cursor = true;
        cancel_control = true;
      }
      // Control+F -> RIGHT
      if (config.option_emacsmode_controlPNBF && *(params.key) == KeyCode::F) {
        *(params.key) = KeyCode::CURSOR_RIGHT;
        allFlagStatus.cursor = true;
        cancel_control = true;
      }
      // Control+V -> PAGEDOWN
      if (config.option_emacsmode_controlV && *(params.key) == KeyCode::V) {
        *(params.key) = KeyCode::PAGEDOWN;
        cancel_control = true;
      }
      // Control+Q -> PAGEUP
      if (config.option_emacsmode_ex_controlQ && *(params.key) == KeyCode::Q) {
        *(params.key) = KeyCode::PAGEUP;
        cancel_control = true;
      }
      // Control+W -> Option+DELETE
      if (config.option_emacsmode_ex_controlW && *(params.key) == KeyCode::W) {
        *(params.key) = KeyCode::DELETE;
        allFlagStatus.optionL.temporary_increase();
        cancel_control = true;
      }
      // Control+1 -> HOME
      // use ex_origKey for spaces_special
      if (config.option_emacsmode_ex_control12 && params.ex_origKey == KeyCode::KEY_1) {
        *(params.key) = KeyCode::HOME;
        cancel_control = true;
      }
      // Control+2 -> END
      // use ex_origKey for spaces_special
      if (config.option_emacsmode_ex_control12 && params.ex_origKey == KeyCode::KEY_2) {
        *(params.key) = KeyCode::END;
        cancel_control = true;
      }

      if (cancel_control) {
        modifierCanceling_control.keyRelease(params);
        return;
      }
    }

    if (allFlagStatus.optionL.isHeldDown()) {
      bool cancel_option = false;

      // Option+V -> PAGEUP
      if (config.option_emacsmode_controlV && *(params.key) == KeyCode::V) {
        *(params.key) = KeyCode::PAGEUP;
        cancel_option = true;
      }
      // Option+B -> Option+LEFT
      if (config.option_emacsmode_optionBF && *(params.key) == KeyCode::B) {
        *(params.key) = KeyCode::CURSOR_LEFT;
        allFlagStatus.cursor = true;
      }
      // Option+F -> Option+RIGHT
      if (config.option_emacsmode_optionBF && *(params.key) == KeyCode::F) {
        *(params.key) = KeyCode::CURSOR_RIGHT;
        allFlagStatus.cursor = true;
      }
      // Option+D -> Option+FORWARD_DELETE
      if (config.option_emacsmode_optionD && *(params.key) == KeyCode::D) {
        *(params.key) = KeyCode::FORWARD_DELETE;
      }

      if (cancel_option) {
        modifierCanceling_option.keyRelease(params);
        return;
      }
    }

    modifierCanceling_control.restore(params);
    modifierCanceling_option.restore(params);
  }

  void
  remap_jis_eisuu2control(const RemapParams &params)
  {
    if (! config.remap_jis_eisuu2control) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_EISUU, ModifierFlag::CONTROL_L);
  }

  void
  remap_jis_eisuu2command(const RemapParams &params)
  {
    if (! config.remap_jis_eisuu2command) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_EISUU, ModifierFlag::COMMAND_L);
  }

  void
  remap_jis_eisuu2option(const RemapParams &params)
  {
    if (! config.remap_jis_eisuu2option) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_EISUU, ModifierFlag::OPTION_L);
  }

  void
  remap_jis_eisuu2shift(const RemapParams &params)
  {
    if (! config.remap_jis_eisuu2shift) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_EISUU, ModifierFlag::SHIFT_L);
  }

  void
  remap_jis_eisuu2tab(const RemapParams &params)
  {
    if (! config.remap_jis_eisuu2tab) return;

    RemapUtil::keyToKey(params, KeyCode::JIS_EISUU, KeyCode::TAB);
  }

  void
  remap_jis_kana2control(const RemapParams &params)
  {
    if (! config.remap_jis_kana2control) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_KANA, ModifierFlag::CONTROL_L);
  }

  void
  remap_jis_kana2command(const RemapParams &params)
  {
    if (! config.remap_jis_kana2command) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_KANA, ModifierFlag::COMMAND_L);
  }

  void
  remap_jis_kana2option(const RemapParams &params)
  {
    if (! config.remap_jis_kana2option) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_KANA, ModifierFlag::OPTION_L);
  }

  void
  remap_jis_kana2shift(const RemapParams &params)
  {
    if (! config.remap_jis_kana2shift) return;

    RemapUtil::keyToModifier(params, KeyCode::JIS_KANA, ModifierFlag::SHIFT_L);
  }

  void
  remap_jis_kana2return(const RemapParams &params)
  {
    if (! config.remap_jis_kana2return) return;

    RemapUtil::keyToKey(params, KeyCode::JIS_KANA, KeyCode::RETURN);
  }

  void
  remap_jis_kanashift2eisuu(const RemapParams &params)
  {
    if (! config.remap_jis_kanashift2eisuu) return;

    if (params.ex_origKey != KeyCode::JIS_KANA) return;

    if (allFlagStatus.shiftL.isHeldDown() || allFlagStatus.shiftR.isHeldDown()) {
      RemapUtil::keyToKey(params, KeyCode::JIS_KANA, KeyCode::JIS_EISUU);

      if (allFlagStatus.shiftL.isHeldDown()) {
        allFlagStatus.shiftL.temporary_decrease();
      } else {
        allFlagStatus.shiftR.temporary_decrease();
      }
    }
  }

  void
  remap_jis_unify_kana_eisuu(const RemapParams &params)
  {
    if (! config.remap_jis_unify_kana_eisuu) return;

    if (params.ex_origKey != KeyCode::JIS_KANA) return;

    static bool isKana = true;

    if (isKana) {
      // do nothing
    } else {
      RemapUtil::keyToKey(params, KeyCode::JIS_KANA, KeyCode::JIS_EISUU);
    }
    if (*(params.eventType) == KeyEvent::UP) {
      isKana = ! isKana;
    }
  }
}

// ----------------------------------------------------------------------
void
org_pqrs_KeyRemap4MacBook::remap_core(const RemapParams &params)
{
  if (config.debug) {
    printf("caught  hid event type %d flags 0x%x key %d ",  *(params.eventType), *(params.flags), *(params.key));
    printf("charCode %d charSet %d ", *(params.charCode), *(params.charSet));
    printf("origCharCode %d origCharSet %d kbdType %d\n",
           *(params.origCharCode), *(params.origCharSet), *(params.keyboardType));
  }

  allFlagStatus.initialize(params);

  // change 'modifiers -> modifiers'
  remap_commandl2control(params);
  remap_commandl2option(params);
  remap_shiftl2control(params);
  remap_controll2command(params);
  remap_option2command(params);
  remap_option2shift(params);
  remap_optionr2command(params);
  remap_optionr2control(params);
  remap_optionr2fn(params);
  remap_shift2fn(params);
  remap_fn2command(params);
  remap_fn2control(params);
  remap_fn2option(params);
  remap_fn2shift(params);
  // change 'keys -> modifiers' or 'keys -> keys'
  remap_spaces_special(params);
  remap_homeposition_functionkey(params);
  remap_deleteshift2tilde(params);
  remap_qwerty2colemak(params);
  remap_return2option(params);
  remap_return2semicolon(params);
  remap_shift2escape(params);
  remap_space2shift(params);
  remap_enter2command(params);
  remap_enter2control(params);
  remap_enter2option(params);
  remap_enter2fn(params);
  remap_enter2return(params);
  remap_enter2space(params);
  remap_enter2semicolon(params);
  remap_optionr2space(params);
  remap_optionr2semicolon(params);
  remap_optionr2enter(params);
  remap_backquote2command(params);
  remap_escape2tilde(params);
  remap_escape2return(params);
  remap_escape2rightclick(params);
  remap_semicolon2return(params);
  remap_drop_funcshift(params);
  remap_tab2expose(params);
  remap_keypad2spaces(params);
  remap_hhkmode(params);
  remap_emacsmode(params);
  remap_jis_eisuu2control(params);
  remap_jis_eisuu2command(params);
  remap_jis_eisuu2option(params);
  remap_jis_eisuu2shift(params);
  remap_jis_eisuu2tab(params);
  remap_jis_kana2control(params);
  remap_jis_kana2command(params);
  remap_jis_kana2option(params);
  remap_jis_kana2shift(params);
  remap_jis_kana2return(params);
  remap_jis_kanashift2eisuu(params);
  remap_jis_unify_kana_eisuu(params);

  *(params.flags) = allFlagStatus.makeFlags(params);

  if (config.debug) {
    if (! *(params.ex_dropKey)) {
      printf("sending hid event type %d flags 0x%x key %d ", *(params.eventType), *(params.flags), *(params.key));
      printf("charCode %d charSet %d ", *(params.charCode), *(params.charSet));
      printf("origCharCode %d origCharSet %d kbdType %d\n",
             *(params.origCharCode), *(params.origCharSet), *(params.keyboardType));
    }
  }
}
