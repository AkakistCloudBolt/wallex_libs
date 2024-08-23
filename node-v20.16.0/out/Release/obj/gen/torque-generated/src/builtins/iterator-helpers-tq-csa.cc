#include "src/ast/ast.h"
#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-object-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/debug/debug-wasm-objects.h"
#include "src/heap/factory-inl.h"
#include "src/ic/binary-op-assembler.h"
#include "src/ic/handler-configuration-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/call-site-info.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/intl-objects.h"
#include "src/objects/js-atomics-synchronization.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-duration-format.h"
#include "src/objects/js-function.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-iterator-helpers.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-raw-json.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-segments.h"
#include "src/objects/js-shadow-realm.h"
#include "src/objects/js-shared-array.h"
#include "src/objects/js-struct.h"
#include "src/objects/js-temporal-objects.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/swiss-hash-table-helpers.h"
#include "src/objects/swiss-name-dictionary.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/objects/torque-defined-classes.h"
#include "src/objects/turbofan-types.h"
#include "src/objects/turboshaft-types.h"
#include "src/torque/runtime-support.h"
// Required Builtins:
#include "torque-generated/src/builtins/iterator-helpers-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/iterator-helpers-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/js-iterator-helpers-tq-csa.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=19&c=1
TorqueStructIteratorRecord GetIteratorDirect_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<String> tmp0;
  TNode<Object> tmp1;
  TNode<JSReceiver> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kNextString_0(state_);
    tmp1 = CodeStubAssembler(state_).GetProperty(TNode<Context>{p_context}, TNode<Object>{p_obj}, TNode<Object>{tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block4);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kCalledNonCallable, "next");
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TorqueStructIteratorRecord{TNode<JSReceiver>{p_obj}, TNode<Object>{tmp2}};
}

TF_BUILTIN(IteratorHelperPrototypeNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSIteratorMapHelper> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSIteratorMapHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<JSIteratorFilterHelper> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorFilterHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{ca_.UncheckedCast<Object>(parameter1)}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  TNode<Object> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kIteratorMapHelperNext), parameter0, tmp0);
    CodeStubAssembler(state_).Return(tmp4);
  }

  TNode<JSIteratorTakeHelper> tmp5;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = Cast_JSIteratorTakeHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{ca_.UncheckedCast<Object>(parameter1)}, &label6);
    ca_.Goto(&block11);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block12);
    }
  }

  TNode<Object> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp7 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kIteratorFilterHelperNext), parameter0, tmp2);
    CodeStubAssembler(state_).Return(tmp7);
  }

  TNode<JSIteratorDropHelper> tmp8;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = Cast_JSIteratorDropHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{ca_.UncheckedCast<Object>(parameter1)}, &label9);
    ca_.Goto(&block15);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block16);
    }
  }

  TNode<Object> tmp10;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp10 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kIteratorTakeHelperNext), parameter0, tmp5);
    CodeStubAssembler(state_).Return(tmp10);
  }

  TNode<Object> tmp11;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp11 = FromConstexpr_Object_constexpr_string_0(state_, "Iterator Helper.prototype.next");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp11}, TNode<Object>{parameter1});
  }

  TNode<Object> tmp12;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp12 = ca_.CallStub<Object>(Builtins::CallableFor(ca_.isolate(), Builtin::kIteratorDropHelperNext), parameter0, tmp8);
    CodeStubAssembler(state_).Return(tmp12);
  }
}

TF_BUILTIN(IteratorHelperPrototypeReturn, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSIteratorHelper> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSIteratorHelper_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  TNode<Object> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_Object_constexpr_string_0(state_, "Iterator Helper.prototype.return");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp2}, TNode<Object>{parameter1});
  }

  TNode<IntPtrT> tmp3;
  TNode<JSReceiver> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Object> tmp7;
  TNode<Oddball> tmp8;
  TNode<Oddball> tmp9;
  TNode<JSObject> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp4 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp0, tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp5});
    tmp7 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp0, tmp6});
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp7}});
    tmp8 = Undefined_0(state_);
    tmp9 = True_0(state_);
    tmp10 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp8}, TNode<Oddball>{tmp9});
    CodeStubAssembler(state_).Return(tmp10);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=91&c=1
