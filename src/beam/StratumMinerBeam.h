/*
 The MIT License (MIT)

 Copyright (c) [2016] [BTC.COM]

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
#pragma once

#include "StratumMiner.h"
#include "StratumServerBeam.h"

class StratumMinerBeam : public StratumMinerBase<StratumTraitsBeam> {
public:
  StratumMinerBeam(StratumSessionBeam &session,
                  const DiffController &diffController,
                  const std::string &clientAgent,
                  const std::string &workerName,
                  int64_t workerId);

  void handleRequest(const std::string &idStr,
                     const std::string &method,
                     const JsonNode &jparams,
                     const JsonNode &jroot) override;

private:
  void handleRequest_Submit(const string &idStr, const JsonNode &jroot);
  void responseError(const string &idStr, int code);
  void responseTrue(const string &idStr);
  void responseFalse(const string &idStr, int errCode);
};
