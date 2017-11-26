/*
 * Copyright (c) 2016, Jonathan Schleifer <js@heap.zone>
 *
 * https://heap.zone/git/scrypt-pwgen.git
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice is present in all copies.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import <ObjFW/ObjFW.h>

@interface SiteStorage: OFObject
{
	OFString *_path;
	OFMutableDictionary<OFString *, OFDictionary<OFNumber *, id> *>
	    *_storage;
	OFArray *_sites;
}

- (OFArray<OFString *> *)sitesWithFilter: (OFString *)filter;
- (bool)hasSite: (OFString *)name;
- (size_t)lengthForSite: (OFString *)name;
- (bool)isSiteLegacy: (OFString *)name;
- (OFString *)keyFileForSite: (OFString *)name;
- (void)setSite: (OFString *)site
	 length: (size_t)length
	 legacy: (bool)legacy
	keyFile: (OFString *)keyFile;
- (void)removeSite: (OFString *)name;
@end