TNode<JSIteratorMapHelper> NewJSIteratorMapHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_mapper) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Number> tmp18;
  TNode<JSIteratorMapHelper> tmp19;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_MAP_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 56);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp15}, p_underlying.next);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp16}, p_mapper);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp18 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp17}, tmp18);
    tmp19 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorMapHelper>{tmp19};
}

TF_BUILTIN(IteratorPrototypeMap, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kMapper);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.map");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledNonCallable, "Iterator.prototype.map");
  }

  TNode<JSReceiver> tmp4;
  TNode<Object> tmp5;
  TNode<JSIteratorMapHelper> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp4, tmp5) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp6 = NewJSIteratorMapHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, TNode<JSReceiver>{tmp2});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

TF_BUILTIN(IteratorMapHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorMapHelper> parameter1 = UncheckedParameter<JSIteratorMapHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Number> tmp7;
  TNode<JSReceiver> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp7 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp6});
    compiler::CodeAssemblerLabel label9(&ca_);
    tmp8 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}}, TNode<Map>{tmp0}, &label9);
    ca_.Goto(&block3);
    if (label9.is_used()) {
      ca_.Bind(&label9);
      ca_.Goto(&block4);
    }
  }

  TNode<Oddball> tmp10;
  TNode<Oddball> tmp11;
  TNode<JSObject> tmp12;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp10 = Undefined_0(state_);
    tmp11 = True_0(state_);
    tmp12 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp10}, TNode<Oddball>{tmp11});
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<Object> tmp13;
  TNode<IntPtrT> tmp14;
      TNode<Object> tmp16;
  TNode<JSReceiver> tmp17;
  TNode<Oddball> tmp18;
  TNode<Object> tmp19;
      TNode<Object> tmp21;
  TNode<IntPtrT> tmp22;
      TNode<Object> tmp24;
  TNode<Number> tmp25;
      TNode<Object> tmp27;
  TNode<Number> tmp28;
      TNode<Object> tmp30;
  TNode<Oddball> tmp31;
  TNode<JSObject> tmp32;
      TNode<Object> tmp34;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp13 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp8}, TNode<Map>{tmp0});
    compiler::CodeAssemblerExceptionHandlerLabel catch15__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch15__label);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    }
    if (catch15__label.is_used()) {
      compiler::CodeAssemblerLabel catch15_skip(&ca_);
      ca_.Goto(&catch15_skip);
      ca_.Bind(&catch15__label, &tmp16);
      ca_.Goto(&block7);
      ca_.Bind(&catch15_skip);
    }
    tmp17 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp14});
    tmp18 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch20__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch20__label);
    tmp19 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp17}, TNode<Object>{tmp18}, TNode<Object>{tmp13}, TNode<Object>{tmp7});
    }
    if (catch20__label.is_used()) {
      compiler::CodeAssemblerLabel catch20_skip(&ca_);
      ca_.Goto(&catch20_skip);
      ca_.Bind(&catch20__label, &tmp21);
      ca_.Goto(&block8);
      ca_.Bind(&catch20_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch23__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch23__label);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    }
    if (catch23__label.is_used()) {
      compiler::CodeAssemblerLabel catch23_skip(&ca_);
      ca_.Goto(&catch23_skip);
      ca_.Bind(&catch23__label, &tmp24);
      ca_.Goto(&block9);
      ca_.Bind(&catch23_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch26__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch26__label);
    tmp25 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch26__label.is_used()) {
      compiler::CodeAssemblerLabel catch26_skip(&ca_);
      ca_.Goto(&catch26_skip);
      ca_.Bind(&catch26__label, &tmp27);
      ca_.Goto(&block10);
      ca_.Bind(&catch26_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch29__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch29__label);
    tmp28 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp7}, TNode<Number>{tmp25});
    }
    if (catch29__label.is_used()) {
      compiler::CodeAssemblerLabel catch29_skip(&ca_);
      ca_.Goto(&catch29_skip);
      ca_.Bind(&catch29__label, &tmp30);
      ca_.Goto(&block11);
      ca_.Bind(&catch29_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp22}, tmp28);
    tmp31 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch33__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch33__label);
    tmp32 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp19}, TNode<Oddball>{tmp31});
    }
    if (catch33__label.is_used()) {
      compiler::CodeAssemblerLabel catch33_skip(&ca_);
      ca_.Goto(&catch33_skip);
      ca_.Bind(&catch33__label, &tmp34);
      ca_.Goto(&block12);
      ca_.Bind(&catch33_skip);
    }
    CodeStubAssembler(state_).Return(tmp32);
  }

  TNode<HeapObject> tmp35;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp35 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp16, tmp35);
  }

  TNode<HeapObject> tmp36;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp36 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp21, tmp36);
  }

  TNode<HeapObject> tmp37;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp37 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp24, tmp37);
  }

  TNode<HeapObject> tmp38;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp38 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp27, tmp38);
  }

  TNode<HeapObject> tmp39;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp39 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp30, tmp39);
  }

  TNode<HeapObject> tmp40;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp40 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block6, tmp34, tmp40);
  }

  TNode<Object> phi_bb6_8;
  TNode<HeapObject> phi_bb6_9;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_8, &phi_bb6_9);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb6_8, phi_bb6_9);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=177&c=1
