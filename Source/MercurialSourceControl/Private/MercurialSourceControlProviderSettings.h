//-------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2014 Vadim Macagon
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------

#pragma once

namespace MercurialSourceControl {

/** Provides access to settings stored in SourceControlSettings.ini. */
class FProviderSettings
{
public:
	const FString& GetMercurialPath() const;
	void SetMercurialPath(const FString& InMercurialPath);
	bool IsLargefilesIntegrationEnabled() const;
	void EnableLargefilesIntegration(bool bEnable);
	void GetLargeAssetTypes(TArray<FString>& OutLargeAssetTypes) const;
	void SetLargeAssetTypes(const TArray<FString>& InLargeAssetTypes);

	void Save();
	void Load();

private:
	mutable FCriticalSection CriticalSection;

	/** Full path to Mercurial executable. */
	FString MercurialPath;

	bool bEnableLargefilesIntegration;

	/** 
		Class names of all the asset types that should be flagged as "large" by the Largefiles
		extension.
	*/
	TArray<FString> LargeAssetTypes;
};

} // namespace MercurialSourceControl
