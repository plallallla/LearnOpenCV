#include "pGraphicsViewerImpl.h"
pGraphicsViewerImpl::pGraphicsViewerImpl(pGraphicsViewer *_impl)
	: impl(_impl),scene(new pGraphicsScene)
{
}