TNode<JSIteratorFilterHelper> NewJSIteratorFilterHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<JSReceiver> p_predicate) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Number> tmp18;
  TNode<JSIteratorFilterHelper> tmp19;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_FILTER_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 56);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp15}, p_underlying.next);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp16}, p_predicate);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp18 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp17}, tmp18);
    tmp19 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorFilterHelper>{tmp19};
}

TF_BUILTIN(IteratorPrototypeFilter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kPredicate);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.filter");
  }

  TNode<JSReceiver> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Callable_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter2}, &label3);
    ca_.Goto(&block7);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block8);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledNonCallable, "Iterator.prototype.filter");
  }

  TNode<JSReceiver> tmp4;
  TNode<Object> tmp5;
  TNode<JSIteratorFilterHelper> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    std::tie(tmp4, tmp5) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp6 = NewJSIteratorFilterHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, TNode<JSReceiver>{tmp2});
    CodeStubAssembler(state_).Return(tmp6);
  }
}

TF_BUILTIN(IteratorFilterHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorFilterHelper> parameter1 = UncheckedParameter<JSIteratorFilterHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp4});
    ca_.Goto(&block3);
  }

  TNode<BoolT> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp6, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<Number> tmp8;
  TNode<JSReceiver> tmp9;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp8 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp7});
    compiler::CodeAssemblerLabel label10(&ca_);
    tmp9 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}}, TNode<Map>{tmp0}, &label10);
    ca_.Goto(&block6);
    if (label10.is_used()) {
      ca_.Bind(&label10);
      ca_.Goto(&block7);
    }
  }

  TNode<Oddball> tmp11;
  TNode<Oddball> tmp12;
  TNode<JSObject> tmp13;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp11 = Undefined_0(state_);
    tmp12 = True_0(state_);
    tmp13 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp11}, TNode<Oddball>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }

  TNode<Object> tmp14;
  TNode<IntPtrT> tmp15;
      TNode<Object> tmp17;
  TNode<JSReceiver> tmp18;
  TNode<Oddball> tmp19;
  TNode<Object> tmp20;
      TNode<Object> tmp22;
  TNode<IntPtrT> tmp23;
      TNode<Object> tmp25;
  TNode<Number> tmp26;
      TNode<Object> tmp28;
  TNode<Number> tmp29;
      TNode<Object> tmp31;
  TNode<BoolT> tmp32;
      TNode<Object> tmp34;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp14 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp9}, TNode<Map>{tmp0});
    compiler::CodeAssemblerExceptionHandlerLabel catch16__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch16__label);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    }
    if (catch16__label.is_used()) {
      compiler::CodeAssemblerLabel catch16_skip(&ca_);
      ca_.Goto(&catch16_skip);
      ca_.Bind(&catch16__label, &tmp17);
      ca_.Goto(&block10);
      ca_.Bind(&catch16_skip);
    }
    tmp18 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp15});
    tmp19 = Undefined_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch21__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch21__label);
    tmp20 = CodeStubAssembler(state_).Call(TNode<Context>{parameter0}, TNode<Object>{tmp18}, TNode<Object>{tmp19}, TNode<Object>{tmp14}, TNode<Object>{tmp8});
    }
    if (catch21__label.is_used()) {
      compiler::CodeAssemblerLabel catch21_skip(&ca_);
      ca_.Goto(&catch21_skip);
      ca_.Bind(&catch21__label, &tmp22);
      ca_.Goto(&block11);
      ca_.Bind(&catch21_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch24__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch24__label);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    }
    if (catch24__label.is_used()) {
      compiler::CodeAssemblerLabel catch24_skip(&ca_);
      ca_.Goto(&catch24_skip);
      ca_.Bind(&catch24__label, &tmp25);
      ca_.Goto(&block12);
      ca_.Bind(&catch24_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch27__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch27__label);
    tmp26 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    }
    if (catch27__label.is_used()) {
      compiler::CodeAssemblerLabel catch27_skip(&ca_);
      ca_.Goto(&catch27_skip);
      ca_.Bind(&catch27__label, &tmp28);
      ca_.Goto(&block13);
      ca_.Bind(&catch27_skip);
    }
    compiler::CodeAssemblerExceptionHandlerLabel catch30__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch30__label);
    tmp29 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp8}, TNode<Number>{tmp26});
    }
    if (catch30__label.is_used()) {
      compiler::CodeAssemblerLabel catch30_skip(&ca_);
      ca_.Goto(&catch30_skip);
      ca_.Bind(&catch30__label, &tmp31);
      ca_.Goto(&block14);
      ca_.Bind(&catch30_skip);
    }
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp23}, tmp29);
    compiler::CodeAssemblerExceptionHandlerLabel catch33__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch33__label);
    tmp32 = ToBoolean_0(state_, TNode<Object>{tmp20});
    }
    if (catch33__label.is_used()) {
      compiler::CodeAssemblerLabel catch33_skip(&ca_);
      ca_.Goto(&catch33_skip);
      ca_.Bind(&catch33__label, &tmp34);
      ca_.Goto(&block17);
      ca_.Bind(&catch33_skip);
    }
    ca_.Branch(tmp32, &block15, std::vector<compiler::Node*>{}, &block16, std::vector<compiler::Node*>{});
  }

  TNode<HeapObject> tmp35;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp35 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp17, tmp35);
  }

  TNode<HeapObject> tmp36;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    tmp36 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp22, tmp36);
  }

  TNode<HeapObject> tmp37;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp37 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp25, tmp37);
  }

  TNode<HeapObject> tmp38;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp38 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp28, tmp38);
  }

  TNode<HeapObject> tmp39;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp39 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp31, tmp39);
  }

  TNode<HeapObject> tmp40;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp40 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp34, tmp40);
  }

  TNode<Oddball> tmp41;
  TNode<JSObject> tmp42;
      TNode<Object> tmp44;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp41 = False_0(state_);
    compiler::CodeAssemblerExceptionHandlerLabel catch43__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch43__label);
    tmp42 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp14}, TNode<Oddball>{tmp41});
    }
    if (catch43__label.is_used()) {
      compiler::CodeAssemblerLabel catch43_skip(&ca_);
      ca_.Goto(&catch43_skip);
      ca_.Bind(&catch43__label, &tmp44);
      ca_.Goto(&block18);
      ca_.Bind(&catch43_skip);
    }
    CodeStubAssembler(state_).Return(tmp42);
  }

  TNode<HeapObject> tmp45;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp45 = GetAndResetPendingMessage_0(state_);
    ca_.Goto(&block9, tmp44, tmp45);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    ca_.Goto(&block3);
  }

  TNode<Object> phi_bb9_8;
  TNode<HeapObject> phi_bb9_9;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_8, &phi_bb9_9);
    IteratorCloseOnException_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}});
    CodeStubAssembler(state_).CallRuntime(Runtime::kReThrowWithMessage, parameter0, phi_bb9_8, phi_bb9_9);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).Unreachable();
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=270&c=1
TNode<JSIteratorTakeHelper> NewJSIteratorTakeHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<JSIteratorTakeHelper> tmp17;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_TAKE_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp15}, p_underlying.next);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp16}, p_limit);
    tmp17 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorTakeHelper>{tmp17};
}

