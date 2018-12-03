/* ------------------------------------------------------------
name: "b259wf"
Code generated with Faust 2.13.5 (https://faust.grame.fr)
Compilation options: -scal -ftz 0
------------------------------------------------------------ */

#pragma once

#include <algorithm>
#include <cmath>
#include <math.h>

static float faustpower2_f(float value) {
  return (value * value);

}

class b259wf {

public:

  void setLowPass(float lowPass)
  {
    if (lowPass < 0.0f)
      lowPass = 0.0f;
    else if (lowPass > 1.0f)
      lowPass = 1.0f;

    mLowPass = lowPass;
  }

  void setFold(float fold)
  {
    if (fold < 0.0f)
      fold = 0.0f;
    else if (fold  > 1.0f)
      fold = 1.0f;

    mFold = fold;
  }

  void setOffset(float offset)
  {
    if (offset < -1.0f)
      offset = -1.0f;
    else if (offset > 1.0f)
      offset = 1.0f;

    mOffset = offset;
  }

  int getNumInputs() const noexcept {
    return 1;

  }

  int getNumOutputs() const noexcept {
    return 1;
  }


  int getSampleRate() const noexcept {
    return fSamplingFreq;
  }

  void init(int samplingFreq) {
    fSamplingFreq = samplingFreq;
    fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
    fConst1 = (31.415926f / fConst0);
    fConst2 = (1.0f / (fConst1 + 1.0f));
    fConst3 = (3.14159274f / fConst0);
    fConst4 = ((0.384615391f * fConst0) + -1300.0f);
    fConst5 = (1.0f - fConst1);

    mLowPass = 0.0f;
    mFold = 0.0f;
    mOffset = 0.0f;
    instanceClear();
  }

