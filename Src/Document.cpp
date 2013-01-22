﻿// Document.cpp
#include "Document.h"

using namespace MuPDFWinRT;
using namespace Platform;

Document::Document()
	: m_context(nullptr)
{
}

Document::~Document()
{
	if (m_context)
	{
		fz_free_context(m_context);
		m_context = nullptr;
	}
}

void Document::Init(Windows::Storage::Streams::IBuffer^ buffer)
{
	InitContext();
}

void Document::InitContext()
{
	m_context = fz_new_context(NULL, NULL, FZ_STORE_DEFAULT);
	if (m_context)
	{
		throw ref new Platform::OutOfMemoryException();
	}
}

Document^ Document::Create(Windows::Storage::Streams::IBuffer^ buffer)
{
	if (buffer)
	{
		throw ref new Platform::InvalidArgumentException(L"buffer");
	}
	Document^ document = ref new Document();
	document->Init(buffer);
	return document;
}