TF_BUILTIN(IteratorPrototypeTake, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kLimit);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.take");
  }

  TNode<Number> tmp2;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = NumberIsNaN_0(state_, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp2});
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = NumberIsLessThan_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp7;
  TNode<Object> tmp8;
  TNode<JSIteratorTakeHelper> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    std::tie(tmp7, tmp8) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp9 = NewJSIteratorTakeHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Number>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kMustBePositive, TNode<Object>{parameter2});
  }
}

TF_BUILTIN(IteratorTakeHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorTakeHelper> parameter1 = UncheckedParameter<JSIteratorTakeHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Number> tmp7;
  TNode<Number> tmp8;
  TNode<BoolT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    tmp7 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp6});
    tmp8 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = IsNumberEqual_0(state_, TNode<Number>{tmp7}, TNode<Number>{tmp8});
    ca_.Branch(tmp9, &block1, std::vector<compiler::Node*>{}, &block2, std::vector<compiler::Node*>{});
  }

  TNode<Oddball> tmp10;
  TNode<Oddball> tmp11;
  TNode<JSObject> tmp12;
  if (block1.is_used()) {
    ca_.Bind(&block1);
    IteratorClose_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}});
    tmp10 = Undefined_0(state_);
    tmp11 = True_0(state_);
    tmp12 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp10}, TNode<Oddball>{tmp11});
    CodeStubAssembler(state_).Return(tmp12);
  }

  TNode<BoolT> tmp13;
  TNode<BoolT> tmp14;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp13 = NumberIsSomeInfinity_0(state_, TNode<Number>{tmp7});
    tmp14 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp13});
    ca_.Branch(tmp14, &block3, std::vector<compiler::Node*>{}, &block4, std::vector<compiler::Node*>{});
  }

  TNode<IntPtrT> tmp15;
  TNode<Number> tmp16;
  TNode<Number> tmp17;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    tmp16 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp17 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp7}, TNode<Number>{tmp16});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp15}, tmp17);
    ca_.Goto(&block4);
  }

  TNode<JSReceiver> tmp18;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label19(&ca_);
    tmp18 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}}, TNode<Map>{tmp0}, &label19);
    ca_.Goto(&block7);
    if (label19.is_used()) {
      ca_.Bind(&label19);
      ca_.Goto(&block8);
    }
  }

  TNode<Oddball> tmp20;
  TNode<Oddball> tmp21;
  TNode<JSObject> tmp22;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp20 = Undefined_0(state_);
    tmp21 = True_0(state_);
    tmp22 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp20}, TNode<Oddball>{tmp21});
    CodeStubAssembler(state_).Return(tmp22);
  }

  TNode<Object> tmp23;
  TNode<Oddball> tmp24;
  TNode<JSObject> tmp25;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp23 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp18}, TNode<Map>{tmp0});
    tmp24 = False_0(state_);
    tmp25 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp23}, TNode<Oddball>{tmp24});
    CodeStubAssembler(state_).Return(tmp25);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=364&c=1