  void compute(int count, const float* input, float* output) {
    float fSlow0 = (0.00100000005f * faustpower2_f(mLowPass));
    float fSlow1 = (0.00100000005f * mFold);
    float fSlow2 = (0.00100000005f * mOffset);
    
    for (int i = 0; (i < count); i = (i + 1)) {
      fRec2[0] = (fSlow0 + (0.999000013f * fRec2[1]));
      float fTemp0 = (1.0f / std::tan((fConst3 * ((fConst4 * fRec2[0]) + 1300.0f))));
      fRec6[0] = (fSlow1 + (0.999000013f * fRec6[1]));
      fRec7[0] = (fSlow2 + (0.999000013f * fRec7[1]));
      float fTemp1 = ((0.600000024f * (((19.0f * fRec6[0]) + 1.0f) * float(input[i]))) - (5.46000004f * (1.0f - (fRec7[0] + 1.0f))));
      fVec0[0] = fTemp1;
      float fTemp2 = std::fabs(fTemp1);
      float fTemp3 = float(((fTemp1 > 0.0f) - (fTemp1 < 0.0f)));
      float fTemp4 = ((fTemp2 > 0.600000024f) ? fTemp1 : (0.600000024f * fTemp3));
      float fTemp5 = (0.0f - (12.0f * (fTemp4 - (0.600000024f * float(((fTemp4 > 0.0f) - (fTemp4 < 0.0f)))))));
      fVec1[0] = fTemp5;
      fRec5[0] = ((0.604193091f * (fTemp5 + fVec1[1])) - (0.450063467f * fRec5[1]));
      fRec4[0] = (fRec5[0] - ((0.974320471f * fRec4[1]) + (0.301678687f * fRec4[2])));
      fRec3[0] = (((1.13799953f * fRec4[1]) + (0.568999767f * (fRec4[0] + fRec4[2]))) - ((1.24242795f * fRec3[1]) + (0.659866512f * fRec3[2])));
      float fTemp6 = ((fTemp2 > 2.99399996f) ? fTemp1 : (2.99399996f * fTemp3));
      float fTemp7 = (0.0f - (27.7770004f * (fTemp6 - (2.99399996f * float(((fTemp6 > 0.0f) - (fTemp6 < 0.0f)))))));
      fVec2[0] = fTemp7;
      fRec10[0] = ((0.273175001f * (fTemp7 + fVec2[1])) - (0.450063467f * fRec10[1]));
      fRec9[0] = (fRec10[0] - ((0.974320471f * fRec9[1]) + (0.301678687f * fRec9[2])));
      fRec8[0] = (((1.13799953f * fRec9[1]) + (0.568999767f * (fRec9[0] + fRec9[2]))) - ((1.24242795f * fRec8[1]) + (0.659866512f * fRec8[2])));
      float fTemp8 = ((fTemp2 > 5.46000004f) ? fTemp1 : (5.46000004f * fTemp3));
      float fTemp9 = (0.0f - (21.4279995f * (fTemp8 - (5.46000004f * float(((fTemp8 > 0.0f) - (fTemp8 < 0.0f)))))));
      fVec3[0] = fTemp9;
      fRec13[0] = ((0.205100909f * (fTemp9 + fVec3[1])) - (0.450063467f * fRec13[1]));
      fRec12[0] = (fRec13[0] - ((0.974320471f * fRec12[1]) + (0.301678687f * fRec12[2])));
      fRec11[0] = (((1.13799953f * fRec12[1]) + (0.568999767f * (fRec12[0] + fRec12[2]))) - ((1.24242795f * fRec11[1]) + (0.659866512f * fRec11[2])));
      float fTemp10 = ((fTemp2 > 1.79999995f) ? fTemp1 : (1.79999995f * fTemp3));
      float fTemp11 = (fTemp10 - (1.79999995f * float(((fTemp10 > 0.0f) - (fTemp10 < 0.0f)))));
      fVec4[0] = fTemp11;
      fRec16[0] = ((7.34826994f * (fTemp11 + fVec4[1])) - (0.450063467f * fRec16[1]));
      fRec15[0] = (fRec16[0] - ((0.974320471f * fRec15[1]) + (0.301678687f * fRec15[2])));
      fRec14[0] = (((1.13799953f * fRec15[1]) + (0.568999767f * (fRec15[0] + fRec15[2]))) - ((1.24242795f * fRec14[1]) + (0.659866512f * fRec14[2])));
      float fTemp12 = ((fTemp2 > 4.07999992f) ? fTemp1 : (4.07999992f * fTemp3));
      float fTemp13 = (fTemp12 - (4.07999992f * float(((fTemp12 > 0.0f) - (fTemp12 < 0.0f)))));
      fVec5[0] = fTemp13;
      fRec19[0] = ((7.04814386f * (fTemp13 + fVec5[1])) - (0.450063467f * fRec19[1]));
      fRec18[0] = (fRec19[0] - ((0.974320471f * fRec18[1]) + (0.301678687f * fRec18[2])));
      fRec17[0] = (((1.13799953f * fRec18[1]) + (0.568999767f * (fRec18[0] + fRec18[2]))) - ((1.24242795f * fRec17[1]) + (0.659866512f * fRec17[2])));
      fRec22[0] = ((3.62515855f * (fTemp1 + fVec0[1])) - (0.450063467f * fRec22[1]));
      fRec21[0] = (fRec22[0] - ((0.974320471f * fRec21[1]) + (0.301678687f * fRec21[2])));
      fRec20[0] = (((1.13799953f * fRec21[1]) + (0.568999767f * (fRec21[0] + fRec21[2]))) - ((1.24242795f * fRec20[1]) + (0.659866512f * fRec20[2])));
      float fTemp14 = ((1.4511472f * (((((fRec3[1] + fRec8[1]) + fRec11[1]) + fRec14[1]) + fRec17[1]) + fRec20[1])) + (0.725573599f * ((((((fRec3[0] + fRec3[2]) + (fRec8[0] + fRec8[2])) + (fRec11[0] + fRec11[2])) + (fRec14[0] + fRec14[2])) + (fRec17[0] + fRec17[2])) + (fRec20[0] + fRec20[2]))));
      fVec6[0] = fTemp14;
      fRec1[0] = (0.0f - (((fRec1[1] * (1.0f - fTemp0)) - (fTemp14 + fVec6[1])) / (fTemp0 + 1.0f)));
      float fTemp15 = std::max<float>(-1.0f, std::min<float>(1.0f, (0.166666672f * fRec1[0])));
      float fTemp16 = (fTemp15 * (1.0f - (0.333333343f * faustpower2_f(fTemp15))));
      fVec7[0] = fTemp16;
      fRec0[0] = (fConst2 * ((fTemp16 - fVec7[1]) + (fConst5 * fRec0[1])));
      output[i] = float(fRec0[0]);
      fRec2[1] = fRec2[0];
      fRec6[1] = fRec6[0];
      fRec7[1] = fRec7[0];
      fVec0[1] = fVec0[0];
      fVec1[1] = fVec1[0];
      fRec5[1] = fRec5[0];
      fRec4[2] = fRec4[1];
      fRec4[1] = fRec4[0];
      fRec3[2] = fRec3[1];
      fRec3[1] = fRec3[0];
      fVec2[1] = fVec2[0];
      fRec10[1] = fRec10[0];
      fRec9[2] = fRec9[1];
      fRec9[1] = fRec9[0];
      fRec8[2] = fRec8[1];
      fRec8[1] = fRec8[0];
      fVec3[1] = fVec3[0];
      fRec13[1] = fRec13[0];
      fRec12[2] = fRec12[1];
      fRec12[1] = fRec12[0];
      fRec11[2] = fRec11[1];
      fRec11[1] = fRec11[0];
      fVec4[1] = fVec4[0];
      fRec16[1] = fRec16[0];
      fRec15[2] = fRec15[1];
      fRec15[1] = fRec15[0];
      fRec14[2] = fRec14[1];
      fRec14[1] = fRec14[0];
      fVec5[1] = fVec5[0];
      fRec19[1] = fRec19[0];
      fRec18[2] = fRec18[1];
      fRec18[1] = fRec18[0];
      fRec17[2] = fRec17[1];
      fRec17[1] = fRec17[0];
      fRec22[1] = fRec22[0];
      fRec21[2] = fRec21[1];
      fRec21[1] = fRec21[0];
      fRec20[2] = fRec20[1];
      fRec20[1] = fRec20[0];
      fVec6[1] = fVec6[0];
      fRec1[1] = fRec1[0];
      fVec7[1] = fVec7[0];
      fRec0[1] = fRec0[0];

    }

  }


private:

