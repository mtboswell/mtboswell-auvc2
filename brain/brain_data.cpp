/*
 * File: brain_data.cpp
 *
 * Real-Time Workshop code generated for Simulink model brain.
 *
 * Model version                        : 1.254
 * Real-Time Workshop file version      : 7.3  (R2009a)  15-Jan-2009
 * Real-Time Workshop file generated on : Fri Apr  9 18:37:37 2010
 * TLC version                          : 7.3 (Jan 16 2009)
 * C/C++ source code generated on       : Fri Apr  9 18:37:37 2010
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: AMD->K5/K6/Athlon
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "brain.h"
#include "brain_private.h"

/* Block parameters (auto storage) */
Parameters_brain brain_P = {
  0.8,
  0.05,
  0.65,
  0.9,
  0.0,
  0.7,
  0.5,
  0.001,
  0.001,
  0.5,
  0.001,
  0.001,
  0.8,
  0.0,
  0.0,
  75.0,
  20.0,
  0.01,
  0.0,
  0.3,
  0.9,
  0.25,
  0.4,
  15.0,
  19200U,
  100U
};

/* Constant parameters (auto storage) */
const ConstParam_brain brain_ConstP = {
  /* Computed Parameter: SINE_TABLE_RTP
   * Referenced by blocks:
   * '<S48>/Hough Transform'
   * '<S49>/Hough Transform'
   * '<S60>/Hough Transform'
   */
  { -1.0, -9.9984769515639127E-01, -9.9939082701909576E-01,
    -9.9862953475457383E-01, -9.9756405025982420E-01, -9.9619469809174555E-01,
    -9.9452189536827329E-01, -9.9254615164132198E-01, -9.9026806874157036E-01,
    -9.8768834059513777E-01, -9.8480775301220802E-01, -9.8162718344766398E-01,
    -9.7814760073380558E-01, -9.7437006478523525E-01, -9.7029572627599647E-01,
    -9.6592582628906831E-01, -9.6126169593831889E-01, -9.5630475596303544E-01,
    -9.5105651629515353E-01, -9.4551857559931674E-01, -9.3969262078590832E-01,
    -9.3358042649720174E-01, -9.2718385456678742E-01, -9.2050485345244037E-01,
    -9.1354545764260087E-01, -9.0630778703664994E-01, -8.9879404629916704E-01,
    -8.9100652418836779E-01, -8.8294759285892688E-01, -8.7461970713939574E-01,
    -8.6602540378443860E-01, -8.5716730070211233E-01, -8.4804809615642596E-01,
    -8.3867056794542405E-01, -8.2903757255504174E-01, -8.1915204428899180E-01,
    -8.0901699437494745E-01, -7.9863551004729283E-01, -7.8801075360672201E-01,
    -7.7714596145697090E-01, -7.6604444311897801E-01, -7.5470958022277201E-01,
    -7.4314482547739424E-01, -7.3135370161917046E-01, -7.1933980033865108E-01,
    -7.0710678118654746E-01, -6.9465837045899725E-01, -6.8199836006249848E-01,
    -6.6913060635885824E-01, -6.5605902899050728E-01, -6.4278760968653925E-01,
    -6.2932039104983739E-01, -6.1566147532565829E-01, -6.0181502315204827E-01,
    -5.8778525229247314E-01, -5.7357643635104605E-01, -5.5919290347074690E-01,
    -5.4463903501502708E-01, -5.2991926423320490E-01, -5.1503807491005416E-01,
    -4.9999999999999994E-01, -4.8480962024633706E-01, -4.6947156278589081E-01,
    -4.5399049973954675E-01, -4.3837114678907740E-01, -4.2261826174069944E-01,
    -4.0673664307580021E-01, -3.9073112848927377E-01, -3.7460659341591201E-01,
    -3.5836794954530027E-01, -3.4202014332566871E-01, -3.2556815445715670E-01,
    -3.0901699437494740E-01, -2.9237170472273677E-01, -2.7563735581699916E-01,
    -2.5881904510252074E-01, -2.4192189559966773E-01, -2.2495105434386500E-01,
    -2.0791169081775934E-01, -1.9080899537654480E-01, -1.7364817766693033E-01,
    -1.5643446504023087E-01, -1.3917310096006544E-01, -1.2186934340514748E-01,
    -1.0452846326765347E-01, -8.7155742747658166E-02, -6.9756473744125302E-02,
    -5.2335956242943835E-02, -3.4899496702500969E-02, -1.7452406437283512E-02,
    0.0 },

  /* Computed Parameter: FIRSTRHO_RTP
   * Referenced by blocks:
   * '<S48>/Hough Transform'
   * '<S49>/Hough Transform'
   */
  -143.0,

  /* Computed Parameter: FIRSTRHO_RTP
   * '<S60>/Hough Transform'
   */
  -199.0,

  /* Computed Parameter: Yweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  { 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F },

  /* Computed Parameter: Xweights
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  { 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F, 0.21875F,
    0.21875F, 0.21875F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F, 0.15625F,
    0.15625F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F, 0.09375F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F,
    0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F, 0.03125F },

  /* Computed Parameter: Yindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  { 0, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74,
    78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118, 122, 126, 130, 134, 138,
    142, 146, 150, 154, 158, 162, 166, 170, 174, 178, 182, 186, 190, 194, 198,
    202, 206, 210, 214, 218, 222, 226, 230, 234, 238, 242, 246, 250, 254, 258,
    262, 266, 270, 274, 278, 282, 286, 290, 294, 298, 302, 306, 310, 314, 318,
    322, 326, 330, 334, 338, 342, 346, 350, 354, 358, 362, 366, 370, 374, 378,
    382, 386, 390, 394, 398, 402, 406, 410, 414, 418, 422, 426, 430, 434, 438,
    442, 446, 450, 454, 458, 462, 466, 470, 474, 0, 3, 7, 11, 15, 19, 23, 27, 31,
    35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107,
    111, 115, 119, 123, 127, 131, 135, 139, 143, 147, 151, 155, 159, 163, 167,
    171, 175, 179, 183, 187, 191, 195, 199, 203, 207, 211, 215, 219, 223, 227,
    231, 235, 239, 243, 247, 251, 255, 259, 263, 267, 271, 275, 279, 283, 287,
    291, 295, 299, 303, 307, 311, 315, 319, 323, 327, 331, 335, 339, 343, 347,
    351, 355, 359, 363, 367, 371, 375, 379, 383, 387, 391, 395, 399, 403, 407,
    411, 415, 419, 423, 427, 431, 435, 439, 443, 447, 451, 455, 459, 463, 467,
    471, 475, 0, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64,
    68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112, 116, 120, 124, 128, 132,
    136, 140, 144, 148, 152, 156, 160, 164, 168, 172, 176, 180, 184, 188, 192,
    196, 200, 204, 208, 212, 216, 220, 224, 228, 232, 236, 240, 244, 248, 252,
    256, 260, 264, 268, 272, 276, 280, 284, 288, 292, 296, 300, 304, 308, 312,
    316, 320, 324, 328, 332, 336, 340, 344, 348, 352, 356, 360, 364, 368, 372,
    376, 380, 384, 388, 392, 396, 400, 404, 408, 412, 416, 420, 424, 428, 432,
    436, 440, 444, 448, 452, 456, 460, 464, 468, 472, 476, 1, 5, 9, 13, 17, 21,
    25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93, 97,
    101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141, 145, 149, 153, 157,
    161, 165, 169, 173, 177, 181, 185, 189, 193, 197, 201, 205, 209, 213, 217,
    221, 225, 229, 233, 237, 241, 245, 249, 253, 257, 261, 265, 269, 273, 277,
    281, 285, 289, 293, 297, 301, 305, 309, 313, 317, 321, 325, 329, 333, 337,
    341, 345, 349, 353, 357, 361, 365, 369, 373, 377, 381, 385, 389, 393, 397,
    401, 405, 409, 413, 417, 421, 425, 429, 433, 437, 441, 445, 449, 453, 457,
    461, 465, 469, 473, 477, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50,
    54, 58, 62, 66, 70, 74, 78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118, 122,
    126, 130, 134, 138, 142, 146, 150, 154, 158, 162, 166, 170, 174, 178, 182,
    186, 190, 194, 198, 202, 206, 210, 214, 218, 222, 226, 230, 234, 238, 242,
    246, 250, 254, 258, 262, 266, 270, 274, 278, 282, 286, 290, 294, 298, 302,
    306, 310, 314, 318, 322, 326, 330, 334, 338, 342, 346, 350, 354, 358, 362,
    366, 370, 374, 378, 382, 386, 390, 394, 398, 402, 406, 410, 414, 418, 422,
    426, 430, 434, 438, 442, 446, 450, 454, 458, 462, 466, 470, 474, 478, 3, 7,
    11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55, 59, 63, 67, 71, 75, 79, 83,
    87, 91, 95, 99, 103, 107, 111, 115, 119, 123, 127, 131, 135, 139, 143, 147,
    151, 155, 159, 163, 167, 171, 175, 179, 183, 187, 191, 195, 199, 203, 207,
    211, 215, 219, 223, 227, 231, 235, 239, 243, 247, 251, 255, 259, 263, 267,
    271, 275, 279, 283, 287, 291, 295, 299, 303, 307, 311, 315, 319, 323, 327,
    331, 335, 339, 343, 347, 351, 355, 359, 363, 367, 371, 375, 379, 383, 387,
    391, 395, 399, 403, 407, 411, 415, 419, 423, 427, 431, 435, 439, 443, 447,
    451, 455, 459, 463, 467, 471, 475, 479, 4, 8, 12, 16, 20, 24, 28, 32, 36, 40,
    44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108, 112,
    116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168, 172,
    176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228, 232,
    236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276, 280, 284, 288, 292,
    296, 300, 304, 308, 312, 316, 320, 324, 328, 332, 336, 340, 344, 348, 352,
    356, 360, 364, 368, 372, 376, 380, 384, 388, 392, 396, 400, 404, 408, 412,
    416, 420, 424, 428, 432, 436, 440, 444, 448, 452, 456, 460, 464, 468, 472,
    476, 479, 5, 9, 13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69,
    73, 77, 81, 85, 89, 93, 97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137,
    141, 145, 149, 153, 157, 161, 165, 169, 173, 177, 181, 185, 189, 193, 197,
    201, 205, 209, 213, 217, 221, 225, 229, 233, 237, 241, 245, 249, 253, 257,
    261, 265, 269, 273, 277, 281, 285, 289, 293, 297, 301, 305, 309, 313, 317,
    321, 325, 329, 333, 337, 341, 345, 349, 353, 357, 361, 365, 369, 373, 377,
    381, 385, 389, 393, 397, 401, 405, 409, 413, 417, 421, 425, 429, 433, 437,
    441, 445, 449, 453, 457, 461, 465, 469, 473, 477, 479 },

  /* Computed Parameter: Xindex
   * Referenced by blocks:
   * '<S6>/Resize'
   * '<S6>/Resize1'
   * '<S6>/Resize2'
   */
  { 0, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70, 74,
    78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118, 122, 126, 130, 134, 138,
    142, 146, 150, 154, 158, 162, 166, 170, 174, 178, 182, 186, 190, 194, 198,
    202, 206, 210, 214, 218, 222, 226, 230, 234, 238, 242, 246, 250, 254, 258,
    262, 266, 270, 274, 278, 282, 286, 290, 294, 298, 302, 306, 310, 314, 318,
    322, 326, 330, 334, 338, 342, 346, 350, 354, 358, 362, 366, 370, 374, 378,
    382, 386, 390, 394, 398, 402, 406, 410, 414, 418, 422, 426, 430, 434, 438,
    442, 446, 450, 454, 458, 462, 466, 470, 474, 478, 482, 486, 490, 494, 498,
    502, 506, 510, 514, 518, 522, 526, 530, 534, 538, 542, 546, 550, 554, 558,
    562, 566, 570, 574, 578, 582, 586, 590, 594, 598, 602, 606, 610, 614, 618,
    622, 626, 630, 634, 0, 3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51, 55,
    59, 63, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107, 111, 115, 119, 123,
    127, 131, 135, 139, 143, 147, 151, 155, 159, 163, 167, 171, 175, 179, 183,
    187, 191, 195, 199, 203, 207, 211, 215, 219, 223, 227, 231, 235, 239, 243,
    247, 251, 255, 259, 263, 267, 271, 275, 279, 283, 287, 291, 295, 299, 303,
    307, 311, 315, 319, 323, 327, 331, 335, 339, 343, 347, 351, 355, 359, 363,
    367, 371, 375, 379, 383, 387, 391, 395, 399, 403, 407, 411, 415, 419, 423,
    427, 431, 435, 439, 443, 447, 451, 455, 459, 463, 467, 471, 475, 479, 483,
    487, 491, 495, 499, 503, 507, 511, 515, 519, 523, 527, 531, 535, 539, 543,
    547, 551, 555, 559, 563, 567, 571, 575, 579, 583, 587, 591, 595, 599, 603,
    607, 611, 615, 619, 623, 627, 631, 635, 0, 4, 8, 12, 16, 20, 24, 28, 32, 36,
    40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108,
    112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164, 168,
    172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224, 228,
    232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276, 280, 284, 288,
    292, 296, 300, 304, 308, 312, 316, 320, 324, 328, 332, 336, 340, 344, 348,
    352, 356, 360, 364, 368, 372, 376, 380, 384, 388, 392, 396, 400, 404, 408,
    412, 416, 420, 424, 428, 432, 436, 440, 444, 448, 452, 456, 460, 464, 468,
    472, 476, 480, 484, 488, 492, 496, 500, 504, 508, 512, 516, 520, 524, 528,
    532, 536, 540, 544, 548, 552, 556, 560, 564, 568, 572, 576, 580, 584, 588,
    592, 596, 600, 604, 608, 612, 616, 620, 624, 628, 632, 636, 1, 5, 9, 13, 17,
    21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85, 89, 93,
    97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141, 145, 149, 153,
    157, 161, 165, 169, 173, 177, 181, 185, 189, 193, 197, 201, 205, 209, 213,
    217, 221, 225, 229, 233, 237, 241, 245, 249, 253, 257, 261, 265, 269, 273,
    277, 281, 285, 289, 293, 297, 301, 305, 309, 313, 317, 321, 325, 329, 333,
    337, 341, 345, 349, 353, 357, 361, 365, 369, 373, 377, 381, 385, 389, 393,
    397, 401, 405, 409, 413, 417, 421, 425, 429, 433, 437, 441, 445, 449, 453,
    457, 461, 465, 469, 473, 477, 481, 485, 489, 493, 497, 501, 505, 509, 513,
    517, 521, 525, 529, 533, 537, 541, 545, 549, 553, 557, 561, 565, 569, 573,
    577, 581, 585, 589, 593, 597, 601, 605, 609, 613, 617, 621, 625, 629, 633,
    637, 2, 6, 10, 14, 18, 22, 26, 30, 34, 38, 42, 46, 50, 54, 58, 62, 66, 70,
    74, 78, 82, 86, 90, 94, 98, 102, 106, 110, 114, 118, 122, 126, 130, 134, 138,
    142, 146, 150, 154, 158, 162, 166, 170, 174, 178, 182, 186, 190, 194, 198,
    202, 206, 210, 214, 218, 222, 226, 230, 234, 238, 242, 246, 250, 254, 258,
    262, 266, 270, 274, 278, 282, 286, 290, 294, 298, 302, 306, 310, 314, 318,
    322, 326, 330, 334, 338, 342, 346, 350, 354, 358, 362, 366, 370, 374, 378,
    382, 386, 390, 394, 398, 402, 406, 410, 414, 418, 422, 426, 430, 434, 438,
    442, 446, 450, 454, 458, 462, 466, 470, 474, 478, 482, 486, 490, 494, 498,
    502, 506, 510, 514, 518, 522, 526, 530, 534, 538, 542, 546, 550, 554, 558,
    562, 566, 570, 574, 578, 582, 586, 590, 594, 598, 602, 606, 610, 614, 618,
    622, 626, 630, 634, 638, 3, 7, 11, 15, 19, 23, 27, 31, 35, 39, 43, 47, 51,
    55, 59, 63, 67, 71, 75, 79, 83, 87, 91, 95, 99, 103, 107, 111, 115, 119, 123,
    127, 131, 135, 139, 143, 147, 151, 155, 159, 163, 167, 171, 175, 179, 183,
    187, 191, 195, 199, 203, 207, 211, 215, 219, 223, 227, 231, 235, 239, 243,
    247, 251, 255, 259, 263, 267, 271, 275, 279, 283, 287, 291, 295, 299, 303,
    307, 311, 315, 319, 323, 327, 331, 335, 339, 343, 347, 351, 355, 359, 363,
    367, 371, 375, 379, 383, 387, 391, 395, 399, 403, 407, 411, 415, 419, 423,
    427, 431, 435, 439, 443, 447, 451, 455, 459, 463, 467, 471, 475, 479, 483,
    487, 491, 495, 499, 503, 507, 511, 515, 519, 523, 527, 531, 535, 539, 543,
    547, 551, 555, 559, 563, 567, 571, 575, 579, 583, 587, 591, 595, 599, 603,
    607, 611, 615, 619, 623, 627, 631, 635, 639, 4, 8, 12, 16, 20, 24, 28, 32,
    36, 40, 44, 48, 52, 56, 60, 64, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104,
    108, 112, 116, 120, 124, 128, 132, 136, 140, 144, 148, 152, 156, 160, 164,
    168, 172, 176, 180, 184, 188, 192, 196, 200, 204, 208, 212, 216, 220, 224,
    228, 232, 236, 240, 244, 248, 252, 256, 260, 264, 268, 272, 276, 280, 284,
    288, 292, 296, 300, 304, 308, 312, 316, 320, 324, 328, 332, 336, 340, 344,
    348, 352, 356, 360, 364, 368, 372, 376, 380, 384, 388, 392, 396, 400, 404,
    408, 412, 416, 420, 424, 428, 432, 436, 440, 444, 448, 452, 456, 460, 464,
    468, 472, 476, 480, 484, 488, 492, 496, 500, 504, 508, 512, 516, 520, 524,
    528, 532, 536, 540, 544, 548, 552, 556, 560, 564, 568, 572, 576, 580, 584,
    588, 592, 596, 600, 604, 608, 612, 616, 620, 624, 628, 632, 636, 639, 5, 9,
    13, 17, 21, 25, 29, 33, 37, 41, 45, 49, 53, 57, 61, 65, 69, 73, 77, 81, 85,
    89, 93, 97, 101, 105, 109, 113, 117, 121, 125, 129, 133, 137, 141, 145, 149,
    153, 157, 161, 165, 169, 173, 177, 181, 185, 189, 193, 197, 201, 205, 209,
    213, 217, 221, 225, 229, 233, 237, 241, 245, 249, 253, 257, 261, 265, 269,
    273, 277, 281, 285, 289, 293, 297, 301, 305, 309, 313, 317, 321, 325, 329,
    333, 337, 341, 345, 349, 353, 357, 361, 365, 369, 373, 377, 381, 385, 389,
    393, 397, 401, 405, 409, 413, 417, 421, 425, 429, 433, 437, 441, 445, 449,
    453, 457, 461, 465, 469, 473, 477, 481, 485, 489, 493, 497, 501, 505, 509,
    513, 517, 521, 525, 529, 533, 537, 541, 545, 549, 553, 557, 561, 565, 569,
    573, 577, 581, 585, 589, 593, 597, 601, 605, 609, 613, 617, 621, 625, 629,
    633, 637, 639 },

  /* Computed Parameter: WALKER_RTP
   * Referenced by blocks:
   * '<S7>/Buoy Blob Analysis'
   * '<S33>/Blob Analysis'
   * '<S63>/Blob Analysis'
   */
  { -1, 121, 122, 123, 1, -121, -122, -123 }
};

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