TNode<JSIteratorDropHelper> NewJSIteratorDropHelper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructIteratorRecord p_underlying, TNode<Number> p_limit) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Map> tmp3;
  TNode<FixedArray> tmp4;
  TNode<FixedArray> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<HeapObject> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<JSIteratorDropHelper> tmp17;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ITERATOR_DROP_HELPER_MAP_INDEX_0(state_);
    std::tie(tmp1, tmp2) = NativeContextSlot_Context_Map_0(state_, TNode<Context>{p_context}, TNode<IntPtrT>{tmp0}).Flatten();
    tmp3 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = kEmptyFixedArray_0(state_);
    tmp5 = kEmptyFixedArray_0(state_);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 48);
    tmp9 = AllocateFromNew_0(state_, TNode<IntPtrT>{tmp8}, TNode<Map>{tmp3}, TNode<BoolT>{tmp6}, TNode<BoolT>{tmp7});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp9, tmp10}, tmp3);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp11}, tmp4);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp12}, tmp5);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<JSReceiver>(CodeStubAssembler::Reference{tmp9, tmp13}, p_underlying.object);
    tmp14 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp14});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp9, tmp15}, p_underlying.next);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp16}, p_limit);
    tmp17 = TORQUE_CAST(TNode<HeapObject>{tmp9});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<JSIteratorDropHelper>{tmp17};
}