  void instanceClear() {
    for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
      fRec2[l0] = 0.0f;

    }
    for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
      fRec6[l1] = 0.0f;

    }
    for (int l2 = 0; (l2 < 2); l2 = (l2 + 1)) {
      fRec7[l2] = 0.0f;

    }
    for (int l3 = 0; (l3 < 2); l3 = (l3 + 1)) {
      fVec0[l3] = 0.0f;

    }
    for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
      fVec1[l4] = 0.0f;

    }
    for (int l5 = 0; (l5 < 2); l5 = (l5 + 1)) {
      fRec5[l5] = 0.0f;

    }
    for (int l6 = 0; (l6 < 3); l6 = (l6 + 1)) {
      fRec4[l6] = 0.0f;

    }
    for (int l7 = 0; (l7 < 3); l7 = (l7 + 1)) {
      fRec3[l7] = 0.0f;

    }
    for (int l8 = 0; (l8 < 2); l8 = (l8 + 1)) {
      fVec2[l8] = 0.0f;

    }
    for (int l9 = 0; (l9 < 2); l9 = (l9 + 1)) {
      fRec10[l9] = 0.0f;

    }
    for (int l10 = 0; (l10 < 3); l10 = (l10 + 1)) {
      fRec9[l10] = 0.0f;

    }
    for (int l11 = 0; (l11 < 3); l11 = (l11 + 1)) {
      fRec8[l11] = 0.0f;

    }
    for (int l12 = 0; (l12 < 2); l12 = (l12 + 1)) {
      fVec3[l12] = 0.0f;

    }
    for (int l13 = 0; (l13 < 2); l13 = (l13 + 1)) {
      fRec13[l13] = 0.0f;

    }
    for (int l14 = 0; (l14 < 3); l14 = (l14 + 1)) {
      fRec12[l14] = 0.0f;

    }
    for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
      fRec11[l15] = 0.0f;

    }
    for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
      fVec4[l16] = 0.0f;

    }
    for (int l17 = 0; (l17 < 2); l17 = (l17 + 1)) {
      fRec16[l17] = 0.0f;

    }
    for (int l18 = 0; (l18 < 3); l18 = (l18 + 1)) {
      fRec15[l18] = 0.0f;

    }
    for (int l19 = 0; (l19 < 3); l19 = (l19 + 1)) {
      fRec14[l19] = 0.0f;

    }
    for (int l20 = 0; (l20 < 2); l20 = (l20 + 1)) {
      fVec5[l20] = 0.0f;

    }
    for (int l21 = 0; (l21 < 2); l21 = (l21 + 1)) {
      fRec19[l21] = 0.0f;

    }
    for (int l22 = 0; (l22 < 3); l22 = (l22 + 1)) {
      fRec18[l22] = 0.0f;

    }
    for (int l23 = 0; (l23 < 3); l23 = (l23 + 1)) {
      fRec17[l23] = 0.0f;

    }
    for (int l24 = 0; (l24 < 2); l24 = (l24 + 1)) {
      fRec22[l24] = 0.0f;

    }
    for (int l25 = 0; (l25 < 3); l25 = (l25 + 1)) {
      fRec21[l25] = 0.0f;

    }
    for (int l26 = 0; (l26 < 3); l26 = (l26 + 1)) {
      fRec20[l26] = 0.0f;

    }
    for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
      fVec6[l27] = 0.0f;

    }
    for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
      fRec1[l28] = 0.0f;

    }
    for (int l29 = 0; (l29 < 2); l29 = (l29 + 1)) {
      fVec7[l29] = 0.0f;

    }
    for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
      fRec0[l30] = 0.0f;

    }
  }


  float mLowPass{ 0.0f };
  float mFold{ 0.0f };
  float mOffset{ 0.0f };

  int fSamplingFreq;
  float fConst0;
  float fConst1;
  float fConst2;
  float fConst3;
  float fConst4;
  float fRec2[2];
  float fRec6[2];
  float fRec7[2];
  float fVec0[2];
  float fVec1[2];
  float fRec5[2];
  float fRec4[3];
  float fRec3[3];
  float fVec2[2];
  float fRec10[2];
  float fRec9[3];
  float fRec8[3];
  float fVec3[2];
  float fRec13[2];
  float fRec12[3];
  float fRec11[3];
  float fVec4[2];
  float fRec16[2];
  float fRec15[3];
  float fRec14[3];
  float fVec5[2];
  float fRec19[2];
  float fRec18[3];
  float fRec17[3];
  float fRec22[2];
  float fRec21[3];
  float fRec20[3];
  float fVec6[2];
  float fRec1[2];
  float fVec7[2];
  float fConst5;
  float fRec0[2];


};


