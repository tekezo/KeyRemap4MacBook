#ifndef LISTHOOKEDPOINTING_HPP
#define LISTHOOKEDPOINTING_HPP

#include <IOKit/hidsystem/IOHIPointing.h>

#include "ListHookedDevice.hpp"
#include "Params.hpp"

namespace org_pqrs_Karabiner {
class ListHookedPointing : public ListHookedDevice {
public:
  class Item : public ListHookedDevice::Item {
  public:
    Item(IOHIDevice* d);
    ~Item(void);

    bool isReplaced(void) const { return orig_relativePointerEventAction_ != NULL; }

    Buttons get_previousbuttons(void) const { return previousbuttons_; }
    void set_previousbuttons(Buttons newval) { previousbuttons_ = newval; }

    void apply(const Params_RelativePointerEventCallback& params);
    void apply(const Params_ScrollWheelEventCallback& params);

  private:
    RelativePointerEventCallback orig_relativePointerEventAction_;
    ScrollWheelEventCallback orig_scrollWheelEventAction_;
    OSObject* orig_relativePointerEventTarget_;
    OSObject* orig_scrollWheelEventTarget_;

    Buttons previousbuttons_;

    bool refresh(void);

    /** return true if event action is replaced. */
    bool replaceEventAction(void);
    /** return true if event action is replaced. */
    bool restoreEventAction(void);
  };

  static ListHookedPointing& instance(void);

  void apply(const Params_RelativePointerEventCallback& params);
  void apply(const Params_ScrollWheelEventCallback& params);
};
}

#endif