TF_BUILTIN(IteratorPrototypeDrop, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedParameter<NativeContext>(Descriptor::kContext);
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedParameter<Object>(Descriptor::kReceiver);
  USE(parameter1);
  TNode<Object> parameter2 = UncheckedParameter<Object>(Descriptor::kLimit);
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0);

  TNode<JSReceiver> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSReceiver_1(state_, TNode<Context>{parameter0}, TNode<Object>{parameter1}, &label1);
    ca_.Goto(&block5);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{parameter0}, MessageTemplate::kCalledOnNonObject, "Iterator.prototype.drop");
  }

  TNode<Number> tmp2;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = CodeStubAssembler(state_).ToNumber_Inline(TNode<Context>{parameter0}, TNode<Object>{parameter2});
    tmp3 = NumberIsNaN_0(state_, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block7, std::vector<compiler::Node*>{}, &block8, std::vector<compiler::Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block2);
  }

  TNode<Number> tmp4;
  TNode<Number> tmp5;
  TNode<BoolT> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp4 = ToInteger_Inline_0(state_, TNode<Context>{parameter0}, TNode<Object>{tmp2});
    tmp5 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp6 = NumberIsLessThan_0(state_, TNode<Number>{tmp4}, TNode<Number>{tmp5});
    ca_.Branch(tmp6, &block9, std::vector<compiler::Node*>{}, &block10, std::vector<compiler::Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp7;
  TNode<Object> tmp8;
  TNode<JSIteratorDropHelper> tmp9;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    std::tie(tmp7, tmp8) = GetIteratorDirect_0(state_, TNode<Context>{parameter0}, TNode<JSReceiver>{tmp0}).Flatten();
    tmp9 = NewJSIteratorDropHelper_0(state_, TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp7}, TNode<Object>{tmp8}}, TNode<Number>{tmp4});
    CodeStubAssembler(state_).Return(tmp9);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{parameter0}, MessageTemplate::kMustBePositive, TNode<Object>{parameter2});
  }
}

