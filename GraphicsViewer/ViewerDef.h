#pragma once

class QMouseEvent;
class pAbstractItem;
class pGraphicsViewerImpl;

using fGetItem = pAbstractItem * (*)(void);
using MouseInterAct = void(*)(QMouseEvent *, pGraphicsViewerImpl *);