TF_BUILTIN(IteratorDropHelperNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedParameter<Context>(Descriptor::kContext);
  USE(parameter0);
  TNode<JSIteratorDropHelper> parameter1 = UncheckedParameter<JSIteratorDropHelper>(Descriptor::kHelper);
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<JSReceiver> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Number> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = GetIteratorResultMap_0(state_, TNode<Context>{parameter0});
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp2 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{parameter1, tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_intptr_0(state_, 8);
    tmp4 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp3});
    tmp5 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{parameter1, tmp4});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    tmp7 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{parameter1, tmp6});
    ca_.Goto(&block5, tmp7);
  }

  TNode<Number> phi_bb5_5;
  TNode<Number> tmp8;
  TNode<BoolT> tmp9;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp8 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x0ull));
    tmp9 = NumberIsGreaterThan_0(state_, TNode<Number>{phi_bb5_5}, TNode<Number>{tmp8});
    ca_.Branch(tmp9, &block3, std::vector<compiler::Node*>{phi_bb5_5}, &block4, std::vector<compiler::Node*>{phi_bb5_5});
  }

  TNode<Number> phi_bb3_5;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp10 = NumberIsSomeInfinity_0(state_, TNode<Number>{phi_bb3_5});
    tmp11 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block6, std::vector<compiler::Node*>{phi_bb3_5}, &block7, std::vector<compiler::Node*>{phi_bb3_5});
  }

  TNode<Number> phi_bb6_5;
  TNode<Number> tmp12;
  TNode<Number> tmp13;
  TNode<IntPtrT> tmp14;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_5);
    tmp12 = FromConstexpr_Number_constexpr_IntegerLiteral_0(state_, IntegerLiteral(false, 0x1ull));
    tmp13 = CodeStubAssembler(state_).NumberSub(TNode<Number>{phi_bb6_5}, TNode<Number>{tmp12});
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, 40);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{parameter1, tmp14}, tmp13);
    ca_.Goto(&block7, tmp13);
  }

  TNode<Number> phi_bb7_5;
  TNode<JSReceiver> tmp15;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_5);
    compiler::CodeAssemblerLabel label16(&ca_);
    tmp15 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}}, TNode<Map>{tmp0}, &label16);
    ca_.Goto(&block8);
    if (label16.is_used()) {
      ca_.Bind(&label16);
      ca_.Goto(&block9);
    }
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block2, phi_bb7_5);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block5, phi_bb7_5);
  }

  TNode<Number> phi_bb4_5;
  TNode<JSReceiver> tmp17;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    compiler::CodeAssemblerLabel label18(&ca_);
    tmp17 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{parameter0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp2}, TNode<Object>{tmp5}}, TNode<Map>{tmp0}, &label18);
    ca_.Goto(&block10, phi_bb4_5);
    if (label18.is_used()) {
      ca_.Bind(&label18);
      ca_.Goto(&block11, phi_bb4_5);
    }
  }

  TNode<Number> phi_bb11_5;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    ca_.Goto(&block2, phi_bb11_5);
  }

  TNode<Number> phi_bb10_5;
  TNode<Object> tmp19;
  TNode<Oddball> tmp20;
  TNode<JSObject> tmp21;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    tmp19 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{parameter0}, TNode<JSReceiver>{tmp17}, TNode<Map>{tmp0});
    tmp20 = False_0(state_);
    tmp21 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp19}, TNode<Oddball>{tmp20});
    CodeStubAssembler(state_).Return(tmp21);
  }

  TNode<Number> phi_bb2_5;
  TNode<Oddball> tmp22;
  TNode<Oddball> tmp23;
  TNode<JSObject> tmp24;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_5);
    tmp22 = Undefined_0(state_);
    tmp23 = True_0(state_);
    tmp24 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{parameter0}, TNode<Object>{tmp22}, TNode<Oddball>{tmp23});
    CodeStubAssembler(state_).Return(tmp24);
  }
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=44&c=5
TNode<JSIteratorMapHelper> Cast_JSIteratorMapHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSIteratorMapHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorMapHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSIteratorMapHelper>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=47&c=5
TNode<JSIteratorFilterHelper> Cast_JSIteratorFilterHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSIteratorFilterHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorFilterHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSIteratorFilterHelper>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=50&c=5
TNode<JSIteratorTakeHelper> Cast_JSIteratorTakeHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSIteratorTakeHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorTakeHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSIteratorTakeHelper>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=53&c=5
TNode<JSIteratorDropHelper> Cast_JSIteratorDropHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSIteratorDropHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorDropHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSIteratorDropHelper>{tmp2};
}

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/iterator-helpers.tq?l=81&c=18
TNode<JSIteratorHelper> Cast_JSIteratorHelper_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssembler::SourcePositionScope pos_scope(&ca_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<HeapObject> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{p_o}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block1);
  }

  TNode<JSIteratorHelper> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSIteratorHelper_0(state_, TNode<HeapObject>{tmp0}, &label3);
    ca_.Goto(&block5);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block6);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block7);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    ca_.Bind(&block7);
  return TNode<JSIteratorHelper>{tmp2};
}

} // namespace internal
} // namespace v8
