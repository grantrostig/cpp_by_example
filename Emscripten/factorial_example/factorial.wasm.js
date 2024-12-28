/**
 * @license
 * Copyright 2019 The Emscripten Authors
 * SPDX-License-Identifier: MIT
 */

// wasm2js.js - enough of a polyfill for the WebAssembly object so that we can load
// wasm2js code that way.

// Emit "var WebAssembly" if definitely using wasm2js. Otherwise, in MAYBE_WASM2JS
// mode, we can't use a "var" since it would prevent normal wasm from working.
/** @suppress{duplicate, const} */
var
WebAssembly = {
  // Note that we do not use closure quoting (this['buffer'], etc.) on these
  // functions, as they are just meant for internal use. In other words, this is
  // not a fully general polyfill.
  /** @constructor */
  Memory: function(opts) {
    this.buffer = new ArrayBuffer(opts['initial'] * 65536);
  },

  Module: function(binary) {
    // TODO: use the binary and info somehow - right now the wasm2js output is embedded in
    // the main JS
  },

  /** @constructor */
  Instance: function(module, info) {
    // TODO: use the module somehow - right now the wasm2js output is embedded in
    // the main JS
    // This will be replaced by the actual wasm2js code.
    this.exports = (
function instantiate(info) {
function Table(ret) {
  // grow method not included; table is not growable
  ret.set = function(i, func) {
    this[i] = func;
  };
  ret.get = function(i) {
    return this[i];
  };
  return ret;
}

  var bufferView;
  var base64ReverseLookup = new Uint8Array(123/*'z'+1*/);
  for (var i = 25; i >= 0; --i) {
    base64ReverseLookup[48+i] = 52+i; // '0-9'
    base64ReverseLookup[65+i] = i; // 'A-Z'
    base64ReverseLookup[97+i] = 26+i; // 'a-z'
  }
  base64ReverseLookup[43] = 62; // '+'
  base64ReverseLookup[47] = 63; // '/'
  /** @noinline Inlining this function would mean expanding the base64 string 4x times in the source code, which Closure seems to be happy to do. */
  function base64DecodeToExistingUint8Array(uint8Array, offset, b64) {
    var b1, b2, i = 0, j = offset, bLength = b64.length, end = offset + (bLength*3>>2) - (b64[bLength-2] == '=') - (b64[bLength-1] == '=');
    for (; i < bLength; i += 4) {
      b1 = base64ReverseLookup[b64.charCodeAt(i+1)];
      b2 = base64ReverseLookup[b64.charCodeAt(i+2)];
      uint8Array[j++] = base64ReverseLookup[b64.charCodeAt(i)] << 2 | b1 >> 4;
      if (j < end) uint8Array[j++] = b1 << 4 | b2 >> 2;
      if (j < end) uint8Array[j++] = b2 << 6 | base64ReverseLookup[b64.charCodeAt(i+3)];
    }
  }
function initActiveSegments(imports) {
  base64DecodeToExistingUint8Array(bufferView, 65536, "aW5maW5pdHkALSsgICAwWDB4AC0wWCswWCAwWC0weCsweCAweABuYW4AaW5mACVkAE5BTgBJTkYALgAobnVsbCkARW50ZXIgYSBudW1iZXI6IABUaGUgZmFjdG9yaWFsIG9mICVkIGlzICVkCgAAABkACgAZGRkAAAAABQAAAAAAAAkAAAAACwAAAAAAAAAAGQARChkZGQMKBwABAAkLGAAACQYLAAALAAYZAAAAGRkZAAAAAAAAAAAAAAAAAAAAAA4AAAAAAAAAABkACg0ZGRkADQAAAgAJDgAAAAkADgAADgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMAAAAAAAAAAAAAAATAAAAABMAAAAACQwAAAAAAAwAAAwAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAEAAAAAAAAAAAAAAADwAAAAQPAAAAAAkQAAAAAAAQAAAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABIAAAAAAAAAAAAAABEAAAAAEQAAAAAJEgAAAAAAEgAAEgAAGgAAABoaGgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAaAAAAGhoaAAAAAAAACQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFAAAAAAAAAAAAAAAFwAAAAAXAAAAAAkUAAAAAAAUAAAUAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABYAAAAAAAAAAAAAABUAAAAAFQAAAAAJFgAAAAAAFgAAFgAAMDEyMzQ1Njc4OUFCQ0RFRtF0ngBXnb0qgHBSD///PicKAAAAZAAAAOgDAAAQJwAAoIYBAEBCDwCAlpgAAOH1BRgAAAA1AAAAcQAAAGv////O+///kr///wAAAAAAAAAA/////////////////////////////////////////////////////////////////wABAgMEBQYHCAn/////////CgsMDQ4PEBESExQVFhcYGRobHB0eHyAhIiP///////8KCwwNDg8QERITFBUWFxgZGhscHR4fICEiI/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////8AAQIEBwMGBQAAAAAAAAACAADAAwAAwAQAAMAFAADABgAAwAcAAMAIAADACQAAwAoAAMALAADADAAAwA0AAMAOAADADwAAwBAAAMARAADAEgAAwBMAAMAUAADAFQAAwBYAAMAXAADAGAAAwBkAAMAaAADAGwAAwBwAAMAdAADAHgAAwB8AAMAAAACzAQAAwwIAAMMDAADDBAAAwwUAAMMGAADDBwAAwwgAAMMJAADDCgAAwwsAAMMMAADDDQAA0w4AAMMPAADDAAAMuwEADMMCAAzDAwAMwwQADNs=");
  base64DecodeToExistingUint8Array(bufferView, 66688, "BQAAAAAAAAAAAAAAAgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAwAAAAQAAAC4BQEAAAQAAAAAAAAAAAAAAQAAAAAAAAAAAAAAAAAAAP////8KAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgAQBAAAAAAAJAAAAAAAAAAAAAAAHAAAAAAAAAAAAAAAAAAAAAAAAAAgAAAAAAAAACQAAANgJAQAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA/////wAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAYBQEAkBABAA==");
}

  var scratchBuffer = new ArrayBuffer(16);
  var i32ScratchView = new Int32Array(scratchBuffer);
  var f32ScratchView = new Float32Array(scratchBuffer);
  var f64ScratchView = new Float64Array(scratchBuffer);
  
  function wasm2js_scratch_load_i32(index) {
    return i32ScratchView[index];
  }
      
  function wasm2js_scratch_store_i32(index, value) {
    i32ScratchView[index] = value;
  }
      
  function wasm2js_scratch_load_f64() {
    return f64ScratchView[0];
  }
      
  function wasm2js_scratch_store_f64(value) {
    f64ScratchView[0] = value;
  }
      function wasm2js_trap() { throw new Error('abort'); }

  function wasm2js_scratch_store_f32(value) {
    f32ScratchView[2] = value;
  }
      
  function wasm2js_scratch_load_f32() {
    return f32ScratchView[2];
  }
      
function asmFunc(imports) {
 var buffer = new ArrayBuffer(16908288);
 var HEAP8 = new Int8Array(buffer);
 var HEAP16 = new Int16Array(buffer);
 var HEAP32 = new Int32Array(buffer);
 var HEAPU8 = new Uint8Array(buffer);
 var HEAPU16 = new Uint16Array(buffer);
 var HEAPU32 = new Uint32Array(buffer);
 var HEAPF32 = new Float32Array(buffer);
 var HEAPF64 = new Float64Array(buffer);
 var Math_imul = Math.imul;
 var Math_fround = Math.fround;
 var Math_abs = Math.abs;
 var Math_clz32 = Math.clz32;
 var Math_min = Math.min;
 var Math_max = Math.max;
 var Math_floor = Math.floor;
 var Math_ceil = Math.ceil;
 var Math_trunc = Math.trunc;
 var Math_sqrt = Math.sqrt;
 var wasi_snapshot_preview1 = imports.wasi_snapshot_preview1;
 var fimport$0 = wasi_snapshot_preview1.proc_exit;
 var fimport$1 = wasi_snapshot_preview1.fd_write;
 var fimport$2 = wasi_snapshot_preview1.fd_close;
 var fimport$3 = wasi_snapshot_preview1.fd_read;
 var legalimport$fimport$4 = wasi_snapshot_preview1.fd_seek;
 var global$0 = 65536;
 var global$1 = 0;
 var global$2 = 0;
 var __wasm_intrinsics_temp_i64 = 0;
 var __wasm_intrinsics_temp_i64$hi = 0;
 var i64toi32_i32$HIGH_BITS = 0;
 // EMSCRIPTEN_START_FUNCS
;
 function $0() {
  $102();
  $67();
 }
 
 function $1($0_1) {
  $0_1 = $0_1 | 0;
  var $3_1 = 0, $12_1 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  HEAP32[($3_1 + 8 | 0) >> 2] = $0_1;
  label$1 : {
   label$2 : {
    if (HEAP32[($3_1 + 8 | 0) >> 2] | 0) {
     break label$2
    }
    HEAP32[($3_1 + 12 | 0) >> 2] = 1;
    break label$1;
   }
   HEAP32[($3_1 + 12 | 0) >> 2] = Math_imul(HEAP32[($3_1 + 8 | 0) >> 2] | 0, $1((HEAP32[($3_1 + 8 | 0) >> 2] | 0) - 1 | 0 | 0) | 0);
  }
  $12_1 = HEAP32[($3_1 + 12 | 0) >> 2] | 0;
  global$0 = $3_1 + 16 | 0;
  return $12_1 | 0;
 }
 
 function $2() {
  var $2_1 = 0, $11_1 = 0;
  $2_1 = global$0 - 48 | 0;
  global$0 = $2_1;
  HEAP32[($2_1 + 44 | 0) >> 2] = 0;
  $8(65602 | 0, 0 | 0) | 0;
  HEAP32[$2_1 >> 2] = $2_1 + 40 | 0;
  $9(65582 | 0, $2_1 | 0) | 0;
  HEAP32[($2_1 + 36 | 0) >> 2] = $1(HEAP32[($2_1 + 40 | 0) >> 2] | 0 | 0) | 0;
  $11_1 = HEAP32[($2_1 + 40 | 0) >> 2] | 0;
  HEAP32[($2_1 + 20 | 0) >> 2] = HEAP32[($2_1 + 36 | 0) >> 2] | 0;
  HEAP32[($2_1 + 16 | 0) >> 2] = $11_1;
  $8(65619 | 0, $2_1 + 16 | 0 | 0) | 0;
  global$0 = $2_1 + 48 | 0;
  return 0 | 0;
 }
 
 function $3() {
  label$1 : {
   if (!1) {
    break label$1
   }
   $0();
  }
  $6($2() | 0 | 0);
  wasm2js_trap();
 }
 
 function $4() {
  
 }
 
 function $5() {
  var $0_1 = 0;
  $0_1 = 0;
  label$1 : {
   if (0 >>> 0 <= 0 >>> 0) {
    break label$1
   }
   label$2 : while (1) {
    $0_1 = $0_1 + -4 | 0;
    FUNCTION_TABLE[HEAP32[$0_1 >> 2] | 0 | 0]();
    if ($0_1 >>> 0 > 0 >>> 0) {
     continue label$2
    }
    break label$2;
   };
  }
  $4();
 }
 
 function $6($0_1) {
  $0_1 = $0_1 | 0;
  $4();
  $5();
  $22();
  $7($0_1 | 0);
  wasm2js_trap();
 }
 
 function $7($0_1) {
  $0_1 = $0_1 | 0;
  fimport$0($0_1 | 0);
  wasm2js_trap();
 }
 
 function $8($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  HEAP32[($2_1 + 12 | 0) >> 2] = $1_1;
  $1_1 = $38(66688 | 0, $0_1 | 0, $1_1 | 0) | 0;
  global$0 = $2_1 + 16 | 0;
  return $1_1 | 0;
 }
 
 function $9($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  HEAP32[($2_1 + 12 | 0) >> 2] = $1_1;
  $1_1 = $74($0_1 | 0, $1_1 | 0) | 0;
  global$0 = $2_1 + 16 | 0;
  return $1_1 | 0;
 }
 
 function $10($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $4_1 = 0, $3_1 = 0, $5_1 = 0, $8_1 = 0, $6_1 = 0, $7_1 = 0, $9_1 = 0;
  $3_1 = global$0 - 32 | 0;
  global$0 = $3_1;
  $4_1 = HEAP32[($0_1 + 28 | 0) >> 2] | 0;
  HEAP32[($3_1 + 16 | 0) >> 2] = $4_1;
  $5_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
  HEAP32[($3_1 + 28 | 0) >> 2] = $2_1;
  HEAP32[($3_1 + 24 | 0) >> 2] = $1_1;
  $1_1 = $5_1 - $4_1 | 0;
  HEAP32[($3_1 + 20 | 0) >> 2] = $1_1;
  $6_1 = $1_1 + $2_1 | 0;
  $4_1 = $3_1 + 16 | 0;
  $7_1 = 2;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : {
       if (!($75(fimport$1(HEAP32[($0_1 + 60 | 0) >> 2] | 0 | 0, $3_1 + 16 | 0 | 0, 2 | 0, $3_1 + 12 | 0 | 0) | 0 | 0) | 0)) {
        break label$5
       }
       $5_1 = $4_1;
       break label$4;
      }
      label$6 : while (1) {
       $1_1 = HEAP32[($3_1 + 12 | 0) >> 2] | 0;
       if (($6_1 | 0) == ($1_1 | 0)) {
        break label$3
       }
       label$7 : {
        if (($1_1 | 0) > (-1 | 0)) {
         break label$7
        }
        $5_1 = $4_1;
        break label$2;
       }
       $8_1 = HEAP32[($4_1 + 4 | 0) >> 2] | 0;
       $9_1 = $1_1 >>> 0 > $8_1 >>> 0;
       $5_1 = $4_1 + ($9_1 << 3 | 0) | 0;
       $8_1 = $1_1 - ($9_1 ? $8_1 : 0) | 0;
       HEAP32[$5_1 >> 2] = (HEAP32[$5_1 >> 2] | 0) + $8_1 | 0;
       $4_1 = $4_1 + ($9_1 ? 12 : 4) | 0;
       HEAP32[$4_1 >> 2] = (HEAP32[$4_1 >> 2] | 0) - $8_1 | 0;
       $6_1 = $6_1 - $1_1 | 0;
       $4_1 = $5_1;
       $7_1 = $7_1 - $9_1 | 0;
       if (!($75(fimport$1(HEAP32[($0_1 + 60 | 0) >> 2] | 0 | 0, $4_1 | 0, $7_1 | 0, $3_1 + 12 | 0 | 0) | 0 | 0) | 0)) {
        continue label$6
       }
       break label$6;
      };
     }
     if (($6_1 | 0) != (-1 | 0)) {
      break label$2
     }
    }
    $1_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
    HEAP32[($0_1 + 28 | 0) >> 2] = $1_1;
    HEAP32[($0_1 + 20 | 0) >> 2] = $1_1;
    HEAP32[($0_1 + 16 | 0) >> 2] = $1_1 + (HEAP32[($0_1 + 48 | 0) >> 2] | 0) | 0;
    $1_1 = $2_1;
    break label$1;
   }
   $1_1 = 0;
   HEAP32[($0_1 + 28 | 0) >> 2] = 0;
   HEAP32[($0_1 + 16 | 0) >> 2] = 0;
   HEAP32[($0_1 + 20 | 0) >> 2] = 0;
   HEAP32[$0_1 >> 2] = HEAP32[$0_1 >> 2] | 0 | 32 | 0;
   if (($7_1 | 0) == (2 | 0)) {
    break label$1
   }
   $1_1 = $2_1 - (HEAP32[($5_1 + 4 | 0) >> 2] | 0) | 0;
  }
  global$0 = $3_1 + 32 | 0;
  return $1_1 | 0;
 }
 
 function $11($0_1) {
  $0_1 = $0_1 | 0;
  return 0 | 0;
 }
 
 function $12($0_1, $1_1, $1$hi, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  i64toi32_i32$HIGH_BITS = 0;
  return 0 | 0;
 }
 
 function $13($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, i64toi32_i32$0 = 0, $4_1 = 0, i64toi32_i32$1 = 0, $6_1 = 0, $5_1 = 0, $6$hi = 0;
  label$1 : {
   if (!$2_1) {
    break label$1
   }
   HEAP8[$0_1 >> 0] = $1_1;
   $3_1 = $0_1 + $2_1 | 0;
   HEAP8[($3_1 + -1 | 0) >> 0] = $1_1;
   if ($2_1 >>> 0 < 3 >>> 0) {
    break label$1
   }
   HEAP8[($0_1 + 2 | 0) >> 0] = $1_1;
   HEAP8[($0_1 + 1 | 0) >> 0] = $1_1;
   HEAP8[($3_1 + -3 | 0) >> 0] = $1_1;
   HEAP8[($3_1 + -2 | 0) >> 0] = $1_1;
   if ($2_1 >>> 0 < 7 >>> 0) {
    break label$1
   }
   HEAP8[($0_1 + 3 | 0) >> 0] = $1_1;
   HEAP8[($3_1 + -4 | 0) >> 0] = $1_1;
   if ($2_1 >>> 0 < 9 >>> 0) {
    break label$1
   }
   $4_1 = (0 - $0_1 | 0) & 3 | 0;
   $3_1 = $0_1 + $4_1 | 0;
   $1_1 = Math_imul($1_1 & 255 | 0, 16843009);
   HEAP32[$3_1 >> 2] = $1_1;
   $4_1 = ($2_1 - $4_1 | 0) & -4 | 0;
   $2_1 = $3_1 + $4_1 | 0;
   HEAP32[($2_1 + -4 | 0) >> 2] = $1_1;
   if ($4_1 >>> 0 < 9 >>> 0) {
    break label$1
   }
   HEAP32[($3_1 + 8 | 0) >> 2] = $1_1;
   HEAP32[($3_1 + 4 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -8 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -12 | 0) >> 2] = $1_1;
   if ($4_1 >>> 0 < 25 >>> 0) {
    break label$1
   }
   HEAP32[($3_1 + 24 | 0) >> 2] = $1_1;
   HEAP32[($3_1 + 20 | 0) >> 2] = $1_1;
   HEAP32[($3_1 + 16 | 0) >> 2] = $1_1;
   HEAP32[($3_1 + 12 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -16 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -20 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -24 | 0) >> 2] = $1_1;
   HEAP32[($2_1 + -28 | 0) >> 2] = $1_1;
   $5_1 = $3_1 & 4 | 0 | 24 | 0;
   $2_1 = $4_1 - $5_1 | 0;
   if ($2_1 >>> 0 < 32 >>> 0) {
    break label$1
   }
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 1;
   i64toi32_i32$1 = __wasm_i64_mul($1_1 | 0, i64toi32_i32$0 | 0, 1 | 0, i64toi32_i32$1 | 0) | 0;
   i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
   $6_1 = i64toi32_i32$1;
   $6$hi = i64toi32_i32$0;
   $1_1 = $3_1 + $5_1 | 0;
   label$2 : while (1) {
    i64toi32_i32$0 = $6$hi;
    i64toi32_i32$1 = $1_1;
    HEAP32[($1_1 + 24 | 0) >> 2] = $6_1;
    HEAP32[($1_1 + 28 | 0) >> 2] = i64toi32_i32$0;
    i64toi32_i32$1 = $1_1;
    HEAP32[($1_1 + 16 | 0) >> 2] = $6_1;
    HEAP32[($1_1 + 20 | 0) >> 2] = i64toi32_i32$0;
    i64toi32_i32$1 = $1_1;
    HEAP32[($1_1 + 8 | 0) >> 2] = $6_1;
    HEAP32[($1_1 + 12 | 0) >> 2] = i64toi32_i32$0;
    i64toi32_i32$1 = $1_1;
    HEAP32[$1_1 >> 2] = $6_1;
    HEAP32[($1_1 + 4 | 0) >> 2] = i64toi32_i32$0;
    $1_1 = $1_1 + 32 | 0;
    $2_1 = $2_1 + -32 | 0;
    if ($2_1 >>> 0 > 31 >>> 0) {
     continue label$2
    }
    break label$2;
   };
  }
  return $0_1 | 0;
 }
 
 function $14($0_1) {
  $0_1 = $0_1 | 0;
  return 1 | 0;
 }
 
 function $15($0_1) {
  $0_1 = $0_1 | 0;
 }
 
 function $16() {
  return 68024 | 0;
 }
 
 function $17() {
  return __wasm_memory_size() << 16 | 0 | 0;
 }
 
 function $18($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $4_1 = 0, $3_1 = 0, $5_1 = 0;
  $3_1 = $0_1 + $2_1 | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      if (($1_1 ^ $0_1 | 0) & 3 | 0) {
       break label$4
      }
      if (!($0_1 & 3 | 0)) {
       break label$3
      }
      if (($2_1 | 0) < (1 | 0)) {
       break label$3
      }
      $2_1 = $0_1;
      label$5 : while (1) {
       HEAP8[$2_1 >> 0] = HEAPU8[$1_1 >> 0] | 0;
       $1_1 = $1_1 + 1 | 0;
       $2_1 = $2_1 + 1 | 0;
       if (!($2_1 & 3 | 0)) {
        break label$2
       }
       if ($2_1 >>> 0 < $3_1 >>> 0) {
        continue label$5
       }
       break label$2;
      };
     }
     label$6 : {
      if ($3_1 >>> 0 < 4 >>> 0) {
       break label$6
      }
      $4_1 = $3_1 + -4 | 0;
      if ($4_1 >>> 0 < $0_1 >>> 0) {
       break label$6
      }
      $2_1 = $0_1;
      label$7 : while (1) {
       HEAP8[$2_1 >> 0] = HEAPU8[$1_1 >> 0] | 0;
       HEAP8[($2_1 + 1 | 0) >> 0] = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
       HEAP8[($2_1 + 2 | 0) >> 0] = HEAPU8[($1_1 + 2 | 0) >> 0] | 0;
       HEAP8[($2_1 + 3 | 0) >> 0] = HEAPU8[($1_1 + 3 | 0) >> 0] | 0;
       $1_1 = $1_1 + 4 | 0;
       $2_1 = $2_1 + 4 | 0;
       if ($2_1 >>> 0 <= $4_1 >>> 0) {
        continue label$7
       }
       break label$1;
      };
     }
     $2_1 = $0_1;
     break label$1;
    }
    $2_1 = $0_1;
   }
   label$8 : {
    $4_1 = $3_1 & -4 | 0;
    if ($4_1 >>> 0 < 64 >>> 0) {
     break label$8
    }
    $5_1 = $4_1 + -64 | 0;
    if ($2_1 >>> 0 > $5_1 >>> 0) {
     break label$8
    }
    label$9 : while (1) {
     HEAP32[$2_1 >> 2] = HEAP32[$1_1 >> 2] | 0;
     HEAP32[($2_1 + 4 | 0) >> 2] = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
     HEAP32[($2_1 + 8 | 0) >> 2] = HEAP32[($1_1 + 8 | 0) >> 2] | 0;
     HEAP32[($2_1 + 12 | 0) >> 2] = HEAP32[($1_1 + 12 | 0) >> 2] | 0;
     HEAP32[($2_1 + 16 | 0) >> 2] = HEAP32[($1_1 + 16 | 0) >> 2] | 0;
     HEAP32[($2_1 + 20 | 0) >> 2] = HEAP32[($1_1 + 20 | 0) >> 2] | 0;
     HEAP32[($2_1 + 24 | 0) >> 2] = HEAP32[($1_1 + 24 | 0) >> 2] | 0;
     HEAP32[($2_1 + 28 | 0) >> 2] = HEAP32[($1_1 + 28 | 0) >> 2] | 0;
     HEAP32[($2_1 + 32 | 0) >> 2] = HEAP32[($1_1 + 32 | 0) >> 2] | 0;
     HEAP32[($2_1 + 36 | 0) >> 2] = HEAP32[($1_1 + 36 | 0) >> 2] | 0;
     HEAP32[($2_1 + 40 | 0) >> 2] = HEAP32[($1_1 + 40 | 0) >> 2] | 0;
     HEAP32[($2_1 + 44 | 0) >> 2] = HEAP32[($1_1 + 44 | 0) >> 2] | 0;
     HEAP32[($2_1 + 48 | 0) >> 2] = HEAP32[($1_1 + 48 | 0) >> 2] | 0;
     HEAP32[($2_1 + 52 | 0) >> 2] = HEAP32[($1_1 + 52 | 0) >> 2] | 0;
     HEAP32[($2_1 + 56 | 0) >> 2] = HEAP32[($1_1 + 56 | 0) >> 2] | 0;
     HEAP32[($2_1 + 60 | 0) >> 2] = HEAP32[($1_1 + 60 | 0) >> 2] | 0;
     $1_1 = $1_1 + 64 | 0;
     $2_1 = $2_1 + 64 | 0;
     if ($2_1 >>> 0 <= $5_1 >>> 0) {
      continue label$9
     }
     break label$9;
    };
   }
   if ($2_1 >>> 0 >= $4_1 >>> 0) {
    break label$1
   }
   label$10 : while (1) {
    HEAP32[$2_1 >> 2] = HEAP32[$1_1 >> 2] | 0;
    $1_1 = $1_1 + 4 | 0;
    $2_1 = $2_1 + 4 | 0;
    if ($2_1 >>> 0 < $4_1 >>> 0) {
     continue label$10
    }
    break label$10;
   };
  }
  label$11 : {
   if ($2_1 >>> 0 >= $3_1 >>> 0) {
    break label$11
   }
   label$12 : while (1) {
    HEAP8[$2_1 >> 0] = HEAPU8[$1_1 >> 0] | 0;
    $1_1 = $1_1 + 1 | 0;
    $2_1 = $2_1 + 1 | 0;
    if (($2_1 | 0) != ($3_1 | 0)) {
     continue label$12
    }
    break label$12;
   };
  }
  return $0_1 | 0;
 }
 
 function $19($0_1) {
  $0_1 = $0_1 | 0;
  return 0 | 0;
 }
 
 function $20($0_1) {
  $0_1 = $0_1 | 0;
 }
 
 function $21() {
  $20(68028 | 0);
  return 68032 | 0;
 }
 
 function $22() {
  var $0_1 = 0;
  label$1 : {
   $0_1 = HEAP32[($21() | 0) >> 2] | 0;
   if (!$0_1) {
    break label$1
   }
   label$2 : while (1) {
    $23($0_1 | 0);
    $0_1 = HEAP32[($0_1 + 56 | 0) >> 2] | 0;
    if ($0_1) {
     continue label$2
    }
    break label$2;
   };
  }
  $23(HEAP32[(0 + 66984 | 0) >> 2] | 0 | 0);
  $23(HEAP32[(0 + 66832 | 0) >> 2] | 0 | 0);
  $23(HEAP32[(0 + 68036 | 0) >> 2] | 0 | 0);
 }
 
 function $23($0_1) {
  $0_1 = $0_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, $1_1 = 0, $2_1 = 0;
  label$1 : {
   if (!$0_1) {
    break label$1
   }
   label$2 : {
    if ((HEAP32[($0_1 + 76 | 0) >> 2] | 0 | 0) < (0 | 0)) {
     break label$2
    }
    $14($0_1 | 0) | 0;
   }
   label$3 : {
    if ((HEAP32[($0_1 + 20 | 0) >> 2] | 0 | 0) == (HEAP32[($0_1 + 28 | 0) >> 2] | 0 | 0)) {
     break label$3
    }
    FUNCTION_TABLE[HEAP32[($0_1 + 36 | 0) >> 2] | 0 | 0]($0_1, 0, 0) | 0;
   }
   $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
   $2_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
   if (($1_1 | 0) == ($2_1 | 0)) {
    break label$1
   }
   i64toi32_i32$1 = $1_1 - $2_1 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
   i64toi32_i32$0 = FUNCTION_TABLE[HEAP32[($0_1 + 40 | 0) >> 2] | 0 | 0]($0_1, i64toi32_i32$1, i64toi32_i32$0, 1) | 0;
   i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
  }
 }
 
 function $24($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0;
  $1_1 = HEAP32[($0_1 + 72 | 0) >> 2] | 0;
  HEAP32[($0_1 + 72 | 0) >> 2] = $1_1 + -1 | 0 | $1_1 | 0;
  label$1 : {
   $1_1 = HEAP32[$0_1 >> 2] | 0;
   if (!($1_1 & 8 | 0)) {
    break label$1
   }
   HEAP32[$0_1 >> 2] = $1_1 | 32 | 0;
   return -1 | 0;
  }
  HEAP32[($0_1 + 4 | 0) >> 2] = 0;
  HEAP32[($0_1 + 8 | 0) >> 2] = 0;
  $1_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
  HEAP32[($0_1 + 28 | 0) >> 2] = $1_1;
  HEAP32[($0_1 + 20 | 0) >> 2] = $1_1;
  HEAP32[($0_1 + 16 | 0) >> 2] = $1_1 + (HEAP32[($0_1 + 48 | 0) >> 2] | 0) | 0;
  return 0 | 0;
 }
 
 function $25($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0;
  $3_1 = ($2_1 | 0) != (0 | 0);
  label$1 : {
   label$2 : {
    label$3 : {
     if (!($0_1 & 3 | 0)) {
      break label$3
     }
     if (!$2_1) {
      break label$3
     }
     $4_1 = $1_1 & 255 | 0;
     label$4 : while (1) {
      if ((HEAPU8[$0_1 >> 0] | 0 | 0) == ($4_1 | 0)) {
       break label$2
      }
      $2_1 = $2_1 + -1 | 0;
      $3_1 = ($2_1 | 0) != (0 | 0);
      $0_1 = $0_1 + 1 | 0;
      if (!($0_1 & 3 | 0)) {
       break label$3
      }
      if ($2_1) {
       continue label$4
      }
      break label$4;
     };
    }
    if (!$3_1) {
     break label$1
    }
    label$5 : {
     if ((HEAPU8[$0_1 >> 0] | 0 | 0) == ($1_1 & 255 | 0 | 0)) {
      break label$5
     }
     if ($2_1 >>> 0 < 4 >>> 0) {
      break label$5
     }
     $4_1 = Math_imul($1_1 & 255 | 0, 16843009);
     label$6 : while (1) {
      $3_1 = (HEAP32[$0_1 >> 2] | 0) ^ $4_1 | 0;
      if ((($3_1 ^ -1 | 0) & ($3_1 + -16843009 | 0) | 0) & -2139062144 | 0) {
       break label$2
      }
      $0_1 = $0_1 + 4 | 0;
      $2_1 = $2_1 + -4 | 0;
      if ($2_1 >>> 0 > 3 >>> 0) {
       continue label$6
      }
      break label$6;
     };
    }
    if (!$2_1) {
     break label$1
    }
   }
   $3_1 = $1_1 & 255 | 0;
   label$7 : while (1) {
    label$8 : {
     if ((HEAPU8[$0_1 >> 0] | 0 | 0) != ($3_1 | 0)) {
      break label$8
     }
     return $0_1 | 0;
    }
    $0_1 = $0_1 + 1 | 0;
    $2_1 = $2_1 + -1 | 0;
    if ($2_1) {
     continue label$7
    }
    break label$7;
   };
  }
  return 0 | 0;
 }
 
 function $26($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0;
  $2_1 = $25($0_1 | 0, 0 | 0, $1_1 | 0) | 0;
  return ($2_1 ? $2_1 - $0_1 | 0 : $1_1) | 0;
 }
 
 function $27($0_1, $1_1) {
  $0_1 = +$0_1;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $3_1 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, $2_1 = 0, $10_1 = 0, $2$hi = 0;
  label$1 : {
   wasm2js_scratch_store_f64(+$0_1);
   i64toi32_i32$0 = wasm2js_scratch_load_i32(1 | 0) | 0;
   $2_1 = wasm2js_scratch_load_i32(0 | 0) | 0;
   $2$hi = i64toi32_i32$0;
   i64toi32_i32$2 = $2_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 52;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $10_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    $10_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
   }
   $3_1 = $10_1 & 2047 | 0;
   if (($3_1 | 0) == (2047 | 0)) {
    break label$1
   }
   label$2 : {
    if ($3_1) {
     break label$2
    }
    label$3 : {
     label$4 : {
      if ($0_1 != 0.0) {
       break label$4
      }
      $3_1 = 0;
      break label$3;
     }
     $0_1 = +$27(+($0_1 * 18446744073709551615.0), $1_1 | 0);
     $3_1 = (HEAP32[$1_1 >> 2] | 0) + -64 | 0;
    }
    HEAP32[$1_1 >> 2] = $3_1;
    return +$0_1;
   }
   HEAP32[$1_1 >> 2] = $3_1 + -1022 | 0;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$0 = $2_1;
   i64toi32_i32$2 = -2146435073;
   i64toi32_i32$3 = -1;
   i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
   i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
   i64toi32_i32$0 = 1071644672;
   i64toi32_i32$3 = 0;
   i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
   wasm2js_scratch_store_i32(0 | 0, i64toi32_i32$1 | i64toi32_i32$3 | 0 | 0);
   wasm2js_scratch_store_i32(1 | 0, i64toi32_i32$0 | 0);
   $0_1 = +wasm2js_scratch_load_f64();
  }
  return +$0_1;
 }
 
 function $28($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0;
  label$1 : {
   label$2 : {
    $3_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
    if ($3_1) {
     break label$2
    }
    $4_1 = 0;
    if ($24($2_1 | 0) | 0) {
     break label$1
    }
    $3_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
   }
   label$3 : {
    $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
    if (($3_1 - $4_1 | 0) >>> 0 >= $1_1 >>> 0) {
     break label$3
    }
    return FUNCTION_TABLE[HEAP32[($2_1 + 36 | 0) >> 2] | 0 | 0]($2_1, $0_1, $1_1) | 0 | 0;
   }
   label$4 : {
    label$5 : {
     if ((HEAP32[($2_1 + 80 | 0) >> 2] | 0 | 0) < (0 | 0)) {
      break label$5
     }
     if (!$1_1) {
      break label$5
     }
     $3_1 = $1_1;
     label$6 : {
      label$7 : while (1) {
       $5_1 = $0_1 + $3_1 | 0;
       if ((HEAPU8[($5_1 + -1 | 0) >> 0] | 0 | 0) == (10 | 0)) {
        break label$6
       }
       $3_1 = $3_1 + -1 | 0;
       if (!$3_1) {
        break label$5
       }
       continue label$7;
      };
     }
     $4_1 = FUNCTION_TABLE[HEAP32[($2_1 + 36 | 0) >> 2] | 0 | 0]($2_1, $0_1, $3_1) | 0;
     if ($4_1 >>> 0 < $3_1 >>> 0) {
      break label$1
     }
     $1_1 = $1_1 - $3_1 | 0;
     $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
     break label$4;
    }
    $5_1 = $0_1;
    $3_1 = 0;
   }
   $18($4_1 | 0, $5_1 | 0, $1_1 | 0) | 0;
   HEAP32[($2_1 + 20 | 0) >> 2] = (HEAP32[($2_1 + 20 | 0) >> 2] | 0) + $1_1 | 0;
   $4_1 = $3_1 + $1_1 | 0;
  }
  return $4_1 | 0;
 }
 
 function $29($0_1, $1_1, $2_1, $3_1, $4_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  var $5_1 = 0, i64toi32_i32$0 = 0, $8_1 = 0, $6_1 = 0, $7_1 = 0;
  $5_1 = global$0 - 208 | 0;
  global$0 = $5_1;
  HEAP32[($5_1 + 204 | 0) >> 2] = $2_1;
  $13($5_1 + 160 | 0 | 0, 0 | 0, 40 | 0) | 0;
  HEAP32[($5_1 + 200 | 0) >> 2] = HEAP32[($5_1 + 204 | 0) >> 2] | 0;
  label$1 : {
   label$2 : {
    if (($30(0 | 0, $1_1 | 0, $5_1 + 200 | 0 | 0, $5_1 + 80 | 0 | 0, $5_1 + 160 | 0 | 0, $3_1 | 0, $4_1 | 0) | 0 | 0) >= (0 | 0)) {
     break label$2
    }
    $4_1 = -1;
    break label$1;
   }
   label$3 : {
    label$4 : {
     if ((HEAP32[($0_1 + 76 | 0) >> 2] | 0 | 0) >= (0 | 0)) {
      break label$4
     }
     $6_1 = 1;
     break label$3;
    }
    $6_1 = !($14($0_1 | 0) | 0);
   }
   $7_1 = HEAP32[$0_1 >> 2] | 0;
   HEAP32[$0_1 >> 2] = $7_1 & -33 | 0;
   label$5 : {
    label$6 : {
     label$7 : {
      label$8 : {
       if (HEAP32[($0_1 + 48 | 0) >> 2] | 0) {
        break label$8
       }
       HEAP32[($0_1 + 48 | 0) >> 2] = 80;
       HEAP32[($0_1 + 28 | 0) >> 2] = 0;
       i64toi32_i32$0 = 0;
       HEAP32[($0_1 + 16 | 0) >> 2] = 0;
       HEAP32[($0_1 + 20 | 0) >> 2] = i64toi32_i32$0;
       $8_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
       HEAP32[($0_1 + 44 | 0) >> 2] = $5_1;
       break label$7;
      }
      $8_1 = 0;
      if (HEAP32[($0_1 + 16 | 0) >> 2] | 0) {
       break label$6
      }
     }
     $2_1 = -1;
     if ($24($0_1 | 0) | 0) {
      break label$5
     }
    }
    $2_1 = $30($0_1 | 0, $1_1 | 0, $5_1 + 200 | 0 | 0, $5_1 + 80 | 0 | 0, $5_1 + 160 | 0 | 0, $3_1 | 0, $4_1 | 0) | 0;
   }
   $4_1 = $7_1 & 32 | 0;
   label$9 : {
    if (!$8_1) {
     break label$9
    }
    FUNCTION_TABLE[HEAP32[($0_1 + 36 | 0) >> 2] | 0 | 0]($0_1, 0, 0) | 0;
    HEAP32[($0_1 + 48 | 0) >> 2] = 0;
    HEAP32[($0_1 + 44 | 0) >> 2] = $8_1;
    HEAP32[($0_1 + 28 | 0) >> 2] = 0;
    $3_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
    i64toi32_i32$0 = 0;
    HEAP32[($0_1 + 16 | 0) >> 2] = 0;
    HEAP32[($0_1 + 20 | 0) >> 2] = i64toi32_i32$0;
    $2_1 = $3_1 ? $2_1 : -1;
   }
   $3_1 = HEAP32[$0_1 >> 2] | 0;
   HEAP32[$0_1 >> 2] = $3_1 | $4_1 | 0;
   $4_1 = $3_1 & 32 | 0 ? -1 : $2_1;
   if ($6_1) {
    break label$1
   }
   $15($0_1 | 0);
  }
  global$0 = $5_1 + 208 | 0;
  return $4_1 | 0;
 }
 
 function $30($0_1, $1_1, $2_1, $3_1, $4_1, $5_1, $6_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  $5_1 = $5_1 | 0;
  $6_1 = $6_1 | 0;
  var $12_1 = 0, $7_1 = 0, $15_1 = 0, $20_1 = 0, i64toi32_i32$1 = 0, $17_1 = 0, $14_1 = 0, $13_1 = 0, i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, $11_1 = 0, $16_1 = 0, $19_1 = 0, $22_1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$5 = 0, $9_1 = 0, $18_1 = 0, $24_1 = 0, $10_1 = 0, $25_1 = 0, $25$hi = 0, $21_1 = 0, $23_1 = 0, $33_1 = 0, $34_1 = 0, $35_1 = 0, $8_1 = 0, $266 = 0;
  $7_1 = global$0 - 80 | 0;
  global$0 = $7_1;
  HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
  $8_1 = $7_1 + 55 | 0;
  $9_1 = $7_1 + 56 | 0;
  $10_1 = 0;
  $11_1 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : while (1) {
       $12_1 = 0;
       label$6 : while (1) {
        $13_1 = $1_1;
        if (($12_1 | 0) > ($11_1 ^ 2147483647 | 0 | 0)) {
         break label$4
        }
        $11_1 = $12_1 + $11_1 | 0;
        $12_1 = $1_1;
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             $14_1 = HEAPU8[$12_1 >> 0] | 0;
             if (!$14_1) {
              break label$11
             }
             label$12 : while (1) {
              label$13 : {
               label$14 : {
                label$15 : {
                 $14_1 = $14_1 & 255 | 0;
                 if ($14_1) {
                  break label$15
                 }
                 $1_1 = $12_1;
                 break label$14;
                }
                if (($14_1 | 0) != (37 | 0)) {
                 break label$13
                }
                $14_1 = $12_1;
                label$16 : while (1) {
                 label$17 : {
                  if ((HEAPU8[($14_1 + 1 | 0) >> 0] | 0 | 0) == (37 | 0)) {
                   break label$17
                  }
                  $1_1 = $14_1;
                  break label$14;
                 }
                 $12_1 = $12_1 + 1 | 0;
                 $15_1 = HEAPU8[($14_1 + 2 | 0) >> 0] | 0;
                 $1_1 = $14_1 + 2 | 0;
                 $14_1 = $1_1;
                 if (($15_1 | 0) == (37 | 0)) {
                  continue label$16
                 }
                 break label$16;
                };
               }
               $12_1 = $12_1 - $13_1 | 0;
               $14_1 = $11_1 ^ 2147483647 | 0;
               if (($12_1 | 0) > ($14_1 | 0)) {
                break label$4
               }
               label$18 : {
                if (!$0_1) {
                 break label$18
                }
                $31($0_1 | 0, $13_1 | 0, $12_1 | 0);
               }
               if ($12_1) {
                continue label$6
               }
               HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
               $12_1 = $1_1 + 1 | 0;
               $16_1 = -1;
               label$19 : {
                $15_1 = (HEAP8[($1_1 + 1 | 0) >> 0] | 0) + -48 | 0;
                if ($15_1 >>> 0 > 9 >>> 0) {
                 break label$19
                }
                if ((HEAPU8[($1_1 + 2 | 0) >> 0] | 0 | 0) != (36 | 0)) {
                 break label$19
                }
                $12_1 = $1_1 + 3 | 0;
                $10_1 = 1;
                $16_1 = $15_1;
               }
               HEAP32[($7_1 + 76 | 0) >> 2] = $12_1;
               $17_1 = 0;
               label$20 : {
                label$21 : {
                 $18_1 = HEAP8[$12_1 >> 0] | 0;
                 $1_1 = $18_1 + -32 | 0;
                 if ($1_1 >>> 0 <= 31 >>> 0) {
                  break label$21
                 }
                 $15_1 = $12_1;
                 break label$20;
                }
                $17_1 = 0;
                $15_1 = $12_1;
                $1_1 = 1 << $1_1 | 0;
                if (!($1_1 & 75913 | 0)) {
                 break label$20
                }
                label$22 : while (1) {
                 $15_1 = $12_1 + 1 | 0;
                 HEAP32[($7_1 + 76 | 0) >> 2] = $15_1;
                 $17_1 = $1_1 | $17_1 | 0;
                 $18_1 = HEAP8[($12_1 + 1 | 0) >> 0] | 0;
                 $1_1 = $18_1 + -32 | 0;
                 if ($1_1 >>> 0 >= 32 >>> 0) {
                  break label$20
                 }
                 $12_1 = $15_1;
                 $1_1 = 1 << $1_1 | 0;
                 if ($1_1 & 75913 | 0) {
                  continue label$22
                 }
                 break label$22;
                };
               }
               label$23 : {
                label$24 : {
                 if (($18_1 | 0) != (42 | 0)) {
                  break label$24
                 }
                 label$25 : {
                  label$26 : {
                   $12_1 = (HEAP8[($15_1 + 1 | 0) >> 0] | 0) + -48 | 0;
                   if ($12_1 >>> 0 > 9 >>> 0) {
                    break label$26
                   }
                   if ((HEAPU8[($15_1 + 2 | 0) >> 0] | 0 | 0) != (36 | 0)) {
                    break label$26
                   }
                   label$27 : {
                    label$28 : {
                     if ($0_1) {
                      break label$28
                     }
                     HEAP32[($4_1 + ($12_1 << 2 | 0) | 0) >> 2] = 10;
                     $19_1 = 0;
                     break label$27;
                    }
                    $19_1 = HEAP32[($3_1 + ($12_1 << 3 | 0) | 0) >> 2] | 0;
                   }
                   $1_1 = $15_1 + 3 | 0;
                   $10_1 = 1;
                   break label$25;
                  }
                  if ($10_1) {
                   break label$10
                  }
                  $1_1 = $15_1 + 1 | 0;
                  label$29 : {
                   if ($0_1) {
                    break label$29
                   }
                   HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
                   $10_1 = 0;
                   $19_1 = 0;
                   break label$23;
                  }
                  $12_1 = HEAP32[$2_1 >> 2] | 0;
                  HEAP32[$2_1 >> 2] = $12_1 + 4 | 0;
                  $19_1 = HEAP32[$12_1 >> 2] | 0;
                  $10_1 = 0;
                 }
                 HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
                 if (($19_1 | 0) > (-1 | 0)) {
                  break label$23
                 }
                 $19_1 = 0 - $19_1 | 0;
                 $17_1 = $17_1 | 8192 | 0;
                 break label$23;
                }
                $19_1 = $32($7_1 + 76 | 0 | 0) | 0;
                if (($19_1 | 0) < (0 | 0)) {
                 break label$4
                }
                $1_1 = HEAP32[($7_1 + 76 | 0) >> 2] | 0;
               }
               $12_1 = 0;
               $20_1 = -1;
               label$30 : {
                label$31 : {
                 if ((HEAPU8[$1_1 >> 0] | 0 | 0) == (46 | 0)) {
                  break label$31
                 }
                 $21_1 = 0;
                 break label$30;
                }
                label$32 : {
                 if ((HEAPU8[($1_1 + 1 | 0) >> 0] | 0 | 0) != (42 | 0)) {
                  break label$32
                 }
                 label$33 : {
                  label$34 : {
                   $15_1 = (HEAP8[($1_1 + 2 | 0) >> 0] | 0) + -48 | 0;
                   if ($15_1 >>> 0 > 9 >>> 0) {
                    break label$34
                   }
                   if ((HEAPU8[($1_1 + 3 | 0) >> 0] | 0 | 0) != (36 | 0)) {
                    break label$34
                   }
                   label$35 : {
                    label$36 : {
                     if ($0_1) {
                      break label$36
                     }
                     HEAP32[($4_1 + ($15_1 << 2 | 0) | 0) >> 2] = 10;
                     $20_1 = 0;
                     break label$35;
                    }
                    $20_1 = HEAP32[($3_1 + ($15_1 << 3 | 0) | 0) >> 2] | 0;
                   }
                   $1_1 = $1_1 + 4 | 0;
                   break label$33;
                  }
                  if ($10_1) {
                   break label$10
                  }
                  $1_1 = $1_1 + 2 | 0;
                  label$37 : {
                   if ($0_1) {
                    break label$37
                   }
                   $20_1 = 0;
                   break label$33;
                  }
                  $15_1 = HEAP32[$2_1 >> 2] | 0;
                  HEAP32[$2_1 >> 2] = $15_1 + 4 | 0;
                  $20_1 = HEAP32[$15_1 >> 2] | 0;
                 }
                 HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
                 $21_1 = ($20_1 | 0) > (-1 | 0);
                 break label$30;
                }
                HEAP32[($7_1 + 76 | 0) >> 2] = $1_1 + 1 | 0;
                $21_1 = 1;
                $20_1 = $32($7_1 + 76 | 0 | 0) | 0;
                $1_1 = HEAP32[($7_1 + 76 | 0) >> 2] | 0;
               }
               label$38 : while (1) {
                $15_1 = $12_1;
                $22_1 = 28;
                $18_1 = $1_1;
                $12_1 = HEAP8[$1_1 >> 0] | 0;
                if (($12_1 + -123 | 0) >>> 0 < -58 >>> 0) {
                 break label$3
                }
                $1_1 = $1_1 + 1 | 0;
                $12_1 = HEAPU8[(($12_1 + Math_imul($15_1, 58) | 0) + 65583 | 0) >> 0] | 0;
                if (($12_1 + -1 | 0) >>> 0 < 8 >>> 0) {
                 continue label$38
                }
                break label$38;
               };
               HEAP32[($7_1 + 76 | 0) >> 2] = $1_1;
               label$39 : {
                label$40 : {
                 if (($12_1 | 0) == (27 | 0)) {
                  break label$40
                 }
                 if (!$12_1) {
                  break label$3
                 }
                 label$41 : {
                  if (($16_1 | 0) < (0 | 0)) {
                   break label$41
                  }
                  label$42 : {
                   if ($0_1) {
                    break label$42
                   }
                   HEAP32[($4_1 + ($16_1 << 2 | 0) | 0) >> 2] = $12_1;
                   continue label$5;
                  }
                  i64toi32_i32$2 = $3_1 + ($16_1 << 3 | 0) | 0;
                  i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
                  i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
                  $266 = i64toi32_i32$0;
                  i64toi32_i32$0 = $7_1;
                  HEAP32[($7_1 + 64 | 0) >> 2] = $266;
                  HEAP32[($7_1 + 68 | 0) >> 2] = i64toi32_i32$1;
                  break label$39;
                 }
                 if (!$0_1) {
                  break label$7
                 }
                 $33($7_1 + 64 | 0 | 0, $12_1 | 0, $2_1 | 0, $6_1 | 0);
                 break label$39;
                }
                if (($16_1 | 0) > (-1 | 0)) {
                 break label$3
                }
                $12_1 = 0;
                if (!$0_1) {
                 continue label$6
                }
               }
               if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) {
                break label$2
               }
               $23_1 = $17_1 & -65537 | 0;
               $17_1 = $17_1 & 8192 | 0 ? $23_1 : $17_1;
               $16_1 = 0;
               $24_1 = 65545;
               $22_1 = $9_1;
               label$43 : {
                label$44 : {
                 label$45 : {
                  label$46 : {
                   label$47 : {
                    label$48 : {
                     label$49 : {
                      label$50 : {
                       label$51 : {
                        label$52 : {
                         label$53 : {
                          label$54 : {
                           label$55 : {
                            label$56 : {
                             label$57 : {
                              label$58 : {
                               $12_1 = HEAP8[$18_1 >> 0] | 0;
                               $12_1 = $15_1 ? (($12_1 & 15 | 0 | 0) == (3 | 0) ? $12_1 & -45 | 0 : $12_1) : $12_1;
                               switch ($12_1 + -88 | 0 | 0) {
                               case 11:
                                break label$43;
                               case 9:
                               case 13:
                               case 14:
                               case 15:
                                break label$44;
                               case 27:
                                break label$49;
                               case 12:
                               case 17:
                                break label$52;
                               case 23:
                                break label$53;
                               case 0:
                               case 32:
                                break label$54;
                               case 24:
                                break label$55;
                               case 22:
                                break label$56;
                               case 29:
                                break label$57;
                               case 1:
                               case 2:
                               case 3:
                               case 4:
                               case 5:
                               case 6:
                               case 7:
                               case 8:
                               case 10:
                               case 16:
                               case 18:
                               case 19:
                               case 20:
                               case 21:
                               case 25:
                               case 26:
                               case 28:
                               case 30:
                               case 31:
                                break label$8;
                               default:
                                break label$58;
                               };
                              }
                              $22_1 = $9_1;
                              label$59 : {
                               switch ($12_1 + -65 | 0 | 0) {
                               case 0:
                               case 4:
                               case 5:
                               case 6:
                                break label$44;
                               case 2:
                                break label$47;
                               case 1:
                               case 3:
                                break label$8;
                               default:
                                break label$59;
                               };
                              }
                              if (($12_1 | 0) == (83 | 0)) {
                               break label$48
                              }
                              break label$9;
                             }
                             $16_1 = 0;
                             $24_1 = 65545;
                             i64toi32_i32$2 = $7_1;
                             i64toi32_i32$1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                             i64toi32_i32$0 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                             $25_1 = i64toi32_i32$1;
                             $25$hi = i64toi32_i32$0;
                             break label$51;
                            }
                            $12_1 = 0;
                            label$60 : {
                             switch ($15_1 & 255 | 0 | 0) {
                             case 0:
                              HEAP32[(HEAP32[($7_1 + 64 | 0) >> 2] | 0) >> 2] = $11_1;
                              continue label$6;
                             case 1:
                              HEAP32[(HEAP32[($7_1 + 64 | 0) >> 2] | 0) >> 2] = $11_1;
                              continue label$6;
                             case 2:
                              i64toi32_i32$1 = $11_1;
                              i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
                              i64toi32_i32$1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                              HEAP32[i64toi32_i32$1 >> 2] = $11_1;
                              HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
                              continue label$6;
                             case 3:
                              HEAP16[(HEAP32[($7_1 + 64 | 0) >> 2] | 0) >> 1] = $11_1;
                              continue label$6;
                             case 4:
                              HEAP8[(HEAP32[($7_1 + 64 | 0) >> 2] | 0) >> 0] = $11_1;
                              continue label$6;
                             case 6:
                              HEAP32[(HEAP32[($7_1 + 64 | 0) >> 2] | 0) >> 2] = $11_1;
                              continue label$6;
                             case 7:
                              break label$60;
                             default:
                              continue label$6;
                             };
                            }
                            i64toi32_i32$1 = $11_1;
                            i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
                            i64toi32_i32$1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                            HEAP32[i64toi32_i32$1 >> 2] = $11_1;
                            HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
                            continue label$6;
                           }
                           $20_1 = $20_1 >>> 0 > 8 >>> 0 ? $20_1 : 8;
                           $17_1 = $17_1 | 8 | 0;
                           $12_1 = 120;
                          }
                          i64toi32_i32$2 = $7_1;
                          i64toi32_i32$0 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                          i64toi32_i32$1 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                          $13_1 = $34(i64toi32_i32$0 | 0, i64toi32_i32$1 | 0, $9_1 | 0, $12_1 & 32 | 0 | 0) | 0;
                          $16_1 = 0;
                          $24_1 = 65545;
                          i64toi32_i32$2 = $7_1;
                          i64toi32_i32$1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                          i64toi32_i32$0 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                          if (!(i64toi32_i32$1 | i64toi32_i32$0 | 0)) {
                           break label$50
                          }
                          if (!($17_1 & 8 | 0)) {
                           break label$50
                          }
                          $24_1 = ($12_1 >>> 4 | 0) + 65545 | 0;
                          $16_1 = 2;
                          break label$50;
                         }
                         $16_1 = 0;
                         $24_1 = 65545;
                         i64toi32_i32$2 = $7_1;
                         i64toi32_i32$0 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                         i64toi32_i32$1 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                         $13_1 = $35(i64toi32_i32$0 | 0, i64toi32_i32$1 | 0, $9_1 | 0) | 0;
                         if (!($17_1 & 8 | 0)) {
                          break label$50
                         }
                         $12_1 = $9_1 - $13_1 | 0;
                         $20_1 = ($20_1 | 0) > ($12_1 | 0) ? $20_1 : $12_1 + 1 | 0;
                         break label$50;
                        }
                        label$67 : {
                         i64toi32_i32$2 = $7_1;
                         i64toi32_i32$1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                         i64toi32_i32$0 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                         $25_1 = i64toi32_i32$1;
                         $25$hi = i64toi32_i32$0;
                         i64toi32_i32$2 = i64toi32_i32$1;
                         i64toi32_i32$1 = -1;
                         i64toi32_i32$3 = -1;
                         if ((i64toi32_i32$0 | 0) > (i64toi32_i32$1 | 0)) {
                          $33_1 = 1
                         } else {
                          if ((i64toi32_i32$0 | 0) >= (i64toi32_i32$1 | 0)) {
                           if (i64toi32_i32$2 >>> 0 <= i64toi32_i32$3 >>> 0) {
                            $34_1 = 0
                           } else {
                            $34_1 = 1
                           }
                           $35_1 = $34_1;
                          } else {
                           $35_1 = 0
                          }
                          $33_1 = $35_1;
                         }
                         if ($33_1) {
                          break label$67
                         }
                         i64toi32_i32$2 = $25$hi;
                         i64toi32_i32$2 = 0;
                         i64toi32_i32$3 = 0;
                         i64toi32_i32$0 = $25$hi;
                         i64toi32_i32$1 = $25_1;
                         i64toi32_i32$5 = (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) + i64toi32_i32$0 | 0;
                         i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
                         $25_1 = i64toi32_i32$3 - i64toi32_i32$1 | 0;
                         $25$hi = i64toi32_i32$5;
                         i64toi32_i32$3 = $7_1;
                         HEAP32[($7_1 + 64 | 0) >> 2] = $25_1;
                         HEAP32[($7_1 + 68 | 0) >> 2] = i64toi32_i32$5;
                         $16_1 = 1;
                         $24_1 = 65545;
                         break label$51;
                        }
                        label$68 : {
                         if (!($17_1 & 2048 | 0)) {
                          break label$68
                         }
                         $16_1 = 1;
                         $24_1 = 65546;
                         break label$51;
                        }
                        $16_1 = $17_1 & 1 | 0;
                        $24_1 = $16_1 ? 65547 : 65545;
                       }
                       i64toi32_i32$5 = $25$hi;
                       $13_1 = $36($25_1 | 0, i64toi32_i32$5 | 0, $9_1 | 0) | 0;
                      }
                      if ($21_1 & ($20_1 | 0) < (0 | 0) | 0) {
                       break label$4
                      }
                      $17_1 = $21_1 ? $17_1 & -65537 | 0 : $17_1;
                      label$69 : {
                       i64toi32_i32$2 = $7_1;
                       i64toi32_i32$5 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                       i64toi32_i32$3 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                       $25_1 = i64toi32_i32$5;
                       $25$hi = i64toi32_i32$3;
                       i64toi32_i32$2 = i64toi32_i32$5;
                       i64toi32_i32$5 = 0;
                       i64toi32_i32$1 = 0;
                       if ((i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$5 | 0) | 0) {
                        break label$69
                       }
                       if ($20_1) {
                        break label$69
                       }
                       $13_1 = $9_1;
                       $22_1 = $13_1;
                       $20_1 = 0;
                       break label$8;
                      }
                      i64toi32_i32$2 = $25$hi;
                      $12_1 = ($9_1 - $13_1 | 0) + !($25_1 | i64toi32_i32$2 | 0) | 0;
                      $20_1 = ($20_1 | 0) > ($12_1 | 0) ? $20_1 : $12_1;
                      break label$9;
                     }
                     $12_1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                     $13_1 = $12_1 ? $12_1 : 65595;
                     $12_1 = $26($13_1 | 0, ($20_1 >>> 0 < 2147483647 >>> 0 ? $20_1 : 2147483647) | 0) | 0;
                     $22_1 = $13_1 + $12_1 | 0;
                     label$70 : {
                      if (($20_1 | 0) <= (-1 | 0)) {
                       break label$70
                      }
                      $17_1 = $23_1;
                      $20_1 = $12_1;
                      break label$8;
                     }
                     $17_1 = $23_1;
                     $20_1 = $12_1;
                     if (HEAPU8[$22_1 >> 0] | 0) {
                      break label$4
                     }
                     break label$8;
                    }
                    label$71 : {
                     if (!$20_1) {
                      break label$71
                     }
                     $14_1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                     break label$46;
                    }
                    $12_1 = 0;
                    $37($0_1 | 0, 32 | 0, $19_1 | 0, 0 | 0, $17_1 | 0);
                    break label$45;
                   }
                   HEAP32[($7_1 + 12 | 0) >> 2] = 0;
                   i64toi32_i32$1 = $7_1;
                   i64toi32_i32$2 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                   i64toi32_i32$3 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
                   HEAP32[($7_1 + 8 | 0) >> 2] = i64toi32_i32$2;
                   HEAP32[($7_1 + 64 | 0) >> 2] = $7_1 + 8 | 0;
                   $14_1 = $7_1 + 8 | 0;
                   $20_1 = -1;
                  }
                  $12_1 = 0;
                  label$72 : {
                   label$73 : while (1) {
                    $15_1 = HEAP32[$14_1 >> 2] | 0;
                    if (!$15_1) {
                     break label$72
                    }
                    $15_1 = $77($7_1 + 4 | 0 | 0, $15_1 | 0) | 0;
                    if (($15_1 | 0) < (0 | 0)) {
                     break label$2
                    }
                    if ($15_1 >>> 0 > ($20_1 - $12_1 | 0) >>> 0) {
                     break label$72
                    }
                    $14_1 = $14_1 + 4 | 0;
                    $12_1 = $15_1 + $12_1 | 0;
                    if ($12_1 >>> 0 < $20_1 >>> 0) {
                     continue label$73
                    }
                    break label$73;
                   };
                  }
                  $22_1 = 61;
                  if (($12_1 | 0) < (0 | 0)) {
                   break label$3
                  }
                  $37($0_1 | 0, 32 | 0, $19_1 | 0, $12_1 | 0, $17_1 | 0);
                  label$74 : {
                   if ($12_1) {
                    break label$74
                   }
                   $12_1 = 0;
                   break label$45;
                  }
                  $15_1 = 0;
                  $14_1 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
                  label$75 : while (1) {
                   $13_1 = HEAP32[$14_1 >> 2] | 0;
                   if (!$13_1) {
                    break label$45
                   }
                   $13_1 = $77($7_1 + 4 | 0 | 0, $13_1 | 0) | 0;
                   $15_1 = $13_1 + $15_1 | 0;
                   if ($15_1 >>> 0 > $12_1 >>> 0) {
                    break label$45
                   }
                   $31($0_1 | 0, $7_1 + 4 | 0 | 0, $13_1 | 0);
                   $14_1 = $14_1 + 4 | 0;
                   if ($15_1 >>> 0 < $12_1 >>> 0) {
                    continue label$75
                   }
                   break label$75;
                  };
                 }
                 $37($0_1 | 0, 32 | 0, $19_1 | 0, $12_1 | 0, $17_1 ^ 8192 | 0 | 0);
                 $12_1 = ($19_1 | 0) > ($12_1 | 0) ? $19_1 : $12_1;
                 continue label$6;
                }
                if ($21_1 & ($20_1 | 0) < (0 | 0) | 0) {
                 break label$4
                }
                $22_1 = 61;
                $12_1 = FUNCTION_TABLE[$5_1 | 0]($0_1, +HEAPF64[($7_1 + 64 | 0) >> 3], $19_1, $20_1, $17_1, $12_1) | 0;
                if (($12_1 | 0) >= (0 | 0)) {
                 continue label$6
                }
                break label$3;
               }
               i64toi32_i32$1 = $7_1;
               i64toi32_i32$3 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
               i64toi32_i32$2 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
               HEAP8[($7_1 + 55 | 0) >> 0] = i64toi32_i32$3;
               $20_1 = 1;
               $13_1 = $8_1;
               $22_1 = $9_1;
               $17_1 = $23_1;
               break label$8;
              }
              $14_1 = HEAPU8[($12_1 + 1 | 0) >> 0] | 0;
              $12_1 = $12_1 + 1 | 0;
              continue label$12;
             };
            }
            if ($0_1) {
             break label$1
            }
            if (!$10_1) {
             break label$7
            }
            $12_1 = 1;
            label$76 : {
             label$77 : while (1) {
              $14_1 = HEAP32[($4_1 + ($12_1 << 2 | 0) | 0) >> 2] | 0;
              if (!$14_1) {
               break label$76
              }
              $33($3_1 + ($12_1 << 3 | 0) | 0 | 0, $14_1 | 0, $2_1 | 0, $6_1 | 0);
              $11_1 = 1;
              $12_1 = $12_1 + 1 | 0;
              if (($12_1 | 0) != (10 | 0)) {
               continue label$77
              }
              break label$1;
             };
            }
            $11_1 = 1;
            if ($12_1 >>> 0 >= 10 >>> 0) {
             break label$1
            }
            label$78 : while (1) {
             if (HEAP32[($4_1 + ($12_1 << 2 | 0) | 0) >> 2] | 0) {
              break label$10
             }
             $11_1 = 1;
             $12_1 = $12_1 + 1 | 0;
             if (($12_1 | 0) == (10 | 0)) {
              break label$1
             }
             continue label$78;
            };
           }
           $22_1 = 28;
           break label$3;
          }
          $22_1 = $9_1;
         }
         $1_1 = $22_1 - $13_1 | 0;
         $18_1 = ($20_1 | 0) > ($1_1 | 0) ? $20_1 : $1_1;
         if (($18_1 | 0) > ($16_1 ^ 2147483647 | 0 | 0)) {
          break label$4
         }
         $22_1 = 61;
         $15_1 = $16_1 + $18_1 | 0;
         $12_1 = ($19_1 | 0) > ($15_1 | 0) ? $19_1 : $15_1;
         if (($12_1 | 0) > ($14_1 | 0)) {
          break label$3
         }
         $37($0_1 | 0, 32 | 0, $12_1 | 0, $15_1 | 0, $17_1 | 0);
         $31($0_1 | 0, $24_1 | 0, $16_1 | 0);
         $37($0_1 | 0, 48 | 0, $12_1 | 0, $15_1 | 0, $17_1 ^ 65536 | 0 | 0);
         $37($0_1 | 0, 48 | 0, $18_1 | 0, $1_1 | 0, 0 | 0);
         $31($0_1 | 0, $13_1 | 0, $1_1 | 0);
         $37($0_1 | 0, 32 | 0, $12_1 | 0, $15_1 | 0, $17_1 ^ 8192 | 0 | 0);
         $1_1 = HEAP32[($7_1 + 76 | 0) >> 2] | 0;
         continue label$6;
        }
        break label$6;
       };
       break label$5;
      };
      $11_1 = 0;
      break label$1;
     }
     $22_1 = 61;
    }
    HEAP32[($16() | 0) >> 2] = $22_1;
   }
   $11_1 = -1;
  }
  global$0 = $7_1 + 80 | 0;
  return $11_1 | 0;
 }
 
 function $31($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  label$1 : {
   if ((HEAPU8[$0_1 >> 0] | 0) & 32 | 0) {
    break label$1
   }
   $28($1_1 | 0, $2_1 | 0, $0_1 | 0) | 0;
  }
 }
 
 function $32($0_1) {
  $0_1 = $0_1 | 0;
  var $3_1 = 0, $1_1 = 0, $2_1 = 0, $4_1 = 0, $5_1 = 0;
  $1_1 = 0;
  label$1 : {
   $2_1 = HEAP32[$0_1 >> 2] | 0;
   $3_1 = (HEAP8[$2_1 >> 0] | 0) + -48 | 0;
   if ($3_1 >>> 0 <= 9 >>> 0) {
    break label$1
   }
   return 0 | 0;
  }
  label$2 : while (1) {
   $4_1 = -1;
   label$3 : {
    if ($1_1 >>> 0 > 214748364 >>> 0) {
     break label$3
    }
    $1_1 = Math_imul($1_1, 10);
    $4_1 = $3_1 >>> 0 > ($1_1 ^ 2147483647 | 0) >>> 0 ? -1 : $3_1 + $1_1 | 0;
   }
   $3_1 = $2_1 + 1 | 0;
   HEAP32[$0_1 >> 2] = $3_1;
   $5_1 = HEAP8[($2_1 + 1 | 0) >> 0] | 0;
   $1_1 = $4_1;
   $2_1 = $3_1;
   $3_1 = $5_1 + -48 | 0;
   if ($3_1 >>> 0 < 10 >>> 0) {
    continue label$2
   }
   break label$2;
  };
  return $1_1 | 0;
 }
 
 function $33($0_1, $1_1, $2_1, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, $21_1 = 0, $29_1 = 0, $37_1 = 0, $45_1 = 0, $55_1 = 0, $63_1 = 0, $71_1 = 0, $79_1 = 0, $87_1 = 0, $97_1 = 0, $105_1 = 0, $115 = 0, $125 = 0, $133 = 0, $141 = 0;
  label$1 : {
   switch ($1_1 + -9 | 0 | 0) {
   case 0:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    HEAP32[$0_1 >> 2] = HEAP32[$1_1 >> 2] | 0;
    return;
   case 1:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
    $21_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $21_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 2:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$1 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = 0;
    $29_1 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $29_1;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 4:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
    $37_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $37_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 5:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$1 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = 0;
    $45_1 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $45_1;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 3:
    $1_1 = ((HEAP32[$2_1 >> 2] | 0) + 7 | 0) & -8 | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 8 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
    $55_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $55_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 6:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$1 = HEAP16[$1_1 >> 1] | 0;
    i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
    $63_1 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $63_1;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 7:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAPU16[$1_1 >> 1] | 0;
    i64toi32_i32$1 = 0;
    $71_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $71_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 8:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$1 = HEAP8[$1_1 >> 0] | 0;
    i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
    $79_1 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $79_1;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 9:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAPU8[$1_1 >> 0] | 0;
    i64toi32_i32$1 = 0;
    $87_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $87_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 10:
    $1_1 = ((HEAP32[$2_1 >> 2] | 0) + 7 | 0) & -8 | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 8 | 0;
    i64toi32_i32$1 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
    $97_1 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $97_1;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 11:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = 0;
    $105_1 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $105_1;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 12:
    $1_1 = ((HEAP32[$2_1 >> 2] | 0) + 7 | 0) & -8 | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 8 | 0;
    i64toi32_i32$1 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
    $115 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $115;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 13:
    $1_1 = ((HEAP32[$2_1 >> 2] | 0) + 7 | 0) & -8 | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 8 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
    $125 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $125;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 14:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$1 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
    $133 = i64toi32_i32$1;
    i64toi32_i32$1 = $0_1;
    HEAP32[i64toi32_i32$1 >> 2] = $133;
    HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
    return;
   case 15:
    $1_1 = HEAP32[$2_1 >> 2] | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 4 | 0;
    i64toi32_i32$0 = HEAP32[$1_1 >> 2] | 0;
    i64toi32_i32$1 = 0;
    $141 = i64toi32_i32$0;
    i64toi32_i32$0 = $0_1;
    HEAP32[i64toi32_i32$0 >> 2] = $141;
    HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
    return;
   case 16:
    $1_1 = ((HEAP32[$2_1 >> 2] | 0) + 7 | 0) & -8 | 0;
    HEAP32[$2_1 >> 2] = $1_1 + 8 | 0;
    HEAPF64[$0_1 >> 3] = +HEAPF64[$1_1 >> 3];
    return;
   case 17:
    FUNCTION_TABLE[$3_1 | 0]($0_1, $2_1);
    break;
   default:
    break label$1;
   };
  }
 }
 
 function $34($0_1, $0$hi, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $10_1 = 0, $3_1 = 0;
  label$1 : {
   i64toi32_i32$0 = $0$hi;
   if (!($0_1 | i64toi32_i32$0 | 0)) {
    break label$1
   }
   label$2 : while (1) {
    $1_1 = $1_1 + -1 | 0;
    i64toi32_i32$0 = $0$hi;
    HEAP8[$1_1 >> 0] = HEAPU8[(($0_1 & 15 | 0) + 66112 | 0) >> 0] | 0 | $2_1 | 0;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 15;
    $3_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 4;
    i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $10_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
     $10_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
    }
    $0_1 = $10_1;
    $0$hi = i64toi32_i32$0;
    if ($3_1) {
     continue label$2
    }
    break label$2;
   };
  }
  return $1_1 | 0;
 }
 
 function $35($0_1, $0$hi, $1_1) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $9_1 = 0, $2_1 = 0;
  label$1 : {
   i64toi32_i32$0 = $0$hi;
   if (!($0_1 | i64toi32_i32$0 | 0)) {
    break label$1
   }
   label$2 : while (1) {
    $1_1 = $1_1 + -1 | 0;
    i64toi32_i32$0 = $0$hi;
    HEAP8[$1_1 >> 0] = $0_1 & 7 | 0 | 48 | 0;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 7;
    $2_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 3;
    i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $9_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
     $9_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
    }
    $0_1 = $9_1;
    $0$hi = i64toi32_i32$0;
    if ($2_1) {
     continue label$2
    }
    break label$2;
   };
  }
  return $1_1 | 0;
 }
 
 function $36($0_1, $0$hi, $1_1) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, $3_1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$3 = 0, $2_1 = 0, $2$hi = 0, $4_1 = 0, $16_1 = 0, $16$hi = 0, $5_1 = 0;
  label$1 : {
   label$2 : {
    i64toi32_i32$0 = $0$hi;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$1 = 1;
    i64toi32_i32$3 = 0;
    if (i64toi32_i32$0 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0 | 0) | 0) {
     break label$2
    }
    i64toi32_i32$2 = i64toi32_i32$0;
    $2_1 = $0_1;
    $2$hi = i64toi32_i32$2;
    break label$1;
   }
   label$3 : while (1) {
    $1_1 = $1_1 + -1 | 0;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$0 = __wasm_i64_udiv($0_1 | 0, i64toi32_i32$2 | 0, 10 | 0, i64toi32_i32$0 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
    $2_1 = i64toi32_i32$0;
    $2$hi = i64toi32_i32$2;
    i64toi32_i32$0 = 0;
    i64toi32_i32$0 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$2 | 0, 10 | 0, i64toi32_i32$0 | 0) | 0;
    i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
    $16_1 = i64toi32_i32$0;
    $16$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$0 = $16$hi;
    i64toi32_i32$1 = $16_1;
    i64toi32_i32$5 = ($0_1 >>> 0 < i64toi32_i32$1 >>> 0) + i64toi32_i32$0 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
    HEAP8[$1_1 >> 0] = $0_1 - i64toi32_i32$1 | 0 | 48 | 0;
    i64toi32_i32$5 = i64toi32_i32$2;
    i64toi32_i32$5 = i64toi32_i32$2;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$3 = 9;
    i64toi32_i32$1 = -1;
    $3_1 = i64toi32_i32$5 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
    i64toi32_i32$2 = $2$hi;
    $0_1 = $2_1;
    $0$hi = i64toi32_i32$2;
    if ($3_1) {
     continue label$3
    }
    break label$3;
   };
  }
  label$4 : {
   i64toi32_i32$2 = $2$hi;
   $3_1 = $2_1;
   if (!$3_1) {
    break label$4
   }
   label$5 : while (1) {
    $1_1 = $1_1 + -1 | 0;
    $4_1 = ($3_1 >>> 0) / (10 >>> 0) | 0;
    HEAP8[$1_1 >> 0] = $3_1 - Math_imul($4_1, 10) | 0 | 48 | 0;
    $5_1 = $3_1 >>> 0 > 9 >>> 0;
    $3_1 = $4_1;
    if ($5_1) {
     continue label$5
    }
    break label$5;
   };
  }
  return $1_1 | 0;
 }
 
 function $37($0_1, $1_1, $2_1, $3_1, $4_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  var $5_1 = 0;
  $5_1 = global$0 - 256 | 0;
  global$0 = $5_1;
  label$1 : {
   if (($2_1 | 0) <= ($3_1 | 0)) {
    break label$1
   }
   if ($4_1 & 73728 | 0) {
    break label$1
   }
   $3_1 = $2_1 - $3_1 | 0;
   $2_1 = $3_1 >>> 0 < 256 >>> 0;
   $13($5_1 | 0, $1_1 | 0, ($2_1 ? $3_1 : 256) | 0) | 0;
   label$2 : {
    if ($2_1) {
     break label$2
    }
    label$3 : while (1) {
     $31($0_1 | 0, $5_1 | 0, 256 | 0);
     $3_1 = $3_1 + -256 | 0;
     if ($3_1 >>> 0 > 255 >>> 0) {
      continue label$3
     }
     break label$3;
    };
   }
   $31($0_1 | 0, $5_1 | 0, $3_1 | 0);
  }
  global$0 = $5_1 + 256 | 0;
 }
 
 function $38($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  return $29($0_1 | 0, $1_1 | 0, $2_1 | 0, 5 | 0, 6 | 0) | 0 | 0;
 }
 
 function $39($0_1, $1_1, $2_1, $3_1, $4_1, $5_1) {
  $0_1 = $0_1 | 0;
  $1_1 = +$1_1;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  $5_1 = $5_1 | 0;
  var $10_1 = 0, $11_1 = 0, $12_1 = 0, $18_1 = 0, $6_1 = 0, $21_1 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, $15_1 = 0, i64toi32_i32$4 = 0, $22_1 = 0, $23_1 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$5 = 0, $19_1 = 0, $17_1 = 0, $8_1 = 0, $26_1 = 0.0, $24_1 = 0, $13_1 = 0, $24$hi = 0, $14_1 = 0, $16_1 = 0, $20_1 = 0, $9_1 = 0, $7_1 = 0, $45_1 = 0, $46_1 = 0, $47_1 = 0, $25$hi = 0, $48_1 = 0, $25_1 = 0, $167 = 0, $169$hi = 0, $171$hi = 0, $173 = 0, $173$hi = 0, $175$hi = 0, $179 = 0, $179$hi = 0, $391 = 0.0, $855 = 0;
  $6_1 = global$0 - 560 | 0;
  global$0 = $6_1;
  $7_1 = 0;
  HEAP32[($6_1 + 44 | 0) >> 2] = 0;
  label$1 : {
   label$2 : {
    i64toi32_i32$0 = $41(+$1_1) | 0;
    i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
    $24_1 = i64toi32_i32$0;
    $24$hi = i64toi32_i32$1;
    i64toi32_i32$2 = i64toi32_i32$0;
    i64toi32_i32$0 = -1;
    i64toi32_i32$3 = -1;
    if ((i64toi32_i32$1 | 0) > (i64toi32_i32$0 | 0)) {
     $45_1 = 1
    } else {
     if ((i64toi32_i32$1 | 0) >= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$2 >>> 0 <= i64toi32_i32$3 >>> 0) {
       $46_1 = 0
      } else {
       $46_1 = 1
      }
      $47_1 = $46_1;
     } else {
      $47_1 = 0
     }
     $45_1 = $47_1;
    }
    if ($45_1) {
     break label$2
    }
    $8_1 = 1;
    $9_1 = 65555;
    $1_1 = -$1_1;
    i64toi32_i32$2 = $41(+$1_1) | 0;
    i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
    $24_1 = i64toi32_i32$2;
    $24$hi = i64toi32_i32$1;
    break label$1;
   }
   label$3 : {
    if (!($4_1 & 2048 | 0)) {
     break label$3
    }
    $8_1 = 1;
    $9_1 = 65558;
    break label$1;
   }
   $8_1 = $4_1 & 1 | 0;
   $9_1 = $8_1 ? 65561 : 65556;
   $7_1 = !$8_1;
  }
  label$4 : {
   label$5 : {
    i64toi32_i32$1 = $24$hi;
    i64toi32_i32$3 = $24_1;
    i64toi32_i32$2 = 2146435072;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
    i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
    i64toi32_i32$3 = 2146435072;
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$1 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | 0) {
     break label$5
    }
    $10_1 = $8_1 + 3 | 0;
    $37($0_1 | 0, 32 | 0, $2_1 | 0, $10_1 | 0, $4_1 & -65537 | 0 | 0);
    $31($0_1 | 0, $9_1 | 0, $8_1 | 0);
    $11_1 = $5_1 & 32 | 0;
    $31($0_1 | 0, ($1_1 != $1_1 ? ($11_1 ? 65574 : 65585) : $11_1 ? 65578 : 65589) | 0, 3 | 0);
    $37($0_1 | 0, 32 | 0, $2_1 | 0, $10_1 | 0, $4_1 ^ 8192 | 0 | 0);
    $12_1 = ($10_1 | 0) > ($2_1 | 0) ? $10_1 : $2_1;
    break label$4;
   }
   $13_1 = $6_1 + 16 | 0;
   label$6 : {
    label$7 : {
     label$8 : {
      label$9 : {
       $1_1 = +$27(+$1_1, $6_1 + 44 | 0 | 0);
       $1_1 = $1_1 + $1_1;
       if ($1_1 == 0.0) {
        break label$9
       }
       $10_1 = HEAP32[($6_1 + 44 | 0) >> 2] | 0;
       HEAP32[($6_1 + 44 | 0) >> 2] = $10_1 + -1 | 0;
       $14_1 = $5_1 | 32 | 0;
       if (($14_1 | 0) != (97 | 0)) {
        break label$8
       }
       break label$6;
      }
      $14_1 = $5_1 | 32 | 0;
      if (($14_1 | 0) == (97 | 0)) {
       break label$6
      }
      $15_1 = ($3_1 | 0) < (0 | 0) ? 6 : $3_1;
      $16_1 = HEAP32[($6_1 + 44 | 0) >> 2] | 0;
      break label$7;
     }
     $16_1 = $10_1 + -29 | 0;
     HEAP32[($6_1 + 44 | 0) >> 2] = $16_1;
     $15_1 = ($3_1 | 0) < (0 | 0) ? 6 : $3_1;
     $1_1 = $1_1 * 268435456.0;
    }
    $17_1 = ($6_1 + 48 | 0) + (($16_1 | 0) < (0 | 0) ? 0 : 288) | 0;
    $11_1 = $17_1;
    label$10 : while (1) {
     label$11 : {
      label$12 : {
       if (!($1_1 < 4294967296.0 & $1_1 >= 0.0 | 0)) {
        break label$12
       }
       $10_1 = ~~$1_1 >>> 0;
       break label$11;
      }
      $10_1 = 0;
     }
     HEAP32[$11_1 >> 2] = $10_1;
     $11_1 = $11_1 + 4 | 0;
     $1_1 = ($1_1 - +($10_1 >>> 0)) * 1.0e9;
     if ($1_1 != 0.0) {
      continue label$10
     }
     break label$10;
    };
    label$13 : {
     label$14 : {
      if (($16_1 | 0) >= (1 | 0)) {
       break label$14
      }
      $3_1 = $16_1;
      $10_1 = $11_1;
      $18_1 = $17_1;
      break label$13;
     }
     $18_1 = $17_1;
     $3_1 = $16_1;
     label$15 : while (1) {
      $3_1 = $3_1 >>> 0 < 29 >>> 0 ? $3_1 : 29;
      label$16 : {
       $10_1 = $11_1 + -4 | 0;
       if ($10_1 >>> 0 < $18_1 >>> 0) {
        break label$16
       }
       i64toi32_i32$1 = 0;
       $25_1 = $3_1;
       $25$hi = i64toi32_i32$1;
       i64toi32_i32$1 = 0;
       $24_1 = 0;
       $24$hi = i64toi32_i32$1;
       label$17 : while (1) {
        $167 = $10_1;
        i64toi32_i32$0 = $10_1;
        i64toi32_i32$1 = HEAP32[$10_1 >> 2] | 0;
        i64toi32_i32$2 = 0;
        $169$hi = i64toi32_i32$2;
        i64toi32_i32$2 = $25$hi;
        i64toi32_i32$2 = $169$hi;
        i64toi32_i32$0 = i64toi32_i32$1;
        i64toi32_i32$1 = $25$hi;
        i64toi32_i32$3 = $25_1;
        i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
         i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
         $48_1 = 0;
        } else {
         i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
         $48_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
        }
        $171$hi = i64toi32_i32$1;
        i64toi32_i32$1 = $24$hi;
        i64toi32_i32$2 = $24_1;
        i64toi32_i32$0 = 0;
        i64toi32_i32$3 = -1;
        i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
        $173 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
        $173$hi = i64toi32_i32$0;
        i64toi32_i32$0 = $171$hi;
        i64toi32_i32$1 = $48_1;
        i64toi32_i32$2 = $173$hi;
        i64toi32_i32$3 = $173;
        i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
        i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
        if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
         i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
        }
        $24_1 = i64toi32_i32$4;
        $24$hi = i64toi32_i32$5;
        $175$hi = i64toi32_i32$5;
        i64toi32_i32$1 = 0;
        i64toi32_i32$1 = __wasm_i64_udiv(i64toi32_i32$4 | 0, i64toi32_i32$5 | 0, 1e9 | 0, i64toi32_i32$1 | 0) | 0;
        i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
        $24_1 = i64toi32_i32$1;
        $24$hi = i64toi32_i32$5;
        i64toi32_i32$1 = 0;
        i64toi32_i32$1 = __wasm_i64_mul($24_1 | 0, i64toi32_i32$5 | 0, 1e9 | 0, i64toi32_i32$1 | 0) | 0;
        i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
        $179 = i64toi32_i32$1;
        $179$hi = i64toi32_i32$5;
        i64toi32_i32$5 = $175$hi;
        i64toi32_i32$0 = i64toi32_i32$4;
        i64toi32_i32$1 = $179$hi;
        i64toi32_i32$3 = $179;
        i64toi32_i32$2 = i64toi32_i32$0 - i64toi32_i32$3 | 0;
        i64toi32_i32$4 = (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) + i64toi32_i32$1 | 0;
        i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$4 | 0;
        HEAP32[$167 >> 2] = i64toi32_i32$2;
        $10_1 = $10_1 + -4 | 0;
        if ($10_1 >>> 0 >= $18_1 >>> 0) {
         continue label$17
        }
        break label$17;
       };
       i64toi32_i32$4 = $24$hi;
       $10_1 = $24_1;
       if (!$10_1) {
        break label$16
       }
       $18_1 = $18_1 + -4 | 0;
       HEAP32[$18_1 >> 2] = $10_1;
      }
      label$18 : {
       label$19 : while (1) {
        $10_1 = $11_1;
        if ($10_1 >>> 0 <= $18_1 >>> 0) {
         break label$18
        }
        $11_1 = $10_1 + -4 | 0;
        if (!(HEAP32[$11_1 >> 2] | 0)) {
         continue label$19
        }
        break label$19;
       };
      }
      $3_1 = (HEAP32[($6_1 + 44 | 0) >> 2] | 0) - $3_1 | 0;
      HEAP32[($6_1 + 44 | 0) >> 2] = $3_1;
      $11_1 = $10_1;
      if (($3_1 | 0) > (0 | 0)) {
       continue label$15
      }
      break label$15;
     };
    }
    label$20 : {
     if (($3_1 | 0) > (-1 | 0)) {
      break label$20
     }
     $19_1 = ((($15_1 + 25 | 0) >>> 0) / (9 >>> 0) | 0) + 1 | 0;
     $20_1 = ($14_1 | 0) == (102 | 0);
     label$21 : while (1) {
      $11_1 = 0 - $3_1 | 0;
      $21_1 = $11_1 >>> 0 < 9 >>> 0 ? $11_1 : 9;
      label$22 : {
       label$23 : {
        if ($18_1 >>> 0 < $10_1 >>> 0) {
         break label$23
        }
        $11_1 = !(HEAP32[$18_1 >> 2] | 0) << 2 | 0;
        break label$22;
       }
       $22_1 = 1e9 >>> $21_1 | 0;
       $23_1 = (-1 << $21_1 | 0) ^ -1 | 0;
       $3_1 = 0;
       $11_1 = $18_1;
       label$24 : while (1) {
        $12_1 = HEAP32[$11_1 >> 2] | 0;
        HEAP32[$11_1 >> 2] = ($12_1 >>> $21_1 | 0) + $3_1 | 0;
        $3_1 = Math_imul($12_1 & $23_1 | 0, $22_1);
        $11_1 = $11_1 + 4 | 0;
        if ($11_1 >>> 0 < $10_1 >>> 0) {
         continue label$24
        }
        break label$24;
       };
       $11_1 = !(HEAP32[$18_1 >> 2] | 0) << 2 | 0;
       if (!$3_1) {
        break label$22
       }
       HEAP32[$10_1 >> 2] = $3_1;
       $10_1 = $10_1 + 4 | 0;
      }
      $3_1 = (HEAP32[($6_1 + 44 | 0) >> 2] | 0) + $21_1 | 0;
      HEAP32[($6_1 + 44 | 0) >> 2] = $3_1;
      $18_1 = $18_1 + $11_1 | 0;
      $11_1 = $20_1 ? $17_1 : $18_1;
      $10_1 = (($10_1 - $11_1 | 0) >> 2 | 0 | 0) > ($19_1 | 0) ? $11_1 + ($19_1 << 2 | 0) | 0 : $10_1;
      if (($3_1 | 0) < (0 | 0)) {
       continue label$21
      }
      break label$21;
     };
    }
    $3_1 = 0;
    label$25 : {
     if ($18_1 >>> 0 >= $10_1 >>> 0) {
      break label$25
     }
     $3_1 = Math_imul(($17_1 - $18_1 | 0) >> 2 | 0, 9);
     $11_1 = 10;
     $12_1 = HEAP32[$18_1 >> 2] | 0;
     if ($12_1 >>> 0 < 10 >>> 0) {
      break label$25
     }
     label$26 : while (1) {
      $3_1 = $3_1 + 1 | 0;
      $11_1 = Math_imul($11_1, 10);
      if ($12_1 >>> 0 >= $11_1 >>> 0) {
       continue label$26
      }
      break label$26;
     };
    }
    label$27 : {
     $11_1 = ($15_1 - (($14_1 | 0) == (102 | 0) ? 0 : $3_1) | 0) - (($15_1 | 0) != (0 | 0) & ($14_1 | 0) == (103 | 0) | 0) | 0;
     if (($11_1 | 0) >= (Math_imul(($10_1 - $17_1 | 0) >> 2 | 0, 9) + -9 | 0 | 0)) {
      break label$27
     }
     $12_1 = $11_1 + 9216 | 0;
     $22_1 = ($12_1 | 0) / (9 | 0) | 0;
     $19_1 = (($6_1 + 48 | 0) + (($16_1 | 0) < (0 | 0) ? 4 : 292) | 0) + ($22_1 << 2 | 0) | 0;
     $21_1 = $19_1 + -4096 | 0;
     $11_1 = 10;
     label$28 : {
      $12_1 = $12_1 - Math_imul($22_1, 9) | 0;
      if (($12_1 | 0) > (7 | 0)) {
       break label$28
      }
      label$29 : while (1) {
       $11_1 = Math_imul($11_1, 10);
       $12_1 = $12_1 + 1 | 0;
       if (($12_1 | 0) != (8 | 0)) {
        continue label$29
       }
       break label$29;
      };
     }
     $23_1 = $19_1 + -4092 | 0;
     label$30 : {
      label$31 : {
       $12_1 = HEAP32[$21_1 >> 2] | 0;
       $20_1 = ($12_1 >>> 0) / ($11_1 >>> 0) | 0;
       $22_1 = $12_1 - Math_imul($20_1, $11_1) | 0;
       if ($22_1) {
        break label$31
       }
       if (($23_1 | 0) == ($10_1 | 0)) {
        break label$30
       }
      }
      label$32 : {
       label$33 : {
        if ($20_1 & 1 | 0) {
         break label$33
        }
        $1_1 = 9007199254740992.0;
        if (($11_1 | 0) != (1e9 | 0)) {
         break label$32
        }
        if ($21_1 >>> 0 <= $18_1 >>> 0) {
         break label$32
        }
        if (!((HEAPU8[($19_1 + -4100 | 0) >> 0] | 0) & 1 | 0)) {
         break label$32
        }
       }
       $1_1 = 9007199254740994.0;
      }
      $391 = ($23_1 | 0) == ($10_1 | 0) ? 1.0 : 1.5;
      $23_1 = $11_1 >>> 1 | 0;
      $26_1 = $22_1 >>> 0 < $23_1 >>> 0 ? .5 : ($22_1 | 0) == ($23_1 | 0) ? $391 : 1.5;
      label$34 : {
       if ($7_1) {
        break label$34
       }
       if ((HEAPU8[$9_1 >> 0] | 0 | 0) != (45 | 0)) {
        break label$34
       }
       $26_1 = -$26_1;
       $1_1 = -$1_1;
      }
      $12_1 = $12_1 - $22_1 | 0;
      HEAP32[$21_1 >> 2] = $12_1;
      if ($1_1 + $26_1 == $1_1) {
       break label$30
      }
      $11_1 = $12_1 + $11_1 | 0;
      HEAP32[$21_1 >> 2] = $11_1;
      label$35 : {
       if ($11_1 >>> 0 < 1e9 >>> 0) {
        break label$35
       }
       label$36 : while (1) {
        HEAP32[$21_1 >> 2] = 0;
        label$37 : {
         $21_1 = $21_1 + -4 | 0;
         if ($21_1 >>> 0 >= $18_1 >>> 0) {
          break label$37
         }
         $18_1 = $18_1 + -4 | 0;
         HEAP32[$18_1 >> 2] = 0;
        }
        $11_1 = (HEAP32[$21_1 >> 2] | 0) + 1 | 0;
        HEAP32[$21_1 >> 2] = $11_1;
        if ($11_1 >>> 0 > 999999999 >>> 0) {
         continue label$36
        }
        break label$36;
       };
      }
      $3_1 = Math_imul(($17_1 - $18_1 | 0) >> 2 | 0, 9);
      $11_1 = 10;
      $12_1 = HEAP32[$18_1 >> 2] | 0;
      if ($12_1 >>> 0 < 10 >>> 0) {
       break label$30
      }
      label$38 : while (1) {
       $3_1 = $3_1 + 1 | 0;
       $11_1 = Math_imul($11_1, 10);
       if ($12_1 >>> 0 >= $11_1 >>> 0) {
        continue label$38
       }
       break label$38;
      };
     }
     $11_1 = $21_1 + 4 | 0;
     $10_1 = $10_1 >>> 0 > $11_1 >>> 0 ? $11_1 : $10_1;
    }
    label$39 : {
     label$40 : while (1) {
      $11_1 = $10_1;
      $12_1 = $10_1 >>> 0 <= $18_1 >>> 0;
      if ($12_1) {
       break label$39
      }
      $10_1 = $10_1 + -4 | 0;
      if (!(HEAP32[$10_1 >> 2] | 0)) {
       continue label$40
      }
      break label$40;
     };
    }
    label$41 : {
     label$42 : {
      if (($14_1 | 0) == (103 | 0)) {
       break label$42
      }
      $21_1 = $4_1 & 8 | 0;
      break label$41;
     }
     $10_1 = $15_1 ? $15_1 : 1;
     $21_1 = ($10_1 | 0) > ($3_1 | 0) & ($3_1 | 0) > (-5 | 0) | 0;
     $15_1 = ($21_1 ? $3_1 ^ -1 | 0 : -1) + $10_1 | 0;
     $5_1 = ($21_1 ? -1 : -2) + $5_1 | 0;
     $21_1 = $4_1 & 8 | 0;
     if ($21_1) {
      break label$41
     }
     $10_1 = -9;
     label$43 : {
      if ($12_1) {
       break label$43
      }
      $21_1 = HEAP32[($11_1 + -4 | 0) >> 2] | 0;
      if (!$21_1) {
       break label$43
      }
      $12_1 = 10;
      $10_1 = 0;
      if (($21_1 >>> 0) % (10 >>> 0) | 0) {
       break label$43
      }
      label$44 : while (1) {
       $22_1 = $10_1;
       $10_1 = $10_1 + 1 | 0;
       $12_1 = Math_imul($12_1, 10);
       if (!(($21_1 >>> 0) % ($12_1 >>> 0) | 0)) {
        continue label$44
       }
       break label$44;
      };
      $10_1 = $22_1 ^ -1 | 0;
     }
     $12_1 = Math_imul(($11_1 - $17_1 | 0) >> 2 | 0, 9);
     label$45 : {
      if (($5_1 & -33 | 0 | 0) != (70 | 0)) {
       break label$45
      }
      $21_1 = 0;
      $10_1 = ($12_1 + $10_1 | 0) + -9 | 0;
      $10_1 = ($10_1 | 0) > (0 | 0) ? $10_1 : 0;
      $15_1 = ($15_1 | 0) < ($10_1 | 0) ? $15_1 : $10_1;
      break label$41;
     }
     $21_1 = 0;
     $10_1 = (($3_1 + $12_1 | 0) + $10_1 | 0) + -9 | 0;
     $10_1 = ($10_1 | 0) > (0 | 0) ? $10_1 : 0;
     $15_1 = ($15_1 | 0) < ($10_1 | 0) ? $15_1 : $10_1;
    }
    $12_1 = -1;
    $22_1 = $15_1 | $21_1 | 0;
    if (($15_1 | 0) > (($22_1 ? 2147483645 : 2147483646) | 0)) {
     break label$4
    }
    $23_1 = ($15_1 + (($22_1 | 0) != (0 | 0)) | 0) + 1 | 0;
    label$46 : {
     label$47 : {
      $20_1 = $5_1 & -33 | 0;
      if (($20_1 | 0) != (70 | 0)) {
       break label$47
      }
      if (($3_1 | 0) > ($23_1 ^ 2147483647 | 0 | 0)) {
       break label$4
      }
      $10_1 = ($3_1 | 0) > (0 | 0) ? $3_1 : 0;
      break label$46;
     }
     label$48 : {
      $10_1 = $3_1 >> 31 | 0;
      i64toi32_i32$4 = 0;
      $10_1 = $36(($3_1 ^ $10_1 | 0) - $10_1 | 0 | 0, i64toi32_i32$4 | 0, $13_1 | 0) | 0;
      if (($13_1 - $10_1 | 0 | 0) > (1 | 0)) {
       break label$48
      }
      label$49 : while (1) {
       $10_1 = $10_1 + -1 | 0;
       HEAP8[$10_1 >> 0] = 48;
       if (($13_1 - $10_1 | 0 | 0) < (2 | 0)) {
        continue label$49
       }
       break label$49;
      };
     }
     $19_1 = $10_1 + -2 | 0;
     HEAP8[$19_1 >> 0] = $5_1;
     $12_1 = -1;
     HEAP8[($10_1 + -1 | 0) >> 0] = ($3_1 | 0) < (0 | 0) ? 45 : 43;
     $10_1 = $13_1 - $19_1 | 0;
     if (($10_1 | 0) > ($23_1 ^ 2147483647 | 0 | 0)) {
      break label$4
     }
    }
    $12_1 = -1;
    $10_1 = $10_1 + $23_1 | 0;
    if (($10_1 | 0) > ($8_1 ^ 2147483647 | 0 | 0)) {
     break label$4
    }
    $23_1 = $10_1 + $8_1 | 0;
    $37($0_1 | 0, 32 | 0, $2_1 | 0, $23_1 | 0, $4_1 | 0);
    $31($0_1 | 0, $9_1 | 0, $8_1 | 0);
    $37($0_1 | 0, 48 | 0, $2_1 | 0, $23_1 | 0, $4_1 ^ 65536 | 0 | 0);
    label$50 : {
     label$51 : {
      label$52 : {
       label$53 : {
        if (($20_1 | 0) != (70 | 0)) {
         break label$53
        }
        $21_1 = $6_1 + 16 | 0 | 8 | 0;
        $3_1 = $6_1 + 16 | 0 | 9 | 0;
        $12_1 = $18_1 >>> 0 > $17_1 >>> 0 ? $17_1 : $18_1;
        $18_1 = $12_1;
        label$54 : while (1) {
         i64toi32_i32$5 = $18_1;
         i64toi32_i32$4 = HEAP32[$18_1 >> 2] | 0;
         i64toi32_i32$0 = 0;
         $10_1 = $36(i64toi32_i32$4 | 0, i64toi32_i32$0 | 0, $3_1 | 0) | 0;
         label$55 : {
          label$56 : {
           if (($18_1 | 0) == ($12_1 | 0)) {
            break label$56
           }
           if ($10_1 >>> 0 <= ($6_1 + 16 | 0) >>> 0) {
            break label$55
           }
           label$57 : while (1) {
            $10_1 = $10_1 + -1 | 0;
            HEAP8[$10_1 >> 0] = 48;
            if ($10_1 >>> 0 > ($6_1 + 16 | 0) >>> 0) {
             continue label$57
            }
            break label$55;
           };
          }
          if (($10_1 | 0) != ($3_1 | 0)) {
           break label$55
          }
          HEAP8[($6_1 + 24 | 0) >> 0] = 48;
          $10_1 = $21_1;
         }
         $31($0_1 | 0, $10_1 | 0, $3_1 - $10_1 | 0 | 0);
         $18_1 = $18_1 + 4 | 0;
         if ($18_1 >>> 0 <= $17_1 >>> 0) {
          continue label$54
         }
         break label$54;
        };
        label$58 : {
         if (!$22_1) {
          break label$58
         }
         $31($0_1 | 0, 65593 | 0, 1 | 0);
        }
        if ($18_1 >>> 0 >= $11_1 >>> 0) {
         break label$52
        }
        if (($15_1 | 0) < (1 | 0)) {
         break label$52
        }
        label$59 : while (1) {
         label$60 : {
          i64toi32_i32$5 = $18_1;
          i64toi32_i32$0 = HEAP32[$18_1 >> 2] | 0;
          i64toi32_i32$4 = 0;
          $10_1 = $36(i64toi32_i32$0 | 0, i64toi32_i32$4 | 0, $3_1 | 0) | 0;
          if ($10_1 >>> 0 <= ($6_1 + 16 | 0) >>> 0) {
           break label$60
          }
          label$61 : while (1) {
           $10_1 = $10_1 + -1 | 0;
           HEAP8[$10_1 >> 0] = 48;
           if ($10_1 >>> 0 > ($6_1 + 16 | 0) >>> 0) {
            continue label$61
           }
           break label$61;
          };
         }
         $31($0_1 | 0, $10_1 | 0, (($15_1 | 0) < (9 | 0) ? $15_1 : 9) | 0);
         $10_1 = $15_1 + -9 | 0;
         $18_1 = $18_1 + 4 | 0;
         if ($18_1 >>> 0 >= $11_1 >>> 0) {
          break label$51
         }
         $12_1 = ($15_1 | 0) > (9 | 0);
         $15_1 = $10_1;
         if ($12_1) {
          continue label$59
         }
         break label$51;
        };
       }
       label$62 : {
        if (($15_1 | 0) < (0 | 0)) {
         break label$62
        }
        $22_1 = $11_1 >>> 0 > $18_1 >>> 0 ? $11_1 : $18_1 + 4 | 0;
        $17_1 = $6_1 + 16 | 0 | 8 | 0;
        $3_1 = $6_1 + 16 | 0 | 9 | 0;
        $11_1 = $18_1;
        label$63 : while (1) {
         label$64 : {
          i64toi32_i32$5 = $11_1;
          i64toi32_i32$4 = HEAP32[$11_1 >> 2] | 0;
          i64toi32_i32$0 = 0;
          $10_1 = $36(i64toi32_i32$4 | 0, i64toi32_i32$0 | 0, $3_1 | 0) | 0;
          if (($10_1 | 0) != ($3_1 | 0)) {
           break label$64
          }
          HEAP8[($6_1 + 24 | 0) >> 0] = 48;
          $10_1 = $17_1;
         }
         label$65 : {
          label$66 : {
           if (($11_1 | 0) == ($18_1 | 0)) {
            break label$66
           }
           if ($10_1 >>> 0 <= ($6_1 + 16 | 0) >>> 0) {
            break label$65
           }
           label$67 : while (1) {
            $10_1 = $10_1 + -1 | 0;
            HEAP8[$10_1 >> 0] = 48;
            if ($10_1 >>> 0 > ($6_1 + 16 | 0) >>> 0) {
             continue label$67
            }
            break label$65;
           };
          }
          $31($0_1 | 0, $10_1 | 0, 1 | 0);
          $10_1 = $10_1 + 1 | 0;
          if (!($15_1 | $21_1 | 0)) {
           break label$65
          }
          $31($0_1 | 0, 65593 | 0, 1 | 0);
         }
         $12_1 = $3_1 - $10_1 | 0;
         $31($0_1 | 0, $10_1 | 0, (($15_1 | 0) > ($12_1 | 0) ? $12_1 : $15_1) | 0);
         $15_1 = $15_1 - $12_1 | 0;
         $11_1 = $11_1 + 4 | 0;
         if ($11_1 >>> 0 >= $22_1 >>> 0) {
          break label$62
         }
         if (($15_1 | 0) > (-1 | 0)) {
          continue label$63
         }
         break label$63;
        };
       }
       $37($0_1 | 0, 48 | 0, $15_1 + 18 | 0 | 0, 18 | 0, 0 | 0);
       $31($0_1 | 0, $19_1 | 0, $13_1 - $19_1 | 0 | 0);
       break label$50;
      }
      $10_1 = $15_1;
     }
     $37($0_1 | 0, 48 | 0, $10_1 + 9 | 0 | 0, 9 | 0, 0 | 0);
    }
    $37($0_1 | 0, 32 | 0, $2_1 | 0, $23_1 | 0, $4_1 ^ 8192 | 0 | 0);
    $12_1 = ($23_1 | 0) > ($2_1 | 0) ? $23_1 : $2_1;
    break label$4;
   }
   $23_1 = $9_1 + ((($5_1 << 26 | 0) >> 31 | 0) & 9 | 0) | 0;
   label$68 : {
    if ($3_1 >>> 0 > 11 >>> 0) {
     break label$68
    }
    $10_1 = 12 - $3_1 | 0;
    $26_1 = 16.0;
    label$69 : while (1) {
     $26_1 = $26_1 * 16.0;
     $10_1 = $10_1 + -1 | 0;
     if ($10_1) {
      continue label$69
     }
     break label$69;
    };
    label$70 : {
     if ((HEAPU8[$23_1 >> 0] | 0 | 0) != (45 | 0)) {
      break label$70
     }
     $1_1 = -($26_1 + (-$1_1 - $26_1));
     break label$68;
    }
    $1_1 = $1_1 + $26_1 - $26_1;
   }
   label$71 : {
    $10_1 = HEAP32[($6_1 + 44 | 0) >> 2] | 0;
    $855 = $10_1;
    $10_1 = $10_1 >> 31 | 0;
    i64toi32_i32$0 = 0;
    $10_1 = $36(($855 ^ $10_1 | 0) - $10_1 | 0 | 0, i64toi32_i32$0 | 0, $13_1 | 0) | 0;
    if (($10_1 | 0) != ($13_1 | 0)) {
     break label$71
    }
    HEAP8[($6_1 + 15 | 0) >> 0] = 48;
    $10_1 = $6_1 + 15 | 0;
   }
   $21_1 = $8_1 | 2 | 0;
   $18_1 = $5_1 & 32 | 0;
   $11_1 = HEAP32[($6_1 + 44 | 0) >> 2] | 0;
   $22_1 = $10_1 + -2 | 0;
   HEAP8[$22_1 >> 0] = $5_1 + 15 | 0;
   HEAP8[($10_1 + -1 | 0) >> 0] = ($11_1 | 0) < (0 | 0) ? 45 : 43;
   $12_1 = $4_1 & 8 | 0;
   $11_1 = $6_1 + 16 | 0;
   label$72 : while (1) {
    $10_1 = $11_1;
    label$73 : {
     label$74 : {
      if (!(Math_abs($1_1) < 2147483648.0)) {
       break label$74
      }
      $11_1 = ~~$1_1;
      break label$73;
     }
     $11_1 = -2147483648;
    }
    HEAP8[$10_1 >> 0] = HEAPU8[($11_1 + 66112 | 0) >> 0] | 0 | $18_1 | 0;
    $1_1 = ($1_1 - +($11_1 | 0)) * 16.0;
    label$75 : {
     $11_1 = $10_1 + 1 | 0;
     if (($11_1 - ($6_1 + 16 | 0) | 0 | 0) != (1 | 0)) {
      break label$75
     }
     label$76 : {
      if ($12_1) {
       break label$76
      }
      if (($3_1 | 0) > (0 | 0)) {
       break label$76
      }
      if ($1_1 == 0.0) {
       break label$75
      }
     }
     HEAP8[($10_1 + 1 | 0) >> 0] = 46;
     $11_1 = $10_1 + 2 | 0;
    }
    if ($1_1 != 0.0) {
     continue label$72
    }
    break label$72;
   };
   $12_1 = -1;
   $18_1 = $13_1 - $22_1 | 0;
   $19_1 = $21_1 + $18_1 | 0;
   if ((2147483645 - $19_1 | 0 | 0) < ($3_1 | 0)) {
    break label$4
   }
   $10_1 = $11_1 - ($6_1 + 16 | 0) | 0;
   $3_1 = $3_1 ? (($10_1 + -2 | 0 | 0) < ($3_1 | 0) ? $3_1 + 2 | 0 : $10_1) : $10_1;
   $11_1 = $19_1 + $3_1 | 0;
   $37($0_1 | 0, 32 | 0, $2_1 | 0, $11_1 | 0, $4_1 | 0);
   $31($0_1 | 0, $23_1 | 0, $21_1 | 0);
   $37($0_1 | 0, 48 | 0, $2_1 | 0, $11_1 | 0, $4_1 ^ 65536 | 0 | 0);
   $31($0_1 | 0, $6_1 + 16 | 0 | 0, $10_1 | 0);
   $37($0_1 | 0, 48 | 0, $3_1 - $10_1 | 0 | 0, 0 | 0, 0 | 0);
   $31($0_1 | 0, $22_1 | 0, $18_1 | 0);
   $37($0_1 | 0, 32 | 0, $2_1 | 0, $11_1 | 0, $4_1 ^ 8192 | 0 | 0);
   $12_1 = ($11_1 | 0) > ($2_1 | 0) ? $11_1 : $2_1;
  }
  global$0 = $6_1 + 560 | 0;
  return $12_1 | 0;
 }
 
 function $40($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, $2_1 = 0, $12_1 = 0, $12$hi = 0, $15_1 = 0, $15$hi = 0;
  $2_1 = ((HEAP32[$1_1 >> 2] | 0) + 7 | 0) & -8 | 0;
  HEAP32[$1_1 >> 2] = $2_1 + 16 | 0;
  i64toi32_i32$2 = $2_1;
  i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $12_1 = i64toi32_i32$0;
  $12$hi = i64toi32_i32$1;
  i64toi32_i32$2 = i64toi32_i32$2 + 8 | 0;
  i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $15_1 = i64toi32_i32$1;
  $15$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $12$hi;
  i64toi32_i32$1 = $15$hi;
  HEAPF64[$0_1 >> 3] = +$100($12_1 | 0, i64toi32_i32$0 | 0, $15_1 | 0, i64toi32_i32$1 | 0);
 }
 
 function $41($0_1) {
  $0_1 = +$0_1;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  wasm2js_scratch_store_f64(+$0_1);
  i64toi32_i32$0 = wasm2js_scratch_load_i32(1 | 0) | 0;
  i64toi32_i32$1 = wasm2js_scratch_load_i32(0 | 0) | 0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$1 | 0;
 }
 
 function $42($0_1) {
  $0_1 = $0_1 | 0;
  return $0_1 | 0;
 }
 
 function $43($0_1) {
  $0_1 = $0_1 | 0;
  return fimport$2($42(HEAP32[($0_1 + 60 | 0) >> 2] | 0 | 0) | 0 | 0) | 0 | 0;
 }
 
 function $44($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $5_1 = 0, $3_1 = 0, $4_1 = 0, $6_1 = 0;
  $3_1 = global$0 - 32 | 0;
  global$0 = $3_1;
  HEAP32[($3_1 + 16 | 0) >> 2] = $1_1;
  $4_1 = 0;
  $5_1 = HEAP32[($0_1 + 48 | 0) >> 2] | 0;
  HEAP32[($3_1 + 20 | 0) >> 2] = $2_1 - (($5_1 | 0) != (0 | 0)) | 0;
  $6_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
  HEAP32[($3_1 + 28 | 0) >> 2] = $5_1;
  HEAP32[($3_1 + 24 | 0) >> 2] = $6_1;
  $5_1 = 32;
  label$1 : {
   label$2 : {
    label$3 : {
     if ($75(fimport$3(HEAP32[($0_1 + 60 | 0) >> 2] | 0 | 0, $3_1 + 16 | 0 | 0, 2 | 0, $3_1 + 12 | 0 | 0) | 0 | 0) | 0) {
      break label$3
     }
     $5_1 = HEAP32[($3_1 + 12 | 0) >> 2] | 0;
     if (($5_1 | 0) > (0 | 0)) {
      break label$2
     }
     $5_1 = $5_1 ? 32 : 16;
    }
    HEAP32[$0_1 >> 2] = HEAP32[$0_1 >> 2] | 0 | $5_1 | 0;
    break label$1;
   }
   $4_1 = $5_1;
   $6_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
   if ($5_1 >>> 0 <= $6_1 >>> 0) {
    break label$1
   }
   $4_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
   HEAP32[($0_1 + 4 | 0) >> 2] = $4_1;
   HEAP32[($0_1 + 8 | 0) >> 2] = $4_1 + ($5_1 - $6_1 | 0) | 0;
   label$4 : {
    if (!(HEAP32[($0_1 + 48 | 0) >> 2] | 0)) {
     break label$4
    }
    HEAP32[($0_1 + 4 | 0) >> 2] = $4_1 + 1 | 0;
    HEAP8[(($1_1 + $2_1 | 0) + -1 | 0) >> 0] = HEAPU8[$4_1 >> 0] | 0;
   }
   $4_1 = $2_1;
  }
  global$0 = $3_1 + 32 | 0;
  return $4_1 | 0;
 }
 
 function $45($0_1, $1_1, $1$hi, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, $3_1 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0;
  $3_1 = global$0 - 16 | 0;
  global$0 = $3_1;
  i64toi32_i32$0 = $1$hi;
  $2_1 = $75(legalfunc$fimport$4($0_1 | 0, $1_1 | 0, i64toi32_i32$0 | 0, $2_1 & 255 | 0 | 0, $3_1 + 8 | 0 | 0) | 0 | 0) | 0;
  i64toi32_i32$2 = $3_1;
  i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] | 0;
  i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] | 0;
  $1_1 = i64toi32_i32$0;
  $1$hi = i64toi32_i32$1;
  global$0 = i64toi32_i32$2 + 16 | 0;
  i64toi32_i32$1 = -1;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$3 = $2_1 ? -1 : $1_1;
  i64toi32_i32$2 = $2_1 ? i64toi32_i32$1 : i64toi32_i32$0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$2;
  return i64toi32_i32$3 | 0;
 }
 
 function $46($0_1, $1_1, $1$hi, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = $45(HEAP32[($0_1 + 60 | 0) >> 2] | 0 | 0, $1_1 | 0, i64toi32_i32$0 | 0, $2_1 | 0) | 0;
  i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
  return i64toi32_i32$0 | 0;
 }
 
 function $47($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, $2_1 = 0;
  $1_1 = HEAP32[($0_1 + 72 | 0) >> 2] | 0;
  HEAP32[($0_1 + 72 | 0) >> 2] = $1_1 + -1 | 0 | $1_1 | 0;
  label$1 : {
   if ((HEAP32[($0_1 + 20 | 0) >> 2] | 0 | 0) == (HEAP32[($0_1 + 28 | 0) >> 2] | 0 | 0)) {
    break label$1
   }
   FUNCTION_TABLE[HEAP32[($0_1 + 36 | 0) >> 2] | 0 | 0]($0_1, 0, 0) | 0;
  }
  HEAP32[($0_1 + 28 | 0) >> 2] = 0;
  HEAP32[($0_1 + 16 | 0) >> 2] = 0;
  HEAP32[($0_1 + 20 | 0) >> 2] = 0;
  label$2 : {
   $1_1 = HEAP32[$0_1 >> 2] | 0;
   if (!($1_1 & 4 | 0)) {
    break label$2
   }
   HEAP32[$0_1 >> 2] = $1_1 | 32 | 0;
   return -1 | 0;
  }
  $2_1 = (HEAP32[($0_1 + 44 | 0) >> 2] | 0) + (HEAP32[($0_1 + 48 | 0) >> 2] | 0) | 0;
  HEAP32[($0_1 + 8 | 0) >> 2] = $2_1;
  HEAP32[($0_1 + 4 | 0) >> 2] = $2_1;
  return ($1_1 << 27 | 0) >> 31 | 0 | 0;
 }
 
 function $48($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, $2_1 = 0;
  $1_1 = global$0 - 16 | 0;
  global$0 = $1_1;
  $2_1 = -1;
  label$1 : {
   if ($47($0_1 | 0) | 0) {
    break label$1
   }
   if ((FUNCTION_TABLE[HEAP32[($0_1 + 32 | 0) >> 2] | 0 | 0]($0_1, $1_1 + 15 | 0, 1) | 0 | 0) != (1 | 0)) {
    break label$1
   }
   $2_1 = HEAPU8[($1_1 + 15 | 0) >> 0] | 0;
  }
  global$0 = $1_1 + 16 | 0;
  return $2_1 | 0;
 }
 
 function $49($0_1, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, $2_1 = 0, $3_1 = 0, i64toi32_i32$2 = 0, $11_1 = 0, $12_1 = 0, $14_1 = 0, $13_1 = 0, $21$hi = 0, i64toi32_i32$3 = 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$1 = $0_1;
  HEAP32[(i64toi32_i32$1 + 112 | 0) >> 2] = $1_1;
  HEAP32[(i64toi32_i32$1 + 116 | 0) >> 2] = $1$hi;
  $2_1 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
  i64toi32_i32$1 = (HEAP32[(i64toi32_i32$1 + 44 | 0) >> 2] | 0) - $2_1 | 0;
  i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
  $13_1 = i64toi32_i32$1;
  i64toi32_i32$1 = $0_1;
  HEAP32[(i64toi32_i32$1 + 120 | 0) >> 2] = $13_1;
  HEAP32[(i64toi32_i32$1 + 124 | 0) >> 2] = i64toi32_i32$0;
  $3_1 = HEAP32[(i64toi32_i32$1 + 8 | 0) >> 2] | 0;
  label$1 : {
   i64toi32_i32$0 = $1$hi;
   if (!($1_1 | $1$hi | 0)) {
    break label$1
   }
   i64toi32_i32$1 = $3_1 - $2_1 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
   $21$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $21$hi;
   i64toi32_i32$2 = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$3 = $1_1;
   if ((i64toi32_i32$0 | 0) < (i64toi32_i32$1 | 0)) {
    $11_1 = 1
   } else {
    if ((i64toi32_i32$0 | 0) <= (i64toi32_i32$1 | 0)) {
     if (i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0) {
      $12_1 = 0
     } else {
      $12_1 = 1
     }
     $14_1 = $12_1;
    } else {
     $14_1 = 0
    }
    $11_1 = $14_1;
   }
   if ($11_1) {
    break label$1
   }
   i64toi32_i32$2 = $1$hi;
   $3_1 = $2_1 + $1_1 | 0;
  }
  HEAP32[($0_1 + 104 | 0) >> 2] = $3_1;
 }
 
 function $50($0_1) {
  $0_1 = $0_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $1_1 = 0, $4$hi = 0, $2_1 = 0, $5$hi = 0, $3_1 = 0, $5_1 = 0, $4_1 = 0, $26_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $30_1 = 0, $31_1 = 0, $7_1 = 0, $7$hi = 0, $15_1 = 0, $15$hi = 0, $35_1 = 0, $40_1 = 0, $40$hi = 0, $59_1 = 0, $59$hi = 0, $67_1 = 0, $74_1 = 0, $74$hi = 0;
  i64toi32_i32$2 = $0_1;
  i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 120 | 0) >> 2] | 0;
  i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 124 | 0) >> 2] | 0;
  $7_1 = i64toi32_i32$0;
  $7$hi = i64toi32_i32$1;
  $1_1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $2_1 = HEAP32[(i64toi32_i32$2 + 44 | 0) >> 2] | 0;
  i64toi32_i32$0 = $1_1 - $2_1 | 0;
  i64toi32_i32$1 = i64toi32_i32$0 >> 31 | 0;
  $15_1 = i64toi32_i32$0;
  $15$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $7$hi;
  i64toi32_i32$2 = $7_1;
  i64toi32_i32$0 = $15$hi;
  i64toi32_i32$3 = $15_1;
  i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
  i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
  if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
  }
  $4_1 = i64toi32_i32$4;
  $4$hi = i64toi32_i32$5;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$1 = $0_1;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 112 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 116 | 0) >> 2] | 0;
     $5_1 = i64toi32_i32$5;
     $5$hi = i64toi32_i32$2;
     if (!(i64toi32_i32$5 | i64toi32_i32$2 | 0)) {
      break label$3
     }
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $5$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$1 = i64toi32_i32$4;
     i64toi32_i32$5 = $5$hi;
     i64toi32_i32$3 = $5_1;
     if ((i64toi32_i32$2 | 0) > (i64toi32_i32$5 | 0)) {
      $26_1 = 1
     } else {
      if ((i64toi32_i32$2 | 0) >= (i64toi32_i32$5 | 0)) {
       if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
        $27_1 = 0
       } else {
        $27_1 = 1
       }
       $28_1 = $27_1;
      } else {
       $28_1 = 0
      }
      $26_1 = $28_1;
     }
     if ($26_1) {
      break label$2
     }
    }
    $2_1 = $48($0_1 | 0) | 0;
    if (($2_1 | 0) > (-1 | 0)) {
     break label$1
    }
    $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
    $2_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
   }
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$1 = -1;
   HEAP32[(i64toi32_i32$2 + 112 | 0) >> 2] = -1;
   HEAP32[(i64toi32_i32$2 + 116 | 0) >> 2] = i64toi32_i32$1;
   HEAP32[(i64toi32_i32$2 + 104 | 0) >> 2] = $1_1;
   $35_1 = i64toi32_i32$2;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$2 = $2_1 - $1_1 | 0;
   i64toi32_i32$1 = i64toi32_i32$2 >> 31 | 0;
   $40_1 = i64toi32_i32$2;
   $40$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$3 = $4_1;
   i64toi32_i32$2 = $40$hi;
   i64toi32_i32$5 = $40_1;
   i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   i64toi32_i32$3 = $35_1;
   HEAP32[(i64toi32_i32$3 + 120 | 0) >> 2] = i64toi32_i32$0;
   HEAP32[(i64toi32_i32$3 + 124 | 0) >> 2] = i64toi32_i32$4;
   return -1 | 0;
  }
  i64toi32_i32$4 = $4$hi;
  i64toi32_i32$1 = $4_1;
  i64toi32_i32$3 = 0;
  i64toi32_i32$5 = 1;
  i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
  i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
  if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) {
   i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
  }
  $4_1 = i64toi32_i32$2;
  $4$hi = i64toi32_i32$0;
  $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
  $3_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
  label$4 : {
   i64toi32_i32$4 = $0_1;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 112 | 0) >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 116 | 0) >> 2] | 0;
   $5_1 = i64toi32_i32$0;
   $5$hi = i64toi32_i32$1;
   i64toi32_i32$4 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 0;
   if ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) | 0) {
    break label$4
   }
   i64toi32_i32$4 = i64toi32_i32$1;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$4 = i64toi32_i32$1;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$3 = i64toi32_i32$5 - i64toi32_i32$2 | 0;
   i64toi32_i32$2 = (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) + i64toi32_i32$1 | 0;
   i64toi32_i32$2 = i64toi32_i32$4 - i64toi32_i32$2 | 0;
   $5_1 = i64toi32_i32$3;
   $5$hi = i64toi32_i32$2;
   i64toi32_i32$5 = $3_1 - $1_1 | 0;
   i64toi32_i32$2 = i64toi32_i32$5 >> 31 | 0;
   $59_1 = i64toi32_i32$5;
   $59$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $5$hi;
   i64toi32_i32$4 = i64toi32_i32$3;
   i64toi32_i32$5 = $59$hi;
   i64toi32_i32$0 = $59_1;
   if ((i64toi32_i32$2 | 0) > (i64toi32_i32$5 | 0)) {
    $29_1 = 1
   } else {
    if ((i64toi32_i32$2 | 0) >= (i64toi32_i32$5 | 0)) {
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
      $30_1 = 0
     } else {
      $30_1 = 1
     }
     $31_1 = $30_1;
    } else {
     $31_1 = 0
    }
    $29_1 = $31_1;
   }
   if ($29_1) {
    break label$4
   }
   i64toi32_i32$4 = $5$hi;
   $3_1 = $1_1 + $5_1 | 0;
  }
  HEAP32[($0_1 + 104 | 0) >> 2] = $3_1;
  $67_1 = $0_1;
  i64toi32_i32$4 = $4$hi;
  $3_1 = HEAP32[($0_1 + 44 | 0) >> 2] | 0;
  i64toi32_i32$2 = $3_1 - $1_1 | 0;
  i64toi32_i32$4 = i64toi32_i32$2 >> 31 | 0;
  $74_1 = i64toi32_i32$2;
  $74$hi = i64toi32_i32$4;
  i64toi32_i32$4 = $4$hi;
  i64toi32_i32$0 = $4_1;
  i64toi32_i32$2 = $74$hi;
  i64toi32_i32$5 = $74_1;
  i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
  i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
  if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
   i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
  }
  i64toi32_i32$0 = $67_1;
  HEAP32[(i64toi32_i32$0 + 120 | 0) >> 2] = i64toi32_i32$1;
  HEAP32[(i64toi32_i32$0 + 124 | 0) >> 2] = i64toi32_i32$3;
  label$5 : {
   if ($1_1 >>> 0 > $3_1 >>> 0) {
    break label$5
   }
   HEAP8[($1_1 + -1 | 0) >> 0] = $2_1;
  }
  return $2_1 | 0;
 }
 
 function $51($0_1, $1_1) {
  $0_1 = +$0_1;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$4 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $8_1 = 0, $32_1 = 0.0, i64toi32_i32$0 = 0;
  label$1 : {
   label$2 : {
    if (($1_1 | 0) < (1024 | 0)) {
     break label$2
    }
    $0_1 = $0_1 * 8988465674311579538646525.0e283;
    label$3 : {
     if ($1_1 >>> 0 >= 2047 >>> 0) {
      break label$3
     }
     $1_1 = $1_1 + -1023 | 0;
     break label$1;
    }
    $0_1 = $0_1 * 8988465674311579538646525.0e283;
    $1_1 = ($1_1 >>> 0 < 3069 >>> 0 ? $1_1 : 3069) + -2046 | 0;
    break label$1;
   }
   if (($1_1 | 0) > (-1023 | 0)) {
    break label$1
   }
   $0_1 = $0_1 * 2.004168360008973e-292;
   label$4 : {
    if ($1_1 >>> 0 <= -1992 >>> 0) {
     break label$4
    }
    $1_1 = $1_1 + 969 | 0;
    break label$1;
   }
   $0_1 = $0_1 * 2.004168360008973e-292;
   $1_1 = ($1_1 >>> 0 > -2960 >>> 0 ? $1_1 : -2960) + 1938 | 0;
  }
  $32_1 = $0_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$2 = $1_1 + 1023 | 0;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 52;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   $8_1 = 0;
  } else {
   i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
   $8_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
  }
  wasm2js_scratch_store_i32(0 | 0, $8_1 | 0);
  wasm2js_scratch_store_i32(1 | 0, i64toi32_i32$1 | 0);
  return +($32_1 * +wasm2js_scratch_load_f64());
 }
 
 function $52($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $22_1 = 0, $23_1 = 0, $24_1 = 0, $7_1 = 0, $11_1 = 0, $18$hi = 0, $20_1 = 0, $20$hi = 0, $21_1 = 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$1 = $0_1;
  HEAP32[i64toi32_i32$1 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$0;
  $7_1 = i64toi32_i32$1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $22_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $22_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  $11_1 = $22_1 & 32768 | 0;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$0 = $2_1;
  i64toi32_i32$2 = 2147418112;
  i64toi32_i32$3 = 0;
  i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = 0;
   $23_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   $23_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
  }
  i64toi32_i32$0 = 0;
  i64toi32_i32$2 = $11_1 | $23_1 | 0;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   $24_1 = 0;
  } else {
   i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
   $24_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
  }
  $18$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$0 = $2_1;
  i64toi32_i32$2 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  $20_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $20$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $18$hi;
  i64toi32_i32$1 = $24_1;
  i64toi32_i32$0 = $20$hi;
  i64toi32_i32$3 = $20_1;
  i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
  $21_1 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
  i64toi32_i32$1 = $7_1;
  HEAP32[(i64toi32_i32$1 + 8 | 0) >> 2] = $21_1;
  HEAP32[(i64toi32_i32$1 + 12 | 0) >> 2] = i64toi32_i32$0;
 }
 
 function $53($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $4_1 = 0, i64toi32_i32$4 = 0, $20_1 = 0, $70_1 = 0, $71_1 = 0, $71$hi = 0, $72_1 = 0, $72$hi = 0, $76$hi = 0, $80_1 = 0, $83_1 = 0;
  $4_1 = global$0 - 80 | 0;
  global$0 = $4_1;
  label$1 : {
   label$2 : {
    if (($3_1 | 0) < (16384 | 0)) {
     break label$2
    }
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$2 = 0;
    i64toi32_i32$3 = 2147352576;
    $97($4_1 + 32 | 0 | 0, $1_1 | 0, i64toi32_i32$0 | 0, $2_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$1 = ($4_1 + 32 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$3;
    $2$hi = i64toi32_i32$2;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 32 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 36 | 0) >> 2] | 0;
    $1_1 = i64toi32_i32$2;
    $1$hi = i64toi32_i32$3;
    label$3 : {
     if ($3_1 >>> 0 >= 32767 >>> 0) {
      break label$3
     }
     $3_1 = $3_1 + -16383 | 0;
     break label$1;
    }
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = 2147352576;
    $97($4_1 + 16 | 0 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0);
    $3_1 = ($3_1 >>> 0 < 49149 >>> 0 ? $3_1 : 49149) + -32766 | 0;
    i64toi32_i32$2 = ($4_1 + 16 | 0) + 8 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$0;
    $2$hi = i64toi32_i32$1;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 16 | 0) >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 20 | 0) >> 2] | 0;
    $1_1 = i64toi32_i32$1;
    $1$hi = i64toi32_i32$0;
    break label$1;
   }
   if (($3_1 | 0) > (-16383 | 0)) {
    break label$1
   }
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 7471104;
   $97($4_1 + 64 | 0 | 0, $1_1 | 0, i64toi32_i32$0 | 0, $2_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0);
   i64toi32_i32$1 = ($4_1 + 64 | 0) + 8 | 0;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
   $2_1 = i64toi32_i32$3;
   $2$hi = i64toi32_i32$2;
   i64toi32_i32$1 = $4_1;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 64 | 0) >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 68 | 0) >> 2] | 0;
   $1_1 = i64toi32_i32$2;
   $1$hi = i64toi32_i32$3;
   label$4 : {
    if ($3_1 >>> 0 <= -32652 >>> 0) {
     break label$4
    }
    $3_1 = $3_1 + 16269 | 0;
    break label$1;
   }
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$1 = 0;
   i64toi32_i32$0 = 7471104;
   $97($4_1 + 48 | 0 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0);
   $3_1 = ($3_1 >>> 0 > -48920 >>> 0 ? $3_1 : -48920) + 32538 | 0;
   i64toi32_i32$2 = ($4_1 + 48 | 0) + 8 | 0;
   i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   $2_1 = i64toi32_i32$0;
   $2$hi = i64toi32_i32$1;
   i64toi32_i32$2 = $4_1;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 48 | 0) >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 52 | 0) >> 2] | 0;
   $1_1 = i64toi32_i32$1;
   $1$hi = i64toi32_i32$0;
  }
  $70_1 = $4_1;
  i64toi32_i32$0 = $1$hi;
  $71_1 = $1_1;
  $71$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $2$hi;
  $72_1 = $2_1;
  $72$hi = i64toi32_i32$0;
  i64toi32_i32$0 = 0;
  i64toi32_i32$2 = $3_1 + 16383 | 0;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   $20_1 = 0;
  } else {
   i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
   $20_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
  }
  $76$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $71$hi;
  i64toi32_i32$2 = $72$hi;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = $76$hi;
  $97($70_1 | 0, $71_1 | 0, i64toi32_i32$1 | 0, $72_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0, $20_1 | 0, i64toi32_i32$3 | 0);
  i64toi32_i32$2 = $4_1 + 8 | 0;
  i64toi32_i32$3 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $80_1 = i64toi32_i32$3;
  i64toi32_i32$3 = $0_1;
  HEAP32[(i64toi32_i32$3 + 8 | 0) >> 2] = $80_1;
  HEAP32[(i64toi32_i32$3 + 12 | 0) >> 2] = i64toi32_i32$0;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $83_1 = i64toi32_i32$0;
  i64toi32_i32$0 = $0_1;
  HEAP32[i64toi32_i32$0 >> 2] = $83_1;
  HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$3;
  global$0 = i64toi32_i32$2 + 80 | 0;
 }
 
 function $54($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, $2$hi = 0, $2_1 = 0, $13_1 = 0, $3_1 = 0, $4_1 = 0;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$1 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $2_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $2$hi = i64toi32_i32$1;
  label$1 : {
   label$2 : {
    i64toi32_i32$1 = i64toi32_i32$0;
    i64toi32_i32$0 = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    i64toi32_i32$3 = 48;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = 0;
     $13_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     $13_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
    }
    $3_1 = $13_1 & 32767 | 0;
    if (($3_1 | 0) == (32767 | 0)) {
     break label$2
    }
    $4_1 = 4;
    if ($3_1) {
     break label$1
    }
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$1 = $2_1;
    i64toi32_i32$0 = $0$hi;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
    return (!(i64toi32_i32$1 | i64toi32_i32$3 | 0 | i64toi32_i32$0 | 0) ? 2 : 3) | 0;
   }
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$2 = $2_1;
   i64toi32_i32$1 = $0$hi;
   i64toi32_i32$3 = $0_1;
   i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $4_1 = !(i64toi32_i32$2 | i64toi32_i32$3 | 0 | i64toi32_i32$1 | 0);
  }
  return $4_1 | 0;
 }
 
 function $55($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, $5_1 = 0, i64toi32_i32$5 = 0, $10$hi = 0, $10_1 = 0, $9$hi = 0, $8_1 = 0, $9_1 = 0, i64toi32_i32$6 = 0, $6_1 = 0, $11$hi = 0, $52_1 = 0, $7_1 = 0, $53_1 = 0, $54_1 = 0, $55_1 = 0, $11_1 = 0, $56_1 = 0, $57_1 = 0, $58_1 = 0, $59_1 = 0, $60_1 = 0, $61_1 = 0, $62_1 = 0, $63_1 = 0, $64_1 = 0, $65_1 = 0, $66_1 = 0, $67_1 = 0, $68_1 = 0, $69_1 = 0, $70_1 = 0, $71_1 = 0, $123$hi = 0, $126 = 0, $127$hi = 0, $148 = 0, $148$hi = 0, $150$hi = 0, $153 = 0, $153$hi = 0, $155$hi = 0, $167$hi = 0, $170 = 0, $171$hi = 0, $200 = 0, $200$hi = 0, $202$hi = 0, $211 = 0, $212 = 0, $212$hi = 0, $214 = 0, $214$hi = 0, $220$hi = 0, $221 = 0, $221$hi = 0, $228 = 0, $228$hi = 0, $233$hi = 0;
  $5_1 = global$0 - 128 | 0;
  global$0 = $5_1;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$2 = 0;
     i64toi32_i32$3 = 0;
     if (!($87($3_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0) | 0)) {
      break label$3
     }
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$3 = i64toi32_i32$1;
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$1;
     $6_1 = $54($3_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$1 | 0) | 0;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 48;
     i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = 0;
      $52_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$3 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
      $52_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
     }
     $7_1 = $52_1;
     $8_1 = $7_1 & 32767 | 0;
     if (($8_1 | 0) == (32767 | 0)) {
      break label$3
     }
     if ($6_1) {
      break label$2
     }
    }
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$0 = $4$hi;
    $97($5_1 + 16 | 0 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $2_1 | 0, i64toi32_i32$1 | 0, $3_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$0 | 0);
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 16 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 20 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$0;
    $4$hi = i64toi32_i32$2;
    i64toi32_i32$1 = (i64toi32_i32$1 + 16 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $3_1 = i64toi32_i32$2;
    $3$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$1 = i64toi32_i32$0;
    i64toi32_i32$3 = i64toi32_i32$2;
    $89($5_1 | 0, $4_1 | 0, i64toi32_i32$0 | 0, $3_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$0 | 0, $3_1 | 0, i64toi32_i32$2 | 0);
    i64toi32_i32$2 = $5_1 + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$3;
    $2$hi = i64toi32_i32$1;
    i64toi32_i32$2 = $5_1;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$1;
    $4$hi = i64toi32_i32$3;
    break label$1;
   }
   label$4 : {
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$2 = $2_1;
    i64toi32_i32$1 = 2147483647;
    i64toi32_i32$0 = -1;
    i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
    $9_1 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
    $9$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$2 = 2147483647;
    i64toi32_i32$0 = -1;
    i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
    $10_1 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
    $10$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$3 = $9$hi;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$0 = $10$hi;
    if (($87($1_1 | 0, i64toi32_i32$2 | 0, $9_1 | 0, i64toi32_i32$3 | 0, $3_1 | 0, i64toi32_i32$1 | 0, $10_1 | 0, i64toi32_i32$0 | 0) | 0 | 0) > (0 | 0)) {
     break label$4
    }
    label$5 : {
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$0 = i64toi32_i32$3;
     i64toi32_i32$0 = i64toi32_i32$1;
     i64toi32_i32$0 = $10$hi;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$1 = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$2 = $10$hi;
     if (!($87($1_1 | 0, i64toi32_i32$0 | 0, $9_1 | 0, i64toi32_i32$1 | 0, $3_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$2 | 0) | 0)) {
      break label$5
     }
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$0;
     $4_1 = $1_1;
     $4$hi = i64toi32_i32$0;
     break label$1;
    }
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = 0;
    $97($5_1 + 112 | 0 | 0, $1_1 | 0, i64toi32_i32$2 | 0, $2_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0);
    i64toi32_i32$3 = $5_1 + 120 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$0;
    $2$hi = i64toi32_i32$1;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 112 | 0) >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 116 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$1;
    $4$hi = i64toi32_i32$0;
    break label$1;
   }
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$3 = $4_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$2 = 48;
   i64toi32_i32$4 = i64toi32_i32$2 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $53_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    $53_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
   }
   $6_1 = $53_1 & 32767 | 0;
   label$6 : {
    label$7 : {
     if (!$8_1) {
      break label$7
     }
     i64toi32_i32$1 = $1$hi;
     $4_1 = $1_1;
     $4$hi = i64toi32_i32$1;
     break label$6;
    }
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = $9$hi;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$3 = $9$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 1081540608;
    $97($5_1 + 96 | 0 | 0, $1_1 | 0, i64toi32_i32$1 | 0, $9_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$2 | 0);
    i64toi32_i32$3 = $5_1 + 104 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $9_1 = i64toi32_i32$2;
    $9$hi = i64toi32_i32$0;
    i64toi32_i32$3 = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    i64toi32_i32$1 = 48;
    i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = 0;
     $54_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     $54_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
    }
    $8_1 = $54_1 + -120 | 0;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 96 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 100 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$2;
    $4$hi = i64toi32_i32$3;
   }
   label$8 : {
    if ($6_1) {
     break label$8
    }
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $10$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 1081540608;
    $97($5_1 + 80 | 0 | 0, $3_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0);
    i64toi32_i32$2 = $5_1 + 88 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$1;
    $10$hi = i64toi32_i32$0;
    i64toi32_i32$2 = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 48;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $55_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     $55_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
    }
    $6_1 = $55_1 + -120 | 0;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 80 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 84 | 0) >> 2] | 0;
    $3_1 = i64toi32_i32$1;
    $3$hi = i64toi32_i32$2;
   }
   i64toi32_i32$2 = $10$hi;
   i64toi32_i32$0 = $10_1;
   i64toi32_i32$1 = 65535;
   i64toi32_i32$3 = -1;
   i64toi32_i32$1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
   i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
   i64toi32_i32$0 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
   $11_1 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   $11$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $9$hi;
   i64toi32_i32$1 = $9_1;
   i64toi32_i32$2 = 65535;
   i64toi32_i32$3 = -1;
   i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
   i64toi32_i32$1 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
   $9_1 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
   $9$hi = i64toi32_i32$1;
   label$9 : {
    if (($8_1 | 0) <= ($6_1 | 0)) {
     break label$9
    }
    label$10 : while (1) {
     label$11 : {
      label$12 : {
       i64toi32_i32$1 = $9$hi;
       i64toi32_i32$1 = $11$hi;
       i64toi32_i32$1 = $9$hi;
       i64toi32_i32$2 = $9_1;
       i64toi32_i32$0 = $11$hi;
       i64toi32_i32$3 = $11_1;
       i64toi32_i32$4 = i64toi32_i32$2 - i64toi32_i32$3 | 0;
       i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0;
       i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$0 | 0;
       i64toi32_i32$5 = i64toi32_i32$1 - i64toi32_i32$5 | 0;
       $123$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $4$hi;
       i64toi32_i32$5 = $3$hi;
       i64toi32_i32$5 = $4$hi;
       i64toi32_i32$1 = $4_1;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$3 = $3_1;
       $126 = $4$hi >>> 0 < i64toi32_i32$2 >>> 0 | (($4$hi | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
       i64toi32_i32$1 = 0;
       $127$hi = i64toi32_i32$1;
       i64toi32_i32$1 = $123$hi;
       i64toi32_i32$3 = i64toi32_i32$4;
       i64toi32_i32$5 = $127$hi;
       i64toi32_i32$2 = $126;
       i64toi32_i32$0 = i64toi32_i32$3 - i64toi32_i32$2 | 0;
       i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0;
       i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
       i64toi32_i32$4 = i64toi32_i32$1 - i64toi32_i32$4 | 0;
       $10_1 = i64toi32_i32$0;
       $10$hi = i64toi32_i32$4;
       i64toi32_i32$1 = i64toi32_i32$0;
       i64toi32_i32$3 = 0;
       i64toi32_i32$2 = 0;
       if ((i64toi32_i32$4 | 0) < (i64toi32_i32$3 | 0)) {
        $56_1 = 1
       } else {
        if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$3 | 0)) {
         if (i64toi32_i32$1 >>> 0 >= i64toi32_i32$2 >>> 0) {
          $57_1 = 0
         } else {
          $57_1 = 1
         }
         $58_1 = $57_1;
        } else {
         $58_1 = 0
        }
        $56_1 = $58_1;
       }
       if ($56_1) {
        break label$12
       }
       label$13 : {
        i64toi32_i32$1 = $10$hi;
        i64toi32_i32$1 = $4$hi;
        i64toi32_i32$1 = $3$hi;
        i64toi32_i32$1 = $4$hi;
        i64toi32_i32$2 = $4_1;
        i64toi32_i32$4 = $3$hi;
        i64toi32_i32$3 = $3_1;
        i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$3 | 0;
        i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0;
        i64toi32_i32$0 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
        i64toi32_i32$0 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
        $4_1 = i64toi32_i32$5;
        $4$hi = i64toi32_i32$0;
        i64toi32_i32$0 = $10$hi;
        i64toi32_i32$1 = $10_1;
        i64toi32_i32$2 = $4$hi;
        i64toi32_i32$3 = $4_1;
        i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
        i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
        i64toi32_i32$1 = 0;
        i64toi32_i32$3 = 0;
        if ((i64toi32_i32$0 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | 0) {
         break label$13
        }
        i64toi32_i32$0 = $1$hi;
        i64toi32_i32$0 = $2$hi;
        i64toi32_i32$0 = $1$hi;
        i64toi32_i32$2 = $2$hi;
        i64toi32_i32$3 = 0;
        i64toi32_i32$1 = 0;
        $97($5_1 + 32 | 0 | 0, $1_1 | 0, i64toi32_i32$0 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0);
        i64toi32_i32$2 = $5_1 + 40 | 0;
        i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
        i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
        $2_1 = i64toi32_i32$1;
        $2$hi = i64toi32_i32$3;
        i64toi32_i32$2 = $5_1;
        i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 32 | 0) >> 2] | 0;
        i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 36 | 0) >> 2] | 0;
        $4_1 = i64toi32_i32$3;
        $4$hi = i64toi32_i32$1;
        break label$1;
       }
       i64toi32_i32$1 = $10$hi;
       i64toi32_i32$2 = $10_1;
       i64toi32_i32$3 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
        $59_1 = 0;
       } else {
        i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
        $59_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
       }
       $148 = $59_1;
       $148$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $4$hi;
       i64toi32_i32$1 = $4_1;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 63;
       i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = 0;
        $60_1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
       } else {
        i64toi32_i32$2 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
        $60_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
       }
       $150$hi = i64toi32_i32$2;
       i64toi32_i32$2 = $148$hi;
       i64toi32_i32$3 = $148;
       i64toi32_i32$1 = $150$hi;
       i64toi32_i32$0 = $60_1;
       i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
       $9_1 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
       $9$hi = i64toi32_i32$1;
       break label$11;
      }
      i64toi32_i32$1 = $9$hi;
      i64toi32_i32$2 = $9_1;
      i64toi32_i32$3 = 0;
      i64toi32_i32$0 = 1;
      i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
       i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
       $61_1 = 0;
      } else {
       i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
       $61_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
      }
      $153 = $61_1;
      $153$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $4$hi;
      i64toi32_i32$1 = $4_1;
      i64toi32_i32$2 = 0;
      i64toi32_i32$0 = 63;
      i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
       i64toi32_i32$2 = 0;
       $62_1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
      } else {
       i64toi32_i32$2 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
       $62_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
      }
      $155$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $153$hi;
      i64toi32_i32$3 = $153;
      i64toi32_i32$1 = $155$hi;
      i64toi32_i32$0 = $62_1;
      i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
      $9_1 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
      $9$hi = i64toi32_i32$1;
     }
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$2 = $4_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 1;
     i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
      $63_1 = 0;
     } else {
      i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
      $63_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
     }
     $4_1 = $63_1;
     $4$hi = i64toi32_i32$3;
     $8_1 = $8_1 + -1 | 0;
     if (($8_1 | 0) > ($6_1 | 0)) {
      continue label$10
     }
     break label$10;
    };
    $8_1 = $6_1;
   }
   label$14 : {
    label$15 : {
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$1 = $9_1;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$0 = $11_1;
     i64toi32_i32$4 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
     i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0;
     i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 - i64toi32_i32$5 | 0;
     $167$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$0 = $3_1;
     $170 = $4$hi >>> 0 < i64toi32_i32$1 >>> 0 | (($4$hi | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $171$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $167$hi;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$5 = $171$hi;
     i64toi32_i32$1 = $170;
     i64toi32_i32$2 = i64toi32_i32$0 - i64toi32_i32$1 | 0;
     i64toi32_i32$6 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0;
     i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 - i64toi32_i32$4 | 0;
     $10_1 = i64toi32_i32$2;
     $10$hi = i64toi32_i32$4;
     i64toi32_i32$3 = i64toi32_i32$2;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$4 | 0) > (i64toi32_i32$0 | 0)) {
      $64_1 = 1
     } else {
      if ((i64toi32_i32$4 | 0) >= (i64toi32_i32$0 | 0)) {
       if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
        $65_1 = 0
       } else {
        $65_1 = 1
       }
       $66_1 = $65_1;
      } else {
       $66_1 = 0
      }
      $64_1 = $66_1;
     }
     if ($64_1) {
      break label$15
     }
     i64toi32_i32$3 = $9$hi;
     $10_1 = $9_1;
     $10$hi = i64toi32_i32$3;
     break label$14;
    }
    i64toi32_i32$3 = $10$hi;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$4 = $3$hi;
    i64toi32_i32$0 = $3_1;
    i64toi32_i32$5 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
    i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0;
    i64toi32_i32$2 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
    i64toi32_i32$2 = i64toi32_i32$3 - i64toi32_i32$2 | 0;
    $4_1 = i64toi32_i32$5;
    $4$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$3 = $10_1;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$0 = $4_1;
    i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$2 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$3 | 0) | 0) {
     break label$14
    }
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$3 = 0;
    $97($5_1 + 48 | 0 | 0, $1_1 | 0, i64toi32_i32$2 | 0, $2_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$1 = $5_1 + 56 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$3;
    $2$hi = i64toi32_i32$0;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 48 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 52 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$0;
    $4$hi = i64toi32_i32$3;
    break label$1;
   }
   label$16 : {
    i64toi32_i32$3 = $10$hi;
    i64toi32_i32$1 = $10_1;
    i64toi32_i32$0 = 65535;
    i64toi32_i32$2 = -1;
    if (i64toi32_i32$3 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0) {
     break label$16
    }
    label$17 : while (1) {
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$2 = $4_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 63;
     i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = 0;
      $67_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
      $67_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
     }
     $3_1 = $67_1;
     $3$hi = i64toi32_i32$3;
     $8_1 = $8_1 + -1 | 0;
     i64toi32_i32$3 = $4$hi;
     i64toi32_i32$1 = $4_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$0 = 1;
     i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
      $68_1 = 0;
     } else {
      i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
      $68_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     }
     $4_1 = $68_1;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $3$hi;
     $200 = $3_1;
     $200$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$3 = $10_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$0 = 1;
     i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
      $69_1 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
      $69_1 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
     }
     $202$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $200$hi;
     i64toi32_i32$2 = $200;
     i64toi32_i32$3 = $202$hi;
     i64toi32_i32$0 = $69_1;
     i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     $10_1 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     $10$hi = i64toi32_i32$3;
     i64toi32_i32$1 = $10_1;
     i64toi32_i32$2 = 65536;
     i64toi32_i32$0 = 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0) {
      continue label$17
     }
     break label$17;
    };
   }
   $6_1 = $7_1 & 32768 | 0;
   label$18 : {
    if (($8_1 | 0) > (0 | 0)) {
     break label$18
    }
    $211 = $5_1 + 64 | 0;
    i64toi32_i32$1 = $4$hi;
    $212 = $4_1;
    $212$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $10$hi;
    i64toi32_i32$0 = $10_1;
    i64toi32_i32$3 = 65535;
    i64toi32_i32$2 = -1;
    i64toi32_i32$3 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
    $214 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
    $214$hi = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    i64toi32_i32$1 = $8_1 + 120 | 0 | $6_1 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 48;
    i64toi32_i32$4 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     $70_1 = 0;
    } else {
     i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
     $70_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
    }
    $220$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $214$hi;
    i64toi32_i32$3 = $214;
    i64toi32_i32$1 = $220$hi;
    i64toi32_i32$2 = $70_1;
    i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $221 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
    $221$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $212$hi;
    i64toi32_i32$3 = $221$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 1065811968;
    $97($211 | 0, $212 | 0, i64toi32_i32$1 | 0, $221 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$2 | 0);
    i64toi32_i32$3 = $5_1 + 72 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$2;
    $2$hi = i64toi32_i32$0;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 64 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 68 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$0;
    $4$hi = i64toi32_i32$2;
    break label$1;
   }
   i64toi32_i32$2 = $10$hi;
   i64toi32_i32$3 = $10_1;
   i64toi32_i32$0 = 65535;
   i64toi32_i32$1 = -1;
   i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
   $228 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $228$hi = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$2 = $8_1 | $6_1 | 0;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = 48;
   i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
    $71_1 = 0;
   } else {
    i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
    $71_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
   }
   $233$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $228$hi;
   i64toi32_i32$0 = $228;
   i64toi32_i32$2 = $233$hi;
   i64toi32_i32$1 = $71_1;
   i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
   $2_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $2$hi = i64toi32_i32$2;
  }
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$0 = $0_1;
  HEAP32[i64toi32_i32$0 >> 2] = $4_1;
  HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$2;
  i64toi32_i32$2 = $2$hi;
  HEAP32[(i64toi32_i32$0 + 8 | 0) >> 2] = $2_1;
  HEAP32[(i64toi32_i32$0 + 12 | 0) >> 2] = i64toi32_i32$2;
  global$0 = $5_1 + 128 | 0;
 }
 
 function $56($0_1, $1_1, $1$hi, $2_1, $2$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, $5_1 = 0;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$2 = $2_1;
  i64toi32_i32$1 = 2147483647;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $5_1 = i64toi32_i32$2 & -1 | 0;
  i64toi32_i32$2 = $0_1;
  HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] = $5_1;
  HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] = i64toi32_i32$1;
  i64toi32_i32$1 = $1$hi;
  HEAP32[i64toi32_i32$2 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] = i64toi32_i32$1;
 }
 
 function $57($0_1, $1_1, $2_1, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $8_1 = 0, $10_1 = 0, $10$hi = 0, $4_1 = 0, $9_1 = 0, $11_1 = 0, $11$hi = 0, $7_1 = 0, $5_1 = 0, $6_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $23_1 = 0, $24_1 = 0, $25_1 = 0, $26_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $30_1 = 0, $31_1 = 0, $32_1 = 0, $33_1 = 0, $34_1 = 0, $35_1 = 0, $36_1 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $40_1 = 0, $12_1 = 0, $12$hi = 0;
  $4_1 = global$0 - 48 | 0;
  global$0 = $4_1;
  i64toi32_i32$0 = 0;
  $10_1 = 0;
  $10$hi = i64toi32_i32$0;
  label$1 : {
   label$2 : {
    if ($2_1 >>> 0 > 2 >>> 0) {
     break label$2
    }
    $2_1 = $2_1 << 2 | 0;
    $5_1 = HEAP32[($2_1 + 66188 | 0) >> 2] | 0;
    $6_1 = HEAP32[($2_1 + 66176 | 0) >> 2] | 0;
    label$3 : while (1) {
     label$4 : {
      label$5 : {
       $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$5
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
       $2_1 = HEAPU8[$2_1 >> 0] | 0;
       break label$4;
      }
      $2_1 = $50($1_1 | 0) | 0;
     }
     if ($58($2_1 | 0) | 0) {
      continue label$3
     }
     break label$3;
    };
    $7_1 = 1;
    label$6 : {
     label$7 : {
      switch ($2_1 + -43 | 0 | 0) {
      case 0:
      case 2:
       break label$7;
      default:
       break label$6;
      };
     }
     $7_1 = ($2_1 | 0) == (45 | 0) ? -1 : 1;
     label$8 : {
      $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
      if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
       break label$8
      }
      HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
      $2_1 = HEAPU8[$2_1 >> 0] | 0;
      break label$6;
     }
     $2_1 = $50($1_1 | 0) | 0;
    }
    $8_1 = 0;
    label$9 : {
     label$10 : {
      label$11 : {
       if (($2_1 & -33 | 0 | 0) != (73 | 0)) {
        break label$11
       }
       label$12 : while (1) {
        if (($8_1 | 0) == (7 | 0)) {
         break label$10
        }
        label$13 : {
         label$14 : {
          $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
          if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
           break label$14
          }
          HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
          $2_1 = HEAPU8[$2_1 >> 0] | 0;
          break label$13;
         }
         $2_1 = $50($1_1 | 0) | 0;
        }
        $9_1 = $8_1 + 65537 | 0;
        $8_1 = $8_1 + 1 | 0;
        if (($2_1 | 32 | 0 | 0) == (HEAP8[$9_1 >> 0] | 0 | 0)) {
         continue label$12
        }
        break label$12;
       };
      }
      label$15 : {
       if (($8_1 | 0) == (3 | 0)) {
        break label$15
       }
       if (($8_1 | 0) == (8 | 0)) {
        break label$10
       }
       if (!$3_1) {
        break label$9
       }
       if ($8_1 >>> 0 < 4 >>> 0) {
        break label$9
       }
       if (($8_1 | 0) == (8 | 0)) {
        break label$10
       }
      }
      label$16 : {
       i64toi32_i32$2 = $1_1;
       i64toi32_i32$0 = HEAP32[($1_1 + 112 | 0) >> 2] | 0;
       i64toi32_i32$1 = HEAP32[($1_1 + 116 | 0) >> 2] | 0;
       $10_1 = i64toi32_i32$0;
       $10$hi = i64toi32_i32$1;
       i64toi32_i32$2 = i64toi32_i32$0;
       i64toi32_i32$0 = 0;
       i64toi32_i32$3 = 0;
       if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
        $20_1 = 1
       } else {
        if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
         if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) {
          $21_1 = 0
         } else {
          $21_1 = 1
         }
         $22_1 = $21_1;
        } else {
         $22_1 = 0
        }
        $20_1 = $22_1;
       }
       if ($20_1) {
        break label$16
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
      }
      if (!$3_1) {
       break label$10
      }
      if ($8_1 >>> 0 < 4 >>> 0) {
       break label$10
      }
      i64toi32_i32$2 = $10$hi;
      i64toi32_i32$3 = $10_1;
      i64toi32_i32$1 = 0;
      i64toi32_i32$0 = 0;
      if ((i64toi32_i32$2 | 0) < (i64toi32_i32$1 | 0)) {
       $23_1 = 1
      } else {
       if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$1 | 0)) {
        if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$0 >>> 0) {
         $24_1 = 0
        } else {
         $24_1 = 1
        }
        $25_1 = $24_1;
       } else {
        $25_1 = 0
       }
       $23_1 = $25_1;
      }
      $2_1 = $23_1;
      label$17 : while (1) {
       label$18 : {
        if ($2_1) {
         break label$18
        }
        HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
       }
       $8_1 = $8_1 + -1 | 0;
       if ($8_1 >>> 0 > 3 >>> 0) {
        continue label$17
       }
       break label$17;
      };
     }
     $91($4_1 | 0, Math_fround(Math_fround(Math_fround($7_1 | 0) * Math_fround(Infinity))));
     i64toi32_i32$0 = $4_1 + 8 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
     $11_1 = i64toi32_i32$3;
     $11$hi = i64toi32_i32$2;
     i64toi32_i32$0 = $4_1;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
     $10_1 = i64toi32_i32$2;
     $10$hi = i64toi32_i32$3;
     break label$1;
    }
    label$19 : {
     label$20 : {
      label$21 : {
       label$22 : {
        label$23 : {
         if ($8_1) {
          break label$23
         }
         $8_1 = 0;
         if (($2_1 & -33 | 0 | 0) != (78 | 0)) {
          break label$23
         }
         label$24 : while (1) {
          if (($8_1 | 0) == (2 | 0)) {
           break label$22
          }
          label$25 : {
           label$26 : {
            $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
            if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
             break label$26
            }
            HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
            $2_1 = HEAPU8[$2_1 >> 0] | 0;
            break label$25;
           }
           $2_1 = $50($1_1 | 0) | 0;
          }
          $9_1 = $8_1 + 65575 | 0;
          $8_1 = $8_1 + 1 | 0;
          if (($2_1 | 32 | 0 | 0) == (HEAP8[$9_1 >> 0] | 0 | 0)) {
           continue label$24
          }
          break label$24;
         };
        }
        switch ($8_1 | 0) {
        case 0:
         break label$19;
        case 3:
         break label$22;
        default:
         break label$21;
        };
       }
       label$27 : {
        label$28 : {
         $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
         if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
          break label$28
         }
         HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
         $2_1 = HEAPU8[$2_1 >> 0] | 0;
         break label$27;
        }
        $2_1 = $50($1_1 | 0) | 0;
       }
       label$29 : {
        label$30 : {
         if (($2_1 | 0) != (40 | 0)) {
          break label$30
         }
         $8_1 = 1;
         break label$29;
        }
        i64toi32_i32$3 = 0;
        $10_1 = 0;
        $10$hi = i64toi32_i32$3;
        i64toi32_i32$3 = 2147450880;
        $11_1 = 0;
        $11$hi = i64toi32_i32$3;
        i64toi32_i32$0 = $1_1;
        i64toi32_i32$3 = HEAP32[($1_1 + 112 | 0) >> 2] | 0;
        i64toi32_i32$2 = HEAP32[($1_1 + 116 | 0) >> 2] | 0;
        i64toi32_i32$0 = i64toi32_i32$3;
        i64toi32_i32$3 = 0;
        i64toi32_i32$1 = 0;
        if ((i64toi32_i32$2 | 0) < (i64toi32_i32$3 | 0)) {
         $26_1 = 1
        } else {
         if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$3 | 0)) {
          if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$1 >>> 0) {
           $27_1 = 0
          } else {
           $27_1 = 1
          }
          $28_1 = $27_1;
         } else {
          $28_1 = 0
         }
         $26_1 = $28_1;
        }
        if ($26_1) {
         break label$1
        }
        HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
        break label$1;
       }
       label$31 : while (1) {
        label$32 : {
         label$33 : {
          $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
          if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
           break label$33
          }
          HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
          $2_1 = HEAPU8[$2_1 >> 0] | 0;
          break label$32;
         }
         $2_1 = $50($1_1 | 0) | 0;
        }
        $9_1 = $2_1 + -65 | 0;
        label$34 : {
         label$35 : {
          if (($2_1 + -48 | 0) >>> 0 < 10 >>> 0) {
           break label$35
          }
          if ($9_1 >>> 0 < 26 >>> 0) {
           break label$35
          }
          $9_1 = $2_1 + -97 | 0;
          if (($2_1 | 0) == (95 | 0)) {
           break label$35
          }
          if ($9_1 >>> 0 >= 26 >>> 0) {
           break label$34
          }
         }
         $8_1 = $8_1 + 1 | 0;
         continue label$31;
        }
        break label$31;
       };
       i64toi32_i32$0 = 2147450880;
       $11_1 = 0;
       $11$hi = i64toi32_i32$0;
       if (($2_1 | 0) == (41 | 0)) {
        break label$1
       }
       label$36 : {
        i64toi32_i32$1 = $1_1;
        i64toi32_i32$0 = HEAP32[($1_1 + 112 | 0) >> 2] | 0;
        i64toi32_i32$2 = HEAP32[($1_1 + 116 | 0) >> 2] | 0;
        $12_1 = i64toi32_i32$0;
        $12$hi = i64toi32_i32$2;
        i64toi32_i32$1 = i64toi32_i32$0;
        i64toi32_i32$0 = 0;
        i64toi32_i32$3 = 0;
        if ((i64toi32_i32$2 | 0) < (i64toi32_i32$0 | 0)) {
         $29_1 = 1
        } else {
         if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$0 | 0)) {
          if (i64toi32_i32$1 >>> 0 >= i64toi32_i32$3 >>> 0) {
           $30_1 = 0
          } else {
           $30_1 = 1
          }
          $31_1 = $30_1;
         } else {
          $31_1 = 0
         }
         $29_1 = $31_1;
        }
        if ($29_1) {
         break label$36
        }
        HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
       }
       label$37 : {
        label$38 : {
         if (!$3_1) {
          break label$38
         }
         if ($8_1) {
          break label$37
         }
         i64toi32_i32$1 = 0;
         $10_1 = 0;
         $10$hi = i64toi32_i32$1;
         break label$1;
        }
        HEAP32[($16() | 0) >> 2] = 28;
        i64toi32_i32$1 = 0;
        $10_1 = 0;
        $10$hi = i64toi32_i32$1;
        break label$20;
       }
       label$39 : while (1) {
        label$40 : {
         i64toi32_i32$1 = $12$hi;
         i64toi32_i32$3 = $12_1;
         i64toi32_i32$2 = 0;
         i64toi32_i32$0 = 0;
         if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) {
          $32_1 = 1
         } else {
          if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
           if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$0 >>> 0) {
            $33_1 = 0
           } else {
            $33_1 = 1
           }
           $34_1 = $33_1;
          } else {
           $34_1 = 0
          }
          $32_1 = $34_1;
         }
         if ($32_1) {
          break label$40
         }
         HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
        }
        i64toi32_i32$3 = 0;
        $10_1 = 0;
        $10$hi = i64toi32_i32$3;
        $8_1 = $8_1 + -1 | 0;
        if ($8_1) {
         continue label$39
        }
        break label$1;
       };
      }
      i64toi32_i32$3 = 0;
      $10_1 = 0;
      $10$hi = i64toi32_i32$3;
      label$41 : {
       i64toi32_i32$0 = $1_1;
       i64toi32_i32$3 = HEAP32[($1_1 + 112 | 0) >> 2] | 0;
       i64toi32_i32$1 = HEAP32[($1_1 + 116 | 0) >> 2] | 0;
       i64toi32_i32$0 = i64toi32_i32$3;
       i64toi32_i32$3 = 0;
       i64toi32_i32$2 = 0;
       if ((i64toi32_i32$1 | 0) < (i64toi32_i32$3 | 0)) {
        $35_1 = 1
       } else {
        if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$3 | 0)) {
         if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$2 >>> 0) {
          $36_1 = 0
         } else {
          $36_1 = 1
         }
         $37_1 = $36_1;
        } else {
         $37_1 = 0
        }
        $35_1 = $37_1;
       }
       if ($35_1) {
        break label$41
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
      }
      HEAP32[($16() | 0) >> 2] = 28;
     }
     i64toi32_i32$0 = $10$hi;
     $49($1_1 | 0, $10_1 | 0, i64toi32_i32$0 | 0);
     break label$2;
    }
    label$42 : {
     if (($2_1 | 0) != (48 | 0)) {
      break label$42
     }
     label$43 : {
      label$44 : {
       $8_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($8_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$44
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $8_1 + 1 | 0;
       $8_1 = HEAPU8[$8_1 >> 0] | 0;
       break label$43;
      }
      $8_1 = $50($1_1 | 0) | 0;
     }
     label$45 : {
      if (($8_1 & -33 | 0 | 0) != (88 | 0)) {
       break label$45
      }
      $59($4_1 + 16 | 0 | 0, $1_1 | 0, $6_1 | 0, $5_1 | 0, $7_1 | 0, $3_1 | 0);
      i64toi32_i32$2 = $4_1 + 24 | 0;
      i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
      $11_1 = i64toi32_i32$0;
      $11$hi = i64toi32_i32$1;
      i64toi32_i32$2 = $4_1;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 16 | 0) >> 2] | 0;
      i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 20 | 0) >> 2] | 0;
      $10_1 = i64toi32_i32$1;
      $10$hi = i64toi32_i32$0;
      break label$1;
     }
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$0 = HEAP32[($1_1 + 112 | 0) >> 2] | 0;
     i64toi32_i32$1 = HEAP32[($1_1 + 116 | 0) >> 2] | 0;
     i64toi32_i32$2 = i64toi32_i32$0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
      $38_1 = 1
     } else {
      if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
       if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) {
        $39_1 = 0
       } else {
        $39_1 = 1
       }
       $40_1 = $39_1;
      } else {
       $40_1 = 0
      }
      $38_1 = $40_1;
     }
     if ($38_1) {
      break label$42
     }
     HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
    }
    $60($4_1 + 32 | 0 | 0, $1_1 | 0, $2_1 | 0, $6_1 | 0, $5_1 | 0, $7_1 | 0, $3_1 | 0);
    i64toi32_i32$3 = $4_1 + 40 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $11_1 = i64toi32_i32$2;
    $11$hi = i64toi32_i32$1;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 32 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 36 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$1;
    $10$hi = i64toi32_i32$2;
    break label$1;
   }
   i64toi32_i32$2 = 0;
   $11_1 = 0;
   $11$hi = i64toi32_i32$2;
  }
  i64toi32_i32$2 = $10$hi;
  i64toi32_i32$1 = $0_1;
  HEAP32[i64toi32_i32$1 >> 2] = $10_1;
  HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$2;
  i64toi32_i32$2 = $11$hi;
  HEAP32[(i64toi32_i32$1 + 8 | 0) >> 2] = $11_1;
  HEAP32[(i64toi32_i32$1 + 12 | 0) >> 2] = i64toi32_i32$2;
  global$0 = $4_1 + 48 | 0;
 }
 
 function $58($0_1) {
  $0_1 = $0_1 | 0;
  return ($0_1 | 0) == (32 | 0) | ($0_1 + -9 | 0) >>> 0 < 5 >>> 0 | 0 | 0;
 }
 
 function $59($0_1, $1_1, $2_1, $3_1, $4_1, $5_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  $5_1 = $5_1 | 0;
  var i64toi32_i32$3 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$2 = 0, $6_1 = 0, $7_1 = 0, $16$hi = 0, $19$hi = 0, $16_1 = 0, $19_1 = 0, $15$hi = 0, $17$hi = 0, $14$hi = 0, $15_1 = 0, $17_1 = 0, $18$hi = 0, $14_1 = 0, $10_1 = 0, $18_1 = 0, $8_1 = 0, $9_1 = 0, $20$hi = 0, $12_1 = 0, $20_1 = 0, $11_1 = 0, $13_1 = 0, $104_1 = 0, $105_1 = 0, $106_1 = 0, $107_1 = 0, $108_1 = 0, $109 = 0, $110 = 0, $111 = 0, $112 = 0, $113 = 0, $114 = 0, $115 = 0, $116 = 0, $117 = 0, $118 = 0, $119 = 0, $120 = 0, $121 = 0, $122 = 0, $123 = 0, $124 = 0, $125 = 0, $127 = 0, $128 = 0, $129 = 0, $126 = 0, $126$hi = 0, $130 = 0, $130$hi = 0, $141 = 0, $141$hi = 0, $145 = 0, $145$hi = 0, $163 = 0, $163$hi = 0, $167 = 0, $167$hi = 0, $267$hi = 0, $274$hi = 0, $283 = 0, $283$hi = 0, $287 = 0, $287$hi = 0, $291 = 0, $291$hi = 0, $295 = 0, $295$hi = 0, $305 = 0, $305$hi = 0, $321$hi = 0, $131 = 0, $326 = 0, $326$hi = 0, $330$hi = 0, $132 = 0, $333 = 0, $333$hi = 0, $350$hi = 0, $358 = 0, $359 = 0, $362$hi = 0, $386 = 0, $386$hi = 0, $390 = 0, $390$hi = 0, $426 = 0, $426$hi = 0, $430 = 0, $430$hi = 0, $434 = 0, $434$hi = 0, $438 = 0, $438$hi = 0, $447 = 0, $447$hi = 0, $450 = 0, $450$hi = 0, $454 = 0, $454$hi = 0, $458 = 0, $458$hi = 0, $460 = 0, $460$hi = 0, $464 = 0, $464$hi = 0, $468 = 0, $468$hi = 0, $472 = 0, $472$hi = 0, $504 = 0, $504$hi = 0, $508 = 0, $508$hi = 0, $512 = 0, $512$hi = 0, $516 = 0, $516$hi = 0;
  $6_1 = global$0 - 432 | 0;
  global$0 = $6_1;
  label$1 : {
   label$2 : {
    $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
    if (($7_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
     break label$2
    }
    HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + 1 | 0;
    $7_1 = HEAPU8[$7_1 >> 0] | 0;
    break label$1;
   }
   $7_1 = $50($1_1 | 0) | 0;
  }
  $8_1 = 0;
  i64toi32_i32$0 = 0;
  $14_1 = 0;
  $14$hi = i64toi32_i32$0;
  $9_1 = 0;
  label$3 : {
   label$4 : {
    label$5 : {
     label$6 : while (1) {
      label$7 : {
       if (($7_1 | 0) == (48 | 0)) {
        break label$7
       }
       if (($7_1 | 0) != (46 | 0)) {
        break label$3
       }
       $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($7_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$5
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + 1 | 0;
       $7_1 = HEAPU8[$7_1 >> 0] | 0;
       break label$4;
      }
      label$8 : {
       $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($7_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$8
       }
       $9_1 = 1;
       HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + 1 | 0;
       $7_1 = HEAPU8[$7_1 >> 0] | 0;
       continue label$6;
      }
      $9_1 = 1;
      $7_1 = $50($1_1 | 0) | 0;
      continue label$6;
     };
    }
    $7_1 = $50($1_1 | 0) | 0;
   }
   $8_1 = 1;
   i64toi32_i32$0 = 0;
   $14_1 = 0;
   $14$hi = i64toi32_i32$0;
   if (($7_1 | 0) != (48 | 0)) {
    break label$3
   }
   label$9 : while (1) {
    label$10 : {
     label$11 : {
      $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
      if (($7_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
       break label$11
      }
      HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + 1 | 0;
      $7_1 = HEAPU8[$7_1 >> 0] | 0;
      break label$10;
     }
     $7_1 = $50($1_1 | 0) | 0;
    }
    i64toi32_i32$0 = $14$hi;
    i64toi32_i32$2 = $14_1;
    i64toi32_i32$1 = -1;
    i64toi32_i32$3 = -1;
    i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $14_1 = i64toi32_i32$4;
    $14$hi = i64toi32_i32$5;
    if (($7_1 | 0) == (48 | 0)) {
     continue label$9
    }
    break label$9;
   };
   $8_1 = 1;
   $9_1 = 1;
  }
  i64toi32_i32$5 = 1073676288;
  $15_1 = 0;
  $15$hi = i64toi32_i32$5;
  $10_1 = 0;
  i64toi32_i32$5 = 0;
  $16_1 = 0;
  $16$hi = i64toi32_i32$5;
  i64toi32_i32$5 = 0;
  $17_1 = 0;
  $17$hi = i64toi32_i32$5;
  i64toi32_i32$5 = 0;
  $18_1 = 0;
  $18$hi = i64toi32_i32$5;
  $11_1 = 0;
  i64toi32_i32$5 = 0;
  $19_1 = 0;
  $19$hi = i64toi32_i32$5;
  label$12 : {
   label$13 : while (1) {
    $12_1 = $7_1;
    label$14 : {
     label$15 : {
      $13_1 = $7_1 + -48 | 0;
      if ($13_1 >>> 0 < 10 >>> 0) {
       break label$15
      }
      $12_1 = $7_1 | 32 | 0;
      label$16 : {
       if (($7_1 | 0) == (46 | 0)) {
        break label$16
       }
       if (($12_1 + -97 | 0) >>> 0 > 5 >>> 0) {
        break label$12
       }
      }
      if (($7_1 | 0) != (46 | 0)) {
       break label$15
      }
      if ($8_1) {
       break label$12
      }
      $8_1 = 1;
      i64toi32_i32$5 = $19$hi;
      $14_1 = $19_1;
      $14$hi = i64toi32_i32$5;
      break label$14;
     }
     $7_1 = ($7_1 | 0) > (57 | 0) ? $12_1 + -87 | 0 : $13_1;
     label$17 : {
      label$18 : {
       i64toi32_i32$5 = $19$hi;
       i64toi32_i32$0 = $19_1;
       i64toi32_i32$2 = 0;
       i64toi32_i32$3 = 7;
       if ((i64toi32_i32$5 | 0) > (i64toi32_i32$2 | 0)) {
        $104_1 = 1
       } else {
        if ((i64toi32_i32$5 | 0) >= (i64toi32_i32$2 | 0)) {
         if (i64toi32_i32$0 >>> 0 <= i64toi32_i32$3 >>> 0) {
          $105_1 = 0
         } else {
          $105_1 = 1
         }
         $106_1 = $105_1;
        } else {
         $106_1 = 0
        }
        $104_1 = $106_1;
       }
       if ($104_1) {
        break label$18
       }
       $10_1 = $7_1 + ($10_1 << 4 | 0) | 0;
       break label$17;
      }
      label$19 : {
       i64toi32_i32$0 = $19$hi;
       i64toi32_i32$3 = $19_1;
       i64toi32_i32$5 = 0;
       i64toi32_i32$2 = 28;
       if (i64toi32_i32$0 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0) {
        break label$19
       }
       $92($6_1 + 48 | 0 | 0, $7_1 | 0);
       i64toi32_i32$3 = $18$hi;
       i64toi32_i32$3 = $15$hi;
       i64toi32_i32$3 = $18$hi;
       i64toi32_i32$0 = $15$hi;
       i64toi32_i32$2 = 0;
       i64toi32_i32$5 = 1073414144;
       $97($6_1 + 32 | 0 | 0, $18_1 | 0, i64toi32_i32$3 | 0, $15_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0);
       i64toi32_i32$0 = $6_1;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 48 | 0) >> 2] | 0;
       i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 52 | 0) >> 2] | 0;
       $126 = i64toi32_i32$5;
       $126$hi = i64toi32_i32$2;
       i64toi32_i32$0 = (i64toi32_i32$0 + 48 | 0) + 8 | 0;
       i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
       $130 = i64toi32_i32$2;
       $130$hi = i64toi32_i32$5;
       i64toi32_i32$0 = $6_1;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 32 | 0) >> 2] | 0;
       i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 36 | 0) >> 2] | 0;
       $18_1 = i64toi32_i32$5;
       $18$hi = i64toi32_i32$2;
       i64toi32_i32$0 = (i64toi32_i32$0 + 32 | 0) + 8 | 0;
       i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
       $15_1 = i64toi32_i32$2;
       $15$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $126$hi;
       i64toi32_i32$2 = $130$hi;
       i64toi32_i32$0 = $18$hi;
       i64toi32_i32$3 = $15$hi;
       $97($6_1 + 16 | 0 | 0, $126 | 0, i64toi32_i32$5 | 0, $130 | 0, i64toi32_i32$2 | 0, $18_1 | 0, i64toi32_i32$0 | 0, $15_1 | 0, i64toi32_i32$3 | 0);
       i64toi32_i32$2 = $6_1;
       i64toi32_i32$3 = HEAP32[($6_1 + 16 | 0) >> 2] | 0;
       i64toi32_i32$0 = HEAP32[($6_1 + 20 | 0) >> 2] | 0;
       $141 = i64toi32_i32$3;
       $141$hi = i64toi32_i32$0;
       i64toi32_i32$2 = ($6_1 + 16 | 0) + 8 | 0;
       i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
       i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
       $145 = i64toi32_i32$0;
       $145$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $16$hi;
       i64toi32_i32$3 = $17$hi;
       i64toi32_i32$3 = $141$hi;
       i64toi32_i32$0 = $145$hi;
       i64toi32_i32$2 = $16$hi;
       i64toi32_i32$5 = $17$hi;
       $85($6_1 | 0, $141 | 0, i64toi32_i32$3 | 0, $145 | 0, i64toi32_i32$0 | 0, $16_1 | 0, i64toi32_i32$2 | 0, $17_1 | 0, i64toi32_i32$5 | 0);
       i64toi32_i32$0 = $6_1 + 8 | 0;
       i64toi32_i32$5 = HEAP32[i64toi32_i32$0 >> 2] | 0;
       i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
       $17_1 = i64toi32_i32$5;
       $17$hi = i64toi32_i32$2;
       i64toi32_i32$0 = $6_1;
       i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
       $16_1 = i64toi32_i32$2;
       $16$hi = i64toi32_i32$5;
       break label$17;
      }
      if (!$7_1) {
       break label$17
      }
      if ($11_1) {
       break label$17
      }
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$5 = $15$hi;
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$2 = $15$hi;
      i64toi32_i32$0 = 0;
      i64toi32_i32$3 = 1073610752;
      $97($6_1 + 80 | 0 | 0, $18_1 | 0, i64toi32_i32$5 | 0, $15_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$3 | 0);
      i64toi32_i32$2 = $6_1;
      i64toi32_i32$3 = HEAP32[($6_1 + 80 | 0) >> 2] | 0;
      i64toi32_i32$0 = HEAP32[($6_1 + 84 | 0) >> 2] | 0;
      $163 = i64toi32_i32$3;
      $163$hi = i64toi32_i32$0;
      i64toi32_i32$2 = ($6_1 + 80 | 0) + 8 | 0;
      i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
      $167 = i64toi32_i32$0;
      $167$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $16$hi;
      i64toi32_i32$3 = $17$hi;
      i64toi32_i32$3 = $163$hi;
      i64toi32_i32$0 = $167$hi;
      i64toi32_i32$2 = $16$hi;
      i64toi32_i32$5 = $17$hi;
      $85($6_1 + 64 | 0 | 0, $163 | 0, i64toi32_i32$3 | 0, $167 | 0, i64toi32_i32$0 | 0, $16_1 | 0, i64toi32_i32$2 | 0, $17_1 | 0, i64toi32_i32$5 | 0);
      i64toi32_i32$0 = ($6_1 + 64 | 0) + 8 | 0;
      i64toi32_i32$5 = HEAP32[i64toi32_i32$0 >> 2] | 0;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
      $17_1 = i64toi32_i32$5;
      $17$hi = i64toi32_i32$2;
      $11_1 = 1;
      i64toi32_i32$0 = $6_1;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 64 | 0) >> 2] | 0;
      i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 68 | 0) >> 2] | 0;
      $16_1 = i64toi32_i32$2;
      $16$hi = i64toi32_i32$5;
     }
     i64toi32_i32$5 = $19$hi;
     i64toi32_i32$0 = $19_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$3 = 1;
     i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $19_1 = i64toi32_i32$1;
     $19$hi = i64toi32_i32$4;
     $9_1 = 1;
    }
    label$20 : {
     $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
     if (($7_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
      break label$20
     }
     HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + 1 | 0;
     $7_1 = HEAPU8[$7_1 >> 0] | 0;
     continue label$13;
    }
    $7_1 = $50($1_1 | 0) | 0;
    continue label$13;
   };
  }
  label$21 : {
   label$22 : {
    if ($9_1) {
     break label$22
    }
    label$23 : {
     label$24 : {
      label$25 : {
       i64toi32_i32$5 = $1_1;
       i64toi32_i32$4 = HEAP32[(i64toi32_i32$5 + 112 | 0) >> 2] | 0;
       i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 116 | 0) >> 2] | 0;
       i64toi32_i32$5 = i64toi32_i32$4;
       i64toi32_i32$4 = 0;
       i64toi32_i32$3 = 0;
       if ((i64toi32_i32$0 | 0) < (i64toi32_i32$4 | 0)) {
        $107_1 = 1
       } else {
        if ((i64toi32_i32$0 | 0) <= (i64toi32_i32$4 | 0)) {
         if (i64toi32_i32$5 >>> 0 >= i64toi32_i32$3 >>> 0) {
          $108_1 = 0
         } else {
          $108_1 = 1
         }
         $109 = $108_1;
        } else {
         $109 = 0
        }
        $107_1 = $109;
       }
       if ($107_1) {
        break label$25
       }
       $7_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + -1 | 0;
       if (!$5_1) {
        break label$24
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + -2 | 0;
       if (!$8_1) {
        break label$23
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $7_1 + -3 | 0;
       break label$23;
      }
      if ($5_1) {
       break label$23
      }
     }
     i64toi32_i32$5 = 0;
     $49($1_1 | 0, 0 | 0, i64toi32_i32$5 | 0);
    }
    $90($6_1 + 96 | 0 | 0, +(+($4_1 | 0) * 0.0));
    i64toi32_i32$3 = $6_1 + 104 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$0;
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 96 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 100 | 0) >> 2] | 0;
    $16_1 = i64toi32_i32$0;
    $16$hi = i64toi32_i32$5;
    break label$21;
   }
   label$26 : {
    i64toi32_i32$5 = $19$hi;
    i64toi32_i32$3 = $19_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$4 = 7;
    if ((i64toi32_i32$5 | 0) > (i64toi32_i32$0 | 0)) {
     $110 = 1
    } else {
     if ((i64toi32_i32$5 | 0) >= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$3 >>> 0 <= i64toi32_i32$4 >>> 0) {
       $111 = 0
      } else {
       $111 = 1
      }
      $112 = $111;
     } else {
      $112 = 0
     }
     $110 = $112;
    }
    if ($110) {
     break label$26
    }
    i64toi32_i32$3 = $19$hi;
    $15_1 = $19_1;
    $15$hi = i64toi32_i32$3;
    label$27 : while (1) {
     $10_1 = $10_1 << 4 | 0;
     i64toi32_i32$3 = $15$hi;
     i64toi32_i32$4 = $15_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$0 = 1;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $15_1 = i64toi32_i32$2;
     $15$hi = i64toi32_i32$1;
     i64toi32_i32$3 = i64toi32_i32$2;
     i64toi32_i32$4 = 0;
     i64toi32_i32$0 = 8;
     if ((i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$4 | 0) | 0) {
      continue label$27
     }
     break label$27;
    };
   }
   label$28 : {
    label$29 : {
     label$30 : {
      label$31 : {
       if (($7_1 & -33 | 0 | 0) != (80 | 0)) {
        break label$31
       }
       i64toi32_i32$3 = $61($1_1 | 0, $5_1 | 0) | 0;
       i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
       $15_1 = i64toi32_i32$3;
       $15$hi = i64toi32_i32$1;
       i64toi32_i32$0 = i64toi32_i32$3;
       i64toi32_i32$3 = -2147483648;
       i64toi32_i32$4 = 0;
       if ((i64toi32_i32$0 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$3 | 0) | 0) {
        break label$28
       }
       label$32 : {
        if (!$5_1) {
         break label$32
        }
        i64toi32_i32$4 = $1_1;
        i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 112 | 0) >> 2] | 0;
        i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 116 | 0) >> 2] | 0;
        i64toi32_i32$4 = i64toi32_i32$0;
        i64toi32_i32$0 = -1;
        i64toi32_i32$3 = -1;
        if ((i64toi32_i32$1 | 0) > (i64toi32_i32$0 | 0)) {
         $113 = 1
        } else {
         if ((i64toi32_i32$1 | 0) >= (i64toi32_i32$0 | 0)) {
          if (i64toi32_i32$4 >>> 0 <= i64toi32_i32$3 >>> 0) {
           $114 = 0
          } else {
           $114 = 1
          }
          $115 = $114;
         } else {
          $115 = 0
         }
         $113 = $115;
        }
        if ($113) {
         break label$30
        }
        break label$29;
       }
       i64toi32_i32$4 = 0;
       $16_1 = 0;
       $16$hi = i64toi32_i32$4;
       i64toi32_i32$4 = 0;
       $49($1_1 | 0, 0 | 0, i64toi32_i32$4 | 0);
       i64toi32_i32$4 = 0;
       $19_1 = 0;
       $19$hi = i64toi32_i32$4;
       break label$21;
      }
      i64toi32_i32$4 = 0;
      $15_1 = 0;
      $15$hi = i64toi32_i32$4;
      i64toi32_i32$3 = $1_1;
      i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 112 | 0) >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 116 | 0) >> 2] | 0;
      i64toi32_i32$3 = i64toi32_i32$4;
      i64toi32_i32$4 = 0;
      i64toi32_i32$0 = 0;
      if ((i64toi32_i32$1 | 0) < (i64toi32_i32$4 | 0)) {
       $116 = 1
      } else {
       if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$4 | 0)) {
        if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$0 >>> 0) {
         $117 = 0
        } else {
         $117 = 1
        }
        $118 = $117;
       } else {
        $118 = 0
       }
       $116 = $118;
      }
      if ($116) {
       break label$28
      }
     }
     HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
    }
    i64toi32_i32$3 = 0;
    $15_1 = 0;
    $15$hi = i64toi32_i32$3;
   }
   label$33 : {
    if ($10_1) {
     break label$33
    }
    $90($6_1 + 112 | 0 | 0, +(+($4_1 | 0) * 0.0));
    i64toi32_i32$0 = $6_1 + 120 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$3;
    $19$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $6_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 112 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 116 | 0) >> 2] | 0;
    $16_1 = i64toi32_i32$1;
    $16$hi = i64toi32_i32$3;
    break label$21;
   }
   label$34 : {
    i64toi32_i32$3 = $14$hi;
    i64toi32_i32$3 = $19$hi;
    i64toi32_i32$5 = $8_1;
    i64toi32_i32$3 = $14$hi;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$4 = i64toi32_i32$5 ? $14_1 : $19_1;
    i64toi32_i32$0 = i64toi32_i32$5 ? i64toi32_i32$3 : i64toi32_i32$1;
    i64toi32_i32$5 = i64toi32_i32$4;
    i64toi32_i32$4 = 0;
    i64toi32_i32$3 = 2;
    i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$5 << i64toi32_i32$1 | 0;
     $119 = 0;
    } else {
     i64toi32_i32$4 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$1 | 0) | 0;
     $119 = i64toi32_i32$5 << i64toi32_i32$1 | 0;
    }
    $267$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $15$hi;
    i64toi32_i32$4 = $267$hi;
    i64toi32_i32$0 = $119;
    i64toi32_i32$5 = $15$hi;
    i64toi32_i32$3 = $15_1;
    i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
    }
    i64toi32_i32$4 = i64toi32_i32$1;
    i64toi32_i32$0 = -1;
    i64toi32_i32$3 = -32;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
    i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
    }
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $274$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$2 = i64toi32_i32$5;
    i64toi32_i32$4 = $274$hi;
    i64toi32_i32$3 = 0 - $3_1 | 0;
    if ((i64toi32_i32$1 | 0) < (i64toi32_i32$4 | 0)) {
     $120 = 1
    } else {
     if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$4 | 0)) {
      if (i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0) {
       $121 = 0
      } else {
       $121 = 1
      }
      $122 = $121;
     } else {
      $122 = 0
     }
     $120 = $122;
    }
    if ($120) {
     break label$34
    }
    HEAP32[($16() | 0) >> 2] = 68;
    $92($6_1 + 160 | 0 | 0, $4_1 | 0);
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 160 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 164 | 0) >> 2] | 0;
    $283 = i64toi32_i32$2;
    $283$hi = i64toi32_i32$1;
    i64toi32_i32$3 = (i64toi32_i32$3 + 160 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $287 = i64toi32_i32$1;
    $287$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $283$hi;
    i64toi32_i32$1 = $287$hi;
    i64toi32_i32$3 = -1;
    i64toi32_i32$4 = 2147418111;
    $97($6_1 + 144 | 0 | 0, $283 | 0, i64toi32_i32$2 | 0, $287 | 0, i64toi32_i32$1 | 0, -1 | 0, i64toi32_i32$3 | 0, -1 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$1 = $6_1;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 144 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 148 | 0) >> 2] | 0;
    $291 = i64toi32_i32$4;
    $291$hi = i64toi32_i32$3;
    i64toi32_i32$1 = (i64toi32_i32$1 + 144 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $295 = i64toi32_i32$3;
    $295$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $291$hi;
    i64toi32_i32$3 = $295$hi;
    i64toi32_i32$1 = -1;
    i64toi32_i32$2 = 2147418111;
    $97($6_1 + 128 | 0 | 0, $291 | 0, i64toi32_i32$4 | 0, $295 | 0, i64toi32_i32$3 | 0, -1 | 0, i64toi32_i32$1 | 0, -1 | 0, i64toi32_i32$2 | 0);
    i64toi32_i32$3 = ($6_1 + 128 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$2;
    $19$hi = i64toi32_i32$1;
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 128 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 132 | 0) >> 2] | 0;
    $16_1 = i64toi32_i32$1;
    $16$hi = i64toi32_i32$2;
    break label$21;
   }
   label$35 : {
    i64toi32_i32$2 = $19$hi;
    i64toi32_i32$1 = $3_1 + -226 | 0;
    i64toi32_i32$2 = i64toi32_i32$1 >> 31 | 0;
    $305 = i64toi32_i32$1;
    $305$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $19$hi;
    i64toi32_i32$3 = $19_1;
    i64toi32_i32$1 = $305$hi;
    i64toi32_i32$4 = $305;
    if ((i64toi32_i32$2 | 0) < (i64toi32_i32$1 | 0)) {
     $123 = 1
    } else {
     if ((i64toi32_i32$2 | 0) <= (i64toi32_i32$1 | 0)) {
      if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$4 >>> 0) {
       $124 = 0
      } else {
       $124 = 1
      }
      $125 = $124;
     } else {
      $125 = 0
     }
     $123 = $125;
    }
    if ($123) {
     break label$35
    }
    label$36 : {
     if (($10_1 | 0) <= (-1 | 0)) {
      break label$36
     }
     label$37 : while (1) {
      i64toi32_i32$3 = $16$hi;
      i64toi32_i32$3 = $17$hi;
      i64toi32_i32$3 = $16$hi;
      i64toi32_i32$2 = $17$hi;
      i64toi32_i32$4 = 0;
      i64toi32_i32$1 = -1073807360;
      $85($6_1 + 416 | 0 | 0, $16_1 | 0, i64toi32_i32$3 | 0, $17_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$1 | 0);
      i64toi32_i32$1 = i64toi32_i32$3;
      i64toi32_i32$1 = i64toi32_i32$2;
      i64toi32_i32$1 = i64toi32_i32$3;
      i64toi32_i32$4 = i64toi32_i32$2;
      i64toi32_i32$2 = 0;
      i64toi32_i32$3 = 1073610752;
      $7_1 = $88($16_1 | 0, i64toi32_i32$1 | 0, $17_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0) | 0;
      i64toi32_i32$3 = i64toi32_i32$1;
      i64toi32_i32$3 = i64toi32_i32$4;
      i64toi32_i32$4 = $6_1;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 416 | 0) >> 2] | 0;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$4 + 420 | 0) >> 2] | 0;
      $321$hi = i64toi32_i32$2;
      i64toi32_i32$2 = i64toi32_i32$1;
      $7_1 = ($7_1 | 0) > (-1 | 0);
      i64toi32_i32$0 = $7_1;
      i64toi32_i32$2 = $321$hi;
      $131 = i64toi32_i32$3;
      i64toi32_i32$3 = i64toi32_i32$1;
      i64toi32_i32$1 = i64toi32_i32$0 ? $131 : $16_1;
      i64toi32_i32$4 = i64toi32_i32$0 ? i64toi32_i32$2 : i64toi32_i32$3;
      $326 = i64toi32_i32$1;
      $326$hi = i64toi32_i32$4;
      i64toi32_i32$0 = ($6_1 + 416 | 0) + 8 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
      $330$hi = i64toi32_i32$1;
      i64toi32_i32$1 = $17$hi;
      i64toi32_i32$3 = $7_1;
      i64toi32_i32$1 = $330$hi;
      $132 = i64toi32_i32$4;
      i64toi32_i32$4 = $17$hi;
      i64toi32_i32$2 = i64toi32_i32$3 ? $132 : $17_1;
      i64toi32_i32$0 = i64toi32_i32$3 ? i64toi32_i32$1 : i64toi32_i32$4;
      $333 = i64toi32_i32$2;
      $333$hi = i64toi32_i32$0;
      i64toi32_i32$0 = $16$hi;
      i64toi32_i32$2 = i64toi32_i32$4;
      i64toi32_i32$3 = $326$hi;
      i64toi32_i32$1 = $333$hi;
      $85($6_1 + 400 | 0 | 0, $16_1 | 0, i64toi32_i32$0 | 0, $17_1 | 0, i64toi32_i32$4 | 0, $326 | 0, i64toi32_i32$3 | 0, $333 | 0, i64toi32_i32$1 | 0);
      i64toi32_i32$1 = $19$hi;
      i64toi32_i32$2 = $19_1;
      i64toi32_i32$3 = -1;
      i64toi32_i32$0 = -1;
      i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
      i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
      if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
       i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
      }
      $19_1 = i64toi32_i32$4;
      $19$hi = i64toi32_i32$5;
      i64toi32_i32$1 = ($6_1 + 400 | 0) + 8 | 0;
      i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
      $17_1 = i64toi32_i32$5;
      $17$hi = i64toi32_i32$2;
      i64toi32_i32$1 = $6_1;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 400 | 0) >> 2] | 0;
      i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 404 | 0) >> 2] | 0;
      $16_1 = i64toi32_i32$2;
      $16$hi = i64toi32_i32$5;
      $10_1 = $10_1 << 1 | 0 | $7_1 | 0;
      if (($10_1 | 0) > (-1 | 0)) {
       continue label$37
      }
      break label$37;
     };
    }
    label$38 : {
     label$39 : {
      i64toi32_i32$5 = $19$hi;
      i64toi32_i32$2 = $3_1;
      i64toi32_i32$5 = i64toi32_i32$2 >> 31 | 0;
      $350$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $19$hi;
      i64toi32_i32$1 = $19_1;
      i64toi32_i32$2 = $350$hi;
      i64toi32_i32$0 = $3_1;
      i64toi32_i32$3 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
      i64toi32_i32$4 = (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) + i64toi32_i32$2 | 0;
      i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$4 | 0;
      i64toi32_i32$5 = i64toi32_i32$3;
      i64toi32_i32$1 = 0;
      i64toi32_i32$0 = 32;
      i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
      i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
      if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
       i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
      }
      $14_1 = i64toi32_i32$2;
      $14$hi = i64toi32_i32$3;
      $7_1 = i64toi32_i32$2;
      $358 = (i64toi32_i32$2 | 0) > (0 | 0) ? i64toi32_i32$2 : 0;
      $359 = $2_1;
      i64toi32_i32$3 = 0;
      $362$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $14$hi;
      i64toi32_i32$4 = i64toi32_i32$2;
      i64toi32_i32$5 = $362$hi;
      i64toi32_i32$0 = $2_1;
      if ((i64toi32_i32$3 | 0) < (i64toi32_i32$5 | 0)) {
       $127 = 1
      } else {
       if ((i64toi32_i32$3 | 0) <= (i64toi32_i32$5 | 0)) {
        if (i64toi32_i32$4 >>> 0 >= i64toi32_i32$0 >>> 0) {
         $128 = 0
        } else {
         $128 = 1
        }
        $129 = $128;
       } else {
        $129 = 0
       }
       $127 = $129;
      }
      $7_1 = $127 ? $358 : $359;
      if (($7_1 | 0) < (113 | 0)) {
       break label$39
      }
      $92($6_1 + 384 | 0 | 0, $4_1 | 0);
      i64toi32_i32$0 = $6_1 + 392 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
      $14_1 = i64toi32_i32$4;
      $14$hi = i64toi32_i32$3;
      i64toi32_i32$3 = 0;
      $15_1 = 0;
      $15$hi = i64toi32_i32$3;
      i64toi32_i32$0 = $6_1;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 384 | 0) >> 2] | 0;
      i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 388 | 0) >> 2] | 0;
      $18_1 = i64toi32_i32$3;
      $18$hi = i64toi32_i32$4;
      i64toi32_i32$4 = 0;
      $20_1 = 0;
      $20$hi = i64toi32_i32$4;
      break label$38;
     }
     $90($6_1 + 352 | 0 | 0, +(+$51(+(1.0), 144 - $7_1 | 0 | 0)));
     $92($6_1 + 336 | 0 | 0, $4_1 | 0);
     i64toi32_i32$0 = $6_1;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 352 | 0) >> 2] | 0;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 356 | 0) >> 2] | 0;
     $386 = i64toi32_i32$4;
     $386$hi = i64toi32_i32$3;
     i64toi32_i32$0 = (i64toi32_i32$0 + 352 | 0) + 8 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
     $390 = i64toi32_i32$3;
     $390$hi = i64toi32_i32$4;
     i64toi32_i32$0 = $6_1;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 336 | 0) >> 2] | 0;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 340 | 0) >> 2] | 0;
     $18_1 = i64toi32_i32$4;
     $18$hi = i64toi32_i32$3;
     i64toi32_i32$0 = (i64toi32_i32$0 + 336 | 0) + 8 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
     $14_1 = i64toi32_i32$3;
     $14$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $386$hi;
     i64toi32_i32$3 = $390$hi;
     i64toi32_i32$0 = $18$hi;
     i64toi32_i32$5 = $14$hi;
     $52($6_1 + 368 | 0 | 0, $386 | 0, i64toi32_i32$4 | 0, $390 | 0, i64toi32_i32$3 | 0, $18_1 | 0, i64toi32_i32$0 | 0, $14_1 | 0, i64toi32_i32$5 | 0);
     i64toi32_i32$3 = ($6_1 + 368 | 0) + 8 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$3 >> 2] | 0;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
     $20_1 = i64toi32_i32$5;
     $20$hi = i64toi32_i32$0;
     i64toi32_i32$3 = $6_1;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 368 | 0) >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 372 | 0) >> 2] | 0;
     $15_1 = i64toi32_i32$0;
     $15$hi = i64toi32_i32$5;
    }
    i64toi32_i32$5 = $16$hi;
    i64toi32_i32$5 = $17$hi;
    i64toi32_i32$5 = $16$hi;
    i64toi32_i32$0 = $17$hi;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 0;
    $7_1 = !($10_1 & 1 | 0) & (($7_1 | 0) < (32 | 0) & ($87($16_1 | 0, i64toi32_i32$5 | 0, $17_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0) | 0 | 0) != (0 | 0) | 0) | 0;
    $93($6_1 + 320 | 0 | 0, $10_1 | $7_1 | 0 | 0);
    i64toi32_i32$4 = $18$hi;
    i64toi32_i32$4 = $14$hi;
    i64toi32_i32$0 = $6_1;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 320 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 324 | 0) >> 2] | 0;
    $426 = i64toi32_i32$4;
    $426$hi = i64toi32_i32$3;
    i64toi32_i32$0 = (i64toi32_i32$0 + 320 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
    $430 = i64toi32_i32$3;
    $430$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $18$hi;
    i64toi32_i32$3 = $14$hi;
    i64toi32_i32$0 = $426$hi;
    i64toi32_i32$5 = $430$hi;
    $97($6_1 + 304 | 0 | 0, $18_1 | 0, i64toi32_i32$4 | 0, $14_1 | 0, i64toi32_i32$3 | 0, $426 | 0, i64toi32_i32$0 | 0, $430 | 0, i64toi32_i32$5 | 0);
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 304 | 0) >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 308 | 0) >> 2] | 0;
    $434 = i64toi32_i32$5;
    $434$hi = i64toi32_i32$0;
    i64toi32_i32$3 = (i64toi32_i32$3 + 304 | 0) + 8 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $438 = i64toi32_i32$0;
    $438$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $15$hi;
    i64toi32_i32$5 = $20$hi;
    i64toi32_i32$5 = $434$hi;
    i64toi32_i32$0 = $438$hi;
    i64toi32_i32$3 = $15$hi;
    i64toi32_i32$4 = $20$hi;
    $85($6_1 + 272 | 0 | 0, $434 | 0, i64toi32_i32$5 | 0, $438 | 0, i64toi32_i32$0 | 0, $15_1 | 0, i64toi32_i32$3 | 0, $20_1 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$4 = $18$hi;
    i64toi32_i32$4 = $14$hi;
    i64toi32_i32$4 = $16$hi;
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$3 = $16$hi;
    i64toi32_i32$5 = i64toi32_i32$1 ? 0 : $16_1;
    i64toi32_i32$0 = i64toi32_i32$1 ? i64toi32_i32$4 : i64toi32_i32$3;
    $447 = i64toi32_i32$5;
    $447$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $17$hi;
    i64toi32_i32$3 = i64toi32_i32$1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = $17$hi;
    i64toi32_i32$4 = i64toi32_i32$3 ? 0 : $17_1;
    i64toi32_i32$1 = i64toi32_i32$3 ? i64toi32_i32$0 : i64toi32_i32$5;
    $450 = i64toi32_i32$4;
    $450$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $18$hi;
    i64toi32_i32$4 = $14$hi;
    i64toi32_i32$3 = $447$hi;
    i64toi32_i32$0 = $450$hi;
    $97($6_1 + 288 | 0 | 0, $18_1 | 0, i64toi32_i32$1 | 0, $14_1 | 0, i64toi32_i32$4 | 0, $447 | 0, i64toi32_i32$3 | 0, $450 | 0, i64toi32_i32$0 | 0);
    i64toi32_i32$4 = $6_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 288 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 292 | 0) >> 2] | 0;
    $454 = i64toi32_i32$0;
    $454$hi = i64toi32_i32$3;
    i64toi32_i32$4 = (i64toi32_i32$4 + 288 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $458 = i64toi32_i32$3;
    $458$hi = i64toi32_i32$0;
    i64toi32_i32$4 = $6_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 272 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 276 | 0) >> 2] | 0;
    $460 = i64toi32_i32$0;
    $460$hi = i64toi32_i32$3;
    i64toi32_i32$4 = (i64toi32_i32$4 + 272 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $464 = i64toi32_i32$3;
    $464$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $454$hi;
    i64toi32_i32$3 = $458$hi;
    i64toi32_i32$4 = $460$hi;
    i64toi32_i32$1 = $464$hi;
    $85($6_1 + 256 | 0 | 0, $454 | 0, i64toi32_i32$0 | 0, $458 | 0, i64toi32_i32$3 | 0, $460 | 0, i64toi32_i32$4 | 0, $464 | 0, i64toi32_i32$1 | 0);
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 256 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 260 | 0) >> 2] | 0;
    $468 = i64toi32_i32$1;
    $468$hi = i64toi32_i32$4;
    i64toi32_i32$3 = (i64toi32_i32$3 + 256 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $472 = i64toi32_i32$4;
    $472$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $15$hi;
    i64toi32_i32$1 = $20$hi;
    i64toi32_i32$1 = $468$hi;
    i64toi32_i32$4 = $472$hi;
    i64toi32_i32$3 = $15$hi;
    i64toi32_i32$0 = $20$hi;
    $99($6_1 + 240 | 0 | 0, $468 | 0, i64toi32_i32$1 | 0, $472 | 0, i64toi32_i32$4 | 0, $15_1 | 0, i64toi32_i32$3 | 0, $20_1 | 0, i64toi32_i32$0 | 0);
    label$40 : {
     i64toi32_i32$4 = $6_1;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 240 | 0) >> 2] | 0;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 244 | 0) >> 2] | 0;
     $16_1 = i64toi32_i32$0;
     $16$hi = i64toi32_i32$3;
     i64toi32_i32$4 = (i64toi32_i32$4 + 240 | 0) + 8 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
     $17_1 = i64toi32_i32$3;
     $17$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $16$hi;
     i64toi32_i32$3 = $17$hi;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = 0;
     if ($87($16_1 | 0, i64toi32_i32$0 | 0, $17_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$1 | 0) | 0) {
      break label$40
     }
     HEAP32[($16() | 0) >> 2] = 68;
    }
    i64toi32_i32$1 = $16$hi;
    i64toi32_i32$1 = $17$hi;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$1 = $16$hi;
    i64toi32_i32$4 = $17$hi;
    $53($6_1 + 224 | 0 | 0, $16_1 | 0, i64toi32_i32$1 | 0, $17_1 | 0, i64toi32_i32$4 | 0, $19_1 | 0);
    i64toi32_i32$3 = ($6_1 + 224 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$4;
    $19$hi = i64toi32_i32$1;
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 224 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 228 | 0) >> 2] | 0;
    $16_1 = i64toi32_i32$1;
    $16$hi = i64toi32_i32$4;
    break label$21;
   }
   HEAP32[($16() | 0) >> 2] = 68;
   $92($6_1 + 208 | 0 | 0, $4_1 | 0);
   i64toi32_i32$3 = $6_1;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 208 | 0) >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 212 | 0) >> 2] | 0;
   $504 = i64toi32_i32$4;
   $504$hi = i64toi32_i32$1;
   i64toi32_i32$3 = (i64toi32_i32$3 + 208 | 0) + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
   $508 = i64toi32_i32$1;
   $508$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $504$hi;
   i64toi32_i32$1 = $508$hi;
   i64toi32_i32$3 = 0;
   i64toi32_i32$0 = 65536;
   $97($6_1 + 192 | 0 | 0, $504 | 0, i64toi32_i32$4 | 0, $508 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$0 | 0);
   i64toi32_i32$1 = $6_1;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 192 | 0) >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 196 | 0) >> 2] | 0;
   $512 = i64toi32_i32$0;
   $512$hi = i64toi32_i32$3;
   i64toi32_i32$1 = (i64toi32_i32$1 + 192 | 0) + 8 | 0;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
   $516 = i64toi32_i32$3;
   $516$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $512$hi;
   i64toi32_i32$3 = $516$hi;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 65536;
   $97($6_1 + 176 | 0 | 0, $512 | 0, i64toi32_i32$0 | 0, $516 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0);
   i64toi32_i32$3 = ($6_1 + 176 | 0) + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$3 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
   $19_1 = i64toi32_i32$4;
   $19$hi = i64toi32_i32$1;
   i64toi32_i32$3 = $6_1;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 176 | 0) >> 2] | 0;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 180 | 0) >> 2] | 0;
   $16_1 = i64toi32_i32$1;
   $16$hi = i64toi32_i32$4;
  }
  i64toi32_i32$4 = $16$hi;
  i64toi32_i32$1 = $0_1;
  HEAP32[i64toi32_i32$1 >> 2] = $16_1;
  HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$4;
  i64toi32_i32$4 = $19$hi;
  HEAP32[(i64toi32_i32$1 + 8 | 0) >> 2] = $19_1;
  HEAP32[(i64toi32_i32$1 + 12 | 0) >> 2] = i64toi32_i32$4;
  global$0 = $6_1 + 432 | 0;
 }
 
 function $60($0_1, $1_1, $2_1, $3_1, $4_1, $5_1, $6_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $4_1 = $4_1 | 0;
  $5_1 = $5_1 | 0;
  $6_1 = $6_1 | 0;
  var i64toi32_i32$4 = 0, i64toi32_i32$5 = 0, i64toi32_i32$1 = 0, $7_1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, $18$hi = 0, $14_1 = 0, $18_1 = 0, $19$hi = 0, $19_1 = 0, $13_1 = 0, i64toi32_i32$0 = 0, $15_1 = 0, $16_1 = 0, $11_1 = 0, $21$hi = 0, $20$hi = 0, $8_1 = 0, $12_1 = 0, $21_1 = 0, $20_1 = 0, $9_1 = 0, $22$hi = 0, $23$hi = 0, $22_1 = 0, $23_1 = 0, $10_1 = 0, $165 = 0, $166 = 0, $167 = 0, $168 = 0, $169 = 0, $170 = 0, $171 = 0, $172 = 0, $173 = 0, $174 = 0, $175 = 0, $176 = 0, $177 = 0, $178 = 0, $179 = 0, $180 = 0, $17_1 = 0, $24_1 = 0.0, $124 = 0, $230 = 0, $230$hi = 0, $234 = 0, $234$hi = 0, $236 = 0, $236$hi = 0, $240 = 0, $240$hi = 0, $250$hi = 0, $259 = 0, $259$hi = 0, $263 = 0, $263$hi = 0, $267 = 0, $267$hi = 0, $271 = 0, $271$hi = 0, $281 = 0, $281$hi = 0, $290 = 0, $290$hi = 0, $294 = 0, $294$hi = 0, $298 = 0, $298$hi = 0, $302 = 0, $302$hi = 0, $351 = 0, $351$hi = 0, $355 = 0, $355$hi = 0, $357 = 0, $357$hi = 0, $361 = 0, $361$hi = 0, $380 = 0, $380$hi = 0, $384 = 0, $384$hi = 0, $386 = 0, $386$hi = 0, $390 = 0, $390$hi = 0, $401 = 0, $401$hi = 0, $405 = 0, $405$hi = 0, $407 = 0, $407$hi = 0, $411 = 0, $411$hi = 0, $439 = 0, $439$hi = 0, $443 = 0, $443$hi = 0, $445 = 0, $445$hi = 0, $449 = 0, $449$hi = 0, $459 = 0, $459$hi = 0, $463 = 0, $463$hi = 0, $465 = 0, $465$hi = 0, $469 = 0, $469$hi = 0, $508 = 0, $586$hi = 0, $588$hi = 0, $596 = 0, $596$hi = 0, $738 = 0, $738$hi = 0, $742 = 0, $742$hi = 0, $744 = 0, $744$hi = 0, $748 = 0, $748$hi = 0, $767 = 0, $767$hi = 0, $771 = 0, $771$hi = 0, $813 = 0, $874 = 0, $874$hi = 0, $878 = 0, $878$hi = 0, $897 = 0, $897$hi = 0, $901 = 0, $901$hi = 0, $919 = 0, $919$hi = 0, $923 = 0, $923$hi = 0, $960 = 0, $960$hi = 0, $964 = 0, $964$hi = 0, $983 = 0, $983$hi = 0, $987 = 0, $987$hi = 0, $1010 = 0, $1010$hi = 0, $1014 = 0, $1014$hi = 0, $1030 = 0, $1030$hi = 0, $1034 = 0, $1034$hi = 0, $1048 = 0, $1048$hi = 0, $1052 = 0, $1052$hi = 0, $1073 = 0, $1073$hi = 0, $1077 = 0, $1077$hi = 0, $1100 = 0, $1100$hi = 0, $1104 = 0, $1104$hi = 0, $1109$hi = 0, $181 = 0, $1116$hi = 0, $182 = 0;
  $7_1 = global$0 - 8976 | 0;
  global$0 = $7_1;
  $8_1 = 0;
  $9_1 = 0 - $4_1 | 0;
  $10_1 = $9_1 - $3_1 | 0;
  i64toi32_i32$0 = 0;
  $18_1 = 0;
  $18$hi = i64toi32_i32$0;
  $11_1 = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : while (1) {
      label$5 : {
       if (($2_1 | 0) == (48 | 0)) {
        break label$5
       }
       if (($2_1 | 0) != (46 | 0)) {
        break label$1
       }
       $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$3
       }
       HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
       $2_1 = HEAPU8[$2_1 >> 0] | 0;
       break label$2;
      }
      label$6 : {
       $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
       if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$6
       }
       $11_1 = 1;
       HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
       $2_1 = HEAPU8[$2_1 >> 0] | 0;
       continue label$4;
      }
      $11_1 = 1;
      $2_1 = $50($1_1 | 0) | 0;
      continue label$4;
     };
    }
    $2_1 = $50($1_1 | 0) | 0;
   }
   $8_1 = 1;
   i64toi32_i32$0 = 0;
   $18_1 = 0;
   $18$hi = i64toi32_i32$0;
   if (($2_1 | 0) != (48 | 0)) {
    break label$1
   }
   label$7 : while (1) {
    label$8 : {
     label$9 : {
      $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
      if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
       break label$9
      }
      HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
      $2_1 = HEAPU8[$2_1 >> 0] | 0;
      break label$8;
     }
     $2_1 = $50($1_1 | 0) | 0;
    }
    i64toi32_i32$0 = $18$hi;
    i64toi32_i32$2 = $18_1;
    i64toi32_i32$1 = -1;
    i64toi32_i32$3 = -1;
    i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $18_1 = i64toi32_i32$4;
    $18$hi = i64toi32_i32$5;
    if (($2_1 | 0) == (48 | 0)) {
     continue label$7
    }
    break label$7;
   };
   $11_1 = 1;
   $8_1 = 1;
  }
  $12_1 = 0;
  HEAP32[($7_1 + 784 | 0) >> 2] = 0;
  $13_1 = $2_1 + -48 | 0;
  label$10 : {
   label$11 : {
    label$12 : {
     label$13 : {
      label$14 : {
       label$15 : {
        label$16 : {
         $14_1 = ($2_1 | 0) == (46 | 0);
         if ($14_1) {
          break label$16
         }
         i64toi32_i32$5 = 0;
         $19_1 = 0;
         $19$hi = i64toi32_i32$5;
         if ($13_1 >>> 0 <= 9 >>> 0) {
          break label$16
         }
         $15_1 = 0;
         $16_1 = 0;
         break label$15;
        }
        i64toi32_i32$5 = 0;
        $19_1 = 0;
        $19$hi = i64toi32_i32$5;
        $16_1 = 0;
        $15_1 = 0;
        $12_1 = 0;
        label$17 : while (1) {
         label$18 : {
          label$19 : {
           if (!($14_1 & 1 | 0)) {
            break label$19
           }
           label$20 : {
            if ($8_1) {
             break label$20
            }
            i64toi32_i32$5 = $19$hi;
            $18_1 = $19_1;
            $18$hi = i64toi32_i32$5;
            $8_1 = 1;
            break label$18;
           }
           $14_1 = !$11_1;
           break label$14;
          }
          i64toi32_i32$5 = $19$hi;
          i64toi32_i32$0 = $19_1;
          i64toi32_i32$2 = 0;
          i64toi32_i32$3 = 1;
          i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
          i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
          if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
           i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
          }
          $19_1 = i64toi32_i32$1;
          $19$hi = i64toi32_i32$4;
          label$21 : {
           if (($15_1 | 0) > (2044 | 0)) {
            break label$21
           }
           $14_1 = ($7_1 + 784 | 0) + ($15_1 << 2 | 0) | 0;
           label$22 : {
            if (!$16_1) {
             break label$22
            }
            $13_1 = ($2_1 + Math_imul(HEAP32[$14_1 >> 2] | 0, 10) | 0) + -48 | 0;
           }
           i64toi32_i32$4 = $19$hi;
           $12_1 = ($2_1 | 0) == (48 | 0) ? $12_1 : $19_1;
           HEAP32[$14_1 >> 2] = $13_1;
           $11_1 = 1;
           $2_1 = $16_1 + 1 | 0;
           $124 = $2_1;
           $2_1 = ($2_1 | 0) == (9 | 0);
           $16_1 = $2_1 ? 0 : $124;
           $15_1 = $15_1 + $2_1 | 0;
           break label$18;
          }
          if (($2_1 | 0) == (48 | 0)) {
           break label$18
          }
          HEAP32[($7_1 + 8960 | 0) >> 2] = HEAP32[($7_1 + 8960 | 0) >> 2] | 0 | 1 | 0;
          $12_1 = 18396;
         }
         label$23 : {
          label$24 : {
           $2_1 = HEAP32[($1_1 + 4 | 0) >> 2] | 0;
           if (($2_1 | 0) == (HEAP32[($1_1 + 104 | 0) >> 2] | 0 | 0)) {
            break label$24
           }
           HEAP32[($1_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
           $2_1 = HEAPU8[$2_1 >> 0] | 0;
           break label$23;
          }
          $2_1 = $50($1_1 | 0) | 0;
         }
         $13_1 = $2_1 + -48 | 0;
         $14_1 = ($2_1 | 0) == (46 | 0);
         if ($14_1) {
          continue label$17
         }
         if ($13_1 >>> 0 < 10 >>> 0) {
          continue label$17
         }
         break label$17;
        };
       }
       i64toi32_i32$4 = $18$hi;
       i64toi32_i32$4 = $19$hi;
       i64toi32_i32$2 = $8_1;
       i64toi32_i32$4 = $18$hi;
       i64toi32_i32$0 = $19$hi;
       i64toi32_i32$3 = i64toi32_i32$2 ? $18_1 : $19_1;
       i64toi32_i32$5 = i64toi32_i32$2 ? i64toi32_i32$4 : i64toi32_i32$0;
       $18_1 = i64toi32_i32$3;
       $18$hi = i64toi32_i32$5;
       label$25 : {
        if (!$11_1) {
         break label$25
        }
        if (($2_1 & -33 | 0 | 0) != (69 | 0)) {
         break label$25
        }
        label$26 : {
         i64toi32_i32$5 = $61($1_1 | 0, $6_1 | 0) | 0;
         i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
         $20_1 = i64toi32_i32$5;
         $20$hi = i64toi32_i32$3;
         i64toi32_i32$2 = i64toi32_i32$5;
         i64toi32_i32$5 = -2147483648;
         i64toi32_i32$4 = 0;
         if ((i64toi32_i32$2 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$5 | 0) | 0) {
          break label$26
         }
         if (!$6_1) {
          break label$12
         }
         i64toi32_i32$2 = 0;
         $20_1 = 0;
         $20$hi = i64toi32_i32$2;
         i64toi32_i32$4 = $1_1;
         i64toi32_i32$2 = HEAP32[(i64toi32_i32$4 + 112 | 0) >> 2] | 0;
         i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 116 | 0) >> 2] | 0;
         i64toi32_i32$4 = i64toi32_i32$2;
         i64toi32_i32$2 = 0;
         i64toi32_i32$5 = 0;
         if ((i64toi32_i32$3 | 0) < (i64toi32_i32$2 | 0)) {
          $165 = 1
         } else {
          if ((i64toi32_i32$3 | 0) <= (i64toi32_i32$2 | 0)) {
           if (i64toi32_i32$4 >>> 0 >= i64toi32_i32$5 >>> 0) {
            $166 = 0
           } else {
            $166 = 1
           }
           $167 = $166;
          } else {
           $167 = 0
          }
          $165 = $167;
         }
         if ($165) {
          break label$26
         }
         HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
        }
        i64toi32_i32$4 = $20$hi;
        i64toi32_i32$4 = $18$hi;
        i64toi32_i32$4 = $20$hi;
        i64toi32_i32$5 = $20_1;
        i64toi32_i32$3 = $18$hi;
        i64toi32_i32$2 = $18_1;
        i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
        i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
        if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) {
         i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
        }
        $18_1 = i64toi32_i32$0;
        $18$hi = i64toi32_i32$1;
        break label$11;
       }
       $14_1 = !$11_1;
       if (($2_1 | 0) < (0 | 0)) {
        break label$13
       }
      }
      i64toi32_i32$4 = $1_1;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 112 | 0) >> 2] | 0;
      i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 116 | 0) >> 2] | 0;
      i64toi32_i32$4 = i64toi32_i32$1;
      i64toi32_i32$1 = 0;
      i64toi32_i32$2 = 0;
      if ((i64toi32_i32$5 | 0) < (i64toi32_i32$1 | 0)) {
       $168 = 1
      } else {
       if ((i64toi32_i32$5 | 0) <= (i64toi32_i32$1 | 0)) {
        if (i64toi32_i32$4 >>> 0 >= i64toi32_i32$2 >>> 0) {
         $169 = 0
        } else {
         $169 = 1
        }
        $170 = $169;
       } else {
        $170 = 0
       }
       $168 = $170;
      }
      if ($168) {
       break label$13
      }
      HEAP32[($1_1 + 4 | 0) >> 2] = (HEAP32[($1_1 + 4 | 0) >> 2] | 0) + -1 | 0;
     }
     if (!$14_1) {
      break label$11
     }
     HEAP32[($16() | 0) >> 2] = 28;
    }
    i64toi32_i32$4 = 0;
    $19_1 = 0;
    $19$hi = i64toi32_i32$4;
    i64toi32_i32$4 = 0;
    $49($1_1 | 0, 0 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$4 = 0;
    $18_1 = 0;
    $18$hi = i64toi32_i32$4;
    break label$10;
   }
   label$27 : {
    $1_1 = HEAP32[($7_1 + 784 | 0) >> 2] | 0;
    if ($1_1) {
     break label$27
    }
    $90($7_1 | 0, +(+($5_1 | 0) * 0.0));
    i64toi32_i32$2 = $7_1 + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$4;
    $18$hi = i64toi32_i32$5;
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$5 = HEAP32[$7_1 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$4;
    break label$10;
   }
   label$28 : {
    i64toi32_i32$4 = $19$hi;
    i64toi32_i32$2 = $19_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$1 = 9;
    if ((i64toi32_i32$4 | 0) > (i64toi32_i32$5 | 0)) {
     $171 = 1
    } else {
     if ((i64toi32_i32$4 | 0) >= (i64toi32_i32$5 | 0)) {
      if (i64toi32_i32$2 >>> 0 <= i64toi32_i32$1 >>> 0) {
       $172 = 0
      } else {
       $172 = 1
      }
      $173 = $172;
     } else {
      $173 = 0
     }
     $171 = $173;
    }
    if ($171) {
     break label$28
    }
    i64toi32_i32$2 = $18$hi;
    i64toi32_i32$2 = $19$hi;
    i64toi32_i32$2 = $18$hi;
    i64toi32_i32$1 = $18_1;
    i64toi32_i32$4 = $19$hi;
    i64toi32_i32$5 = $19_1;
    if ((i64toi32_i32$1 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$4 | 0) | 0) {
     break label$28
    }
    label$29 : {
     if (($3_1 | 0) > (30 | 0)) {
      break label$29
     }
     if ($1_1 >>> $3_1 | 0) {
      break label$28
     }
    }
    $92($7_1 + 48 | 0 | 0, $5_1 | 0);
    $93($7_1 + 32 | 0 | 0, $1_1 | 0);
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 48 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 52 | 0) >> 2] | 0;
    $230 = i64toi32_i32$1;
    $230$hi = i64toi32_i32$2;
    i64toi32_i32$5 = (i64toi32_i32$5 + 48 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $234 = i64toi32_i32$2;
    $234$hi = i64toi32_i32$1;
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 32 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 36 | 0) >> 2] | 0;
    $236 = i64toi32_i32$1;
    $236$hi = i64toi32_i32$2;
    i64toi32_i32$5 = (i64toi32_i32$5 + 32 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $240 = i64toi32_i32$2;
    $240$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $230$hi;
    i64toi32_i32$2 = $234$hi;
    i64toi32_i32$5 = $236$hi;
    i64toi32_i32$4 = $240$hi;
    $97($7_1 + 16 | 0 | 0, $230 | 0, i64toi32_i32$1 | 0, $234 | 0, i64toi32_i32$2 | 0, $236 | 0, i64toi32_i32$5 | 0, $240 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$2 = ($7_1 + 16 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$4;
    $18$hi = i64toi32_i32$5;
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$5 = HEAP32[($7_1 + 16 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 20 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$4;
    break label$10;
   }
   label$30 : {
    i64toi32_i32$4 = $18$hi;
    i64toi32_i32$4 = 0;
    $250$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $18$hi;
    i64toi32_i32$2 = $18_1;
    i64toi32_i32$5 = $250$hi;
    i64toi32_i32$1 = $9_1 >>> 1 | 0;
    if ((i64toi32_i32$4 | 0) < (i64toi32_i32$5 | 0)) {
     $174 = 1
    } else {
     if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$5 | 0)) {
      if (i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0) {
       $175 = 0
      } else {
       $175 = 1
      }
      $176 = $175;
     } else {
      $176 = 0
     }
     $174 = $176;
    }
    if ($174) {
     break label$30
    }
    HEAP32[($16() | 0) >> 2] = 68;
    $92($7_1 + 96 | 0 | 0, $5_1 | 0);
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$2 = HEAP32[($7_1 + 96 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 100 | 0) >> 2] | 0;
    $259 = i64toi32_i32$2;
    $259$hi = i64toi32_i32$4;
    i64toi32_i32$1 = ($7_1 + 96 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $263 = i64toi32_i32$4;
    $263$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $259$hi;
    i64toi32_i32$4 = $263$hi;
    i64toi32_i32$1 = -1;
    i64toi32_i32$5 = 2147418111;
    $97($7_1 + 80 | 0 | 0, $259 | 0, i64toi32_i32$2 | 0, $263 | 0, i64toi32_i32$4 | 0, -1 | 0, i64toi32_i32$1 | 0, -1 | 0, i64toi32_i32$5 | 0);
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 80 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 84 | 0) >> 2] | 0;
    $267 = i64toi32_i32$5;
    $267$hi = i64toi32_i32$1;
    i64toi32_i32$4 = (i64toi32_i32$4 + 80 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $271 = i64toi32_i32$1;
    $271$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $267$hi;
    i64toi32_i32$1 = $271$hi;
    i64toi32_i32$4 = -1;
    i64toi32_i32$2 = 2147418111;
    $97($7_1 + 64 | 0 | 0, $267 | 0, i64toi32_i32$5 | 0, $271 | 0, i64toi32_i32$1 | 0, -1 | 0, i64toi32_i32$4 | 0, -1 | 0, i64toi32_i32$2 | 0);
    i64toi32_i32$1 = ($7_1 + 64 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$2;
    $18$hi = i64toi32_i32$4;
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 64 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[($7_1 + 68 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$4;
    $19$hi = i64toi32_i32$2;
    break label$10;
   }
   label$31 : {
    i64toi32_i32$2 = $18$hi;
    i64toi32_i32$4 = $4_1 + -226 | 0;
    i64toi32_i32$2 = i64toi32_i32$4 >> 31 | 0;
    $281 = i64toi32_i32$4;
    $281$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $18$hi;
    i64toi32_i32$1 = $18_1;
    i64toi32_i32$4 = $281$hi;
    i64toi32_i32$5 = $281;
    if ((i64toi32_i32$2 | 0) > (i64toi32_i32$4 | 0)) {
     $177 = 1
    } else {
     if ((i64toi32_i32$2 | 0) >= (i64toi32_i32$4 | 0)) {
      if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
       $178 = 0
      } else {
       $178 = 1
      }
      $179 = $178;
     } else {
      $179 = 0
     }
     $177 = $179;
    }
    if ($177) {
     break label$31
    }
    HEAP32[($16() | 0) >> 2] = 68;
    $92($7_1 + 144 | 0 | 0, $5_1 | 0);
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 144 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 148 | 0) >> 2] | 0;
    $290 = i64toi32_i32$1;
    $290$hi = i64toi32_i32$2;
    i64toi32_i32$5 = (i64toi32_i32$5 + 144 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $294 = i64toi32_i32$2;
    $294$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $290$hi;
    i64toi32_i32$2 = $294$hi;
    i64toi32_i32$5 = 0;
    i64toi32_i32$4 = 65536;
    $97($7_1 + 128 | 0 | 0, $290 | 0, i64toi32_i32$1 | 0, $294 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0, 0 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 128 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[($7_1 + 132 | 0) >> 2] | 0;
    $298 = i64toi32_i32$4;
    $298$hi = i64toi32_i32$5;
    i64toi32_i32$2 = ($7_1 + 128 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $302 = i64toi32_i32$5;
    $302$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $298$hi;
    i64toi32_i32$5 = $302$hi;
    i64toi32_i32$2 = 0;
    i64toi32_i32$1 = 65536;
    $97($7_1 + 112 | 0 | 0, $298 | 0, i64toi32_i32$4 | 0, $302 | 0, i64toi32_i32$5 | 0, 0 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0);
    i64toi32_i32$5 = ($7_1 + 112 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$1;
    $18$hi = i64toi32_i32$2;
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 112 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 116 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$2;
    $19$hi = i64toi32_i32$1;
    break label$10;
   }
   label$32 : {
    if (!$16_1) {
     break label$32
    }
    label$33 : {
     if (($16_1 | 0) > (8 | 0)) {
      break label$33
     }
     $2_1 = ($7_1 + 784 | 0) + ($15_1 << 2 | 0) | 0;
     $1_1 = HEAP32[$2_1 >> 2] | 0;
     label$34 : while (1) {
      $1_1 = Math_imul($1_1, 10);
      $16_1 = $16_1 + 1 | 0;
      if (($16_1 | 0) != (9 | 0)) {
       continue label$34
      }
      break label$34;
     };
     HEAP32[$2_1 >> 2] = $1_1;
    }
    $15_1 = $15_1 + 1 | 0;
   }
   i64toi32_i32$1 = $18$hi;
   $16_1 = $18_1;
   label$35 : {
    if (($12_1 | 0) >= (9 | 0)) {
     break label$35
    }
    if (($12_1 | 0) > ($16_1 | 0)) {
     break label$35
    }
    if (($16_1 | 0) > (17 | 0)) {
     break label$35
    }
    label$36 : {
     if (($16_1 | 0) != (9 | 0)) {
      break label$36
     }
     $92($7_1 + 192 | 0 | 0, $5_1 | 0);
     $93($7_1 + 176 | 0 | 0, HEAP32[($7_1 + 784 | 0) >> 2] | 0 | 0);
     i64toi32_i32$5 = $7_1;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 192 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 196 | 0) >> 2] | 0;
     $351 = i64toi32_i32$1;
     $351$hi = i64toi32_i32$2;
     i64toi32_i32$5 = (i64toi32_i32$5 + 192 | 0) + 8 | 0;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
     $355 = i64toi32_i32$2;
     $355$hi = i64toi32_i32$1;
     i64toi32_i32$5 = $7_1;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 176 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 180 | 0) >> 2] | 0;
     $357 = i64toi32_i32$1;
     $357$hi = i64toi32_i32$2;
     i64toi32_i32$5 = (i64toi32_i32$5 + 176 | 0) + 8 | 0;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
     $361 = i64toi32_i32$2;
     $361$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $351$hi;
     i64toi32_i32$2 = $355$hi;
     i64toi32_i32$5 = $357$hi;
     i64toi32_i32$4 = $361$hi;
     $97($7_1 + 160 | 0 | 0, $351 | 0, i64toi32_i32$1 | 0, $355 | 0, i64toi32_i32$2 | 0, $357 | 0, i64toi32_i32$5 | 0, $361 | 0, i64toi32_i32$4 | 0);
     i64toi32_i32$2 = ($7_1 + 160 | 0) + 8 | 0;
     i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
     $18_1 = i64toi32_i32$4;
     $18$hi = i64toi32_i32$5;
     i64toi32_i32$2 = $7_1;
     i64toi32_i32$5 = HEAP32[($7_1 + 160 | 0) >> 2] | 0;
     i64toi32_i32$4 = HEAP32[($7_1 + 164 | 0) >> 2] | 0;
     $19_1 = i64toi32_i32$5;
     $19$hi = i64toi32_i32$4;
     break label$10;
    }
    label$37 : {
     if (($16_1 | 0) > (8 | 0)) {
      break label$37
     }
     $92($7_1 + 272 | 0 | 0, $5_1 | 0);
     $93($7_1 + 256 | 0 | 0, HEAP32[($7_1 + 784 | 0) >> 2] | 0 | 0);
     i64toi32_i32$2 = $7_1;
     i64toi32_i32$4 = HEAP32[($7_1 + 272 | 0) >> 2] | 0;
     i64toi32_i32$5 = HEAP32[($7_1 + 276 | 0) >> 2] | 0;
     $380 = i64toi32_i32$4;
     $380$hi = i64toi32_i32$5;
     i64toi32_i32$2 = ($7_1 + 272 | 0) + 8 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
     $384 = i64toi32_i32$5;
     $384$hi = i64toi32_i32$4;
     i64toi32_i32$2 = $7_1;
     i64toi32_i32$4 = HEAP32[($7_1 + 256 | 0) >> 2] | 0;
     i64toi32_i32$5 = HEAP32[($7_1 + 260 | 0) >> 2] | 0;
     $386 = i64toi32_i32$4;
     $386$hi = i64toi32_i32$5;
     i64toi32_i32$2 = ($7_1 + 256 | 0) + 8 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
     $390 = i64toi32_i32$5;
     $390$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $380$hi;
     i64toi32_i32$5 = $384$hi;
     i64toi32_i32$2 = $386$hi;
     i64toi32_i32$1 = $390$hi;
     $97($7_1 + 240 | 0 | 0, $380 | 0, i64toi32_i32$4 | 0, $384 | 0, i64toi32_i32$5 | 0, $386 | 0, i64toi32_i32$2 | 0, $390 | 0, i64toi32_i32$1 | 0);
     $92($7_1 + 224 | 0 | 0, HEAP32[(((8 - $16_1 | 0) << 2 | 0) + 66144 | 0) >> 2] | 0 | 0);
     i64toi32_i32$5 = $7_1;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 240 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 244 | 0) >> 2] | 0;
     $401 = i64toi32_i32$1;
     $401$hi = i64toi32_i32$2;
     i64toi32_i32$5 = (i64toi32_i32$5 + 240 | 0) + 8 | 0;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
     $405 = i64toi32_i32$2;
     $405$hi = i64toi32_i32$1;
     i64toi32_i32$5 = $7_1;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 224 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 228 | 0) >> 2] | 0;
     $407 = i64toi32_i32$1;
     $407$hi = i64toi32_i32$2;
     i64toi32_i32$5 = (i64toi32_i32$5 + 224 | 0) + 8 | 0;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
     $411 = i64toi32_i32$2;
     $411$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $401$hi;
     i64toi32_i32$2 = $405$hi;
     i64toi32_i32$5 = $407$hi;
     i64toi32_i32$4 = $411$hi;
     $89($7_1 + 208 | 0 | 0, $401 | 0, i64toi32_i32$1 | 0, $405 | 0, i64toi32_i32$2 | 0, $407 | 0, i64toi32_i32$5 | 0, $411 | 0, i64toi32_i32$4 | 0);
     i64toi32_i32$2 = ($7_1 + 208 | 0) + 8 | 0;
     i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
     $18_1 = i64toi32_i32$4;
     $18$hi = i64toi32_i32$5;
     i64toi32_i32$2 = $7_1;
     i64toi32_i32$5 = HEAP32[($7_1 + 208 | 0) >> 2] | 0;
     i64toi32_i32$4 = HEAP32[($7_1 + 212 | 0) >> 2] | 0;
     $19_1 = i64toi32_i32$5;
     $19$hi = i64toi32_i32$4;
     break label$10;
    }
    $1_1 = HEAP32[($7_1 + 784 | 0) >> 2] | 0;
    label$38 : {
     $2_1 = ($3_1 + Math_imul($16_1, -3) | 0) + 27 | 0;
     if (($2_1 | 0) > (30 | 0)) {
      break label$38
     }
     if ($1_1 >>> $2_1 | 0) {
      break label$35
     }
    }
    $92($7_1 + 352 | 0 | 0, $5_1 | 0);
    $93($7_1 + 336 | 0 | 0, $1_1 | 0);
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 352 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[($7_1 + 356 | 0) >> 2] | 0;
    $439 = i64toi32_i32$4;
    $439$hi = i64toi32_i32$5;
    i64toi32_i32$2 = ($7_1 + 352 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $443 = i64toi32_i32$5;
    $443$hi = i64toi32_i32$4;
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 336 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[($7_1 + 340 | 0) >> 2] | 0;
    $445 = i64toi32_i32$4;
    $445$hi = i64toi32_i32$5;
    i64toi32_i32$2 = ($7_1 + 336 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $449 = i64toi32_i32$5;
    $449$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $439$hi;
    i64toi32_i32$5 = $443$hi;
    i64toi32_i32$2 = $445$hi;
    i64toi32_i32$1 = $449$hi;
    $97($7_1 + 320 | 0 | 0, $439 | 0, i64toi32_i32$4 | 0, $443 | 0, i64toi32_i32$5 | 0, $445 | 0, i64toi32_i32$2 | 0, $449 | 0, i64toi32_i32$1 | 0);
    $92($7_1 + 304 | 0 | 0, HEAP32[(($16_1 << 2 | 0) + 66104 | 0) >> 2] | 0 | 0);
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 320 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 324 | 0) >> 2] | 0;
    $459 = i64toi32_i32$1;
    $459$hi = i64toi32_i32$2;
    i64toi32_i32$5 = (i64toi32_i32$5 + 320 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $463 = i64toi32_i32$2;
    $463$hi = i64toi32_i32$1;
    i64toi32_i32$5 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 304 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 308 | 0) >> 2] | 0;
    $465 = i64toi32_i32$1;
    $465$hi = i64toi32_i32$2;
    i64toi32_i32$5 = (i64toi32_i32$5 + 304 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $469 = i64toi32_i32$2;
    $469$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $459$hi;
    i64toi32_i32$2 = $463$hi;
    i64toi32_i32$5 = $465$hi;
    i64toi32_i32$4 = $469$hi;
    $97($7_1 + 288 | 0 | 0, $459 | 0, i64toi32_i32$1 | 0, $463 | 0, i64toi32_i32$2 | 0, $465 | 0, i64toi32_i32$5 | 0, $469 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$2 = ($7_1 + 288 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$4;
    $18$hi = i64toi32_i32$5;
    i64toi32_i32$2 = $7_1;
    i64toi32_i32$5 = HEAP32[($7_1 + 288 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 292 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$4;
    break label$10;
   }
   label$39 : while (1) {
    $14_1 = $15_1;
    $15_1 = $14_1 + -1 | 0;
    if (!(HEAP32[(($7_1 + 784 | 0) + ($15_1 << 2 | 0) | 0) >> 2] | 0)) {
     continue label$39
    }
    break label$39;
   };
   $12_1 = 0;
   label$40 : {
    label$41 : {
     $1_1 = ($16_1 | 0) % (9 | 0) | 0;
     if ($1_1) {
      break label$41
     }
     $13_1 = 0;
     break label$40;
    }
    $13_1 = 0;
    $9_1 = ($16_1 | 0) < (0 | 0) ? $1_1 + 9 | 0 : $1_1;
    label$42 : {
     label$43 : {
      if ($14_1) {
       break label$43
      }
      $14_1 = 0;
      break label$42;
     }
     $11_1 = HEAP32[(((8 - $9_1 | 0) << 2 | 0) + 66144 | 0) >> 2] | 0;
     $6_1 = (1e9 | 0) / ($11_1 | 0) | 0;
     $2_1 = 0;
     $1_1 = 0;
     $13_1 = 0;
     label$44 : while (1) {
      $15_1 = ($7_1 + 784 | 0) + ($1_1 << 2 | 0) | 0;
      $508 = $15_1;
      $15_1 = HEAP32[$15_1 >> 2] | 0;
      $8_1 = ($15_1 >>> 0) / ($11_1 >>> 0) | 0;
      $2_1 = $8_1 + $2_1 | 0;
      HEAP32[$508 >> 2] = $2_1;
      $2_1 = ($1_1 | 0) == ($13_1 | 0) & !$2_1 | 0;
      $13_1 = $2_1 ? ($13_1 + 1 | 0) & 2047 | 0 : $13_1;
      $16_1 = $2_1 ? $16_1 + -9 | 0 : $16_1;
      $2_1 = Math_imul($6_1, $15_1 - Math_imul($8_1, $11_1) | 0);
      $1_1 = $1_1 + 1 | 0;
      if (($1_1 | 0) != ($14_1 | 0)) {
       continue label$44
      }
      break label$44;
     };
     if (!$2_1) {
      break label$42
     }
     HEAP32[(($7_1 + 784 | 0) + ($14_1 << 2 | 0) | 0) >> 2] = $2_1;
     $14_1 = $14_1 + 1 | 0;
    }
    $16_1 = ($16_1 - $9_1 | 0) + 9 | 0;
   }
   label$45 : while (1) {
    $9_1 = ($7_1 + 784 | 0) + ($13_1 << 2 | 0) | 0;
    $6_1 = ($16_1 | 0) < (36 | 0);
    label$46 : {
     label$47 : while (1) {
      label$48 : {
       if ($6_1) {
        break label$48
       }
       if (($16_1 | 0) != (36 | 0)) {
        break label$46
       }
       if ((HEAP32[$9_1 >> 2] | 0) >>> 0 >= 10384593 >>> 0) {
        break label$46
       }
      }
      $15_1 = $14_1 + 2047 | 0;
      $11_1 = 0;
      label$49 : while (1) {
       $2_1 = $14_1;
       label$50 : {
        label$51 : {
         $1_1 = $15_1 & 2047 | 0;
         $14_1 = ($7_1 + 784 | 0) + ($1_1 << 2 | 0) | 0;
         i64toi32_i32$2 = $14_1;
         i64toi32_i32$4 = HEAP32[i64toi32_i32$2 >> 2] | 0;
         i64toi32_i32$5 = 0;
         i64toi32_i32$2 = i64toi32_i32$4;
         i64toi32_i32$4 = 0;
         i64toi32_i32$1 = 29;
         i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
         if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
          i64toi32_i32$4 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
          $180 = 0;
         } else {
          i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
          $180 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
         }
         $586$hi = i64toi32_i32$4;
         i64toi32_i32$4 = 0;
         $588$hi = i64toi32_i32$4;
         i64toi32_i32$4 = $586$hi;
         i64toi32_i32$5 = $180;
         i64toi32_i32$2 = $588$hi;
         i64toi32_i32$1 = $11_1;
         i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
         i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
         if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
          i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
         }
         $18_1 = i64toi32_i32$3;
         $18$hi = i64toi32_i32$0;
         i64toi32_i32$4 = i64toi32_i32$3;
         i64toi32_i32$5 = 0;
         i64toi32_i32$1 = 1000000001;
         if (i64toi32_i32$0 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 >= i64toi32_i32$1 >>> 0 | 0) | 0) {
          break label$51
         }
         $11_1 = 0;
         break label$50;
        }
        i64toi32_i32$4 = $18$hi;
        i64toi32_i32$0 = 0;
        i64toi32_i32$0 = __wasm_i64_udiv($18_1 | 0, i64toi32_i32$4 | 0, 1e9 | 0, i64toi32_i32$0 | 0) | 0;
        i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
        $19_1 = i64toi32_i32$0;
        $19$hi = i64toi32_i32$4;
        i64toi32_i32$0 = 0;
        i64toi32_i32$0 = __wasm_i64_mul($19_1 | 0, i64toi32_i32$4 | 0, 1e9 | 0, i64toi32_i32$0 | 0) | 0;
        i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
        $596 = i64toi32_i32$0;
        $596$hi = i64toi32_i32$4;
        i64toi32_i32$4 = $18$hi;
        i64toi32_i32$1 = $18_1;
        i64toi32_i32$0 = $596$hi;
        i64toi32_i32$5 = $596;
        i64toi32_i32$2 = i64toi32_i32$1 - i64toi32_i32$5 | 0;
        i64toi32_i32$3 = (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) + i64toi32_i32$0 | 0;
        i64toi32_i32$3 = i64toi32_i32$4 - i64toi32_i32$3 | 0;
        $18_1 = i64toi32_i32$2;
        $18$hi = i64toi32_i32$3;
        i64toi32_i32$3 = $19$hi;
        $11_1 = $19_1;
       }
       i64toi32_i32$3 = $18$hi;
       $15_1 = $18_1;
       HEAP32[$14_1 >> 2] = $15_1;
       $8_1 = ($2_1 + -1 | 0) & 2047 | 0;
       $14_1 = ($1_1 | 0) != ($8_1 | 0) ? $2_1 : ($1_1 | 0) == ($13_1 | 0) ? $2_1 : $15_1 ? $2_1 : $1_1;
       $15_1 = $1_1 + -1 | 0;
       if (($1_1 | 0) != ($13_1 | 0)) {
        continue label$49
       }
       break label$49;
      };
      $12_1 = $12_1 + -29 | 0;
      $14_1 = $2_1;
      if (!$11_1) {
       continue label$47
      }
      break label$47;
     };
     label$52 : {
      label$53 : {
       $13_1 = ($13_1 + -1 | 0) & 2047 | 0;
       if (($13_1 | 0) == ($2_1 | 0)) {
        break label$53
       }
       $14_1 = $2_1;
       break label$52;
      }
      $1_1 = ($7_1 + 784 | 0) + ((($2_1 + 2046 | 0) & 2047 | 0) << 2 | 0) | 0;
      HEAP32[$1_1 >> 2] = HEAP32[$1_1 >> 2] | 0 | (HEAP32[(($7_1 + 784 | 0) + ($8_1 << 2 | 0) | 0) >> 2] | 0) | 0;
      $14_1 = $8_1;
     }
     $16_1 = $16_1 + 9 | 0;
     HEAP32[(($7_1 + 784 | 0) + ($13_1 << 2 | 0) | 0) >> 2] = $11_1;
     continue label$45;
    }
    break label$45;
   };
   label$54 : {
    label$55 : while (1) {
     $17_1 = ($14_1 + 1 | 0) & 2047 | 0;
     $9_1 = ($7_1 + 784 | 0) + ((($14_1 + -1 | 0) & 2047 | 0) << 2 | 0) | 0;
     label$56 : while (1) {
      $15_1 = ($16_1 | 0) > (45 | 0) ? 9 : 1;
      label$57 : {
       label$58 : while (1) {
        $11_1 = $13_1;
        $1_1 = 0;
        label$59 : {
         label$60 : {
          label$61 : while (1) {
           $2_1 = ($1_1 + $11_1 | 0) & 2047 | 0;
           if (($2_1 | 0) == ($14_1 | 0)) {
            break label$60
           }
           $2_1 = HEAP32[(($7_1 + 784 | 0) + ($2_1 << 2 | 0) | 0) >> 2] | 0;
           $13_1 = HEAP32[(($1_1 << 2 | 0) + 66128 | 0) >> 2] | 0;
           if ($2_1 >>> 0 < $13_1 >>> 0) {
            break label$60
           }
           if ($2_1 >>> 0 > $13_1 >>> 0) {
            break label$59
           }
           $1_1 = $1_1 + 1 | 0;
           if (($1_1 | 0) != (4 | 0)) {
            continue label$61
           }
           break label$61;
          };
         }
         if (($16_1 | 0) != (36 | 0)) {
          break label$59
         }
         i64toi32_i32$3 = 0;
         $18_1 = 0;
         $18$hi = i64toi32_i32$3;
         $1_1 = 0;
         i64toi32_i32$3 = 0;
         $19_1 = 0;
         $19$hi = i64toi32_i32$3;
         label$62 : while (1) {
          label$63 : {
           $2_1 = ($1_1 + $11_1 | 0) & 2047 | 0;
           if (($2_1 | 0) != ($14_1 | 0)) {
            break label$63
           }
           $14_1 = ($14_1 + 1 | 0) & 2047 | 0;
           HEAP32[((($14_1 << 2 | 0) + ($7_1 + 784 | 0) | 0) + -4 | 0) >> 2] = 0;
          }
          $93($7_1 + 768 | 0 | 0, HEAP32[(($7_1 + 784 | 0) + ($2_1 << 2 | 0) | 0) >> 2] | 0 | 0);
          i64toi32_i32$3 = $18$hi;
          i64toi32_i32$3 = $19$hi;
          i64toi32_i32$3 = $18$hi;
          i64toi32_i32$1 = $19$hi;
          i64toi32_i32$4 = 0;
          i64toi32_i32$5 = 1075633366;
          $97($7_1 + 752 | 0 | 0, $18_1 | 0, i64toi32_i32$3 | 0, $19_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0, 1342177280 | 0, i64toi32_i32$5 | 0);
          i64toi32_i32$1 = $7_1;
          i64toi32_i32$5 = HEAP32[($7_1 + 752 | 0) >> 2] | 0;
          i64toi32_i32$4 = HEAP32[($7_1 + 756 | 0) >> 2] | 0;
          $738 = i64toi32_i32$5;
          $738$hi = i64toi32_i32$4;
          i64toi32_i32$1 = ($7_1 + 752 | 0) + 8 | 0;
          i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
          i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
          $742 = i64toi32_i32$4;
          $742$hi = i64toi32_i32$5;
          i64toi32_i32$1 = $7_1;
          i64toi32_i32$5 = HEAP32[($7_1 + 768 | 0) >> 2] | 0;
          i64toi32_i32$4 = HEAP32[($7_1 + 772 | 0) >> 2] | 0;
          $744 = i64toi32_i32$5;
          $744$hi = i64toi32_i32$4;
          i64toi32_i32$1 = ($7_1 + 768 | 0) + 8 | 0;
          i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
          i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
          $748 = i64toi32_i32$4;
          $748$hi = i64toi32_i32$5;
          i64toi32_i32$5 = $738$hi;
          i64toi32_i32$4 = $742$hi;
          i64toi32_i32$1 = $744$hi;
          i64toi32_i32$3 = $748$hi;
          $85($7_1 + 736 | 0 | 0, $738 | 0, i64toi32_i32$5 | 0, $742 | 0, i64toi32_i32$4 | 0, $744 | 0, i64toi32_i32$1 | 0, $748 | 0, i64toi32_i32$3 | 0);
          i64toi32_i32$4 = ($7_1 + 736 | 0) + 8 | 0;
          i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
          i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
          $19_1 = i64toi32_i32$3;
          $19$hi = i64toi32_i32$1;
          i64toi32_i32$4 = $7_1;
          i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 736 | 0) >> 2] | 0;
          i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 740 | 0) >> 2] | 0;
          $18_1 = i64toi32_i32$1;
          $18$hi = i64toi32_i32$3;
          $1_1 = $1_1 + 1 | 0;
          if (($1_1 | 0) != (4 | 0)) {
           continue label$62
          }
          break label$62;
         };
         $92(i64toi32_i32$4 + 720 | 0 | 0, $5_1 | 0);
         i64toi32_i32$3 = $19$hi;
         i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 720 | 0) >> 2] | 0;
         i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 724 | 0) >> 2] | 0;
         $767 = i64toi32_i32$3;
         $767$hi = i64toi32_i32$1;
         i64toi32_i32$4 = (i64toi32_i32$4 + 720 | 0) + 8 | 0;
         i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
         i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
         $771 = i64toi32_i32$1;
         $771$hi = i64toi32_i32$3;
         i64toi32_i32$3 = $18$hi;
         i64toi32_i32$1 = $19$hi;
         i64toi32_i32$4 = $767$hi;
         i64toi32_i32$5 = $771$hi;
         $97($7_1 + 704 | 0 | 0, $18_1 | 0, i64toi32_i32$3 | 0, $19_1 | 0, i64toi32_i32$1 | 0, $767 | 0, i64toi32_i32$4 | 0, $771 | 0, i64toi32_i32$5 | 0);
         i64toi32_i32$1 = ($7_1 + 704 | 0) + 8 | 0;
         i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
         i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
         $19_1 = i64toi32_i32$5;
         $19$hi = i64toi32_i32$4;
         i64toi32_i32$4 = 0;
         $18_1 = 0;
         $18$hi = i64toi32_i32$4;
         i64toi32_i32$1 = $7_1;
         i64toi32_i32$4 = HEAP32[($7_1 + 704 | 0) >> 2] | 0;
         i64toi32_i32$5 = HEAP32[($7_1 + 708 | 0) >> 2] | 0;
         $20_1 = i64toi32_i32$4;
         $20$hi = i64toi32_i32$5;
         $13_1 = $12_1 + 113 | 0;
         $1_1 = $13_1 - $4_1 | 0;
         $8_1 = ($1_1 | 0) < ($3_1 | 0);
         $2_1 = $8_1 ? (($1_1 | 0) > (0 | 0) ? $1_1 : 0) : $3_1;
         if (($2_1 | 0) <= (112 | 0)) {
          break label$57
         }
         i64toi32_i32$5 = 0;
         $21_1 = 0;
         $21$hi = i64toi32_i32$5;
         i64toi32_i32$5 = 0;
         $22_1 = 0;
         $22$hi = i64toi32_i32$5;
         i64toi32_i32$5 = 0;
         $23_1 = 0;
         $23$hi = i64toi32_i32$5;
         break label$54;
        }
        $12_1 = $15_1 + $12_1 | 0;
        $13_1 = $14_1;
        if (($11_1 | 0) == ($14_1 | 0)) {
         continue label$58
        }
        break label$58;
       };
       $8_1 = 1e9 >>> $15_1 | 0;
       $6_1 = (-1 << $15_1 | 0) ^ -1 | 0;
       $1_1 = 0;
       $13_1 = $11_1;
       label$64 : while (1) {
        $2_1 = ($7_1 + 784 | 0) + ($11_1 << 2 | 0) | 0;
        $813 = $2_1;
        $2_1 = HEAP32[$2_1 >> 2] | 0;
        $1_1 = ($2_1 >>> $15_1 | 0) + $1_1 | 0;
        HEAP32[$813 >> 2] = $1_1;
        $1_1 = ($11_1 | 0) == ($13_1 | 0) & !$1_1 | 0;
        $13_1 = $1_1 ? ($13_1 + 1 | 0) & 2047 | 0 : $13_1;
        $16_1 = $1_1 ? $16_1 + -9 | 0 : $16_1;
        $1_1 = Math_imul($2_1 & $6_1 | 0, $8_1);
        $11_1 = ($11_1 + 1 | 0) & 2047 | 0;
        if (($11_1 | 0) != ($14_1 | 0)) {
         continue label$64
        }
        break label$64;
       };
       if (!$1_1) {
        continue label$56
       }
       label$65 : {
        if (($17_1 | 0) == ($13_1 | 0)) {
         break label$65
        }
        HEAP32[(($7_1 + 784 | 0) + ($14_1 << 2 | 0) | 0) >> 2] = $1_1;
        $14_1 = $17_1;
        continue label$55;
       }
       HEAP32[$9_1 >> 2] = HEAP32[$9_1 >> 2] | 0 | 1 | 0;
       continue label$56;
      }
      break label$56;
     };
     break label$55;
    };
    $90($7_1 + 656 | 0 | 0, +(+$51(+(1.0), 225 - $2_1 | 0 | 0)));
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$5 = HEAP32[($7_1 + 656 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 660 | 0) >> 2] | 0;
    $874 = i64toi32_i32$5;
    $874$hi = i64toi32_i32$4;
    i64toi32_i32$1 = ($7_1 + 656 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $878 = i64toi32_i32$4;
    $878$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $20$hi;
    i64toi32_i32$5 = $19$hi;
    i64toi32_i32$5 = $874$hi;
    i64toi32_i32$4 = $878$hi;
    i64toi32_i32$1 = $20$hi;
    i64toi32_i32$3 = $19$hi;
    $52($7_1 + 688 | 0 | 0, $874 | 0, i64toi32_i32$5 | 0, $878 | 0, i64toi32_i32$4 | 0, $20_1 | 0, i64toi32_i32$1 | 0, $19_1 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$4 = ($7_1 + 688 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $23_1 = i64toi32_i32$3;
    $23$hi = i64toi32_i32$1;
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 688 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 692 | 0) >> 2] | 0;
    $22_1 = i64toi32_i32$1;
    $22$hi = i64toi32_i32$3;
    $90(i64toi32_i32$4 + 640 | 0 | 0, +(+$51(+(1.0), 113 - $2_1 | 0 | 0)));
    i64toi32_i32$3 = $20$hi;
    i64toi32_i32$3 = $19$hi;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 640 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 644 | 0) >> 2] | 0;
    $897 = i64toi32_i32$3;
    $897$hi = i64toi32_i32$1;
    i64toi32_i32$4 = (i64toi32_i32$4 + 640 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $901 = i64toi32_i32$1;
    $901$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $20$hi;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$4 = $897$hi;
    i64toi32_i32$5 = $901$hi;
    $55($7_1 + 672 | 0 | 0, $20_1 | 0, i64toi32_i32$3 | 0, $19_1 | 0, i64toi32_i32$1 | 0, $897 | 0, i64toi32_i32$4 | 0, $901 | 0, i64toi32_i32$5 | 0);
    i64toi32_i32$5 = i64toi32_i32$3;
    i64toi32_i32$5 = i64toi32_i32$1;
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$5 = HEAP32[($7_1 + 672 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 676 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$5;
    $18$hi = i64toi32_i32$4;
    i64toi32_i32$1 = ($7_1 + 672 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $21_1 = i64toi32_i32$4;
    $21$hi = i64toi32_i32$5;
    i64toi32_i32$5 = i64toi32_i32$3;
    i64toi32_i32$4 = $19$hi;
    i64toi32_i32$1 = $18$hi;
    i64toi32_i32$3 = $21$hi;
    $99($7_1 + 624 | 0 | 0, $20_1 | 0, i64toi32_i32$5 | 0, $19_1 | 0, i64toi32_i32$4 | 0, $18_1 | 0, i64toi32_i32$1 | 0, $21_1 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$3 = $22$hi;
    i64toi32_i32$3 = $23$hi;
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 624 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 628 | 0) >> 2] | 0;
    $919 = i64toi32_i32$3;
    $919$hi = i64toi32_i32$1;
    i64toi32_i32$4 = (i64toi32_i32$4 + 624 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $923 = i64toi32_i32$1;
    $923$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $22$hi;
    i64toi32_i32$1 = $23$hi;
    i64toi32_i32$4 = $919$hi;
    i64toi32_i32$5 = $923$hi;
    $85($7_1 + 608 | 0 | 0, $22_1 | 0, i64toi32_i32$3 | 0, $23_1 | 0, i64toi32_i32$1 | 0, $919 | 0, i64toi32_i32$4 | 0, $923 | 0, i64toi32_i32$5 | 0);
    i64toi32_i32$1 = ($7_1 + 608 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$4;
    i64toi32_i32$1 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 608 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[($7_1 + 612 | 0) >> 2] | 0;
    $20_1 = i64toi32_i32$4;
    $20$hi = i64toi32_i32$5;
   }
   label$66 : {
    $15_1 = ($11_1 + 4 | 0) & 2047 | 0;
    if (($15_1 | 0) == ($14_1 | 0)) {
     break label$66
    }
    label$67 : {
     label$68 : {
      $15_1 = HEAP32[(($7_1 + 784 | 0) + ($15_1 << 2 | 0) | 0) >> 2] | 0;
      if ($15_1 >>> 0 > 499999999 >>> 0) {
       break label$68
      }
      label$69 : {
       if ($15_1) {
        break label$69
       }
       if ((($11_1 + 5 | 0) & 2047 | 0 | 0) == ($14_1 | 0)) {
        break label$67
       }
      }
      $90($7_1 + 496 | 0 | 0, +(+($5_1 | 0) * .25));
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$5 = $21$hi;
      i64toi32_i32$1 = $7_1;
      i64toi32_i32$5 = HEAP32[($7_1 + 496 | 0) >> 2] | 0;
      i64toi32_i32$4 = HEAP32[($7_1 + 500 | 0) >> 2] | 0;
      $960 = i64toi32_i32$5;
      $960$hi = i64toi32_i32$4;
      i64toi32_i32$1 = ($7_1 + 496 | 0) + 8 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
      i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
      $964 = i64toi32_i32$4;
      $964$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$4 = $21$hi;
      i64toi32_i32$1 = $960$hi;
      i64toi32_i32$3 = $964$hi;
      $85($7_1 + 480 | 0 | 0, $18_1 | 0, i64toi32_i32$5 | 0, $21_1 | 0, i64toi32_i32$4 | 0, $960 | 0, i64toi32_i32$1 | 0, $964 | 0, i64toi32_i32$3 | 0);
      i64toi32_i32$4 = ($7_1 + 480 | 0) + 8 | 0;
      i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
      $21_1 = i64toi32_i32$3;
      $21$hi = i64toi32_i32$1;
      i64toi32_i32$4 = $7_1;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 480 | 0) >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 484 | 0) >> 2] | 0;
      $18_1 = i64toi32_i32$1;
      $18$hi = i64toi32_i32$3;
      break label$67;
     }
     label$70 : {
      if (($15_1 | 0) == (5e8 | 0)) {
       break label$70
      }
      $90($7_1 + 592 | 0 | 0, +(+($5_1 | 0) * .75));
      i64toi32_i32$3 = $18$hi;
      i64toi32_i32$3 = $21$hi;
      i64toi32_i32$4 = $7_1;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 592 | 0) >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 596 | 0) >> 2] | 0;
      $983 = i64toi32_i32$3;
      $983$hi = i64toi32_i32$1;
      i64toi32_i32$4 = (i64toi32_i32$4 + 592 | 0) + 8 | 0;
      i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
      $987 = i64toi32_i32$1;
      $987$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $18$hi;
      i64toi32_i32$1 = $21$hi;
      i64toi32_i32$4 = $983$hi;
      i64toi32_i32$5 = $987$hi;
      $85($7_1 + 576 | 0 | 0, $18_1 | 0, i64toi32_i32$3 | 0, $21_1 | 0, i64toi32_i32$1 | 0, $983 | 0, i64toi32_i32$4 | 0, $987 | 0, i64toi32_i32$5 | 0);
      i64toi32_i32$1 = ($7_1 + 576 | 0) + 8 | 0;
      i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
      i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
      $21_1 = i64toi32_i32$5;
      $21$hi = i64toi32_i32$4;
      i64toi32_i32$1 = $7_1;
      i64toi32_i32$4 = HEAP32[($7_1 + 576 | 0) >> 2] | 0;
      i64toi32_i32$5 = HEAP32[($7_1 + 580 | 0) >> 2] | 0;
      $18_1 = i64toi32_i32$4;
      $18$hi = i64toi32_i32$5;
      break label$67;
     }
     $24_1 = +($5_1 | 0);
     label$71 : {
      if ((($11_1 + 5 | 0) & 2047 | 0 | 0) != ($14_1 | 0)) {
       break label$71
      }
      $90($7_1 + 528 | 0 | 0, +($24_1 * .5));
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$5 = $21$hi;
      i64toi32_i32$1 = $7_1;
      i64toi32_i32$5 = HEAP32[($7_1 + 528 | 0) >> 2] | 0;
      i64toi32_i32$4 = HEAP32[($7_1 + 532 | 0) >> 2] | 0;
      $1010 = i64toi32_i32$5;
      $1010$hi = i64toi32_i32$4;
      i64toi32_i32$1 = ($7_1 + 528 | 0) + 8 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
      i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
      $1014 = i64toi32_i32$4;
      $1014$hi = i64toi32_i32$5;
      i64toi32_i32$5 = $18$hi;
      i64toi32_i32$4 = $21$hi;
      i64toi32_i32$1 = $1010$hi;
      i64toi32_i32$3 = $1014$hi;
      $85($7_1 + 512 | 0 | 0, $18_1 | 0, i64toi32_i32$5 | 0, $21_1 | 0, i64toi32_i32$4 | 0, $1010 | 0, i64toi32_i32$1 | 0, $1014 | 0, i64toi32_i32$3 | 0);
      i64toi32_i32$4 = ($7_1 + 512 | 0) + 8 | 0;
      i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
      $21_1 = i64toi32_i32$3;
      $21$hi = i64toi32_i32$1;
      i64toi32_i32$4 = $7_1;
      i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 512 | 0) >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 516 | 0) >> 2] | 0;
      $18_1 = i64toi32_i32$1;
      $18$hi = i64toi32_i32$3;
      break label$67;
     }
     $90($7_1 + 560 | 0 | 0, +($24_1 * .75));
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$4 = $7_1;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 560 | 0) >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 564 | 0) >> 2] | 0;
     $1030 = i64toi32_i32$3;
     $1030$hi = i64toi32_i32$1;
     i64toi32_i32$4 = (i64toi32_i32$4 + 560 | 0) + 8 | 0;
     i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
     $1034 = i64toi32_i32$1;
     $1034$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$1 = $21$hi;
     i64toi32_i32$4 = $1030$hi;
     i64toi32_i32$5 = $1034$hi;
     $85($7_1 + 544 | 0 | 0, $18_1 | 0, i64toi32_i32$3 | 0, $21_1 | 0, i64toi32_i32$1 | 0, $1030 | 0, i64toi32_i32$4 | 0, $1034 | 0, i64toi32_i32$5 | 0);
     i64toi32_i32$1 = ($7_1 + 544 | 0) + 8 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
     $21_1 = i64toi32_i32$5;
     $21$hi = i64toi32_i32$4;
     i64toi32_i32$1 = $7_1;
     i64toi32_i32$4 = HEAP32[($7_1 + 544 | 0) >> 2] | 0;
     i64toi32_i32$5 = HEAP32[($7_1 + 548 | 0) >> 2] | 0;
     $18_1 = i64toi32_i32$4;
     $18$hi = i64toi32_i32$5;
    }
    if (($2_1 | 0) > (111 | 0)) {
     break label$66
    }
    i64toi32_i32$5 = $18$hi;
    i64toi32_i32$5 = $21$hi;
    i64toi32_i32$5 = $18$hi;
    i64toi32_i32$4 = $21$hi;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 1073676288;
    $55($7_1 + 464 | 0 | 0, $18_1 | 0, i64toi32_i32$5 | 0, $21_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 464 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 468 | 0) >> 2] | 0;
    $1048 = i64toi32_i32$3;
    $1048$hi = i64toi32_i32$1;
    i64toi32_i32$4 = (i64toi32_i32$4 + 464 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $1052 = i64toi32_i32$1;
    $1052$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $1048$hi;
    i64toi32_i32$1 = $1052$hi;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 0;
    if ($87($1048 | 0, i64toi32_i32$3 | 0, $1052 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$5 | 0) | 0) {
     break label$66
    }
    i64toi32_i32$5 = $18$hi;
    i64toi32_i32$5 = $21$hi;
    i64toi32_i32$5 = $18$hi;
    i64toi32_i32$4 = $21$hi;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 1073676288;
    $85($7_1 + 448 | 0 | 0, $18_1 | 0, i64toi32_i32$5 | 0, $21_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$3 | 0);
    i64toi32_i32$4 = ($7_1 + 448 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $21_1 = i64toi32_i32$3;
    $21$hi = i64toi32_i32$1;
    i64toi32_i32$4 = $7_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 448 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 452 | 0) >> 2] | 0;
    $18_1 = i64toi32_i32$1;
    $18$hi = i64toi32_i32$3;
   }
   i64toi32_i32$3 = $20$hi;
   i64toi32_i32$3 = $19$hi;
   i64toi32_i32$3 = $18$hi;
   i64toi32_i32$3 = $21$hi;
   i64toi32_i32$3 = $20$hi;
   i64toi32_i32$1 = $19$hi;
   i64toi32_i32$4 = $18$hi;
   i64toi32_i32$5 = $21$hi;
   $85($7_1 + 432 | 0 | 0, $20_1 | 0, i64toi32_i32$3 | 0, $19_1 | 0, i64toi32_i32$1 | 0, $18_1 | 0, i64toi32_i32$4 | 0, $21_1 | 0, i64toi32_i32$5 | 0);
   i64toi32_i32$1 = $7_1;
   i64toi32_i32$5 = HEAP32[($7_1 + 432 | 0) >> 2] | 0;
   i64toi32_i32$4 = HEAP32[($7_1 + 436 | 0) >> 2] | 0;
   $1073 = i64toi32_i32$5;
   $1073$hi = i64toi32_i32$4;
   i64toi32_i32$1 = ($7_1 + 432 | 0) + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
   $1077 = i64toi32_i32$4;
   $1077$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $22$hi;
   i64toi32_i32$5 = $23$hi;
   i64toi32_i32$5 = $1073$hi;
   i64toi32_i32$4 = $1077$hi;
   i64toi32_i32$1 = $22$hi;
   i64toi32_i32$3 = $23$hi;
   $99($7_1 + 416 | 0 | 0, $1073 | 0, i64toi32_i32$5 | 0, $1077 | 0, i64toi32_i32$4 | 0, $22_1 | 0, i64toi32_i32$1 | 0, $23_1 | 0, i64toi32_i32$3 | 0);
   i64toi32_i32$4 = ($7_1 + 416 | 0) + 8 | 0;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
   $19_1 = i64toi32_i32$3;
   $19$hi = i64toi32_i32$1;
   i64toi32_i32$4 = $7_1;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 416 | 0) >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 420 | 0) >> 2] | 0;
   $20_1 = i64toi32_i32$1;
   $20$hi = i64toi32_i32$3;
   label$72 : {
    if (($13_1 & 2147483647 | 0 | 0) <= ($10_1 + -2 | 0 | 0)) {
     break label$72
    }
    i64toi32_i32$3 = $19$hi;
    i64toi32_i32$3 = $20$hi;
    i64toi32_i32$1 = $19$hi;
    $56(i64toi32_i32$4 + 400 | 0 | 0, $20_1 | 0, i64toi32_i32$3 | 0, $19_1 | 0, i64toi32_i32$1 | 0);
    i64toi32_i32$1 = i64toi32_i32$3;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$1 = i64toi32_i32$3;
    i64toi32_i32$3 = $19$hi;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 1073610752;
    $97($7_1 + 384 | 0 | 0, $20_1 | 0, i64toi32_i32$1 | 0, $19_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$5 | 0);
    i64toi32_i32$3 = $7_1;
    i64toi32_i32$5 = HEAP32[($7_1 + 400 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[($7_1 + 404 | 0) >> 2] | 0;
    $1100 = i64toi32_i32$5;
    $1100$hi = i64toi32_i32$4;
    i64toi32_i32$3 = ($7_1 + 400 | 0) + 8 | 0;
    i64toi32_i32$4 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $1104 = i64toi32_i32$4;
    $1104$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $1100$hi;
    i64toi32_i32$4 = $1104$hi;
    i64toi32_i32$3 = 0;
    i64toi32_i32$1 = 1081081856;
    $13_1 = $88($1100 | 0, i64toi32_i32$5 | 0, $1104 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0) | 0;
    i64toi32_i32$4 = ($7_1 + 384 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $1109$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $19$hi;
    $14_1 = ($13_1 | 0) > (-1 | 0);
    i64toi32_i32$0 = $14_1;
    i64toi32_i32$3 = $1109$hi;
    $181 = i64toi32_i32$1;
    i64toi32_i32$1 = $19$hi;
    i64toi32_i32$5 = $14_1 ? $181 : $19_1;
    i64toi32_i32$4 = $14_1 ? i64toi32_i32$3 : i64toi32_i32$1;
    $19_1 = i64toi32_i32$5;
    $19$hi = i64toi32_i32$4;
    i64toi32_i32$0 = $7_1;
    i64toi32_i32$4 = HEAP32[($7_1 + 384 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[($7_1 + 388 | 0) >> 2] | 0;
    $1116$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $20$hi;
    i64toi32_i32$1 = $14_1;
    i64toi32_i32$5 = $1116$hi;
    $182 = i64toi32_i32$4;
    i64toi32_i32$4 = $20$hi;
    i64toi32_i32$3 = i64toi32_i32$1 ? $182 : $20_1;
    i64toi32_i32$0 = i64toi32_i32$1 ? i64toi32_i32$5 : i64toi32_i32$4;
    $20_1 = i64toi32_i32$3;
    $20$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $18$hi;
    i64toi32_i32$0 = $21$hi;
    i64toi32_i32$0 = $18$hi;
    i64toi32_i32$3 = $21$hi;
    i64toi32_i32$1 = 0;
    i64toi32_i32$5 = 0;
    $11_1 = $87($18_1 | 0, $18$hi | 0, $21_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$5 | 0) | 0;
    label$73 : {
     $12_1 = $12_1 + $14_1 | 0;
     if (($12_1 + 110 | 0 | 0) > ($10_1 | 0)) {
      break label$73
     }
     if (!(($8_1 & (($2_1 | 0) != ($1_1 | 0) | ($13_1 | 0) < (0 | 0) | 0) | 0) & ($11_1 | 0) != (0 | 0) | 0)) {
      break label$72
     }
    }
    HEAP32[($16() | 0) >> 2] = 68;
   }
   i64toi32_i32$5 = $20$hi;
   i64toi32_i32$5 = $19$hi;
   i64toi32_i32$5 = $20$hi;
   i64toi32_i32$1 = $19$hi;
   $53($7_1 + 368 | 0 | 0, $20_1 | 0, i64toi32_i32$5 | 0, $19_1 | 0, i64toi32_i32$1 | 0, $12_1 | 0);
   i64toi32_i32$3 = ($7_1 + 368 | 0) + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
   $18_1 = i64toi32_i32$1;
   $18$hi = i64toi32_i32$5;
   i64toi32_i32$3 = $7_1;
   i64toi32_i32$5 = HEAP32[($7_1 + 368 | 0) >> 2] | 0;
   i64toi32_i32$1 = HEAP32[($7_1 + 372 | 0) >> 2] | 0;
   $19_1 = i64toi32_i32$5;
   $19$hi = i64toi32_i32$1;
  }
  i64toi32_i32$1 = $18$hi;
  i64toi32_i32$5 = $0_1;
  HEAP32[(i64toi32_i32$5 + 8 | 0) >> 2] = $18_1;
  HEAP32[(i64toi32_i32$5 + 12 | 0) >> 2] = i64toi32_i32$1;
  i64toi32_i32$1 = $19$hi;
  HEAP32[i64toi32_i32$5 >> 2] = $19_1;
  HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] = i64toi32_i32$1;
  global$0 = $7_1 + 8976 | 0;
 }
 
 function $61($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$5 = 0, i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, $3_1 = 0, $6$hi = 0, $6_1 = 0, $5_1 = 0, i64toi32_i32$3 = 0, $4_1 = 0, $18_1 = 0, $19_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $23_1 = 0, $24_1 = 0, $25_1 = 0, $26_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $88$hi = 0, $90_1 = 0, $90$hi = 0, $139$hi = 0;
  label$1 : {
   label$2 : {
    $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
    if (($2_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
     break label$2
    }
    HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
    $3_1 = HEAPU8[$2_1 >> 0] | 0;
    break label$1;
   }
   $3_1 = $50($0_1 | 0) | 0;
  }
  label$3 : {
   label$4 : {
    label$5 : {
     label$6 : {
      switch ($3_1 + -43 | 0 | 0) {
      case 0:
      case 2:
       label$8 : {
        label$9 : {
         $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
         if (($2_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
          break label$9
         }
         HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
         $2_1 = HEAPU8[$2_1 >> 0] | 0;
         break label$8;
        }
        $2_1 = $50($0_1 | 0) | 0;
       }
       $4_1 = ($3_1 | 0) == (45 | 0);
       $5_1 = $2_1 + -58 | 0;
       if (!$1_1) {
        break label$5
       }
       if ($5_1 >>> 0 > -11 >>> 0) {
        break label$5
       }
       i64toi32_i32$2 = $0_1;
       i64toi32_i32$0 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
       i64toi32_i32$1 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
       i64toi32_i32$2 = i64toi32_i32$0;
       i64toi32_i32$0 = 0;
       i64toi32_i32$3 = 0;
       if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
        $18_1 = 1
       } else {
        if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
         if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) {
          $19_1 = 0
         } else {
          $19_1 = 1
         }
         $20_1 = $19_1;
        } else {
         $20_1 = 0
        }
        $18_1 = $20_1;
       }
       if ($18_1) {
        break label$4
       }
       HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
       break label$4;
      default:
       break label$6;
      };
     }
     $5_1 = $3_1 + -58 | 0;
     $4_1 = 0;
     $2_1 = $3_1;
    }
    if ($5_1 >>> 0 < -10 >>> 0) {
     break label$4
    }
    i64toi32_i32$2 = 0;
    $6_1 = 0;
    $6$hi = i64toi32_i32$2;
    label$10 : {
     if (($2_1 + -48 | 0) >>> 0 >= 10 >>> 0) {
      break label$10
     }
     $3_1 = 0;
     label$11 : while (1) {
      $3_1 = $2_1 + Math_imul($3_1, 10) | 0;
      label$12 : {
       label$13 : {
        $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
        if (($2_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
         break label$13
        }
        HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
        $2_1 = HEAPU8[$2_1 >> 0] | 0;
        break label$12;
       }
       $2_1 = $50($0_1 | 0) | 0;
      }
      $3_1 = $3_1 + -48 | 0;
      label$14 : {
       $5_1 = $2_1 + -48 | 0;
       if ($5_1 >>> 0 > 9 >>> 0) {
        break label$14
       }
       if (($3_1 | 0) < (214748364 | 0)) {
        continue label$11
       }
      }
      break label$11;
     };
     i64toi32_i32$1 = $3_1;
     i64toi32_i32$2 = i64toi32_i32$1 >> 31 | 0;
     $6_1 = i64toi32_i32$1;
     $6$hi = i64toi32_i32$2;
     if ($5_1 >>> 0 >= 10 >>> 0) {
      break label$10
     }
     label$15 : while (1) {
      i64toi32_i32$2 = 0;
      $88$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $6$hi;
      i64toi32_i32$1 = 0;
      i64toi32_i32$1 = __wasm_i64_mul($6_1 | 0, i64toi32_i32$2 | 0, 10 | 0, i64toi32_i32$1 | 0) | 0;
      i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
      $90_1 = i64toi32_i32$1;
      $90$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $88$hi;
      i64toi32_i32$3 = $2_1;
      i64toi32_i32$1 = $90$hi;
      i64toi32_i32$0 = $90_1;
      i64toi32_i32$4 = $2_1 + i64toi32_i32$0 | 0;
      i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
      if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
       i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
      }
      $6_1 = i64toi32_i32$4;
      $6$hi = i64toi32_i32$5;
      label$16 : {
       label$17 : {
        $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
        if (($2_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
         break label$17
        }
        HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
        $2_1 = HEAPU8[$2_1 >> 0] | 0;
        break label$16;
       }
       $2_1 = $50($0_1 | 0) | 0;
      }
      i64toi32_i32$5 = $6$hi;
      i64toi32_i32$2 = $6_1;
      i64toi32_i32$3 = -1;
      i64toi32_i32$0 = -48;
      i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
      i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
      if (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) {
       i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
      }
      $6_1 = i64toi32_i32$1;
      $6$hi = i64toi32_i32$4;
      label$18 : {
       $3_1 = $2_1 + -48 | 0;
       if ($3_1 >>> 0 > 9 >>> 0) {
        break label$18
       }
       i64toi32_i32$5 = i64toi32_i32$1;
       i64toi32_i32$2 = 21474836;
       i64toi32_i32$0 = 2061584302;
       if ((i64toi32_i32$4 | 0) < (i64toi32_i32$2 | 0)) {
        $21_1 = 1
       } else {
        if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$2 | 0)) {
         if (i64toi32_i32$5 >>> 0 >= i64toi32_i32$0 >>> 0) {
          $22_1 = 0
         } else {
          $22_1 = 1
         }
         $23_1 = $22_1;
        } else {
         $23_1 = 0
        }
        $21_1 = $23_1;
       }
       if ($21_1) {
        continue label$15
       }
      }
      break label$15;
     };
     if ($3_1 >>> 0 >= 10 >>> 0) {
      break label$10
     }
     label$19 : while (1) {
      label$20 : {
       label$21 : {
        $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
        if (($2_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
         break label$21
        }
        HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 + 1 | 0;
        $2_1 = HEAPU8[$2_1 >> 0] | 0;
        break label$20;
       }
       $2_1 = $50($0_1 | 0) | 0;
      }
      if (($2_1 + -48 | 0) >>> 0 < 10 >>> 0) {
       continue label$19
      }
      break label$19;
     };
    }
    label$22 : {
     i64toi32_i32$0 = $0_1;
     i64toi32_i32$5 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
     i64toi32_i32$4 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
     i64toi32_i32$0 = i64toi32_i32$5;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = 0;
     if ((i64toi32_i32$4 | 0) < (i64toi32_i32$5 | 0)) {
      $24_1 = 1
     } else {
      if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$5 | 0)) {
       if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$2 >>> 0) {
        $25_1 = 0
       } else {
        $25_1 = 1
       }
       $26_1 = $25_1;
      } else {
       $26_1 = 0
      }
      $24_1 = $26_1;
     }
     if ($24_1) {
      break label$22
     }
     HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
    }
    i64toi32_i32$0 = $6$hi;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = $6$hi;
    i64toi32_i32$5 = $6_1;
    i64toi32_i32$3 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
    i64toi32_i32$1 = (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) + i64toi32_i32$4 | 0;
    i64toi32_i32$1 = i64toi32_i32$0 - i64toi32_i32$1 | 0;
    $139$hi = i64toi32_i32$1;
    i64toi32_i32$1 = i64toi32_i32$4;
    i64toi32_i32$4 = $4_1;
    i64toi32_i32$1 = $139$hi;
    i64toi32_i32$2 = $6$hi;
    i64toi32_i32$5 = i64toi32_i32$4 ? i64toi32_i32$3 : i64toi32_i32$5;
    i64toi32_i32$0 = i64toi32_i32$4 ? i64toi32_i32$1 : i64toi32_i32$2;
    $6_1 = i64toi32_i32$5;
    $6$hi = i64toi32_i32$0;
    break label$3;
   }
   i64toi32_i32$0 = -2147483648;
   $6_1 = 0;
   $6$hi = i64toi32_i32$0;
   i64toi32_i32$4 = $0_1;
   i64toi32_i32$0 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
   i64toi32_i32$5 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
   i64toi32_i32$4 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 0;
   if ((i64toi32_i32$5 | 0) < (i64toi32_i32$0 | 0)) {
    $27_1 = 1
   } else {
    if ((i64toi32_i32$5 | 0) <= (i64toi32_i32$0 | 0)) {
     if (i64toi32_i32$4 >>> 0 >= i64toi32_i32$1 >>> 0) {
      $28_1 = 0
     } else {
      $28_1 = 1
     }
     $29_1 = $28_1;
    } else {
     $29_1 = 0
    }
    $27_1 = $29_1;
   }
   if ($27_1) {
    break label$3
   }
   HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
   i64toi32_i32$4 = -2147483648;
   i64toi32_i32$5 = 0;
   i64toi32_i32$HIGH_BITS = i64toi32_i32$4;
   return i64toi32_i32$5 | 0;
  }
  i64toi32_i32$5 = $6$hi;
  i64toi32_i32$4 = $6_1;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$5;
  return i64toi32_i32$4 | 0;
 }
 
 function $62($0_1, $1_1, $2_1, $3_1, $3$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  var i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, $5_1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$1 = 0, $9$hi = 0, $9_1 = 0, $7_1 = 0, $10$hi = 0, $11$hi = 0, $10_1 = 0, $11_1 = 0, $12$hi = 0, $6_1 = 0, $12_1 = 0, $4_1 = 0, $30_1 = 0, $31_1 = 0, $32_1 = 0, $33_1 = 0, $34_1 = 0, $35_1 = 0, $8_1 = 0, $36_1 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $40_1 = 0, $194 = 0, $194$hi = 0, $248 = 0, $248$hi = 0, $346$hi = 0, $413$hi = 0;
  $4_1 = global$0 - 16 | 0;
  global$0 = $4_1;
  label$1 : {
   label$2 : {
    label$3 : {
     if ($1_1 >>> 0 > 36 >>> 0) {
      break label$3
     }
     if (($1_1 | 0) != (1 | 0)) {
      break label$2
     }
    }
    HEAP32[($16() | 0) >> 2] = 28;
    i64toi32_i32$0 = 0;
    $3_1 = 0;
    $3$hi = i64toi32_i32$0;
    break label$1;
   }
   label$4 : while (1) {
    label$5 : {
     label$6 : {
      $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
      if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
       break label$6
      }
      HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
      $5_1 = HEAPU8[$5_1 >> 0] | 0;
      break label$5;
     }
     $5_1 = $50($0_1 | 0) | 0;
    }
    if ($63($5_1 | 0) | 0) {
     continue label$4
    }
    break label$4;
   };
   $6_1 = 0;
   label$7 : {
    label$8 : {
     switch ($5_1 + -43 | 0 | 0) {
     case 0:
     case 2:
      break label$8;
     default:
      break label$7;
     };
    }
    $6_1 = ($5_1 | 0) == (45 | 0) ? -1 : 0;
    label$9 : {
     $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
     if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
      break label$9
     }
     HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
     $5_1 = HEAPU8[$5_1 >> 0] | 0;
     break label$7;
    }
    $5_1 = $50($0_1 | 0) | 0;
   }
   label$10 : {
    label$11 : {
     label$12 : {
      label$13 : {
       label$14 : {
        if (($1_1 | 0) != (0 | 0) & ($1_1 | 0) != (16 | 0) | 0) {
         break label$14
        }
        if (($5_1 | 0) != (48 | 0)) {
         break label$14
        }
        label$15 : {
         label$16 : {
          $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
          if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
           break label$16
          }
          HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
          $5_1 = HEAPU8[$5_1 >> 0] | 0;
          break label$15;
         }
         $5_1 = $50($0_1 | 0) | 0;
        }
        label$17 : {
         if (($5_1 & -33 | 0 | 0) != (88 | 0)) {
          break label$17
         }
         label$18 : {
          label$19 : {
           $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
           if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
            break label$19
           }
           HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
           $5_1 = HEAPU8[$5_1 >> 0] | 0;
           break label$18;
          }
          $5_1 = $50($0_1 | 0) | 0;
         }
         $1_1 = 16;
         if ((HEAPU8[($5_1 + 66209 | 0) >> 0] | 0) >>> 0 < 16 >>> 0) {
          break label$12
         }
         i64toi32_i32$0 = 0;
         $3_1 = 0;
         $3$hi = i64toi32_i32$0;
         label$20 : {
          label$21 : {
           i64toi32_i32$2 = $0_1;
           i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 112 | 0) >> 2] | 0;
           i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 116 | 0) >> 2] | 0;
           i64toi32_i32$2 = i64toi32_i32$0;
           i64toi32_i32$0 = 0;
           i64toi32_i32$3 = 0;
           if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
            $30_1 = 1
           } else {
            if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
             if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) {
              $31_1 = 0
             } else {
              $31_1 = 1
             }
             $32_1 = $31_1;
            } else {
             $32_1 = 0
            }
            $30_1 = $32_1;
           }
           if ($30_1) {
            break label$21
           }
           $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
           HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + -1 | 0;
           if (!$2_1) {
            break label$20
           }
           HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + -2 | 0;
           break label$1;
          }
          if ($2_1) {
           break label$1
          }
         }
         i64toi32_i32$2 = 0;
         $3_1 = 0;
         $3$hi = i64toi32_i32$2;
         i64toi32_i32$2 = 0;
         $49($0_1 | 0, 0 | 0, i64toi32_i32$2 | 0);
         break label$1;
        }
        if ($1_1) {
         break label$13
        }
        $1_1 = 8;
        break label$12;
       }
       $1_1 = $1_1 ? $1_1 : 10;
       if ($1_1 >>> 0 > (HEAPU8[($5_1 + 66209 | 0) >> 0] | 0) >>> 0) {
        break label$13
       }
       i64toi32_i32$2 = 0;
       $3_1 = 0;
       $3$hi = i64toi32_i32$2;
       label$22 : {
        i64toi32_i32$3 = $0_1;
        i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 112 | 0) >> 2] | 0;
        i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 116 | 0) >> 2] | 0;
        i64toi32_i32$3 = i64toi32_i32$2;
        i64toi32_i32$2 = 0;
        i64toi32_i32$0 = 0;
        if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) {
         $33_1 = 1
        } else {
         if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
          if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$0 >>> 0) {
           $34_1 = 0
          } else {
           $34_1 = 1
          }
          $35_1 = $34_1;
         } else {
          $35_1 = 0
         }
         $33_1 = $35_1;
        }
        if ($33_1) {
         break label$22
        }
        HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
       }
       i64toi32_i32$3 = 0;
       $49($0_1 | 0, 0 | 0, i64toi32_i32$3 | 0);
       HEAP32[($16() | 0) >> 2] = 28;
       break label$1;
      }
      if (($1_1 | 0) != (10 | 0)) {
       break label$12
      }
      i64toi32_i32$3 = 0;
      $9_1 = 0;
      $9$hi = i64toi32_i32$3;
      label$23 : {
       $2_1 = $5_1 + -48 | 0;
       if ($2_1 >>> 0 > 9 >>> 0) {
        break label$23
       }
       $5_1 = 0;
       label$24 : while (1) {
        label$25 : {
         label$26 : {
          $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
          if (($1_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
           break label$26
          }
          HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 + 1 | 0;
          $1_1 = HEAPU8[$1_1 >> 0] | 0;
          break label$25;
         }
         $1_1 = $50($0_1 | 0) | 0;
        }
        $5_1 = Math_imul($5_1, 10) + $2_1 | 0;
        label$27 : {
         $2_1 = $1_1 + -48 | 0;
         if ($2_1 >>> 0 > 9 >>> 0) {
          break label$27
         }
         if ($5_1 >>> 0 < 429496729 >>> 0) {
          continue label$24
         }
        }
        break label$24;
       };
       i64toi32_i32$3 = 0;
       $9_1 = $5_1;
       $9$hi = i64toi32_i32$3;
      }
      if ($2_1 >>> 0 > 9 >>> 0) {
       break label$10
      }
      i64toi32_i32$3 = $9$hi;
      i64toi32_i32$1 = 0;
      i64toi32_i32$1 = __wasm_i64_mul($9_1 | 0, i64toi32_i32$3 | 0, 10 | 0, i64toi32_i32$1 | 0) | 0;
      i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
      $10_1 = i64toi32_i32$1;
      $10$hi = i64toi32_i32$3;
      i64toi32_i32$3 = 0;
      $11_1 = $2_1;
      $11$hi = i64toi32_i32$3;
      label$28 : while (1) {
       label$29 : {
        label$30 : {
         $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
         if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
          break label$30
         }
         HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
         $5_1 = HEAPU8[$5_1 >> 0] | 0;
         break label$29;
        }
        $5_1 = $50($0_1 | 0) | 0;
       }
       i64toi32_i32$3 = $10$hi;
       i64toi32_i32$3 = $11$hi;
       i64toi32_i32$3 = $10$hi;
       i64toi32_i32$0 = $10_1;
       i64toi32_i32$1 = $11$hi;
       i64toi32_i32$2 = $11_1;
       i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
       i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
       if (i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0) {
        i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
       }
       $9_1 = i64toi32_i32$4;
       $9$hi = i64toi32_i32$5;
       label$31 : {
        label$32 : {
         $2_1 = $5_1 + -48 | 0;
         if ($2_1 >>> 0 > 9 >>> 0) {
          break label$32
         }
         i64toi32_i32$3 = i64toi32_i32$4;
         i64toi32_i32$0 = 429496729;
         i64toi32_i32$2 = -1717986918;
         if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0) {
          break label$31
         }
        }
        $1_1 = 10;
        if ($2_1 >>> 0 <= 9 >>> 0) {
         break label$11
        }
        break label$10;
       }
       i64toi32_i32$3 = $9$hi;
       i64toi32_i32$5 = 0;
       i64toi32_i32$5 = __wasm_i64_mul($9_1 | 0, i64toi32_i32$3 | 0, 10 | 0, i64toi32_i32$5 | 0) | 0;
       i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
       $10_1 = i64toi32_i32$5;
       $10$hi = i64toi32_i32$3;
       i64toi32_i32$3 = 0;
       $11_1 = $2_1;
       $11$hi = i64toi32_i32$3;
       i64toi32_i32$2 = $2_1;
       i64toi32_i32$5 = -1;
       i64toi32_i32$0 = -1;
       i64toi32_i32$5 = i64toi32_i32$3 ^ i64toi32_i32$5 | 0;
       $194 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
       $194$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $10$hi;
       i64toi32_i32$3 = $10_1;
       i64toi32_i32$2 = $194$hi;
       i64toi32_i32$0 = $194;
       if (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$3 >>> 0 <= i64toi32_i32$0 >>> 0 | 0) | 0) {
        continue label$28
       }
       break label$28;
      };
      $1_1 = 10;
      break label$11;
     }
     label$33 : {
      if (!($1_1 & ($1_1 + -1 | 0) | 0)) {
       break label$33
      }
      i64toi32_i32$3 = 0;
      $9_1 = 0;
      $9$hi = i64toi32_i32$3;
      label$34 : {
       $7_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
       if ($1_1 >>> 0 <= $7_1 >>> 0) {
        break label$34
       }
       $2_1 = 0;
       label$35 : while (1) {
        label$36 : {
         label$37 : {
          $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
          if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
           break label$37
          }
          HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
          $5_1 = HEAPU8[$5_1 >> 0] | 0;
          break label$36;
         }
         $5_1 = $50($0_1 | 0) | 0;
        }
        $2_1 = $7_1 + Math_imul($2_1, $1_1) | 0;
        label$38 : {
         $7_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
         if ($1_1 >>> 0 <= $7_1 >>> 0) {
          break label$38
         }
         if ($2_1 >>> 0 < 119304647 >>> 0) {
          continue label$35
         }
        }
        break label$35;
       };
       i64toi32_i32$3 = 0;
       $9_1 = $2_1;
       $9$hi = i64toi32_i32$3;
      }
      if ($1_1 >>> 0 <= $7_1 >>> 0) {
       break label$11
      }
      i64toi32_i32$3 = 0;
      $10_1 = $1_1;
      $10$hi = i64toi32_i32$3;
      label$39 : while (1) {
       i64toi32_i32$3 = $9$hi;
       i64toi32_i32$3 = $10$hi;
       i64toi32_i32$3 = $9$hi;
       i64toi32_i32$5 = $10$hi;
       i64toi32_i32$5 = __wasm_i64_mul($9_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$5 | 0) | 0;
       i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
       $11_1 = i64toi32_i32$5;
       $11$hi = i64toi32_i32$3;
       i64toi32_i32$3 = 0;
       i64toi32_i32$0 = $7_1;
       i64toi32_i32$5 = 0;
       i64toi32_i32$2 = 255;
       i64toi32_i32$5 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
       $12_1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
       $12$hi = i64toi32_i32$5;
       i64toi32_i32$3 = $12_1;
       i64toi32_i32$0 = -1;
       i64toi32_i32$2 = -1;
       i64toi32_i32$0 = i64toi32_i32$5 ^ i64toi32_i32$0 | 0;
       $248 = i64toi32_i32$3 ^ i64toi32_i32$2 | 0;
       $248$hi = i64toi32_i32$0;
       i64toi32_i32$0 = $11$hi;
       i64toi32_i32$5 = $11_1;
       i64toi32_i32$3 = $248$hi;
       i64toi32_i32$2 = $248;
       if (i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0) {
        break label$11
       }
       label$40 : {
        label$41 : {
         $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
         if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
          break label$41
         }
         HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
         $5_1 = HEAPU8[$5_1 >> 0] | 0;
         break label$40;
        }
        $5_1 = $50($0_1 | 0) | 0;
       }
       i64toi32_i32$5 = $11$hi;
       i64toi32_i32$5 = $12$hi;
       i64toi32_i32$5 = $11$hi;
       i64toi32_i32$2 = $11_1;
       i64toi32_i32$0 = $12$hi;
       i64toi32_i32$3 = $12_1;
       i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
       i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
       if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
        i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
       }
       $9_1 = i64toi32_i32$1;
       $9$hi = i64toi32_i32$4;
       $7_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
       if ($1_1 >>> 0 <= $7_1 >>> 0) {
        break label$11
       }
       i64toi32_i32$4 = $10$hi;
       i64toi32_i32$4 = $9$hi;
       i64toi32_i32$4 = $10$hi;
       i64toi32_i32$2 = 0;
       i64toi32_i32$5 = $9$hi;
       i64toi32_i32$3 = 0;
       $98($4_1 | 0, $10_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$2 | 0, i64toi32_i32$1 | 0, i64toi32_i32$5 | 0, 0 | 0, i64toi32_i32$3 | 0);
       i64toi32_i32$2 = $4_1;
       i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] | 0;
       i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] | 0;
       i64toi32_i32$2 = i64toi32_i32$3;
       i64toi32_i32$3 = 0;
       i64toi32_i32$4 = 0;
       if ((i64toi32_i32$2 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$5 | 0) != (i64toi32_i32$3 | 0) | 0) {
        break label$11
       }
       continue label$39;
      };
     }
     $8_1 = HEAP8[(((Math_imul($1_1, 23) >>> 5 | 0) & 7 | 0) + 66465 | 0) >> 0] | 0;
     i64toi32_i32$2 = 0;
     $9_1 = 0;
     $9$hi = i64toi32_i32$2;
     label$42 : {
      $2_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
      if ($1_1 >>> 0 <= $2_1 >>> 0) {
       break label$42
      }
      $7_1 = 0;
      label$43 : while (1) {
       label$44 : {
        label$45 : {
         $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
         if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
          break label$45
         }
         HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
         $5_1 = HEAPU8[$5_1 >> 0] | 0;
         break label$44;
        }
        $5_1 = $50($0_1 | 0) | 0;
       }
       $7_1 = $2_1 | ($7_1 << $8_1 | 0) | 0;
       label$46 : {
        $2_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
        if ($1_1 >>> 0 <= $2_1 >>> 0) {
         break label$46
        }
        if ($7_1 >>> 0 < 134217728 >>> 0) {
         continue label$43
        }
       }
       break label$43;
      };
      i64toi32_i32$2 = 0;
      $9_1 = $7_1;
      $9$hi = i64toi32_i32$2;
     }
     if ($1_1 >>> 0 <= $2_1 >>> 0) {
      break label$11
     }
     i64toi32_i32$2 = 0;
     $11_1 = $8_1;
     $11$hi = i64toi32_i32$2;
     i64toi32_i32$2 = -1;
     i64toi32_i32$4 = -1;
     i64toi32_i32$5 = $11$hi;
     i64toi32_i32$3 = $11_1;
     i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = 0;
      $36_1 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$5 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
      $36_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$0 | 0) | 0;
     }
     $12_1 = $36_1;
     $12$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $9$hi;
     i64toi32_i32$5 = $12$hi;
     i64toi32_i32$2 = $12_1;
     i64toi32_i32$4 = $9$hi;
     i64toi32_i32$3 = $9_1;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0) {
      break label$11
     }
     label$47 : while (1) {
      i64toi32_i32$2 = 0;
      i64toi32_i32$3 = $2_1;
      i64toi32_i32$5 = 0;
      i64toi32_i32$4 = 255;
      i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
      $10_1 = i64toi32_i32$3 & i64toi32_i32$4 | 0;
      $10$hi = i64toi32_i32$5;
      label$48 : {
       label$49 : {
        $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
        if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
         break label$49
        }
        HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
        $5_1 = HEAPU8[$5_1 >> 0] | 0;
        break label$48;
       }
       $5_1 = $50($0_1 | 0) | 0;
      }
      i64toi32_i32$5 = $9$hi;
      i64toi32_i32$5 = $11$hi;
      i64toi32_i32$5 = $9$hi;
      i64toi32_i32$2 = $9_1;
      i64toi32_i32$3 = $11$hi;
      i64toi32_i32$4 = $11_1;
      i64toi32_i32$0 = i64toi32_i32$4 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
       i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$0 | 0;
       $37_1 = 0;
      } else {
       i64toi32_i32$3 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$0 | 0) | 0;
       $37_1 = i64toi32_i32$2 << i64toi32_i32$0 | 0;
      }
      $346$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $10$hi;
      i64toi32_i32$3 = $346$hi;
      i64toi32_i32$5 = $37_1;
      i64toi32_i32$2 = $10$hi;
      i64toi32_i32$4 = $10_1;
      i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
      $9_1 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
      $9$hi = i64toi32_i32$2;
      $2_1 = HEAPU8[($5_1 + 66209 | 0) >> 0] | 0;
      if ($1_1 >>> 0 <= $2_1 >>> 0) {
       break label$11
      }
      i64toi32_i32$2 = $12$hi;
      i64toi32_i32$2 = $9$hi;
      i64toi32_i32$3 = $9_1;
      i64toi32_i32$5 = $12$hi;
      i64toi32_i32$4 = $12_1;
      if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 <= i64toi32_i32$4 >>> 0 | 0) | 0) {
       continue label$47
      }
      break label$47;
     };
    }
    if ($1_1 >>> 0 <= (HEAPU8[($5_1 + 66209 | 0) >> 0] | 0) >>> 0) {
     break label$10
    }
    label$50 : while (1) {
     label$51 : {
      label$52 : {
       $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
       if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
        break label$52
       }
       HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
       $5_1 = HEAPU8[$5_1 >> 0] | 0;
       break label$51;
      }
      $5_1 = $50($0_1 | 0) | 0;
     }
     if ($1_1 >>> 0 > (HEAPU8[($5_1 + 66209 | 0) >> 0] | 0) >>> 0) {
      continue label$50
     }
     break label$50;
    };
    HEAP32[($16() | 0) >> 2] = 68;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$4 = $3_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$2 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
    $6_1 = !(i64toi32_i32$4 & i64toi32_i32$5 | 0 | i64toi32_i32$2 | 0) ? $6_1 : 0;
    i64toi32_i32$2 = i64toi32_i32$3;
    i64toi32_i32$2 = i64toi32_i32$3;
    $9_1 = i64toi32_i32$4;
    $9$hi = i64toi32_i32$3;
   }
   label$53 : {
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 112 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 116 | 0) >> 2] | 0;
    i64toi32_i32$3 = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    i64toi32_i32$5 = 0;
    if ((i64toi32_i32$4 | 0) < (i64toi32_i32$2 | 0)) {
     $38_1 = 1
    } else {
     if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$2 | 0)) {
      if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$5 >>> 0) {
       $39_1 = 0
      } else {
       $39_1 = 1
      }
      $40_1 = $39_1;
     } else {
      $40_1 = 0
     }
     $38_1 = $40_1;
    }
    if ($38_1) {
     break label$53
    }
    HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
   }
   label$54 : {
    i64toi32_i32$3 = $9$hi;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $9$hi;
    i64toi32_i32$5 = $9_1;
    i64toi32_i32$4 = $3$hi;
    i64toi32_i32$2 = $3_1;
    if (i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0) {
     break label$54
    }
    label$55 : {
     i64toi32_i32$5 = i64toi32_i32$4;
     if (i64toi32_i32$2 & 1 | 0) {
      break label$55
     }
     if ($6_1) {
      break label$55
     }
     HEAP32[($16() | 0) >> 2] = 68;
     i64toi32_i32$3 = -1;
     i64toi32_i32$4 = -1;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $3_1 = i64toi32_i32$0;
     $3$hi = i64toi32_i32$1;
     break label$1;
    }
    i64toi32_i32$1 = $9$hi;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$1 = $9$hi;
    i64toi32_i32$5 = $9_1;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$4 = $3_1;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 <= i64toi32_i32$4 >>> 0 | 0) | 0) {
     break label$54
    }
    HEAP32[($16() | 0) >> 2] = 68;
    break label$1;
   }
   i64toi32_i32$5 = $9$hi;
   i64toi32_i32$1 = $6_1;
   i64toi32_i32$5 = i64toi32_i32$1 >> 31 | 0;
   $3_1 = i64toi32_i32$1;
   $3$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $9$hi;
   i64toi32_i32$4 = $9_1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$1 = i64toi32_i32$5 ^ i64toi32_i32$1 | 0;
   $413$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $413$hi;
   i64toi32_i32$5 = i64toi32_i32$4 ^ i64toi32_i32$2 | 0;
   i64toi32_i32$4 = $3$hi;
   i64toi32_i32$3 = i64toi32_i32$5 - i64toi32_i32$2 | 0;
   i64toi32_i32$0 = (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) + i64toi32_i32$4 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 - i64toi32_i32$0 | 0;
   $3_1 = i64toi32_i32$3;
   $3$hi = i64toi32_i32$0;
  }
  global$0 = $4_1 + 16 | 0;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$5 = $3_1;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$5 | 0;
 }
 
 function $63($0_1) {
  $0_1 = $0_1 | 0;
  return ($0_1 | 0) == (32 | 0) | ($0_1 + -9 | 0) >>> 0 < 5 >>> 0 | 0 | 0;
 }
 
 function $64() {
  return 42 | 0;
 }
 
 function $65() {
  return $64() | 0 | 0;
 }
 
 function $66() {
  return 69136 | 0;
 }
 
 function $67() {
  HEAP32[(0 + 69232 | 0) >> 2] = 69112;
  HEAP32[(0 + 69160 | 0) >> 2] = $65() | 0;
 }
 
 function $68($0_1, $1_1, $2_1, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  var $5_1 = 0, $4_1 = 0, $6_1 = 0, $7_1 = 0;
  $4_1 = $3_1 ? $3_1 : 69268;
  $3_1 = HEAP32[$4_1 >> 2] | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      if ($1_1) {
       break label$4
      }
      if ($3_1) {
       break label$3
      }
      return 0 | 0;
     }
     $5_1 = -2;
     if (!$2_1) {
      break label$2
     }
     label$5 : {
      label$6 : {
       if (!$3_1) {
        break label$6
       }
       $5_1 = $2_1;
       break label$5;
      }
      label$7 : {
       $5_1 = HEAPU8[$1_1 >> 0] | 0;
       $3_1 = $5_1 << 24 >> 24;
       if (($3_1 | 0) < (0 | 0)) {
        break label$7
       }
       label$8 : {
        if (!$0_1) {
         break label$8
        }
        HEAP32[$0_1 >> 2] = $5_1;
       }
       return ($3_1 | 0) != (0 | 0) | 0;
      }
      label$9 : {
       if (HEAP32[(HEAP32[(($66() | 0) + 96 | 0) >> 2] | 0) >> 2] | 0) {
        break label$9
       }
       $5_1 = 1;
       if (!$0_1) {
        break label$2
       }
       HEAP32[$0_1 >> 2] = $3_1 & 57343 | 0;
       return 1 | 0;
      }
      $3_1 = $5_1 + -194 | 0;
      if ($3_1 >>> 0 > 50 >>> 0) {
       break label$3
      }
      $3_1 = HEAP32[(($3_1 << 2 | 0) + 66480 | 0) >> 2] | 0;
      $5_1 = $2_1 + -1 | 0;
      if (!$5_1) {
       break label$1
      }
      $1_1 = $1_1 + 1 | 0;
     }
     $6_1 = HEAPU8[$1_1 >> 0] | 0;
     $7_1 = $6_1 >>> 3 | 0;
     if (($7_1 + -16 | 0 | (($3_1 >> 26 | 0) + $7_1 | 0) | 0) >>> 0 > 7 >>> 0) {
      break label$3
     }
     label$10 : while (1) {
      $5_1 = $5_1 + -1 | 0;
      label$11 : {
       $3_1 = ($6_1 & 255 | 0) + -128 | 0 | ($3_1 << 6 | 0) | 0;
       if (($3_1 | 0) < (0 | 0)) {
        break label$11
       }
       HEAP32[$4_1 >> 2] = 0;
       label$12 : {
        if (!$0_1) {
         break label$12
        }
        HEAP32[$0_1 >> 2] = $3_1;
       }
       return $2_1 - $5_1 | 0 | 0;
      }
      if (!$5_1) {
       break label$1
      }
      $1_1 = $1_1 + 1 | 0;
      $6_1 = HEAPU8[$1_1 >> 0] | 0;
      if (($6_1 & 192 | 0 | 0) == (128 | 0)) {
       continue label$10
      }
      break label$10;
     };
    }
    HEAP32[$4_1 >> 2] = 0;
    HEAP32[($16() | 0) >> 2] = 25;
    $5_1 = -1;
   }
   return $5_1 | 0;
  }
  HEAP32[$4_1 >> 2] = $3_1;
  return -2 | 0;
 }
 
 function $69($0_1) {
  $0_1 = $0_1 | 0;
  label$1 : {
   if ($0_1) {
    break label$1
   }
   return 1 | 0;
  }
  return !(HEAP32[$0_1 >> 2] | 0) | 0;
 }
 
 function $70($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, i64toi32_i32$0 = 0, $5_1 = 0, i64toi32_i32$2 = 0, $9_1 = 0, i64toi32_i32$5 = 0, $14_1 = 0, $3_1 = 0, $11_1 = 0, $8_1 = 0, $13_1 = 0, $19$hi = 0, $12_1 = 0, $15_1 = 0, $20$hi = 0, $17_1 = 0, $6_1 = 0, $19_1 = 0, $10_1 = 0, $20_1 = 0, $21$hi = 0, $16_1 = 0, $18_1 = 0, $21_1 = 0, i64toi32_i32$6 = 0, $4_1 = 0, $62_1 = 0, $63_1 = 0, $64_1 = 0, $65_1 = 0, $66_1 = 0, $67_1 = 0, $68_1 = 0, $69_1 = 0, $70_1 = 0, $71_1 = 0, $72_1 = 0, $73_1 = 0, $74_1 = 0, $75_1 = 0, $76_1 = 0, $77_1 = 0, $7_1 = 0, $80$hi = 0, $82$hi = 0, $87_1 = 0, $87$hi = 0, $146$hi = 0, $148$hi = 0, $154 = 0, $154$hi = 0, $282$hi = 0, $284$hi = 0, $289 = 0, $289$hi = 0, $329 = 0, $329$hi = 0, $335 = 0, $335$hi = 0, $336$hi = 0, $435 = 0, $435$hi = 0, $441 = 0, $441$hi = 0, $442$hi = 0, $653 = 0, $653$hi = 0, $658 = 0, $658$hi = 0, $686$hi = 0, $688$hi = 0, $694 = 0, $694$hi = 0;
  $3_1 = global$0 - 304 | 0;
  global$0 = $3_1;
  label$1 : {
   label$2 : {
    if ((HEAP32[($0_1 + 76 | 0) >> 2] | 0 | 0) >= (0 | 0)) {
     break label$2
    }
    $4_1 = 1;
    break label$1;
   }
   $4_1 = !($14($0_1 | 0) | 0);
  }
  label$3 : {
   label$4 : {
    label$5 : {
     if (HEAP32[($0_1 + 4 | 0) >> 2] | 0) {
      break label$5
     }
     $47($0_1 | 0) | 0;
     if (!(HEAP32[($0_1 + 4 | 0) >> 2] | 0)) {
      break label$4
     }
    }
    label$6 : {
     $5_1 = HEAPU8[$1_1 >> 0] | 0;
     if ($5_1) {
      break label$6
     }
     $6_1 = 0;
     break label$3;
    }
    $7_1 = $3_1 + 16 | 0;
    i64toi32_i32$0 = 0;
    $19_1 = 0;
    $19$hi = i64toi32_i32$0;
    $6_1 = 0;
    label$7 : {
     label$8 : {
      label$9 : {
       label$10 : {
        label$11 : {
         label$12 : {
          label$13 : while (1) {
           label$14 : {
            label$15 : {
             $5_1 = $5_1 & 255 | 0;
             if (!($71($5_1 | 0) | 0)) {
              break label$15
             }
             label$16 : while (1) {
              $5_1 = $1_1;
              $1_1 = $1_1 + 1 | 0;
              if ($71(HEAPU8[($5_1 + 1 | 0) >> 0] | 0 | 0) | 0) {
               continue label$16
              }
              break label$16;
             };
             i64toi32_i32$0 = 0;
             $49($0_1 | 0, 0 | 0, i64toi32_i32$0 | 0);
             label$17 : while (1) {
              label$18 : {
               label$19 : {
                $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                if (($1_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                 break label$19
                }
                HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 + 1 | 0;
                $1_1 = HEAPU8[$1_1 >> 0] | 0;
                break label$18;
               }
               $1_1 = $50($0_1 | 0) | 0;
              }
              if ($71($1_1 | 0) | 0) {
               continue label$17
              }
              break label$17;
             };
             $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
             label$20 : {
              i64toi32_i32$2 = $0_1;
              i64toi32_i32$0 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
              i64toi32_i32$1 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
              i64toi32_i32$2 = i64toi32_i32$0;
              i64toi32_i32$0 = 0;
              i64toi32_i32$3 = 0;
              if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
               $62_1 = 1
              } else {
               if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
                if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$3 >>> 0) {
                 $63_1 = 0
                } else {
                 $63_1 = 1
                }
                $64_1 = $63_1;
               } else {
                $64_1 = 0
               }
               $62_1 = $64_1;
              }
              if ($62_1) {
               break label$20
              }
              $1_1 = $1_1 + -1 | 0;
              HEAP32[($0_1 + 4 | 0) >> 2] = $1_1;
             }
             i64toi32_i32$3 = $0_1;
             i64toi32_i32$2 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
             i64toi32_i32$1 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
             $80$hi = i64toi32_i32$1;
             i64toi32_i32$1 = $19$hi;
             i64toi32_i32$1 = $80$hi;
             i64toi32_i32$3 = i64toi32_i32$2;
             i64toi32_i32$2 = $19$hi;
             i64toi32_i32$0 = $19_1;
             i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
             i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
             if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
              i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
             }
             $82$hi = i64toi32_i32$5;
             i64toi32_i32$3 = $1_1 - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
             i64toi32_i32$5 = i64toi32_i32$3 >> 31 | 0;
             $87_1 = i64toi32_i32$3;
             $87$hi = i64toi32_i32$5;
             i64toi32_i32$5 = $82$hi;
             i64toi32_i32$1 = i64toi32_i32$4;
             i64toi32_i32$3 = $87$hi;
             i64toi32_i32$0 = $87_1;
             i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
             i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
             if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
              i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
             }
             $19_1 = i64toi32_i32$2;
             $19$hi = i64toi32_i32$4;
             break label$14;
            }
            label$21 : {
             label$22 : {
              label$23 : {
               label$24 : {
                if (($5_1 | 0) != (37 | 0)) {
                 break label$24
                }
                $5_1 = HEAPU8[($1_1 + 1 | 0) >> 0] | 0;
                if (($5_1 | 0) == (42 | 0)) {
                 break label$23
                }
                if (($5_1 | 0) != (37 | 0)) {
                 break label$22
                }
               }
               i64toi32_i32$4 = 0;
               $49($0_1 | 0, 0 | 0, i64toi32_i32$4 | 0);
               label$25 : {
                label$26 : {
                 if ((HEAPU8[$1_1 >> 0] | 0 | 0) != (37 | 0)) {
                  break label$26
                 }
                 label$27 : while (1) {
                  label$28 : {
                   label$29 : {
                    $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                    if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                     break label$29
                    }
                    HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
                    $5_1 = HEAPU8[$5_1 >> 0] | 0;
                    break label$28;
                   }
                   $5_1 = $50($0_1 | 0) | 0;
                  }
                  if ($71($5_1 | 0) | 0) {
                   continue label$27
                  }
                  break label$27;
                 };
                 $1_1 = $1_1 + 1 | 0;
                 break label$25;
                }
                label$30 : {
                 $5_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                 if (($5_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                  break label$30
                 }
                 HEAP32[($0_1 + 4 | 0) >> 2] = $5_1 + 1 | 0;
                 $5_1 = HEAPU8[$5_1 >> 0] | 0;
                 break label$25;
                }
                $5_1 = $50($0_1 | 0) | 0;
               }
               label$31 : {
                if (($5_1 | 0) == (HEAPU8[$1_1 >> 0] | 0 | 0)) {
                 break label$31
                }
                label$32 : {
                 i64toi32_i32$5 = $0_1;
                 i64toi32_i32$4 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
                 i64toi32_i32$1 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
                 i64toi32_i32$5 = i64toi32_i32$4;
                 i64toi32_i32$4 = 0;
                 i64toi32_i32$0 = 0;
                 if ((i64toi32_i32$1 | 0) < (i64toi32_i32$4 | 0)) {
                  $65_1 = 1
                 } else {
                  if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$4 | 0)) {
                   if (i64toi32_i32$5 >>> 0 >= i64toi32_i32$0 >>> 0) {
                    $66_1 = 0
                   } else {
                    $66_1 = 1
                   }
                   $67_1 = $66_1;
                  } else {
                   $67_1 = 0
                  }
                  $65_1 = $67_1;
                 }
                 if ($65_1) {
                  break label$32
                 }
                 HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
                }
                if (($5_1 | 0) > (-1 | 0)) {
                 break label$3
                }
                if ($6_1) {
                 break label$3
                }
                break label$4;
               }
               i64toi32_i32$0 = $0_1;
               i64toi32_i32$5 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
               i64toi32_i32$1 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
               $146$hi = i64toi32_i32$1;
               i64toi32_i32$1 = $19$hi;
               i64toi32_i32$1 = $146$hi;
               i64toi32_i32$0 = i64toi32_i32$5;
               i64toi32_i32$5 = $19$hi;
               i64toi32_i32$4 = $19_1;
               i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
               i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
               if (i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0) {
                i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
               }
               $148$hi = i64toi32_i32$2;
               i64toi32_i32$0 = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
               i64toi32_i32$2 = i64toi32_i32$0 >> 31 | 0;
               $154 = i64toi32_i32$0;
               $154$hi = i64toi32_i32$2;
               i64toi32_i32$2 = $148$hi;
               i64toi32_i32$1 = i64toi32_i32$3;
               i64toi32_i32$0 = $154$hi;
               i64toi32_i32$4 = $154;
               i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
               i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
               if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0) {
                i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
               }
               $19_1 = i64toi32_i32$5;
               $19$hi = i64toi32_i32$3;
               $5_1 = $1_1;
               break label$14;
              }
              $5_1 = $1_1 + 2 | 0;
              $8_1 = 0;
              break label$21;
             }
             label$33 : {
              $9_1 = $5_1 + -48 | 0;
              if ($9_1 >>> 0 > 9 >>> 0) {
               break label$33
              }
              if ((HEAPU8[($1_1 + 2 | 0) >> 0] | 0 | 0) != (36 | 0)) {
               break label$33
              }
              $5_1 = $1_1 + 3 | 0;
              $8_1 = $72($2_1 | 0, $9_1 | 0) | 0;
              break label$21;
             }
             $5_1 = $1_1 + 1 | 0;
             $8_1 = HEAP32[$2_1 >> 2] | 0;
             $2_1 = $2_1 + 4 | 0;
            }
            $10_1 = 0;
            $9_1 = 0;
            label$34 : {
             $1_1 = HEAPU8[$5_1 >> 0] | 0;
             if (($1_1 + -48 | 0) >>> 0 > 9 >>> 0) {
              break label$34
             }
             label$35 : while (1) {
              $9_1 = (Math_imul($9_1, 10) + $1_1 | 0) + -48 | 0;
              $1_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
              $5_1 = $5_1 + 1 | 0;
              if (($1_1 + -48 | 0) >>> 0 < 10 >>> 0) {
               continue label$35
              }
              break label$35;
             };
            }
            label$36 : {
             label$37 : {
              if (($1_1 | 0) == (109 | 0)) {
               break label$37
              }
              $11_1 = $5_1;
              break label$36;
             }
             $11_1 = $5_1 + 1 | 0;
             $12_1 = 0;
             $10_1 = ($8_1 | 0) != (0 | 0);
             $1_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
             $13_1 = 0;
            }
            $5_1 = $11_1 + 1 | 0;
            $14_1 = 3;
            $15_1 = $10_1;
            label$38 : {
             label$39 : {
              switch (($1_1 & 255 | 0) + -65 | 0 | 0) {
              case 39:
               $1_1 = (HEAPU8[($11_1 + 1 | 0) >> 0] | 0 | 0) == (104 | 0);
               $5_1 = $1_1 ? $11_1 + 2 | 0 : $5_1;
               $14_1 = $1_1 ? -2 : -1;
               break label$38;
              case 43:
               $1_1 = (HEAPU8[($11_1 + 1 | 0) >> 0] | 0 | 0) == (108 | 0);
               $5_1 = $1_1 ? $11_1 + 2 | 0 : $5_1;
               $14_1 = $1_1 ? 3 : 1;
               break label$38;
              case 51:
              case 57:
               $14_1 = 1;
               break label$38;
              case 11:
               $14_1 = 2;
               break label$38;
              case 41:
               break label$38;
              case 0:
              case 2:
              case 4:
              case 5:
              case 6:
              case 18:
              case 23:
              case 26:
              case 32:
              case 34:
              case 35:
              case 36:
              case 37:
              case 38:
              case 40:
              case 45:
              case 46:
              case 47:
              case 50:
              case 52:
              case 55:
               break label$39;
              default:
               break label$8;
              };
             }
             $14_1 = 0;
             $5_1 = $11_1;
            }
            $1_1 = HEAPU8[$5_1 >> 0] | 0;
            $11_1 = ($1_1 & 47 | 0 | 0) == (3 | 0);
            $16_1 = $11_1 ? 1 : $14_1;
            label$44 : {
             $17_1 = $11_1 ? $1_1 | 32 | 0 : $1_1;
             if (($17_1 | 0) == (91 | 0)) {
              break label$44
             }
             label$45 : {
              label$46 : {
               if (($17_1 | 0) == (110 | 0)) {
                break label$46
               }
               if (($17_1 | 0) != (99 | 0)) {
                break label$45
               }
               $9_1 = ($9_1 | 0) > (1 | 0) ? $9_1 : 1;
               break label$44;
              }
              i64toi32_i32$3 = $19$hi;
              $73($8_1 | 0, $16_1 | 0, $19_1 | 0, i64toi32_i32$3 | 0);
              break label$14;
             }
             i64toi32_i32$3 = 0;
             $49($0_1 | 0, 0 | 0, i64toi32_i32$3 | 0);
             label$47 : while (1) {
              label$48 : {
               label$49 : {
                $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                if (($1_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                 break label$49
                }
                HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 + 1 | 0;
                $1_1 = HEAPU8[$1_1 >> 0] | 0;
                break label$48;
               }
               $1_1 = $50($0_1 | 0) | 0;
              }
              if ($71($1_1 | 0) | 0) {
               continue label$47
              }
              break label$47;
             };
             $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
             label$50 : {
              i64toi32_i32$2 = $0_1;
              i64toi32_i32$3 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
              i64toi32_i32$1 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
              i64toi32_i32$2 = i64toi32_i32$3;
              i64toi32_i32$3 = 0;
              i64toi32_i32$4 = 0;
              if ((i64toi32_i32$1 | 0) < (i64toi32_i32$3 | 0)) {
               $68_1 = 1
              } else {
               if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$3 | 0)) {
                if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$4 >>> 0) {
                 $69_1 = 0
                } else {
                 $69_1 = 1
                }
                $70_1 = $69_1;
               } else {
                $70_1 = 0
               }
               $68_1 = $70_1;
              }
              if ($68_1) {
               break label$50
              }
              $1_1 = $1_1 + -1 | 0;
              HEAP32[($0_1 + 4 | 0) >> 2] = $1_1;
             }
             i64toi32_i32$4 = $0_1;
             i64toi32_i32$2 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
             i64toi32_i32$1 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
             $282$hi = i64toi32_i32$1;
             i64toi32_i32$1 = $19$hi;
             i64toi32_i32$1 = $282$hi;
             i64toi32_i32$4 = i64toi32_i32$2;
             i64toi32_i32$2 = $19$hi;
             i64toi32_i32$3 = $19_1;
             i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
             i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
             if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) {
              i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
             }
             $284$hi = i64toi32_i32$5;
             i64toi32_i32$4 = $1_1 - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
             i64toi32_i32$5 = i64toi32_i32$4 >> 31 | 0;
             $289 = i64toi32_i32$4;
             $289$hi = i64toi32_i32$5;
             i64toi32_i32$5 = $284$hi;
             i64toi32_i32$1 = i64toi32_i32$0;
             i64toi32_i32$4 = $289$hi;
             i64toi32_i32$3 = $289;
             i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
             i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
             if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
              i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
             }
             $19_1 = i64toi32_i32$2;
             $19$hi = i64toi32_i32$0;
            }
            i64toi32_i32$1 = $9_1;
            i64toi32_i32$0 = i64toi32_i32$1 >> 31 | 0;
            $20_1 = i64toi32_i32$1;
            $20$hi = i64toi32_i32$0;
            $49($0_1 | 0, i64toi32_i32$1 | 0, i64toi32_i32$0 | 0);
            label$51 : {
             label$52 : {
              $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
              if (($1_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
               break label$52
              }
              HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 + 1 | 0;
              break label$51;
             }
             if (($50($0_1 | 0) | 0 | 0) < (0 | 0)) {
              break label$9
             }
            }
            label$53 : {
             i64toi32_i32$5 = $0_1;
             i64toi32_i32$0 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
             i64toi32_i32$1 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
             i64toi32_i32$5 = i64toi32_i32$0;
             i64toi32_i32$0 = 0;
             i64toi32_i32$3 = 0;
             if ((i64toi32_i32$1 | 0) < (i64toi32_i32$0 | 0)) {
              $71_1 = 1
             } else {
              if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$0 | 0)) {
               if (i64toi32_i32$5 >>> 0 >= i64toi32_i32$3 >>> 0) {
                $72_1 = 0
               } else {
                $72_1 = 1
               }
               $73_1 = $72_1;
              } else {
               $73_1 = 0
              }
              $71_1 = $73_1;
             }
             if ($71_1) {
              break label$53
             }
             HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + -1 | 0;
            }
            $1_1 = 16;
            label$54 : {
             label$55 : {
              label$56 : {
               label$57 : {
                label$58 : {
                 switch ($17_1 + -88 | 0 | 0) {
                 default:
                  $1_1 = $17_1 + -65 | 0;
                  if ($1_1 >>> 0 > 6 >>> 0) {
                   break label$54
                  }
                  if (!((1 << $1_1 | 0) & 113 | 0)) {
                   break label$54
                  }
                 case 9:
                 case 13:
                 case 14:
                 case 15:
                  $57($3_1 + 8 | 0 | 0, $0_1 | 0, $16_1 | 0, 0 | 0);
                  i64toi32_i32$3 = $0_1;
                  i64toi32_i32$5 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
                  i64toi32_i32$1 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
                  $329 = i64toi32_i32$5;
                  $329$hi = i64toi32_i32$1;
                  i64toi32_i32$5 = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
                  i64toi32_i32$1 = i64toi32_i32$5 >> 31 | 0;
                  $335 = i64toi32_i32$5;
                  $335$hi = i64toi32_i32$1;
                  i64toi32_i32$1 = 0;
                  i64toi32_i32$3 = 0;
                  i64toi32_i32$5 = $335$hi;
                  i64toi32_i32$0 = $335;
                  i64toi32_i32$4 = i64toi32_i32$3 - i64toi32_i32$0 | 0;
                  i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0;
                  i64toi32_i32$2 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
                  i64toi32_i32$2 = i64toi32_i32$1 - i64toi32_i32$2 | 0;
                  $336$hi = i64toi32_i32$2;
                  i64toi32_i32$2 = $329$hi;
                  i64toi32_i32$1 = $329;
                  i64toi32_i32$3 = $336$hi;
                  i64toi32_i32$0 = i64toi32_i32$4;
                  if ((i64toi32_i32$1 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | 0) {
                   break label$56
                  }
                  break label$10;
                 case 3:
                 case 11:
                 case 27:
                  label$64 : {
                   if (($17_1 | 16 | 0 | 0) != (115 | 0)) {
                    break label$64
                   }
                   $13($3_1 + 32 | 0 | 0, -1 | 0, 257 | 0) | 0;
                   HEAP8[($3_1 + 32 | 0) >> 0] = 0;
                   if (($17_1 | 0) != (115 | 0)) {
                    break label$55
                   }
                   HEAP8[($3_1 + 65 | 0) >> 0] = 0;
                   HEAP8[($3_1 + 46 | 0) >> 0] = 0;
                   $74_1 = 0;
                   HEAP16[($3_1 + 42 | 0) >> 1] = $74_1;
                   HEAP16[($3_1 + 44 | 0) >> 1] = $74_1 >>> 16 | 0;
                   break label$55;
                  }
                  $14_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
                  $1_1 = ($14_1 | 0) == (94 | 0);
                  $13($3_1 + 32 | 0 | 0, $1_1 | 0, 257 | 0) | 0;
                  HEAP8[($3_1 + 32 | 0) >> 0] = 0;
                  $15_1 = $1_1 ? $5_1 + 2 | 0 : $5_1 + 1 | 0;
                  label$65 : {
                   label$66 : {
                    label$67 : {
                     label$68 : {
                      $1_1 = HEAPU8[($5_1 + ($1_1 ? 2 : 1) | 0) >> 0] | 0;
                      if (($1_1 | 0) == (45 | 0)) {
                       break label$68
                      }
                      if (($1_1 | 0) == (93 | 0)) {
                       break label$67
                      }
                      $11_1 = ($14_1 | 0) != (94 | 0);
                      $5_1 = $15_1;
                      break label$65;
                     }
                     $11_1 = ($14_1 | 0) != (94 | 0);
                     HEAP8[($3_1 + 78 | 0) >> 0] = $11_1;
                     break label$66;
                    }
                    $11_1 = ($14_1 | 0) != (94 | 0);
                    HEAP8[($3_1 + 126 | 0) >> 0] = $11_1;
                   }
                   $5_1 = $15_1 + 1 | 0;
                  }
                  label$69 : while (1) {
                   label$70 : {
                    label$71 : {
                     $14_1 = HEAPU8[$5_1 >> 0] | 0;
                     if (($14_1 | 0) == (45 | 0)) {
                      break label$71
                     }
                     if (!$14_1) {
                      break label$9
                     }
                     if (($14_1 | 0) == (93 | 0)) {
                      break label$55
                     }
                     break label$70;
                    }
                    $14_1 = 45;
                    $18_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
                    if (!$18_1) {
                     break label$70
                    }
                    if (($18_1 | 0) == (93 | 0)) {
                     break label$70
                    }
                    $15_1 = $5_1 + 1 | 0;
                    label$72 : {
                     label$73 : {
                      $1_1 = HEAPU8[($5_1 + -1 | 0) >> 0] | 0;
                      if ($1_1 >>> 0 < $18_1 >>> 0) {
                       break label$73
                      }
                      $14_1 = $18_1;
                      break label$72;
                     }
                     label$74 : while (1) {
                      $1_1 = $1_1 + 1 | 0;
                      HEAP8[(($3_1 + 32 | 0) + $1_1 | 0) >> 0] = $11_1;
                      $14_1 = HEAPU8[$15_1 >> 0] | 0;
                      if ($1_1 >>> 0 < $14_1 >>> 0) {
                       continue label$74
                      }
                      break label$74;
                     };
                    }
                    $5_1 = $15_1;
                   }
                   HEAP8[(($14_1 + ($3_1 + 32 | 0) | 0) + 1 | 0) >> 0] = $11_1;
                   $5_1 = $5_1 + 1 | 0;
                   continue label$69;
                  };
                 case 23:
                  $1_1 = 8;
                  break label$57;
                 case 12:
                 case 29:
                  $1_1 = 10;
                  break label$57;
                 case 1:
                 case 2:
                 case 4:
                 case 5:
                 case 6:
                 case 7:
                 case 8:
                 case 10:
                 case 16:
                 case 18:
                 case 19:
                 case 20:
                 case 21:
                 case 22:
                 case 25:
                 case 26:
                 case 28:
                 case 30:
                 case 31:
                  break label$54;
                 case 0:
                 case 24:
                 case 32:
                  break label$57;
                 case 17:
                  break label$58;
                 };
                }
                $1_1 = 0;
               }
               i64toi32_i32$1 = -1;
               i64toi32_i32$1 = $62($0_1 | 0, $1_1 | 0, 0 | 0, -1 | 0, i64toi32_i32$1 | 0) | 0;
               i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
               $20_1 = i64toi32_i32$1;
               $20$hi = i64toi32_i32$2;
               i64toi32_i32$0 = $0_1;
               i64toi32_i32$2 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
               i64toi32_i32$1 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
               $435 = i64toi32_i32$2;
               $435$hi = i64toi32_i32$1;
               i64toi32_i32$2 = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
               i64toi32_i32$1 = i64toi32_i32$2 >> 31 | 0;
               $441 = i64toi32_i32$2;
               $441$hi = i64toi32_i32$1;
               i64toi32_i32$1 = 0;
               i64toi32_i32$0 = 0;
               i64toi32_i32$2 = $441$hi;
               i64toi32_i32$3 = $441;
               i64toi32_i32$5 = i64toi32_i32$0 - i64toi32_i32$3 | 0;
               i64toi32_i32$6 = i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0;
               i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$2 | 0;
               i64toi32_i32$4 = i64toi32_i32$1 - i64toi32_i32$4 | 0;
               $442$hi = i64toi32_i32$4;
               i64toi32_i32$4 = $435$hi;
               i64toi32_i32$1 = $435;
               i64toi32_i32$0 = $442$hi;
               i64toi32_i32$3 = i64toi32_i32$5;
               if ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$0 | 0) | 0) {
                break label$10
               }
               label$75 : {
                if (($17_1 | 0) != (112 | 0)) {
                 break label$75
                }
                if (!$8_1) {
                 break label$75
                }
                i64toi32_i32$1 = $20$hi;
                HEAP32[$8_1 >> 2] = $20_1;
                break label$54;
               }
               i64toi32_i32$1 = $20$hi;
               $73($8_1 | 0, $16_1 | 0, $20_1 | 0, i64toi32_i32$1 | 0);
               break label$54;
              }
              if (!$8_1) {
               break label$54
              }
              i64toi32_i32$3 = $7_1;
              i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
              i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
              $20_1 = i64toi32_i32$1;
              $20$hi = i64toi32_i32$4;
              i64toi32_i32$3 = $3_1;
              i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 8 | 0) >> 2] | 0;
              i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 12 | 0) >> 2] | 0;
              $21_1 = i64toi32_i32$4;
              $21$hi = i64toi32_i32$1;
              label$76 : {
               switch ($16_1 | 0) {
               case 0:
                i64toi32_i32$1 = $21$hi;
                i64toi32_i32$1 = $20$hi;
                i64toi32_i32$1 = $21$hi;
                i64toi32_i32$4 = $20$hi;
                HEAPF32[$8_1 >> 2] = Math_fround($101($21_1 | 0, i64toi32_i32$1 | 0, $20_1 | 0, i64toi32_i32$4 | 0));
                break label$54;
               case 1:
                i64toi32_i32$4 = $21$hi;
                i64toi32_i32$4 = $20$hi;
                i64toi32_i32$4 = $21$hi;
                i64toi32_i32$1 = $20$hi;
                HEAPF64[$8_1 >> 3] = +$100($21_1 | 0, i64toi32_i32$4 | 0, $20_1 | 0, i64toi32_i32$1 | 0);
                break label$54;
               case 2:
                break label$76;
               default:
                break label$54;
               };
              }
              i64toi32_i32$1 = $21$hi;
              i64toi32_i32$4 = $8_1;
              HEAP32[i64toi32_i32$4 >> 2] = $21_1;
              HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] = i64toi32_i32$1;
              i64toi32_i32$1 = $20$hi;
              HEAP32[(i64toi32_i32$4 + 8 | 0) >> 2] = $20_1;
              HEAP32[(i64toi32_i32$4 + 12 | 0) >> 2] = i64toi32_i32$1;
              break label$54;
             }
             $11_1 = ($17_1 | 0) != (99 | 0);
             $14_1 = $11_1 ? 31 : $9_1 + 1 | 0;
             label$79 : {
              label$80 : {
               if (($16_1 | 0) != (1 | 0)) {
                break label$80
               }
               $9_1 = $8_1;
               label$81 : {
                if (!$10_1) {
                 break label$81
                }
                $9_1 = $79($14_1 << 2 | 0 | 0) | 0;
                if (!$9_1) {
                 break label$11
                }
               }
               i64toi32_i32$4 = $3_1;
               i64toi32_i32$1 = 0;
               HEAP32[(i64toi32_i32$4 + 296 | 0) >> 2] = 0;
               HEAP32[(i64toi32_i32$4 + 300 | 0) >> 2] = i64toi32_i32$1;
               $1_1 = 0;
               label$82 : while (1) {
                $13_1 = $9_1;
                label$83 : {
                 label$84 : while (1) {
                  label$85 : {
                   label$86 : {
                    $9_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                    if (($9_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                     break label$86
                    }
                    HEAP32[($0_1 + 4 | 0) >> 2] = $9_1 + 1 | 0;
                    $9_1 = HEAPU8[$9_1 >> 0] | 0;
                    break label$85;
                   }
                   $9_1 = $50($0_1 | 0) | 0;
                  }
                  if (!(HEAPU8[(($9_1 + ($3_1 + 32 | 0) | 0) + 1 | 0) >> 0] | 0)) {
                   break label$83
                  }
                  HEAP8[($3_1 + 27 | 0) >> 0] = $9_1;
                  $9_1 = $68($3_1 + 28 | 0 | 0, $3_1 + 27 | 0 | 0, 1 | 0, $3_1 + 296 | 0 | 0) | 0;
                  if (($9_1 | 0) == (-2 | 0)) {
                   continue label$84
                  }
                  label$87 : {
                   if (($9_1 | 0) != (-1 | 0)) {
                    break label$87
                   }
                   $12_1 = 0;
                   break label$9;
                  }
                  label$88 : {
                   if (!$13_1) {
                    break label$88
                   }
                   HEAP32[($13_1 + ($1_1 << 2 | 0) | 0) >> 2] = HEAP32[($3_1 + 28 | 0) >> 2] | 0;
                   $1_1 = $1_1 + 1 | 0;
                  }
                  if (!$10_1) {
                   continue label$84
                  }
                  if (($1_1 | 0) != ($14_1 | 0)) {
                   continue label$84
                  }
                  break label$84;
                 };
                 $15_1 = 1;
                 $12_1 = 0;
                 $14_1 = $14_1 << 1 | 0 | 1 | 0;
                 $9_1 = $82($13_1 | 0, $14_1 << 2 | 0 | 0) | 0;
                 if ($9_1) {
                  continue label$82
                 }
                 break label$8;
                }
                break label$82;
               };
               $12_1 = 0;
               $14_1 = $13_1;
               if (!($69($3_1 + 296 | 0 | 0) | 0)) {
                break label$9
               }
               break label$79;
              }
              label$89 : {
               if (!$10_1) {
                break label$89
               }
               $1_1 = 0;
               $9_1 = $79($14_1 | 0) | 0;
               if (!$9_1) {
                break label$11
               }
               label$90 : while (1) {
                $13_1 = $9_1;
                label$91 : while (1) {
                 label$92 : {
                  label$93 : {
                   $9_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                   if (($9_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                    break label$93
                   }
                   HEAP32[($0_1 + 4 | 0) >> 2] = $9_1 + 1 | 0;
                   $9_1 = HEAPU8[$9_1 >> 0] | 0;
                   break label$92;
                  }
                  $9_1 = $50($0_1 | 0) | 0;
                 }
                 label$94 : {
                  if (HEAPU8[(($9_1 + ($3_1 + 32 | 0) | 0) + 1 | 0) >> 0] | 0) {
                   break label$94
                  }
                  $14_1 = 0;
                  $12_1 = $13_1;
                  break label$79;
                 }
                 HEAP8[($13_1 + $1_1 | 0) >> 0] = $9_1;
                 $1_1 = $1_1 + 1 | 0;
                 if (($1_1 | 0) != ($14_1 | 0)) {
                  continue label$91
                 }
                 break label$91;
                };
                $15_1 = 1;
                $14_1 = $14_1 << 1 | 0 | 1 | 0;
                $9_1 = $82($13_1 | 0, $14_1 | 0) | 0;
                if ($9_1) {
                 continue label$90
                }
                break label$90;
               };
               $12_1 = $13_1;
               $13_1 = 0;
               break label$8;
              }
              $1_1 = 0;
              label$95 : {
               if (!$8_1) {
                break label$95
               }
               label$96 : while (1) {
                label$97 : {
                 label$98 : {
                  $9_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                  if (($9_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                   break label$98
                  }
                  HEAP32[($0_1 + 4 | 0) >> 2] = $9_1 + 1 | 0;
                  $9_1 = HEAPU8[$9_1 >> 0] | 0;
                  break label$97;
                 }
                 $9_1 = $50($0_1 | 0) | 0;
                }
                label$99 : {
                 if (HEAPU8[(($9_1 + ($3_1 + 32 | 0) | 0) + 1 | 0) >> 0] | 0) {
                  break label$99
                 }
                 $14_1 = 0;
                 $13_1 = $8_1;
                 $12_1 = $8_1;
                 break label$79;
                }
                HEAP8[($8_1 + $1_1 | 0) >> 0] = $9_1;
                $1_1 = $1_1 + 1 | 0;
                continue label$96;
               };
              }
              label$100 : while (1) {
               label$101 : {
                label$102 : {
                 $1_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
                 if (($1_1 | 0) == (HEAP32[($0_1 + 104 | 0) >> 2] | 0 | 0)) {
                  break label$102
                 }
                 HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 + 1 | 0;
                 $1_1 = HEAPU8[$1_1 >> 0] | 0;
                 break label$101;
                }
                $1_1 = $50($0_1 | 0) | 0;
               }
               if (HEAPU8[(($1_1 + ($3_1 + 32 | 0) | 0) + 1 | 0) >> 0] | 0) {
                continue label$100
               }
               break label$100;
              };
              $13_1 = 0;
              $12_1 = 0;
              $14_1 = 0;
              $1_1 = 0;
             }
             $9_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
             label$103 : {
              i64toi32_i32$3 = $0_1;
              i64toi32_i32$1 = HEAP32[($0_1 + 112 | 0) >> 2] | 0;
              i64toi32_i32$4 = HEAP32[($0_1 + 116 | 0) >> 2] | 0;
              i64toi32_i32$3 = i64toi32_i32$1;
              i64toi32_i32$1 = 0;
              i64toi32_i32$0 = 0;
              if ((i64toi32_i32$4 | 0) < (i64toi32_i32$1 | 0)) {
               $75_1 = 1
              } else {
               if ((i64toi32_i32$4 | 0) <= (i64toi32_i32$1 | 0)) {
                if (i64toi32_i32$3 >>> 0 >= i64toi32_i32$0 >>> 0) {
                 $76_1 = 0
                } else {
                 $76_1 = 1
                }
                $77_1 = $76_1;
               } else {
                $77_1 = 0
               }
               $75_1 = $77_1;
              }
              if ($75_1) {
               break label$103
              }
              $9_1 = $9_1 + -1 | 0;
              HEAP32[($0_1 + 4 | 0) >> 2] = $9_1;
             }
             i64toi32_i32$0 = $0_1;
             i64toi32_i32$3 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
             i64toi32_i32$4 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
             $653 = i64toi32_i32$3;
             $653$hi = i64toi32_i32$4;
             i64toi32_i32$3 = $9_1 - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
             i64toi32_i32$4 = i64toi32_i32$3 >> 31 | 0;
             $658 = i64toi32_i32$3;
             $658$hi = i64toi32_i32$4;
             i64toi32_i32$4 = $653$hi;
             i64toi32_i32$0 = $653;
             i64toi32_i32$3 = $658$hi;
             i64toi32_i32$1 = $658;
             i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
             i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
             if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
              i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
             }
             $21_1 = i64toi32_i32$2;
             $21$hi = i64toi32_i32$5;
             if (!(i64toi32_i32$2 | i64toi32_i32$5 | 0)) {
              break label$12
             }
             i64toi32_i32$5 = $20$hi;
             i64toi32_i32$5 = $21$hi;
             i64toi32_i32$4 = i64toi32_i32$2;
             i64toi32_i32$0 = $20$hi;
             i64toi32_i32$1 = $20_1;
             if (!($11_1 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) | 0) | 0)) {
              break label$12
             }
             label$104 : {
              if (!$10_1) {
               break label$104
              }
              HEAP32[$8_1 >> 2] = $13_1;
             }
             label$105 : {
              if (($17_1 | 0) == (99 | 0)) {
               break label$105
              }
              label$106 : {
               if (!$14_1) {
                break label$106
               }
               HEAP32[($14_1 + ($1_1 << 2 | 0) | 0) >> 2] = 0;
              }
              label$107 : {
               if ($12_1) {
                break label$107
               }
               $12_1 = 0;
               break label$105;
              }
              HEAP8[($12_1 + $1_1 | 0) >> 0] = 0;
             }
             $13_1 = $14_1;
            }
            i64toi32_i32$1 = $0_1;
            i64toi32_i32$4 = HEAP32[($0_1 + 120 | 0) >> 2] | 0;
            i64toi32_i32$5 = HEAP32[($0_1 + 124 | 0) >> 2] | 0;
            $686$hi = i64toi32_i32$5;
            i64toi32_i32$5 = $19$hi;
            i64toi32_i32$5 = $686$hi;
            i64toi32_i32$1 = i64toi32_i32$4;
            i64toi32_i32$4 = $19$hi;
            i64toi32_i32$0 = $19_1;
            i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
            i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
            if (i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0) {
             i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
            }
            $688$hi = i64toi32_i32$2;
            i64toi32_i32$1 = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) - (HEAP32[($0_1 + 44 | 0) >> 2] | 0) | 0;
            i64toi32_i32$2 = i64toi32_i32$1 >> 31 | 0;
            $694 = i64toi32_i32$1;
            $694$hi = i64toi32_i32$2;
            i64toi32_i32$2 = $688$hi;
            i64toi32_i32$5 = i64toi32_i32$3;
            i64toi32_i32$1 = $694$hi;
            i64toi32_i32$0 = $694;
            i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
            i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
            if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
             i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
            }
            $19_1 = i64toi32_i32$4;
            $19$hi = i64toi32_i32$3;
            $6_1 = $6_1 + (($8_1 | 0) != (0 | 0)) | 0;
           }
           $1_1 = $5_1 + 1 | 0;
           $5_1 = HEAPU8[($5_1 + 1 | 0) >> 0] | 0;
           if ($5_1) {
            continue label$13
           }
           break label$3;
          };
         }
         $13_1 = $14_1;
         break label$10;
        }
        $15_1 = 1;
        $12_1 = 0;
        $13_1 = 0;
        break label$8;
       }
       $15_1 = $10_1;
       break label$7;
      }
      $15_1 = $10_1;
     }
     $6_1 = $6_1 ? $6_1 : -1;
    }
    if (!$15_1) {
     break label$3
    }
    $81($12_1 | 0);
    $81($13_1 | 0);
    break label$3;
   }
   $6_1 = -1;
  }
  label$108 : {
   if ($4_1) {
    break label$108
   }
   $15($0_1 | 0);
  }
  global$0 = $3_1 + 304 | 0;
  return $6_1 | 0;
 }
 
 function $71($0_1) {
  $0_1 = $0_1 | 0;
  return ($0_1 | 0) == (32 | 0) | ($0_1 + -9 | 0) >>> 0 < 5 >>> 0 | 0 | 0;
 }
 
 function $72($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0;
  $2_1 = global$0 - 16 | 0;
  HEAP32[($2_1 + 12 | 0) >> 2] = $0_1;
  $0_1 = $1_1 >>> 0 > 1 >>> 0 ? ($0_1 + ($1_1 << 2 | 0) | 0) + -4 | 0 : $0_1;
  HEAP32[($2_1 + 8 | 0) >> 2] = $0_1 + 4 | 0;
  return HEAP32[$0_1 >> 2] | 0 | 0;
 }
 
 function $73($0_1, $1_1, $2_1, $2$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  var i64toi32_i32$0 = 0;
  label$1 : {
   if (!$0_1) {
    break label$1
   }
   label$2 : {
    switch ($1_1 + 2 | 0 | 0) {
    case 0:
     i64toi32_i32$0 = $2$hi;
     HEAP8[$0_1 >> 0] = $2_1;
     return;
    case 1:
     i64toi32_i32$0 = $2$hi;
     HEAP16[$0_1 >> 1] = $2_1;
     return;
    case 2:
    case 3:
     i64toi32_i32$0 = $2$hi;
     HEAP32[$0_1 >> 2] = $2_1;
     return;
    case 5:
     break label$2;
    default:
     break label$1;
    };
   }
   i64toi32_i32$0 = $2$hi;
   HEAP32[$0_1 >> 2] = $2_1;
   HEAP32[($0_1 + 4 | 0) >> 2] = i64toi32_i32$0;
  }
 }
 
 function $74($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  return $70(66840 | 0, $0_1 | 0, $1_1 | 0) | 0 | 0;
 }
 
 function $75($0_1) {
  $0_1 = $0_1 | 0;
  label$1 : {
   if ($0_1) {
    break label$1
   }
   return 0 | 0;
  }
  HEAP32[($16() | 0) >> 2] = $0_1;
  return -1 | 0;
 }
 
 function $76($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $3_1 = 0;
  $3_1 = 1;
  label$1 : {
   label$2 : {
    if (!$0_1) {
     break label$2
    }
    if ($1_1 >>> 0 <= 127 >>> 0) {
     break label$1
    }
    label$3 : {
     label$4 : {
      if (HEAP32[(HEAP32[(($66() | 0) + 96 | 0) >> 2] | 0) >> 2] | 0) {
       break label$4
      }
      if (($1_1 & -128 | 0 | 0) == (57216 | 0)) {
       break label$1
      }
      HEAP32[($16() | 0) >> 2] = 25;
      break label$3;
     }
     label$5 : {
      if ($1_1 >>> 0 > 2047 >>> 0) {
       break label$5
      }
      HEAP8[($0_1 + 1 | 0) >> 0] = $1_1 & 63 | 0 | 128 | 0;
      HEAP8[$0_1 >> 0] = $1_1 >>> 6 | 0 | 192 | 0;
      return 2 | 0;
     }
     label$6 : {
      label$7 : {
       if ($1_1 >>> 0 < 55296 >>> 0) {
        break label$7
       }
       if (($1_1 & -8192 | 0 | 0) != (57344 | 0)) {
        break label$6
       }
      }
      HEAP8[($0_1 + 2 | 0) >> 0] = $1_1 & 63 | 0 | 128 | 0;
      HEAP8[$0_1 >> 0] = $1_1 >>> 12 | 0 | 224 | 0;
      HEAP8[($0_1 + 1 | 0) >> 0] = ($1_1 >>> 6 | 0) & 63 | 0 | 128 | 0;
      return 3 | 0;
     }
     label$8 : {
      if (($1_1 + -65536 | 0) >>> 0 > 1048575 >>> 0) {
       break label$8
      }
      HEAP8[($0_1 + 3 | 0) >> 0] = $1_1 & 63 | 0 | 128 | 0;
      HEAP8[$0_1 >> 0] = $1_1 >>> 18 | 0 | 240 | 0;
      HEAP8[($0_1 + 2 | 0) >> 0] = ($1_1 >>> 6 | 0) & 63 | 0 | 128 | 0;
      HEAP8[($0_1 + 1 | 0) >> 0] = ($1_1 >>> 12 | 0) & 63 | 0 | 128 | 0;
      return 4 | 0;
     }
     HEAP32[($16() | 0) >> 2] = 25;
    }
    $3_1 = -1;
   }
   return $3_1 | 0;
  }
  HEAP8[$0_1 >> 0] = $1_1;
  return 1 | 0;
 }
 
 function $77($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  label$1 : {
   if ($0_1) {
    break label$1
   }
   return 0 | 0;
  }
  return $76($0_1 | 0, $1_1 | 0, 0 | 0) | 0 | 0;
 }
 
 function $78($0_1) {
  $0_1 = $0_1 | 0;
  var $1_1 = 0, $2_1 = 0;
  $1_1 = HEAP32[(0 + 66988 | 0) >> 2] | 0;
  $2_1 = ($0_1 + 7 | 0) & -8 | 0;
  $0_1 = $1_1 + $2_1 | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     if (!$2_1) {
      break label$3
     }
     if ($0_1 >>> 0 <= $1_1 >>> 0) {
      break label$2
     }
    }
    if ($0_1 >>> 0 <= ($17() | 0) >>> 0) {
     break label$1
    }
    if ($19($0_1 | 0) | 0) {
     break label$1
    }
   }
   HEAP32[($16() | 0) >> 2] = 48;
   return -1 | 0;
  }
  HEAP32[(0 + 66988 | 0) >> 2] = $0_1;
  return $1_1 | 0;
 }
 
 function $79($0_1) {
  $0_1 = $0_1 | 0;
  var $5_1 = 0, $4_1 = 0, $7_1 = 0, $8_1 = 0, $3_1 = 0, $2_1 = 0, $6_1 = 0, $10_1 = 0, $11_1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $1_1 = 0, $9_1 = 0, $79_1 = 0, $183 = 0, $782 = 0, $784 = 0;
  $1_1 = global$0 - 16 | 0;
  global$0 = $1_1;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : {
       label$6 : {
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             if ($0_1 >>> 0 > 244 >>> 0) {
              break label$11
             }
             label$12 : {
              $2_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
              $3_1 = $0_1 >>> 0 < 11 >>> 0 ? 16 : ($0_1 + 11 | 0) & 504 | 0;
              $4_1 = $3_1 >>> 3 | 0;
              $0_1 = $2_1 >>> $4_1 | 0;
              if (!($0_1 & 3 | 0)) {
               break label$12
              }
              label$13 : {
               label$14 : {
                $3_1 = (($0_1 ^ -1 | 0) & 1 | 0) + $4_1 | 0;
                $4_1 = $3_1 << 3 | 0;
                $0_1 = $4_1 + 69312 | 0;
                $4_1 = HEAP32[($4_1 + 69320 | 0) >> 2] | 0;
                $5_1 = HEAP32[($4_1 + 8 | 0) >> 2] | 0;
                if (($0_1 | 0) != ($5_1 | 0)) {
                 break label$14
                }
                HEAP32[(0 + 69272 | 0) >> 2] = $2_1 & (__wasm_rotl_i32(-2 | 0, $3_1 | 0) | 0) | 0;
                break label$13;
               }
               HEAP32[($5_1 + 12 | 0) >> 2] = $0_1;
               HEAP32[($0_1 + 8 | 0) >> 2] = $5_1;
              }
              $0_1 = $4_1 + 8 | 0;
              $3_1 = $3_1 << 3 | 0;
              HEAP32[($4_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
              $4_1 = $4_1 + $3_1 | 0;
              HEAP32[($4_1 + 4 | 0) >> 2] = HEAP32[($4_1 + 4 | 0) >> 2] | 0 | 1 | 0;
              break label$1;
             }
             $6_1 = HEAP32[(0 + 69280 | 0) >> 2] | 0;
             if ($3_1 >>> 0 <= $6_1 >>> 0) {
              break label$10
             }
             label$15 : {
              if (!$0_1) {
               break label$15
              }
              label$16 : {
               label$17 : {
                $79_1 = $0_1 << $4_1 | 0;
                $0_1 = 2 << $4_1 | 0;
                $4_1 = __wasm_ctz_i32($79_1 & ($0_1 | (0 - $0_1 | 0) | 0) | 0 | 0) | 0;
                $0_1 = $4_1 << 3 | 0;
                $5_1 = $0_1 + 69312 | 0;
                $0_1 = HEAP32[($0_1 + 69320 | 0) >> 2] | 0;
                $7_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
                if (($5_1 | 0) != ($7_1 | 0)) {
                 break label$17
                }
                $2_1 = $2_1 & (__wasm_rotl_i32(-2 | 0, $4_1 | 0) | 0) | 0;
                HEAP32[(0 + 69272 | 0) >> 2] = $2_1;
                break label$16;
               }
               HEAP32[($7_1 + 12 | 0) >> 2] = $5_1;
               HEAP32[($5_1 + 8 | 0) >> 2] = $7_1;
              }
              HEAP32[($0_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
              $7_1 = $0_1 + $3_1 | 0;
              $4_1 = $4_1 << 3 | 0;
              $3_1 = $4_1 - $3_1 | 0;
              HEAP32[($7_1 + 4 | 0) >> 2] = $3_1 | 1 | 0;
              HEAP32[($0_1 + $4_1 | 0) >> 2] = $3_1;
              label$18 : {
               if (!$6_1) {
                break label$18
               }
               $5_1 = ($6_1 & -8 | 0) + 69312 | 0;
               $4_1 = HEAP32[(0 + 69292 | 0) >> 2] | 0;
               label$19 : {
                label$20 : {
                 $8_1 = 1 << ($6_1 >>> 3 | 0) | 0;
                 if ($2_1 & $8_1 | 0) {
                  break label$20
                 }
                 HEAP32[(0 + 69272 | 0) >> 2] = $2_1 | $8_1 | 0;
                 $8_1 = $5_1;
                 break label$19;
                }
                $8_1 = HEAP32[($5_1 + 8 | 0) >> 2] | 0;
               }
               HEAP32[($5_1 + 8 | 0) >> 2] = $4_1;
               HEAP32[($8_1 + 12 | 0) >> 2] = $4_1;
               HEAP32[($4_1 + 12 | 0) >> 2] = $5_1;
               HEAP32[($4_1 + 8 | 0) >> 2] = $8_1;
              }
              $0_1 = $0_1 + 8 | 0;
              HEAP32[(0 + 69292 | 0) >> 2] = $7_1;
              HEAP32[(0 + 69280 | 0) >> 2] = $3_1;
              break label$1;
             }
             $9_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
             if (!$9_1) {
              break label$10
             }
             $7_1 = HEAP32[(((__wasm_ctz_i32($9_1 | 0) | 0) << 2 | 0) + 69576 | 0) >> 2] | 0;
             $4_1 = ((HEAP32[($7_1 + 4 | 0) >> 2] | 0) & -8 | 0) - $3_1 | 0;
             $5_1 = $7_1;
             label$21 : {
              label$22 : while (1) {
               label$23 : {
                $0_1 = HEAP32[($5_1 + 16 | 0) >> 2] | 0;
                if ($0_1) {
                 break label$23
                }
                $0_1 = HEAP32[($5_1 + 20 | 0) >> 2] | 0;
                if (!$0_1) {
                 break label$21
                }
               }
               $5_1 = ((HEAP32[($0_1 + 4 | 0) >> 2] | 0) & -8 | 0) - $3_1 | 0;
               $183 = $5_1;
               $5_1 = $5_1 >>> 0 < $4_1 >>> 0;
               $4_1 = $5_1 ? $183 : $4_1;
               $7_1 = $5_1 ? $0_1 : $7_1;
               $5_1 = $0_1;
               continue label$22;
              };
             }
             $10_1 = HEAP32[($7_1 + 24 | 0) >> 2] | 0;
             label$24 : {
              $0_1 = HEAP32[($7_1 + 12 | 0) >> 2] | 0;
              if (($0_1 | 0) == ($7_1 | 0)) {
               break label$24
              }
              $5_1 = HEAP32[($7_1 + 8 | 0) >> 2] | 0;
              HEAP32[(0 + 69288 | 0) >> 2] | 0;
              HEAP32[($5_1 + 12 | 0) >> 2] = $0_1;
              HEAP32[($0_1 + 8 | 0) >> 2] = $5_1;
              break label$2;
             }
             label$25 : {
              label$26 : {
               $5_1 = HEAP32[($7_1 + 20 | 0) >> 2] | 0;
               if (!$5_1) {
                break label$26
               }
               $8_1 = $7_1 + 20 | 0;
               break label$25;
              }
              $5_1 = HEAP32[($7_1 + 16 | 0) >> 2] | 0;
              if (!$5_1) {
               break label$9
              }
              $8_1 = $7_1 + 16 | 0;
             }
             label$27 : while (1) {
              $11_1 = $8_1;
              $0_1 = $5_1;
              $8_1 = $0_1 + 20 | 0;
              $5_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
              if ($5_1) {
               continue label$27
              }
              $8_1 = $0_1 + 16 | 0;
              $5_1 = HEAP32[($0_1 + 16 | 0) >> 2] | 0;
              if ($5_1) {
               continue label$27
              }
              break label$27;
             };
             HEAP32[$11_1 >> 2] = 0;
             break label$2;
            }
            $3_1 = -1;
            if ($0_1 >>> 0 > -65 >>> 0) {
             break label$10
            }
            $0_1 = $0_1 + 11 | 0;
            $3_1 = $0_1 & -8 | 0;
            $10_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
            if (!$10_1) {
             break label$10
            }
            $6_1 = 0;
            label$28 : {
             if ($3_1 >>> 0 < 256 >>> 0) {
              break label$28
             }
             $6_1 = 31;
             if ($3_1 >>> 0 > 16777215 >>> 0) {
              break label$28
             }
             $0_1 = Math_clz32($0_1 >>> 8 | 0);
             $6_1 = ((($3_1 >>> (38 - $0_1 | 0) | 0) & 1 | 0) - ($0_1 << 1 | 0) | 0) + 62 | 0;
            }
            $4_1 = 0 - $3_1 | 0;
            label$29 : {
             label$30 : {
              label$31 : {
               label$32 : {
                $5_1 = HEAP32[(($6_1 << 2 | 0) + 69576 | 0) >> 2] | 0;
                if ($5_1) {
                 break label$32
                }
                $0_1 = 0;
                $8_1 = 0;
                break label$31;
               }
               $0_1 = 0;
               $7_1 = $3_1 << (($6_1 | 0) == (31 | 0) ? 0 : 25 - ($6_1 >>> 1 | 0) | 0) | 0;
               $8_1 = 0;
               label$33 : while (1) {
                label$34 : {
                 $2_1 = ((HEAP32[($5_1 + 4 | 0) >> 2] | 0) & -8 | 0) - $3_1 | 0;
                 if ($2_1 >>> 0 >= $4_1 >>> 0) {
                  break label$34
                 }
                 $4_1 = $2_1;
                 $8_1 = $5_1;
                 if ($4_1) {
                  break label$34
                 }
                 $4_1 = 0;
                 $8_1 = $5_1;
                 $0_1 = $5_1;
                 break label$30;
                }
                $2_1 = HEAP32[($5_1 + 20 | 0) >> 2] | 0;
                $11_1 = HEAP32[(($5_1 + (($7_1 >>> 29 | 0) & 4 | 0) | 0) + 16 | 0) >> 2] | 0;
                $0_1 = $2_1 ? (($2_1 | 0) == ($11_1 | 0) ? $0_1 : $2_1) : $0_1;
                $7_1 = $7_1 << 1 | 0;
                $5_1 = $11_1;
                if ($5_1) {
                 continue label$33
                }
                break label$33;
               };
              }
              label$35 : {
               if ($0_1 | $8_1 | 0) {
                break label$35
               }
               $8_1 = 0;
               $0_1 = 2 << $6_1 | 0;
               $0_1 = ($0_1 | (0 - $0_1 | 0) | 0) & $10_1 | 0;
               if (!$0_1) {
                break label$10
               }
               $0_1 = HEAP32[(((__wasm_ctz_i32($0_1 | 0) | 0) << 2 | 0) + 69576 | 0) >> 2] | 0;
              }
              if (!$0_1) {
               break label$29
              }
             }
             label$36 : while (1) {
              $2_1 = ((HEAP32[($0_1 + 4 | 0) >> 2] | 0) & -8 | 0) - $3_1 | 0;
              $7_1 = $2_1 >>> 0 < $4_1 >>> 0;
              label$37 : {
               $5_1 = HEAP32[($0_1 + 16 | 0) >> 2] | 0;
               if ($5_1) {
                break label$37
               }
               $5_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
              }
              $4_1 = $7_1 ? $2_1 : $4_1;
              $8_1 = $7_1 ? $0_1 : $8_1;
              $0_1 = $5_1;
              if ($0_1) {
               continue label$36
              }
              break label$36;
             };
            }
            if (!$8_1) {
             break label$10
            }
            if ($4_1 >>> 0 >= ((HEAP32[(0 + 69280 | 0) >> 2] | 0) - $3_1 | 0) >>> 0) {
             break label$10
            }
            $11_1 = HEAP32[($8_1 + 24 | 0) >> 2] | 0;
            label$38 : {
             $0_1 = HEAP32[($8_1 + 12 | 0) >> 2] | 0;
             if (($0_1 | 0) == ($8_1 | 0)) {
              break label$38
             }
             $5_1 = HEAP32[($8_1 + 8 | 0) >> 2] | 0;
             HEAP32[(0 + 69288 | 0) >> 2] | 0;
             HEAP32[($5_1 + 12 | 0) >> 2] = $0_1;
             HEAP32[($0_1 + 8 | 0) >> 2] = $5_1;
             break label$3;
            }
            label$39 : {
             label$40 : {
              $5_1 = HEAP32[($8_1 + 20 | 0) >> 2] | 0;
              if (!$5_1) {
               break label$40
              }
              $7_1 = $8_1 + 20 | 0;
              break label$39;
             }
             $5_1 = HEAP32[($8_1 + 16 | 0) >> 2] | 0;
             if (!$5_1) {
              break label$8
             }
             $7_1 = $8_1 + 16 | 0;
            }
            label$41 : while (1) {
             $2_1 = $7_1;
             $0_1 = $5_1;
             $7_1 = $0_1 + 20 | 0;
             $5_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
             if ($5_1) {
              continue label$41
             }
             $7_1 = $0_1 + 16 | 0;
             $5_1 = HEAP32[($0_1 + 16 | 0) >> 2] | 0;
             if ($5_1) {
              continue label$41
             }
             break label$41;
            };
            HEAP32[$2_1 >> 2] = 0;
            break label$3;
           }
           label$42 : {
            $0_1 = HEAP32[(0 + 69280 | 0) >> 2] | 0;
            if ($0_1 >>> 0 < $3_1 >>> 0) {
             break label$42
            }
            $4_1 = HEAP32[(0 + 69292 | 0) >> 2] | 0;
            label$43 : {
             label$44 : {
              $5_1 = $0_1 - $3_1 | 0;
              if ($5_1 >>> 0 < 16 >>> 0) {
               break label$44
              }
              $7_1 = $4_1 + $3_1 | 0;
              HEAP32[($7_1 + 4 | 0) >> 2] = $5_1 | 1 | 0;
              HEAP32[($4_1 + $0_1 | 0) >> 2] = $5_1;
              HEAP32[($4_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
              break label$43;
             }
             HEAP32[($4_1 + 4 | 0) >> 2] = $0_1 | 3 | 0;
             $0_1 = $4_1 + $0_1 | 0;
             HEAP32[($0_1 + 4 | 0) >> 2] = HEAP32[($0_1 + 4 | 0) >> 2] | 0 | 1 | 0;
             $7_1 = 0;
             $5_1 = 0;
            }
            HEAP32[(0 + 69280 | 0) >> 2] = $5_1;
            HEAP32[(0 + 69292 | 0) >> 2] = $7_1;
            $0_1 = $4_1 + 8 | 0;
            break label$1;
           }
           label$45 : {
            $7_1 = HEAP32[(0 + 69284 | 0) >> 2] | 0;
            if ($7_1 >>> 0 <= $3_1 >>> 0) {
             break label$45
            }
            $4_1 = $7_1 - $3_1 | 0;
            HEAP32[(0 + 69284 | 0) >> 2] = $4_1;
            $0_1 = HEAP32[(0 + 69296 | 0) >> 2] | 0;
            $5_1 = $0_1 + $3_1 | 0;
            HEAP32[(0 + 69296 | 0) >> 2] = $5_1;
            HEAP32[($5_1 + 4 | 0) >> 2] = $4_1 | 1 | 0;
            HEAP32[($0_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
            $0_1 = $0_1 + 8 | 0;
            break label$1;
           }
           label$46 : {
            label$47 : {
             if (!(HEAP32[(0 + 69744 | 0) >> 2] | 0)) {
              break label$47
             }
             $4_1 = HEAP32[(0 + 69752 | 0) >> 2] | 0;
             break label$46;
            }
            i64toi32_i32$1 = 0;
            i64toi32_i32$0 = -1;
            HEAP32[(i64toi32_i32$1 + 69756 | 0) >> 2] = -1;
            HEAP32[(i64toi32_i32$1 + 69760 | 0) >> 2] = i64toi32_i32$0;
            i64toi32_i32$1 = 0;
            i64toi32_i32$0 = 4096;
            HEAP32[(i64toi32_i32$1 + 69748 | 0) >> 2] = 4096;
            HEAP32[(i64toi32_i32$1 + 69752 | 0) >> 2] = i64toi32_i32$0;
            HEAP32[(0 + 69744 | 0) >> 2] = (($1_1 + 12 | 0) & -16 | 0) ^ 1431655768 | 0;
            HEAP32[(0 + 69764 | 0) >> 2] = 0;
            HEAP32[(0 + 69716 | 0) >> 2] = 0;
            $4_1 = 4096;
           }
           $0_1 = 0;
           $6_1 = $3_1 + 47 | 0;
           $2_1 = $4_1 + $6_1 | 0;
           $11_1 = 0 - $4_1 | 0;
           $8_1 = $2_1 & $11_1 | 0;
           if ($8_1 >>> 0 <= $3_1 >>> 0) {
            break label$1
           }
           $0_1 = 0;
           label$48 : {
            $4_1 = HEAP32[(0 + 69712 | 0) >> 2] | 0;
            if (!$4_1) {
             break label$48
            }
            $5_1 = HEAP32[(0 + 69704 | 0) >> 2] | 0;
            $10_1 = $5_1 + $8_1 | 0;
            if ($10_1 >>> 0 <= $5_1 >>> 0) {
             break label$1
            }
            if ($10_1 >>> 0 > $4_1 >>> 0) {
             break label$1
            }
           }
           label$49 : {
            label$50 : {
             if ((HEAPU8[(0 + 69716 | 0) >> 0] | 0) & 4 | 0) {
              break label$50
             }
             label$51 : {
              label$52 : {
               label$53 : {
                label$54 : {
                 label$55 : {
                  $4_1 = HEAP32[(0 + 69296 | 0) >> 2] | 0;
                  if (!$4_1) {
                   break label$55
                  }
                  $0_1 = 69720;
                  label$56 : while (1) {
                   label$57 : {
                    $5_1 = HEAP32[$0_1 >> 2] | 0;
                    if ($5_1 >>> 0 > $4_1 >>> 0) {
                     break label$57
                    }
                    if (($5_1 + (HEAP32[($0_1 + 4 | 0) >> 2] | 0) | 0) >>> 0 > $4_1 >>> 0) {
                     break label$54
                    }
                   }
                   $0_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
                   if ($0_1) {
                    continue label$56
                   }
                   break label$56;
                  };
                 }
                 $7_1 = $78(0 | 0) | 0;
                 if (($7_1 | 0) == (-1 | 0)) {
                  break label$51
                 }
                 $2_1 = $8_1;
                 label$58 : {
                  $0_1 = HEAP32[(0 + 69748 | 0) >> 2] | 0;
                  $4_1 = $0_1 + -1 | 0;
                  if (!($4_1 & $7_1 | 0)) {
                   break label$58
                  }
                  $2_1 = ($8_1 - $7_1 | 0) + (($4_1 + $7_1 | 0) & (0 - $0_1 | 0) | 0) | 0;
                 }
                 if ($2_1 >>> 0 <= $3_1 >>> 0) {
                  break label$51
                 }
                 label$59 : {
                  $0_1 = HEAP32[(0 + 69712 | 0) >> 2] | 0;
                  if (!$0_1) {
                   break label$59
                  }
                  $4_1 = HEAP32[(0 + 69704 | 0) >> 2] | 0;
                  $5_1 = $4_1 + $2_1 | 0;
                  if ($5_1 >>> 0 <= $4_1 >>> 0) {
                   break label$51
                  }
                  if ($5_1 >>> 0 > $0_1 >>> 0) {
                   break label$51
                  }
                 }
                 $0_1 = $78($2_1 | 0) | 0;
                 if (($0_1 | 0) != ($7_1 | 0)) {
                  break label$53
                 }
                 break label$49;
                }
                $2_1 = ($2_1 - $7_1 | 0) & $11_1 | 0;
                $7_1 = $78($2_1 | 0) | 0;
                if (($7_1 | 0) == ((HEAP32[$0_1 >> 2] | 0) + (HEAP32[($0_1 + 4 | 0) >> 2] | 0) | 0 | 0)) {
                 break label$52
                }
                $0_1 = $7_1;
               }
               if (($0_1 | 0) == (-1 | 0)) {
                break label$51
               }
               label$60 : {
                if ($2_1 >>> 0 < ($3_1 + 48 | 0) >>> 0) {
                 break label$60
                }
                $7_1 = $0_1;
                break label$49;
               }
               $4_1 = HEAP32[(0 + 69752 | 0) >> 2] | 0;
               $4_1 = (($6_1 - $2_1 | 0) + $4_1 | 0) & (0 - $4_1 | 0) | 0;
               if (($78($4_1 | 0) | 0 | 0) == (-1 | 0)) {
                break label$51
               }
               $2_1 = $4_1 + $2_1 | 0;
               $7_1 = $0_1;
               break label$49;
              }
              if (($7_1 | 0) != (-1 | 0)) {
               break label$49
              }
             }
             HEAP32[(0 + 69716 | 0) >> 2] = HEAP32[(0 + 69716 | 0) >> 2] | 0 | 4 | 0;
            }
            $7_1 = $78($8_1 | 0) | 0;
            $0_1 = $78(0 | 0) | 0;
            if (($7_1 | 0) == (-1 | 0)) {
             break label$5
            }
            if (($0_1 | 0) == (-1 | 0)) {
             break label$5
            }
            if ($7_1 >>> 0 >= $0_1 >>> 0) {
             break label$5
            }
            $2_1 = $0_1 - $7_1 | 0;
            if ($2_1 >>> 0 <= ($3_1 + 40 | 0) >>> 0) {
             break label$5
            }
           }
           $0_1 = (HEAP32[(0 + 69704 | 0) >> 2] | 0) + $2_1 | 0;
           HEAP32[(0 + 69704 | 0) >> 2] = $0_1;
           label$61 : {
            if ($0_1 >>> 0 <= (HEAP32[(0 + 69708 | 0) >> 2] | 0) >>> 0) {
             break label$61
            }
            HEAP32[(0 + 69708 | 0) >> 2] = $0_1;
           }
           label$62 : {
            label$63 : {
             $4_1 = HEAP32[(0 + 69296 | 0) >> 2] | 0;
             if (!$4_1) {
              break label$63
             }
             $0_1 = 69720;
             label$64 : while (1) {
              $5_1 = HEAP32[$0_1 >> 2] | 0;
              $8_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
              if (($7_1 | 0) == ($5_1 + $8_1 | 0 | 0)) {
               break label$62
              }
              $0_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
              if ($0_1) {
               continue label$64
              }
              break label$7;
             };
            }
            label$65 : {
             label$66 : {
              $0_1 = HEAP32[(0 + 69288 | 0) >> 2] | 0;
              if (!$0_1) {
               break label$66
              }
              if ($7_1 >>> 0 >= $0_1 >>> 0) {
               break label$65
              }
             }
             HEAP32[(0 + 69288 | 0) >> 2] = $7_1;
            }
            $0_1 = 0;
            HEAP32[(0 + 69724 | 0) >> 2] = $2_1;
            HEAP32[(0 + 69720 | 0) >> 2] = $7_1;
            HEAP32[(0 + 69304 | 0) >> 2] = -1;
            HEAP32[(0 + 69308 | 0) >> 2] = HEAP32[(0 + 69744 | 0) >> 2] | 0;
            HEAP32[(0 + 69732 | 0) >> 2] = 0;
            label$67 : while (1) {
             $4_1 = $0_1 << 3 | 0;
             $5_1 = $4_1 + 69312 | 0;
             HEAP32[($4_1 + 69320 | 0) >> 2] = $5_1;
             HEAP32[($4_1 + 69324 | 0) >> 2] = $5_1;
             $0_1 = $0_1 + 1 | 0;
             if (($0_1 | 0) != (32 | 0)) {
              continue label$67
             }
             break label$67;
            };
            $0_1 = $2_1 + -40 | 0;
            $4_1 = (-8 - $7_1 | 0) & 7 | 0;
            $5_1 = $0_1 - $4_1 | 0;
            HEAP32[(0 + 69284 | 0) >> 2] = $5_1;
            $4_1 = $7_1 + $4_1 | 0;
            HEAP32[(0 + 69296 | 0) >> 2] = $4_1;
            HEAP32[($4_1 + 4 | 0) >> 2] = $5_1 | 1 | 0;
            HEAP32[(($7_1 + $0_1 | 0) + 4 | 0) >> 2] = 40;
            HEAP32[(0 + 69300 | 0) >> 2] = HEAP32[(0 + 69760 | 0) >> 2] | 0;
            break label$6;
           }
           if ($4_1 >>> 0 >= $7_1 >>> 0) {
            break label$7
           }
           if ($4_1 >>> 0 < $5_1 >>> 0) {
            break label$7
           }
           if ((HEAP32[($0_1 + 12 | 0) >> 2] | 0) & 8 | 0) {
            break label$7
           }
           HEAP32[($0_1 + 4 | 0) >> 2] = $8_1 + $2_1 | 0;
           $0_1 = (-8 - $4_1 | 0) & 7 | 0;
           $5_1 = $4_1 + $0_1 | 0;
           HEAP32[(0 + 69296 | 0) >> 2] = $5_1;
           $7_1 = (HEAP32[(0 + 69284 | 0) >> 2] | 0) + $2_1 | 0;
           $0_1 = $7_1 - $0_1 | 0;
           HEAP32[(0 + 69284 | 0) >> 2] = $0_1;
           HEAP32[($5_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
           HEAP32[(($4_1 + $7_1 | 0) + 4 | 0) >> 2] = 40;
           HEAP32[(0 + 69300 | 0) >> 2] = HEAP32[(0 + 69760 | 0) >> 2] | 0;
           break label$6;
          }
          $0_1 = 0;
          break label$2;
         }
         $0_1 = 0;
         break label$3;
        }
        label$68 : {
         if ($7_1 >>> 0 >= (HEAP32[(0 + 69288 | 0) >> 2] | 0) >>> 0) {
          break label$68
         }
         HEAP32[(0 + 69288 | 0) >> 2] = $7_1;
        }
        $5_1 = $7_1 + $2_1 | 0;
        $0_1 = 69720;
        label$69 : {
         label$70 : {
          label$71 : while (1) {
           if ((HEAP32[$0_1 >> 2] | 0 | 0) == ($5_1 | 0)) {
            break label$70
           }
           $0_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
           if ($0_1) {
            continue label$71
           }
           break label$69;
          };
         }
         if (!((HEAPU8[($0_1 + 12 | 0) >> 0] | 0) & 8 | 0)) {
          break label$4
         }
        }
        $0_1 = 69720;
        label$72 : {
         label$73 : while (1) {
          label$74 : {
           $5_1 = HEAP32[$0_1 >> 2] | 0;
           if ($5_1 >>> 0 > $4_1 >>> 0) {
            break label$74
           }
           $5_1 = $5_1 + (HEAP32[($0_1 + 4 | 0) >> 2] | 0) | 0;
           if ($5_1 >>> 0 > $4_1 >>> 0) {
            break label$72
           }
          }
          $0_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
          continue label$73;
         };
        }
        $0_1 = $2_1 + -40 | 0;
        $8_1 = (-8 - $7_1 | 0) & 7 | 0;
        $11_1 = $0_1 - $8_1 | 0;
        HEAP32[(0 + 69284 | 0) >> 2] = $11_1;
        $8_1 = $7_1 + $8_1 | 0;
        HEAP32[(0 + 69296 | 0) >> 2] = $8_1;
        HEAP32[($8_1 + 4 | 0) >> 2] = $11_1 | 1 | 0;
        HEAP32[(($7_1 + $0_1 | 0) + 4 | 0) >> 2] = 40;
        HEAP32[(0 + 69300 | 0) >> 2] = HEAP32[(0 + 69760 | 0) >> 2] | 0;
        $0_1 = ($5_1 + ((39 - $5_1 | 0) & 7 | 0) | 0) + -47 | 0;
        $8_1 = $0_1 >>> 0 < ($4_1 + 16 | 0) >>> 0 ? $4_1 : $0_1;
        HEAP32[($8_1 + 4 | 0) >> 2] = 27;
        i64toi32_i32$2 = 0;
        i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 69728 | 0) >> 2] | 0;
        i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 69732 | 0) >> 2] | 0;
        $782 = i64toi32_i32$0;
        i64toi32_i32$0 = $8_1 + 16 | 0;
        HEAP32[i64toi32_i32$0 >> 2] = $782;
        HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$1;
        i64toi32_i32$2 = 0;
        i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 69720 | 0) >> 2] | 0;
        i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 69724 | 0) >> 2] | 0;
        $784 = i64toi32_i32$1;
        i64toi32_i32$1 = $8_1;
        HEAP32[($8_1 + 8 | 0) >> 2] = $784;
        HEAP32[($8_1 + 12 | 0) >> 2] = i64toi32_i32$0;
        HEAP32[(0 + 69728 | 0) >> 2] = $8_1 + 8 | 0;
        HEAP32[(0 + 69724 | 0) >> 2] = $2_1;
        HEAP32[(0 + 69720 | 0) >> 2] = $7_1;
        HEAP32[(0 + 69732 | 0) >> 2] = 0;
        $0_1 = $8_1 + 24 | 0;
        label$75 : while (1) {
         HEAP32[($0_1 + 4 | 0) >> 2] = 7;
         $7_1 = $0_1 + 8 | 0;
         $0_1 = $0_1 + 4 | 0;
         if ($7_1 >>> 0 < $5_1 >>> 0) {
          continue label$75
         }
         break label$75;
        };
        if (($8_1 | 0) == ($4_1 | 0)) {
         break label$6
        }
        HEAP32[($8_1 + 4 | 0) >> 2] = (HEAP32[($8_1 + 4 | 0) >> 2] | 0) & -2 | 0;
        $7_1 = $8_1 - $4_1 | 0;
        HEAP32[($4_1 + 4 | 0) >> 2] = $7_1 | 1 | 0;
        HEAP32[$8_1 >> 2] = $7_1;
        label$76 : {
         label$77 : {
          if ($7_1 >>> 0 > 255 >>> 0) {
           break label$77
          }
          $0_1 = ($7_1 & -8 | 0) + 69312 | 0;
          label$78 : {
           label$79 : {
            $5_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
            $7_1 = 1 << ($7_1 >>> 3 | 0) | 0;
            if ($5_1 & $7_1 | 0) {
             break label$79
            }
            HEAP32[(0 + 69272 | 0) >> 2] = $5_1 | $7_1 | 0;
            $5_1 = $0_1;
            break label$78;
           }
           $5_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
          }
          HEAP32[($0_1 + 8 | 0) >> 2] = $4_1;
          HEAP32[($5_1 + 12 | 0) >> 2] = $4_1;
          $7_1 = 12;
          $8_1 = 8;
          break label$76;
         }
         $0_1 = 31;
         label$80 : {
          if ($7_1 >>> 0 > 16777215 >>> 0) {
           break label$80
          }
          $0_1 = Math_clz32($7_1 >>> 8 | 0);
          $0_1 = ((($7_1 >>> (38 - $0_1 | 0) | 0) & 1 | 0) - ($0_1 << 1 | 0) | 0) + 62 | 0;
         }
         HEAP32[($4_1 + 28 | 0) >> 2] = $0_1;
         i64toi32_i32$1 = $4_1;
         i64toi32_i32$0 = 0;
         HEAP32[($4_1 + 16 | 0) >> 2] = 0;
         HEAP32[($4_1 + 20 | 0) >> 2] = i64toi32_i32$0;
         $5_1 = ($0_1 << 2 | 0) + 69576 | 0;
         label$81 : {
          label$82 : {
           label$83 : {
            $8_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
            $2_1 = 1 << $0_1 | 0;
            if ($8_1 & $2_1 | 0) {
             break label$83
            }
            HEAP32[(0 + 69276 | 0) >> 2] = $8_1 | $2_1 | 0;
            HEAP32[$5_1 >> 2] = $4_1;
            HEAP32[($4_1 + 24 | 0) >> 2] = $5_1;
            break label$82;
           }
           $0_1 = $7_1 << (($0_1 | 0) == (31 | 0) ? 0 : 25 - ($0_1 >>> 1 | 0) | 0) | 0;
           $8_1 = HEAP32[$5_1 >> 2] | 0;
           label$84 : while (1) {
            $5_1 = $8_1;
            if (((HEAP32[($5_1 + 4 | 0) >> 2] | 0) & -8 | 0 | 0) == ($7_1 | 0)) {
             break label$81
            }
            $8_1 = $0_1 >>> 29 | 0;
            $0_1 = $0_1 << 1 | 0;
            $2_1 = ($5_1 + ($8_1 & 4 | 0) | 0) + 16 | 0;
            $8_1 = HEAP32[$2_1 >> 2] | 0;
            if ($8_1) {
             continue label$84
            }
            break label$84;
           };
           HEAP32[$2_1 >> 2] = $4_1;
           HEAP32[($4_1 + 24 | 0) >> 2] = $5_1;
          }
          $7_1 = 8;
          $8_1 = 12;
          $5_1 = $4_1;
          $0_1 = $4_1;
          break label$76;
         }
         $0_1 = HEAP32[($5_1 + 8 | 0) >> 2] | 0;
         HEAP32[($0_1 + 12 | 0) >> 2] = $4_1;
         HEAP32[($5_1 + 8 | 0) >> 2] = $4_1;
         HEAP32[($4_1 + 8 | 0) >> 2] = $0_1;
         $0_1 = 0;
         $7_1 = 24;
         $8_1 = 12;
        }
        HEAP32[($4_1 + $8_1 | 0) >> 2] = $5_1;
        HEAP32[($4_1 + $7_1 | 0) >> 2] = $0_1;
       }
       $0_1 = HEAP32[(0 + 69284 | 0) >> 2] | 0;
       if ($0_1 >>> 0 <= $3_1 >>> 0) {
        break label$5
       }
       $4_1 = $0_1 - $3_1 | 0;
       HEAP32[(0 + 69284 | 0) >> 2] = $4_1;
       $0_1 = HEAP32[(0 + 69296 | 0) >> 2] | 0;
       $5_1 = $0_1 + $3_1 | 0;
       HEAP32[(0 + 69296 | 0) >> 2] = $5_1;
       HEAP32[($5_1 + 4 | 0) >> 2] = $4_1 | 1 | 0;
       HEAP32[($0_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
       $0_1 = $0_1 + 8 | 0;
       break label$1;
      }
      HEAP32[($16() | 0) >> 2] = 48;
      $0_1 = 0;
      break label$1;
     }
     HEAP32[$0_1 >> 2] = $7_1;
     HEAP32[($0_1 + 4 | 0) >> 2] = (HEAP32[($0_1 + 4 | 0) >> 2] | 0) + $2_1 | 0;
     $0_1 = $80($7_1 | 0, $5_1 | 0, $3_1 | 0) | 0;
     break label$1;
    }
    label$85 : {
     if (!$11_1) {
      break label$85
     }
     label$86 : {
      label$87 : {
       $7_1 = HEAP32[($8_1 + 28 | 0) >> 2] | 0;
       $5_1 = ($7_1 << 2 | 0) + 69576 | 0;
       if (($8_1 | 0) != (HEAP32[$5_1 >> 2] | 0 | 0)) {
        break label$87
       }
       HEAP32[$5_1 >> 2] = $0_1;
       if ($0_1) {
        break label$86
       }
       $10_1 = $10_1 & (__wasm_rotl_i32(-2 | 0, $7_1 | 0) | 0) | 0;
       HEAP32[(0 + 69276 | 0) >> 2] = $10_1;
       break label$85;
      }
      HEAP32[($11_1 + ((HEAP32[($11_1 + 16 | 0) >> 2] | 0 | 0) == ($8_1 | 0) ? 16 : 20) | 0) >> 2] = $0_1;
      if (!$0_1) {
       break label$85
      }
     }
     HEAP32[($0_1 + 24 | 0) >> 2] = $11_1;
     label$88 : {
      $5_1 = HEAP32[($8_1 + 16 | 0) >> 2] | 0;
      if (!$5_1) {
       break label$88
      }
      HEAP32[($0_1 + 16 | 0) >> 2] = $5_1;
      HEAP32[($5_1 + 24 | 0) >> 2] = $0_1;
     }
     $5_1 = HEAP32[($8_1 + 20 | 0) >> 2] | 0;
     if (!$5_1) {
      break label$85
     }
     HEAP32[($0_1 + 20 | 0) >> 2] = $5_1;
     HEAP32[($5_1 + 24 | 0) >> 2] = $0_1;
    }
    label$89 : {
     label$90 : {
      if ($4_1 >>> 0 > 15 >>> 0) {
       break label$90
      }
      $0_1 = $4_1 + $3_1 | 0;
      HEAP32[($8_1 + 4 | 0) >> 2] = $0_1 | 3 | 0;
      $0_1 = $8_1 + $0_1 | 0;
      HEAP32[($0_1 + 4 | 0) >> 2] = HEAP32[($0_1 + 4 | 0) >> 2] | 0 | 1 | 0;
      break label$89;
     }
     HEAP32[($8_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
     $7_1 = $8_1 + $3_1 | 0;
     HEAP32[($7_1 + 4 | 0) >> 2] = $4_1 | 1 | 0;
     HEAP32[($7_1 + $4_1 | 0) >> 2] = $4_1;
     label$91 : {
      if ($4_1 >>> 0 > 255 >>> 0) {
       break label$91
      }
      $0_1 = ($4_1 & -8 | 0) + 69312 | 0;
      label$92 : {
       label$93 : {
        $3_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
        $4_1 = 1 << ($4_1 >>> 3 | 0) | 0;
        if ($3_1 & $4_1 | 0) {
         break label$93
        }
        HEAP32[(0 + 69272 | 0) >> 2] = $3_1 | $4_1 | 0;
        $4_1 = $0_1;
        break label$92;
       }
       $4_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
      }
      HEAP32[($0_1 + 8 | 0) >> 2] = $7_1;
      HEAP32[($4_1 + 12 | 0) >> 2] = $7_1;
      HEAP32[($7_1 + 12 | 0) >> 2] = $0_1;
      HEAP32[($7_1 + 8 | 0) >> 2] = $4_1;
      break label$89;
     }
     $0_1 = 31;
     label$94 : {
      if ($4_1 >>> 0 > 16777215 >>> 0) {
       break label$94
      }
      $0_1 = Math_clz32($4_1 >>> 8 | 0);
      $0_1 = ((($4_1 >>> (38 - $0_1 | 0) | 0) & 1 | 0) - ($0_1 << 1 | 0) | 0) + 62 | 0;
     }
     HEAP32[($7_1 + 28 | 0) >> 2] = $0_1;
     i64toi32_i32$1 = $7_1;
     i64toi32_i32$0 = 0;
     HEAP32[($7_1 + 16 | 0) >> 2] = 0;
     HEAP32[($7_1 + 20 | 0) >> 2] = i64toi32_i32$0;
     $3_1 = ($0_1 << 2 | 0) + 69576 | 0;
     label$95 : {
      label$96 : {
       label$97 : {
        $5_1 = 1 << $0_1 | 0;
        if ($10_1 & $5_1 | 0) {
         break label$97
        }
        HEAP32[(0 + 69276 | 0) >> 2] = $10_1 | $5_1 | 0;
        HEAP32[$3_1 >> 2] = $7_1;
        HEAP32[($7_1 + 24 | 0) >> 2] = $3_1;
        break label$96;
       }
       $0_1 = $4_1 << (($0_1 | 0) == (31 | 0) ? 0 : 25 - ($0_1 >>> 1 | 0) | 0) | 0;
       $5_1 = HEAP32[$3_1 >> 2] | 0;
       label$98 : while (1) {
        $3_1 = $5_1;
        if (((HEAP32[($5_1 + 4 | 0) >> 2] | 0) & -8 | 0 | 0) == ($4_1 | 0)) {
         break label$95
        }
        $5_1 = $0_1 >>> 29 | 0;
        $0_1 = $0_1 << 1 | 0;
        $2_1 = ($3_1 + ($5_1 & 4 | 0) | 0) + 16 | 0;
        $5_1 = HEAP32[$2_1 >> 2] | 0;
        if ($5_1) {
         continue label$98
        }
        break label$98;
       };
       HEAP32[$2_1 >> 2] = $7_1;
       HEAP32[($7_1 + 24 | 0) >> 2] = $3_1;
      }
      HEAP32[($7_1 + 12 | 0) >> 2] = $7_1;
      HEAP32[($7_1 + 8 | 0) >> 2] = $7_1;
      break label$89;
     }
     $0_1 = HEAP32[($3_1 + 8 | 0) >> 2] | 0;
     HEAP32[($0_1 + 12 | 0) >> 2] = $7_1;
     HEAP32[($3_1 + 8 | 0) >> 2] = $7_1;
     HEAP32[($7_1 + 24 | 0) >> 2] = 0;
     HEAP32[($7_1 + 12 | 0) >> 2] = $3_1;
     HEAP32[($7_1 + 8 | 0) >> 2] = $0_1;
    }
    $0_1 = $8_1 + 8 | 0;
    break label$1;
   }
   label$99 : {
    if (!$10_1) {
     break label$99
    }
    label$100 : {
     label$101 : {
      $8_1 = HEAP32[($7_1 + 28 | 0) >> 2] | 0;
      $5_1 = ($8_1 << 2 | 0) + 69576 | 0;
      if (($7_1 | 0) != (HEAP32[$5_1 >> 2] | 0 | 0)) {
       break label$101
      }
      HEAP32[$5_1 >> 2] = $0_1;
      if ($0_1) {
       break label$100
      }
      HEAP32[(0 + 69276 | 0) >> 2] = $9_1 & (__wasm_rotl_i32(-2 | 0, $8_1 | 0) | 0) | 0;
      break label$99;
     }
     HEAP32[($10_1 + ((HEAP32[($10_1 + 16 | 0) >> 2] | 0 | 0) == ($7_1 | 0) ? 16 : 20) | 0) >> 2] = $0_1;
     if (!$0_1) {
      break label$99
     }
    }
    HEAP32[($0_1 + 24 | 0) >> 2] = $10_1;
    label$102 : {
     $5_1 = HEAP32[($7_1 + 16 | 0) >> 2] | 0;
     if (!$5_1) {
      break label$102
     }
     HEAP32[($0_1 + 16 | 0) >> 2] = $5_1;
     HEAP32[($5_1 + 24 | 0) >> 2] = $0_1;
    }
    $5_1 = HEAP32[($7_1 + 20 | 0) >> 2] | 0;
    if (!$5_1) {
     break label$99
    }
    HEAP32[($0_1 + 20 | 0) >> 2] = $5_1;
    HEAP32[($5_1 + 24 | 0) >> 2] = $0_1;
   }
   label$103 : {
    label$104 : {
     if ($4_1 >>> 0 > 15 >>> 0) {
      break label$104
     }
     $0_1 = $4_1 + $3_1 | 0;
     HEAP32[($7_1 + 4 | 0) >> 2] = $0_1 | 3 | 0;
     $0_1 = $7_1 + $0_1 | 0;
     HEAP32[($0_1 + 4 | 0) >> 2] = HEAP32[($0_1 + 4 | 0) >> 2] | 0 | 1 | 0;
     break label$103;
    }
    HEAP32[($7_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
    $3_1 = $7_1 + $3_1 | 0;
    HEAP32[($3_1 + 4 | 0) >> 2] = $4_1 | 1 | 0;
    HEAP32[($3_1 + $4_1 | 0) >> 2] = $4_1;
    label$105 : {
     if (!$6_1) {
      break label$105
     }
     $5_1 = ($6_1 & -8 | 0) + 69312 | 0;
     $0_1 = HEAP32[(0 + 69292 | 0) >> 2] | 0;
     label$106 : {
      label$107 : {
       $8_1 = 1 << ($6_1 >>> 3 | 0) | 0;
       if ($8_1 & $2_1 | 0) {
        break label$107
       }
       HEAP32[(0 + 69272 | 0) >> 2] = $8_1 | $2_1 | 0;
       $8_1 = $5_1;
       break label$106;
      }
      $8_1 = HEAP32[($5_1 + 8 | 0) >> 2] | 0;
     }
     HEAP32[($5_1 + 8 | 0) >> 2] = $0_1;
     HEAP32[($8_1 + 12 | 0) >> 2] = $0_1;
     HEAP32[($0_1 + 12 | 0) >> 2] = $5_1;
     HEAP32[($0_1 + 8 | 0) >> 2] = $8_1;
    }
    HEAP32[(0 + 69292 | 0) >> 2] = $3_1;
    HEAP32[(0 + 69280 | 0) >> 2] = $4_1;
   }
   $0_1 = $7_1 + 8 | 0;
  }
  global$0 = $1_1 + 16 | 0;
  return $0_1 | 0;
 }
 
 function $80($0_1, $1_1, $2_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $2_1 = $2_1 | 0;
  var $4_1 = 0, $5_1 = 0, $7_1 = 0, $8_1 = 0, $9_1 = 0, $3_1 = 0, $6_1 = 0;
  $3_1 = $0_1 + ((-8 - $0_1 | 0) & 7 | 0) | 0;
  HEAP32[($3_1 + 4 | 0) >> 2] = $2_1 | 3 | 0;
  $4_1 = $1_1 + ((-8 - $1_1 | 0) & 7 | 0) | 0;
  $5_1 = $3_1 + $2_1 | 0;
  $0_1 = $4_1 - $5_1 | 0;
  label$1 : {
   label$2 : {
    if (($4_1 | 0) != (HEAP32[(0 + 69296 | 0) >> 2] | 0 | 0)) {
     break label$2
    }
    HEAP32[(0 + 69296 | 0) >> 2] = $5_1;
    $2_1 = (HEAP32[(0 + 69284 | 0) >> 2] | 0) + $0_1 | 0;
    HEAP32[(0 + 69284 | 0) >> 2] = $2_1;
    HEAP32[($5_1 + 4 | 0) >> 2] = $2_1 | 1 | 0;
    break label$1;
   }
   label$3 : {
    if (($4_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
     break label$3
    }
    HEAP32[(0 + 69292 | 0) >> 2] = $5_1;
    $2_1 = (HEAP32[(0 + 69280 | 0) >> 2] | 0) + $0_1 | 0;
    HEAP32[(0 + 69280 | 0) >> 2] = $2_1;
    HEAP32[($5_1 + 4 | 0) >> 2] = $2_1 | 1 | 0;
    HEAP32[($5_1 + $2_1 | 0) >> 2] = $2_1;
    break label$1;
   }
   label$4 : {
    $1_1 = HEAP32[($4_1 + 4 | 0) >> 2] | 0;
    if (($1_1 & 3 | 0 | 0) != (1 | 0)) {
     break label$4
    }
    $6_1 = $1_1 & -8 | 0;
    $2_1 = HEAP32[($4_1 + 12 | 0) >> 2] | 0;
    label$5 : {
     label$6 : {
      if ($1_1 >>> 0 > 255 >>> 0) {
       break label$6
      }
      $7_1 = HEAP32[($4_1 + 8 | 0) >> 2] | 0;
      $8_1 = $1_1 >>> 3 | 0;
      $1_1 = ($8_1 << 3 | 0) + 69312 | 0;
      label$7 : {
       if (($2_1 | 0) != ($7_1 | 0)) {
        break label$7
       }
       HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $8_1 | 0) | 0) | 0;
       break label$5;
      }
      HEAP32[($7_1 + 12 | 0) >> 2] = $2_1;
      HEAP32[($2_1 + 8 | 0) >> 2] = $7_1;
      break label$5;
     }
     $9_1 = HEAP32[($4_1 + 24 | 0) >> 2] | 0;
     label$8 : {
      label$9 : {
       if (($2_1 | 0) == ($4_1 | 0)) {
        break label$9
       }
       $1_1 = HEAP32[($4_1 + 8 | 0) >> 2] | 0;
       HEAP32[(0 + 69288 | 0) >> 2] | 0;
       HEAP32[($1_1 + 12 | 0) >> 2] = $2_1;
       HEAP32[($2_1 + 8 | 0) >> 2] = $1_1;
       break label$8;
      }
      label$10 : {
       label$11 : {
        label$12 : {
         $1_1 = HEAP32[($4_1 + 20 | 0) >> 2] | 0;
         if (!$1_1) {
          break label$12
         }
         $7_1 = $4_1 + 20 | 0;
         break label$11;
        }
        $1_1 = HEAP32[($4_1 + 16 | 0) >> 2] | 0;
        if (!$1_1) {
         break label$10
        }
        $7_1 = $4_1 + 16 | 0;
       }
       label$13 : while (1) {
        $8_1 = $7_1;
        $2_1 = $1_1;
        $7_1 = $2_1 + 20 | 0;
        $1_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
        if ($1_1) {
         continue label$13
        }
        $7_1 = $2_1 + 16 | 0;
        $1_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
        if ($1_1) {
         continue label$13
        }
        break label$13;
       };
       HEAP32[$8_1 >> 2] = 0;
       break label$8;
      }
      $2_1 = 0;
     }
     if (!$9_1) {
      break label$5
     }
     label$14 : {
      label$15 : {
       $7_1 = HEAP32[($4_1 + 28 | 0) >> 2] | 0;
       $1_1 = ($7_1 << 2 | 0) + 69576 | 0;
       if (($4_1 | 0) != (HEAP32[$1_1 >> 2] | 0 | 0)) {
        break label$15
       }
       HEAP32[$1_1 >> 2] = $2_1;
       if ($2_1) {
        break label$14
       }
       HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $7_1 | 0) | 0) | 0;
       break label$5;
      }
      HEAP32[($9_1 + ((HEAP32[($9_1 + 16 | 0) >> 2] | 0 | 0) == ($4_1 | 0) ? 16 : 20) | 0) >> 2] = $2_1;
      if (!$2_1) {
       break label$5
      }
     }
     HEAP32[($2_1 + 24 | 0) >> 2] = $9_1;
     label$16 : {
      $1_1 = HEAP32[($4_1 + 16 | 0) >> 2] | 0;
      if (!$1_1) {
       break label$16
      }
      HEAP32[($2_1 + 16 | 0) >> 2] = $1_1;
      HEAP32[($1_1 + 24 | 0) >> 2] = $2_1;
     }
     $1_1 = HEAP32[($4_1 + 20 | 0) >> 2] | 0;
     if (!$1_1) {
      break label$5
     }
     HEAP32[($2_1 + 20 | 0) >> 2] = $1_1;
     HEAP32[($1_1 + 24 | 0) >> 2] = $2_1;
    }
    $0_1 = $6_1 + $0_1 | 0;
    $4_1 = $4_1 + $6_1 | 0;
    $1_1 = HEAP32[($4_1 + 4 | 0) >> 2] | 0;
   }
   HEAP32[($4_1 + 4 | 0) >> 2] = $1_1 & -2 | 0;
   HEAP32[($5_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
   HEAP32[($5_1 + $0_1 | 0) >> 2] = $0_1;
   label$17 : {
    if ($0_1 >>> 0 > 255 >>> 0) {
     break label$17
    }
    $2_1 = ($0_1 & -8 | 0) + 69312 | 0;
    label$18 : {
     label$19 : {
      $1_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
      $0_1 = 1 << ($0_1 >>> 3 | 0) | 0;
      if ($1_1 & $0_1 | 0) {
       break label$19
      }
      HEAP32[(0 + 69272 | 0) >> 2] = $1_1 | $0_1 | 0;
      $0_1 = $2_1;
      break label$18;
     }
     $0_1 = HEAP32[($2_1 + 8 | 0) >> 2] | 0;
    }
    HEAP32[($2_1 + 8 | 0) >> 2] = $5_1;
    HEAP32[($0_1 + 12 | 0) >> 2] = $5_1;
    HEAP32[($5_1 + 12 | 0) >> 2] = $2_1;
    HEAP32[($5_1 + 8 | 0) >> 2] = $0_1;
    break label$1;
   }
   $2_1 = 31;
   label$20 : {
    if ($0_1 >>> 0 > 16777215 >>> 0) {
     break label$20
    }
    $2_1 = Math_clz32($0_1 >>> 8 | 0);
    $2_1 = ((($0_1 >>> (38 - $2_1 | 0) | 0) & 1 | 0) - ($2_1 << 1 | 0) | 0) + 62 | 0;
   }
   HEAP32[($5_1 + 28 | 0) >> 2] = $2_1;
   HEAP32[($5_1 + 16 | 0) >> 2] = 0;
   HEAP32[($5_1 + 20 | 0) >> 2] = 0;
   $1_1 = ($2_1 << 2 | 0) + 69576 | 0;
   label$21 : {
    label$22 : {
     label$23 : {
      $7_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
      $4_1 = 1 << $2_1 | 0;
      if ($7_1 & $4_1 | 0) {
       break label$23
      }
      HEAP32[(0 + 69276 | 0) >> 2] = $7_1 | $4_1 | 0;
      HEAP32[$1_1 >> 2] = $5_1;
      HEAP32[($5_1 + 24 | 0) >> 2] = $1_1;
      break label$22;
     }
     $2_1 = $0_1 << (($2_1 | 0) == (31 | 0) ? 0 : 25 - ($2_1 >>> 1 | 0) | 0) | 0;
     $7_1 = HEAP32[$1_1 >> 2] | 0;
     label$24 : while (1) {
      $1_1 = $7_1;
      if (((HEAP32[($1_1 + 4 | 0) >> 2] | 0) & -8 | 0 | 0) == ($0_1 | 0)) {
       break label$21
      }
      $7_1 = $2_1 >>> 29 | 0;
      $2_1 = $2_1 << 1 | 0;
      $4_1 = ($1_1 + ($7_1 & 4 | 0) | 0) + 16 | 0;
      $7_1 = HEAP32[$4_1 >> 2] | 0;
      if ($7_1) {
       continue label$24
      }
      break label$24;
     };
     HEAP32[$4_1 >> 2] = $5_1;
     HEAP32[($5_1 + 24 | 0) >> 2] = $1_1;
    }
    HEAP32[($5_1 + 12 | 0) >> 2] = $5_1;
    HEAP32[($5_1 + 8 | 0) >> 2] = $5_1;
    break label$1;
   }
   $2_1 = HEAP32[($1_1 + 8 | 0) >> 2] | 0;
   HEAP32[($2_1 + 12 | 0) >> 2] = $5_1;
   HEAP32[($1_1 + 8 | 0) >> 2] = $5_1;
   HEAP32[($5_1 + 24 | 0) >> 2] = 0;
   HEAP32[($5_1 + 12 | 0) >> 2] = $1_1;
   HEAP32[($5_1 + 8 | 0) >> 2] = $2_1;
  }
  return $3_1 + 8 | 0 | 0;
 }
 
 function $81($0_1) {
  $0_1 = $0_1 | 0;
  var $4_1 = 0, $2_1 = 0, $1_1 = 0, $5_1 = 0, $3_1 = 0, $6_1 = 0, $7_1 = 0;
  label$1 : {
   if (!$0_1) {
    break label$1
   }
   $1_1 = $0_1 + -8 | 0;
   $2_1 = HEAP32[($0_1 + -4 | 0) >> 2] | 0;
   $0_1 = $2_1 & -8 | 0;
   $3_1 = $1_1 + $0_1 | 0;
   label$2 : {
    if ($2_1 & 1 | 0) {
     break label$2
    }
    if (!($2_1 & 2 | 0)) {
     break label$1
    }
    $4_1 = HEAP32[$1_1 >> 2] | 0;
    $1_1 = $1_1 - $4_1 | 0;
    $5_1 = HEAP32[(0 + 69288 | 0) >> 2] | 0;
    if ($1_1 >>> 0 < $5_1 >>> 0) {
     break label$1
    }
    $0_1 = $4_1 + $0_1 | 0;
    label$3 : {
     label$4 : {
      label$5 : {
       if (($1_1 | 0) == (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
        break label$5
       }
       $2_1 = HEAP32[($1_1 + 12 | 0) >> 2] | 0;
       label$6 : {
        if ($4_1 >>> 0 > 255 >>> 0) {
         break label$6
        }
        $5_1 = HEAP32[($1_1 + 8 | 0) >> 2] | 0;
        $6_1 = $4_1 >>> 3 | 0;
        $4_1 = ($6_1 << 3 | 0) + 69312 | 0;
        label$7 : {
         if (($2_1 | 0) != ($5_1 | 0)) {
          break label$7
         }
         HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $6_1 | 0) | 0) | 0;
         break label$2;
        }
        HEAP32[($5_1 + 12 | 0) >> 2] = $2_1;
        HEAP32[($2_1 + 8 | 0) >> 2] = $5_1;
        break label$2;
       }
       $7_1 = HEAP32[($1_1 + 24 | 0) >> 2] | 0;
       label$8 : {
        if (($2_1 | 0) == ($1_1 | 0)) {
         break label$8
        }
        $4_1 = HEAP32[($1_1 + 8 | 0) >> 2] | 0;
        HEAP32[($4_1 + 12 | 0) >> 2] = $2_1;
        HEAP32[($2_1 + 8 | 0) >> 2] = $4_1;
        break label$3;
       }
       label$9 : {
        label$10 : {
         $4_1 = HEAP32[($1_1 + 20 | 0) >> 2] | 0;
         if (!$4_1) {
          break label$10
         }
         $5_1 = $1_1 + 20 | 0;
         break label$9;
        }
        $4_1 = HEAP32[($1_1 + 16 | 0) >> 2] | 0;
        if (!$4_1) {
         break label$4
        }
        $5_1 = $1_1 + 16 | 0;
       }
       label$11 : while (1) {
        $6_1 = $5_1;
        $2_1 = $4_1;
        $5_1 = $2_1 + 20 | 0;
        $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
        if ($4_1) {
         continue label$11
        }
        $5_1 = $2_1 + 16 | 0;
        $4_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
        if ($4_1) {
         continue label$11
        }
        break label$11;
       };
       HEAP32[$6_1 >> 2] = 0;
       break label$3;
      }
      $2_1 = HEAP32[($3_1 + 4 | 0) >> 2] | 0;
      if (($2_1 & 3 | 0 | 0) != (3 | 0)) {
       break label$2
      }
      HEAP32[(0 + 69280 | 0) >> 2] = $0_1;
      HEAP32[($3_1 + 4 | 0) >> 2] = $2_1 & -2 | 0;
      HEAP32[($1_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
      HEAP32[$3_1 >> 2] = $0_1;
      return;
     }
     $2_1 = 0;
    }
    if (!$7_1) {
     break label$2
    }
    label$12 : {
     label$13 : {
      $5_1 = HEAP32[($1_1 + 28 | 0) >> 2] | 0;
      $4_1 = ($5_1 << 2 | 0) + 69576 | 0;
      if (($1_1 | 0) != (HEAP32[$4_1 >> 2] | 0 | 0)) {
       break label$13
      }
      HEAP32[$4_1 >> 2] = $2_1;
      if ($2_1) {
       break label$12
      }
      HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $5_1 | 0) | 0) | 0;
      break label$2;
     }
     HEAP32[($7_1 + ((HEAP32[($7_1 + 16 | 0) >> 2] | 0 | 0) == ($1_1 | 0) ? 16 : 20) | 0) >> 2] = $2_1;
     if (!$2_1) {
      break label$2
     }
    }
    HEAP32[($2_1 + 24 | 0) >> 2] = $7_1;
    label$14 : {
     $4_1 = HEAP32[($1_1 + 16 | 0) >> 2] | 0;
     if (!$4_1) {
      break label$14
     }
     HEAP32[($2_1 + 16 | 0) >> 2] = $4_1;
     HEAP32[($4_1 + 24 | 0) >> 2] = $2_1;
    }
    $4_1 = HEAP32[($1_1 + 20 | 0) >> 2] | 0;
    if (!$4_1) {
     break label$2
    }
    HEAP32[($2_1 + 20 | 0) >> 2] = $4_1;
    HEAP32[($4_1 + 24 | 0) >> 2] = $2_1;
   }
   if ($1_1 >>> 0 >= $3_1 >>> 0) {
    break label$1
   }
   $4_1 = HEAP32[($3_1 + 4 | 0) >> 2] | 0;
   if (!($4_1 & 1 | 0)) {
    break label$1
   }
   label$15 : {
    label$16 : {
     label$17 : {
      label$18 : {
       label$19 : {
        if ($4_1 & 2 | 0) {
         break label$19
        }
        label$20 : {
         if (($3_1 | 0) != (HEAP32[(0 + 69296 | 0) >> 2] | 0 | 0)) {
          break label$20
         }
         HEAP32[(0 + 69296 | 0) >> 2] = $1_1;
         $0_1 = (HEAP32[(0 + 69284 | 0) >> 2] | 0) + $0_1 | 0;
         HEAP32[(0 + 69284 | 0) >> 2] = $0_1;
         HEAP32[($1_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
         if (($1_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
          break label$1
         }
         HEAP32[(0 + 69280 | 0) >> 2] = 0;
         HEAP32[(0 + 69292 | 0) >> 2] = 0;
         return;
        }
        label$21 : {
         if (($3_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
          break label$21
         }
         HEAP32[(0 + 69292 | 0) >> 2] = $1_1;
         $0_1 = (HEAP32[(0 + 69280 | 0) >> 2] | 0) + $0_1 | 0;
         HEAP32[(0 + 69280 | 0) >> 2] = $0_1;
         HEAP32[($1_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
         HEAP32[($1_1 + $0_1 | 0) >> 2] = $0_1;
         return;
        }
        $0_1 = ($4_1 & -8 | 0) + $0_1 | 0;
        $2_1 = HEAP32[($3_1 + 12 | 0) >> 2] | 0;
        label$22 : {
         if ($4_1 >>> 0 > 255 >>> 0) {
          break label$22
         }
         $5_1 = HEAP32[($3_1 + 8 | 0) >> 2] | 0;
         $3_1 = $4_1 >>> 3 | 0;
         $4_1 = ($3_1 << 3 | 0) + 69312 | 0;
         label$23 : {
          if (($2_1 | 0) != ($5_1 | 0)) {
           break label$23
          }
          HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $3_1 | 0) | 0) | 0;
          break label$16;
         }
         HEAP32[($5_1 + 12 | 0) >> 2] = $2_1;
         HEAP32[($2_1 + 8 | 0) >> 2] = $5_1;
         break label$16;
        }
        $7_1 = HEAP32[($3_1 + 24 | 0) >> 2] | 0;
        label$24 : {
         if (($2_1 | 0) == ($3_1 | 0)) {
          break label$24
         }
         $4_1 = HEAP32[($3_1 + 8 | 0) >> 2] | 0;
         HEAP32[(0 + 69288 | 0) >> 2] | 0;
         HEAP32[($4_1 + 12 | 0) >> 2] = $2_1;
         HEAP32[($2_1 + 8 | 0) >> 2] = $4_1;
         break label$17;
        }
        label$25 : {
         label$26 : {
          $4_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
          if (!$4_1) {
           break label$26
          }
          $5_1 = $3_1 + 20 | 0;
          break label$25;
         }
         $4_1 = HEAP32[($3_1 + 16 | 0) >> 2] | 0;
         if (!$4_1) {
          break label$18
         }
         $5_1 = $3_1 + 16 | 0;
        }
        label$27 : while (1) {
         $6_1 = $5_1;
         $2_1 = $4_1;
         $5_1 = $2_1 + 20 | 0;
         $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$27
         }
         $5_1 = $2_1 + 16 | 0;
         $4_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$27
         }
         break label$27;
        };
        HEAP32[$6_1 >> 2] = 0;
        break label$17;
       }
       HEAP32[($3_1 + 4 | 0) >> 2] = $4_1 & -2 | 0;
       HEAP32[($1_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
       HEAP32[($1_1 + $0_1 | 0) >> 2] = $0_1;
       break label$15;
      }
      $2_1 = 0;
     }
     if (!$7_1) {
      break label$16
     }
     label$28 : {
      label$29 : {
       $5_1 = HEAP32[($3_1 + 28 | 0) >> 2] | 0;
       $4_1 = ($5_1 << 2 | 0) + 69576 | 0;
       if (($3_1 | 0) != (HEAP32[$4_1 >> 2] | 0 | 0)) {
        break label$29
       }
       HEAP32[$4_1 >> 2] = $2_1;
       if ($2_1) {
        break label$28
       }
       HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $5_1 | 0) | 0) | 0;
       break label$16;
      }
      HEAP32[($7_1 + ((HEAP32[($7_1 + 16 | 0) >> 2] | 0 | 0) == ($3_1 | 0) ? 16 : 20) | 0) >> 2] = $2_1;
      if (!$2_1) {
       break label$16
      }
     }
     HEAP32[($2_1 + 24 | 0) >> 2] = $7_1;
     label$30 : {
      $4_1 = HEAP32[($3_1 + 16 | 0) >> 2] | 0;
      if (!$4_1) {
       break label$30
      }
      HEAP32[($2_1 + 16 | 0) >> 2] = $4_1;
      HEAP32[($4_1 + 24 | 0) >> 2] = $2_1;
     }
     $4_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
     if (!$4_1) {
      break label$16
     }
     HEAP32[($2_1 + 20 | 0) >> 2] = $4_1;
     HEAP32[($4_1 + 24 | 0) >> 2] = $2_1;
    }
    HEAP32[($1_1 + 4 | 0) >> 2] = $0_1 | 1 | 0;
    HEAP32[($1_1 + $0_1 | 0) >> 2] = $0_1;
    if (($1_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
     break label$15
    }
    HEAP32[(0 + 69280 | 0) >> 2] = $0_1;
    return;
   }
   label$31 : {
    if ($0_1 >>> 0 > 255 >>> 0) {
     break label$31
    }
    $2_1 = ($0_1 & -8 | 0) + 69312 | 0;
    label$32 : {
     label$33 : {
      $4_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
      $0_1 = 1 << ($0_1 >>> 3 | 0) | 0;
      if ($4_1 & $0_1 | 0) {
       break label$33
      }
      HEAP32[(0 + 69272 | 0) >> 2] = $4_1 | $0_1 | 0;
      $0_1 = $2_1;
      break label$32;
     }
     $0_1 = HEAP32[($2_1 + 8 | 0) >> 2] | 0;
    }
    HEAP32[($2_1 + 8 | 0) >> 2] = $1_1;
    HEAP32[($0_1 + 12 | 0) >> 2] = $1_1;
    HEAP32[($1_1 + 12 | 0) >> 2] = $2_1;
    HEAP32[($1_1 + 8 | 0) >> 2] = $0_1;
    return;
   }
   $2_1 = 31;
   label$34 : {
    if ($0_1 >>> 0 > 16777215 >>> 0) {
     break label$34
    }
    $2_1 = Math_clz32($0_1 >>> 8 | 0);
    $2_1 = ((($0_1 >>> (38 - $2_1 | 0) | 0) & 1 | 0) - ($2_1 << 1 | 0) | 0) + 62 | 0;
   }
   HEAP32[($1_1 + 28 | 0) >> 2] = $2_1;
   HEAP32[($1_1 + 16 | 0) >> 2] = 0;
   HEAP32[($1_1 + 20 | 0) >> 2] = 0;
   $3_1 = ($2_1 << 2 | 0) + 69576 | 0;
   label$35 : {
    label$36 : {
     label$37 : {
      label$38 : {
       $4_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
       $5_1 = 1 << $2_1 | 0;
       if ($4_1 & $5_1 | 0) {
        break label$38
       }
       HEAP32[(0 + 69276 | 0) >> 2] = $4_1 | $5_1 | 0;
       $0_1 = 8;
       $2_1 = 24;
       $5_1 = $3_1;
       break label$37;
      }
      $2_1 = $0_1 << (($2_1 | 0) == (31 | 0) ? 0 : 25 - ($2_1 >>> 1 | 0) | 0) | 0;
      $5_1 = HEAP32[$3_1 >> 2] | 0;
      label$39 : while (1) {
       $4_1 = $5_1;
       if (((HEAP32[($4_1 + 4 | 0) >> 2] | 0) & -8 | 0 | 0) == ($0_1 | 0)) {
        break label$36
       }
       $5_1 = $2_1 >>> 29 | 0;
       $2_1 = $2_1 << 1 | 0;
       $3_1 = ($4_1 + ($5_1 & 4 | 0) | 0) + 16 | 0;
       $5_1 = HEAP32[$3_1 >> 2] | 0;
       if ($5_1) {
        continue label$39
       }
       break label$39;
      };
      $0_1 = 8;
      $2_1 = 24;
      $5_1 = $4_1;
     }
     $4_1 = $1_1;
     $6_1 = $4_1;
     break label$35;
    }
    $5_1 = HEAP32[($4_1 + 8 | 0) >> 2] | 0;
    HEAP32[($5_1 + 12 | 0) >> 2] = $1_1;
    $2_1 = 8;
    $3_1 = $4_1 + 8 | 0;
    $6_1 = 0;
    $0_1 = 24;
   }
   HEAP32[$3_1 >> 2] = $1_1;
   HEAP32[($1_1 + $2_1 | 0) >> 2] = $5_1;
   HEAP32[($1_1 + 12 | 0) >> 2] = $4_1;
   HEAP32[($1_1 + $0_1 | 0) >> 2] = $6_1;
   $1_1 = (HEAP32[(0 + 69304 | 0) >> 2] | 0) + -1 | 0;
   HEAP32[(0 + 69304 | 0) >> 2] = $1_1 ? $1_1 : -1;
  }
 }
 
 function $82($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $2_1 = 0, $3_1 = 0;
  label$1 : {
   if ($0_1) {
    break label$1
   }
   return $79($1_1 | 0) | 0 | 0;
  }
  label$2 : {
   if ($1_1 >>> 0 < -64 >>> 0) {
    break label$2
   }
   HEAP32[($16() | 0) >> 2] = 48;
   return 0 | 0;
  }
  label$3 : {
   $2_1 = $83($0_1 + -8 | 0 | 0, ($1_1 >>> 0 < 11 >>> 0 ? 16 : ($1_1 + 11 | 0) & -8 | 0) | 0) | 0;
   if (!$2_1) {
    break label$3
   }
   return $2_1 + 8 | 0 | 0;
  }
  label$4 : {
   $2_1 = $79($1_1 | 0) | 0;
   if ($2_1) {
    break label$4
   }
   return 0 | 0;
  }
  $3_1 = HEAP32[($0_1 + -4 | 0) >> 2] | 0;
  $3_1 = ($3_1 & 3 | 0 ? -4 : -8) + ($3_1 & -8 | 0) | 0;
  $18($2_1 | 0, $0_1 | 0, ($3_1 >>> 0 < $1_1 >>> 0 ? $3_1 : $1_1) | 0) | 0;
  $81($0_1 | 0);
  return $2_1 | 0;
 }
 
 function $83($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $3_1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $2_1 = 0, $7_1 = 0, $9_1 = 0, $8_1 = 0, $10_1 = 0;
  $2_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
  $3_1 = $2_1 & -8 | 0;
  label$1 : {
   label$2 : {
    if ($2_1 & 3 | 0) {
     break label$2
    }
    label$3 : {
     if ($1_1 >>> 0 >= 256 >>> 0) {
      break label$3
     }
     return 0 | 0;
    }
    label$4 : {
     if ($3_1 >>> 0 < ($1_1 + 4 | 0) >>> 0) {
      break label$4
     }
     $4_1 = $0_1;
     if (($3_1 - $1_1 | 0) >>> 0 <= ((HEAP32[(0 + 69752 | 0) >> 2] | 0) << 1 | 0) >>> 0) {
      break label$1
     }
    }
    return 0 | 0;
   }
   $5_1 = $0_1 + $3_1 | 0;
   label$5 : {
    label$6 : {
     if ($3_1 >>> 0 < $1_1 >>> 0) {
      break label$6
     }
     $3_1 = $3_1 - $1_1 | 0;
     if ($3_1 >>> 0 < 16 >>> 0) {
      break label$5
     }
     HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $1_1 | 0 | 2 | 0;
     $1_1 = $0_1 + $1_1 | 0;
     HEAP32[($1_1 + 4 | 0) >> 2] = $3_1 | 3 | 0;
     HEAP32[($5_1 + 4 | 0) >> 2] = HEAP32[($5_1 + 4 | 0) >> 2] | 0 | 1 | 0;
     $84($1_1 | 0, $3_1 | 0);
     break label$5;
    }
    $4_1 = 0;
    label$7 : {
     if (($5_1 | 0) != (HEAP32[(0 + 69296 | 0) >> 2] | 0 | 0)) {
      break label$7
     }
     $3_1 = (HEAP32[(0 + 69284 | 0) >> 2] | 0) + $3_1 | 0;
     if ($3_1 >>> 0 <= $1_1 >>> 0) {
      break label$1
     }
     HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $1_1 | 0 | 2 | 0;
     $2_1 = $0_1 + $1_1 | 0;
     $1_1 = $3_1 - $1_1 | 0;
     HEAP32[($2_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
     HEAP32[(0 + 69284 | 0) >> 2] = $1_1;
     HEAP32[(0 + 69296 | 0) >> 2] = $2_1;
     break label$5;
    }
    label$8 : {
     if (($5_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
      break label$8
     }
     $4_1 = 0;
     $3_1 = (HEAP32[(0 + 69280 | 0) >> 2] | 0) + $3_1 | 0;
     if ($3_1 >>> 0 < $1_1 >>> 0) {
      break label$1
     }
     label$9 : {
      label$10 : {
       $4_1 = $3_1 - $1_1 | 0;
       if ($4_1 >>> 0 < 16 >>> 0) {
        break label$10
       }
       HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $1_1 | 0 | 2 | 0;
       $1_1 = $0_1 + $1_1 | 0;
       HEAP32[($1_1 + 4 | 0) >> 2] = $4_1 | 1 | 0;
       $3_1 = $0_1 + $3_1 | 0;
       HEAP32[$3_1 >> 2] = $4_1;
       HEAP32[($3_1 + 4 | 0) >> 2] = (HEAP32[($3_1 + 4 | 0) >> 2] | 0) & -2 | 0;
       break label$9;
      }
      HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $3_1 | 0 | 2 | 0;
      $1_1 = $0_1 + $3_1 | 0;
      HEAP32[($1_1 + 4 | 0) >> 2] = HEAP32[($1_1 + 4 | 0) >> 2] | 0 | 1 | 0;
      $4_1 = 0;
      $1_1 = 0;
     }
     HEAP32[(0 + 69292 | 0) >> 2] = $1_1;
     HEAP32[(0 + 69280 | 0) >> 2] = $4_1;
     break label$5;
    }
    $4_1 = 0;
    $6_1 = HEAP32[($5_1 + 4 | 0) >> 2] | 0;
    if ($6_1 & 2 | 0) {
     break label$1
    }
    $7_1 = ($6_1 & -8 | 0) + $3_1 | 0;
    if ($7_1 >>> 0 < $1_1 >>> 0) {
     break label$1
    }
    $8_1 = $7_1 - $1_1 | 0;
    $3_1 = HEAP32[($5_1 + 12 | 0) >> 2] | 0;
    label$11 : {
     label$12 : {
      if ($6_1 >>> 0 > 255 >>> 0) {
       break label$12
      }
      $4_1 = HEAP32[($5_1 + 8 | 0) >> 2] | 0;
      $6_1 = $6_1 >>> 3 | 0;
      $5_1 = ($6_1 << 3 | 0) + 69312 | 0;
      label$13 : {
       if (($3_1 | 0) != ($4_1 | 0)) {
        break label$13
       }
       HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $6_1 | 0) | 0) | 0;
       break label$11;
      }
      HEAP32[($4_1 + 12 | 0) >> 2] = $3_1;
      HEAP32[($3_1 + 8 | 0) >> 2] = $4_1;
      break label$11;
     }
     $9_1 = HEAP32[($5_1 + 24 | 0) >> 2] | 0;
     label$14 : {
      label$15 : {
       if (($3_1 | 0) == ($5_1 | 0)) {
        break label$15
       }
       $4_1 = HEAP32[($5_1 + 8 | 0) >> 2] | 0;
       HEAP32[(0 + 69288 | 0) >> 2] | 0;
       HEAP32[($4_1 + 12 | 0) >> 2] = $3_1;
       HEAP32[($3_1 + 8 | 0) >> 2] = $4_1;
       break label$14;
      }
      label$16 : {
       label$17 : {
        label$18 : {
         $4_1 = HEAP32[($5_1 + 20 | 0) >> 2] | 0;
         if (!$4_1) {
          break label$18
         }
         $6_1 = $5_1 + 20 | 0;
         break label$17;
        }
        $4_1 = HEAP32[($5_1 + 16 | 0) >> 2] | 0;
        if (!$4_1) {
         break label$16
        }
        $6_1 = $5_1 + 16 | 0;
       }
       label$19 : while (1) {
        $10_1 = $6_1;
        $3_1 = $4_1;
        $6_1 = $3_1 + 20 | 0;
        $4_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
        if ($4_1) {
         continue label$19
        }
        $6_1 = $3_1 + 16 | 0;
        $4_1 = HEAP32[($3_1 + 16 | 0) >> 2] | 0;
        if ($4_1) {
         continue label$19
        }
        break label$19;
       };
       HEAP32[$10_1 >> 2] = 0;
       break label$14;
      }
      $3_1 = 0;
     }
     if (!$9_1) {
      break label$11
     }
     label$20 : {
      label$21 : {
       $6_1 = HEAP32[($5_1 + 28 | 0) >> 2] | 0;
       $4_1 = ($6_1 << 2 | 0) + 69576 | 0;
       if (($5_1 | 0) != (HEAP32[$4_1 >> 2] | 0 | 0)) {
        break label$21
       }
       HEAP32[$4_1 >> 2] = $3_1;
       if ($3_1) {
        break label$20
       }
       HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $6_1 | 0) | 0) | 0;
       break label$11;
      }
      HEAP32[($9_1 + ((HEAP32[($9_1 + 16 | 0) >> 2] | 0 | 0) == ($5_1 | 0) ? 16 : 20) | 0) >> 2] = $3_1;
      if (!$3_1) {
       break label$11
      }
     }
     HEAP32[($3_1 + 24 | 0) >> 2] = $9_1;
     label$22 : {
      $4_1 = HEAP32[($5_1 + 16 | 0) >> 2] | 0;
      if (!$4_1) {
       break label$22
      }
      HEAP32[($3_1 + 16 | 0) >> 2] = $4_1;
      HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
     }
     $4_1 = HEAP32[($5_1 + 20 | 0) >> 2] | 0;
     if (!$4_1) {
      break label$11
     }
     HEAP32[($3_1 + 20 | 0) >> 2] = $4_1;
     HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
    }
    label$23 : {
     if ($8_1 >>> 0 > 15 >>> 0) {
      break label$23
     }
     HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $7_1 | 0 | 2 | 0;
     $1_1 = $0_1 + $7_1 | 0;
     HEAP32[($1_1 + 4 | 0) >> 2] = HEAP32[($1_1 + 4 | 0) >> 2] | 0 | 1 | 0;
     break label$5;
    }
    HEAP32[($0_1 + 4 | 0) >> 2] = $2_1 & 1 | 0 | $1_1 | 0 | 2 | 0;
    $1_1 = $0_1 + $1_1 | 0;
    HEAP32[($1_1 + 4 | 0) >> 2] = $8_1 | 3 | 0;
    $3_1 = $0_1 + $7_1 | 0;
    HEAP32[($3_1 + 4 | 0) >> 2] = HEAP32[($3_1 + 4 | 0) >> 2] | 0 | 1 | 0;
    $84($1_1 | 0, $8_1 | 0);
   }
   $4_1 = $0_1;
  }
  return $4_1 | 0;
 }
 
 function $84($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var $4_1 = 0, $3_1 = 0, $5_1 = 0, $2_1 = 0, $7_1 = 0, $6_1 = 0;
  $2_1 = $0_1 + $1_1 | 0;
  label$1 : {
   label$2 : {
    $3_1 = HEAP32[($0_1 + 4 | 0) >> 2] | 0;
    if ($3_1 & 1 | 0) {
     break label$2
    }
    if (!($3_1 & 2 | 0)) {
     break label$1
    }
    $4_1 = HEAP32[$0_1 >> 2] | 0;
    $1_1 = $4_1 + $1_1 | 0;
    label$3 : {
     label$4 : {
      label$5 : {
       label$6 : {
        $0_1 = $0_1 - $4_1 | 0;
        if (($0_1 | 0) == (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
         break label$6
        }
        $3_1 = HEAP32[($0_1 + 12 | 0) >> 2] | 0;
        label$7 : {
         if ($4_1 >>> 0 > 255 >>> 0) {
          break label$7
         }
         $5_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
         $6_1 = $4_1 >>> 3 | 0;
         $4_1 = ($6_1 << 3 | 0) + 69312 | 0;
         if (($3_1 | 0) != ($5_1 | 0)) {
          break label$5
         }
         HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $6_1 | 0) | 0) | 0;
         break label$2;
        }
        $7_1 = HEAP32[($0_1 + 24 | 0) >> 2] | 0;
        label$8 : {
         if (($3_1 | 0) == ($0_1 | 0)) {
          break label$8
         }
         $4_1 = HEAP32[($0_1 + 8 | 0) >> 2] | 0;
         HEAP32[(0 + 69288 | 0) >> 2] | 0;
         HEAP32[($4_1 + 12 | 0) >> 2] = $3_1;
         HEAP32[($3_1 + 8 | 0) >> 2] = $4_1;
         break label$3;
        }
        label$9 : {
         label$10 : {
          $4_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
          if (!$4_1) {
           break label$10
          }
          $5_1 = $0_1 + 20 | 0;
          break label$9;
         }
         $4_1 = HEAP32[($0_1 + 16 | 0) >> 2] | 0;
         if (!$4_1) {
          break label$4
         }
         $5_1 = $0_1 + 16 | 0;
        }
        label$11 : while (1) {
         $6_1 = $5_1;
         $3_1 = $4_1;
         $5_1 = $3_1 + 20 | 0;
         $4_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$11
         }
         $5_1 = $3_1 + 16 | 0;
         $4_1 = HEAP32[($3_1 + 16 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$11
         }
         break label$11;
        };
        HEAP32[$6_1 >> 2] = 0;
        break label$3;
       }
       $3_1 = HEAP32[($2_1 + 4 | 0) >> 2] | 0;
       if (($3_1 & 3 | 0 | 0) != (3 | 0)) {
        break label$2
       }
       HEAP32[(0 + 69280 | 0) >> 2] = $1_1;
       HEAP32[($2_1 + 4 | 0) >> 2] = $3_1 & -2 | 0;
       HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
       HEAP32[$2_1 >> 2] = $1_1;
       return;
      }
      HEAP32[($5_1 + 12 | 0) >> 2] = $3_1;
      HEAP32[($3_1 + 8 | 0) >> 2] = $5_1;
      break label$2;
     }
     $3_1 = 0;
    }
    if (!$7_1) {
     break label$2
    }
    label$12 : {
     label$13 : {
      $5_1 = HEAP32[($0_1 + 28 | 0) >> 2] | 0;
      $4_1 = ($5_1 << 2 | 0) + 69576 | 0;
      if (($0_1 | 0) != (HEAP32[$4_1 >> 2] | 0 | 0)) {
       break label$13
      }
      HEAP32[$4_1 >> 2] = $3_1;
      if ($3_1) {
       break label$12
      }
      HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $5_1 | 0) | 0) | 0;
      break label$2;
     }
     HEAP32[($7_1 + ((HEAP32[($7_1 + 16 | 0) >> 2] | 0 | 0) == ($0_1 | 0) ? 16 : 20) | 0) >> 2] = $3_1;
     if (!$3_1) {
      break label$2
     }
    }
    HEAP32[($3_1 + 24 | 0) >> 2] = $7_1;
    label$14 : {
     $4_1 = HEAP32[($0_1 + 16 | 0) >> 2] | 0;
     if (!$4_1) {
      break label$14
     }
     HEAP32[($3_1 + 16 | 0) >> 2] = $4_1;
     HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
    }
    $4_1 = HEAP32[($0_1 + 20 | 0) >> 2] | 0;
    if (!$4_1) {
     break label$2
    }
    HEAP32[($3_1 + 20 | 0) >> 2] = $4_1;
    HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
   }
   label$15 : {
    label$16 : {
     label$17 : {
      label$18 : {
       label$19 : {
        $4_1 = HEAP32[($2_1 + 4 | 0) >> 2] | 0;
        if ($4_1 & 2 | 0) {
         break label$19
        }
        label$20 : {
         if (($2_1 | 0) != (HEAP32[(0 + 69296 | 0) >> 2] | 0 | 0)) {
          break label$20
         }
         HEAP32[(0 + 69296 | 0) >> 2] = $0_1;
         $1_1 = (HEAP32[(0 + 69284 | 0) >> 2] | 0) + $1_1 | 0;
         HEAP32[(0 + 69284 | 0) >> 2] = $1_1;
         HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
         if (($0_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
          break label$1
         }
         HEAP32[(0 + 69280 | 0) >> 2] = 0;
         HEAP32[(0 + 69292 | 0) >> 2] = 0;
         return;
        }
        label$21 : {
         if (($2_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
          break label$21
         }
         HEAP32[(0 + 69292 | 0) >> 2] = $0_1;
         $1_1 = (HEAP32[(0 + 69280 | 0) >> 2] | 0) + $1_1 | 0;
         HEAP32[(0 + 69280 | 0) >> 2] = $1_1;
         HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
         HEAP32[($0_1 + $1_1 | 0) >> 2] = $1_1;
         return;
        }
        $1_1 = ($4_1 & -8 | 0) + $1_1 | 0;
        $3_1 = HEAP32[($2_1 + 12 | 0) >> 2] | 0;
        label$22 : {
         if ($4_1 >>> 0 > 255 >>> 0) {
          break label$22
         }
         $5_1 = HEAP32[($2_1 + 8 | 0) >> 2] | 0;
         $2_1 = $4_1 >>> 3 | 0;
         $4_1 = ($2_1 << 3 | 0) + 69312 | 0;
         label$23 : {
          if (($3_1 | 0) != ($5_1 | 0)) {
           break label$23
          }
          HEAP32[(0 + 69272 | 0) >> 2] = (HEAP32[(0 + 69272 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $2_1 | 0) | 0) | 0;
          break label$16;
         }
         HEAP32[($5_1 + 12 | 0) >> 2] = $3_1;
         HEAP32[($3_1 + 8 | 0) >> 2] = $5_1;
         break label$16;
        }
        $7_1 = HEAP32[($2_1 + 24 | 0) >> 2] | 0;
        label$24 : {
         if (($3_1 | 0) == ($2_1 | 0)) {
          break label$24
         }
         $4_1 = HEAP32[($2_1 + 8 | 0) >> 2] | 0;
         HEAP32[(0 + 69288 | 0) >> 2] | 0;
         HEAP32[($4_1 + 12 | 0) >> 2] = $3_1;
         HEAP32[($3_1 + 8 | 0) >> 2] = $4_1;
         break label$17;
        }
        label$25 : {
         label$26 : {
          $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
          if (!$4_1) {
           break label$26
          }
          $5_1 = $2_1 + 20 | 0;
          break label$25;
         }
         $4_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
         if (!$4_1) {
          break label$18
         }
         $5_1 = $2_1 + 16 | 0;
        }
        label$27 : while (1) {
         $6_1 = $5_1;
         $3_1 = $4_1;
         $5_1 = $3_1 + 20 | 0;
         $4_1 = HEAP32[($3_1 + 20 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$27
         }
         $5_1 = $3_1 + 16 | 0;
         $4_1 = HEAP32[($3_1 + 16 | 0) >> 2] | 0;
         if ($4_1) {
          continue label$27
         }
         break label$27;
        };
        HEAP32[$6_1 >> 2] = 0;
        break label$17;
       }
       HEAP32[($2_1 + 4 | 0) >> 2] = $4_1 & -2 | 0;
       HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
       HEAP32[($0_1 + $1_1 | 0) >> 2] = $1_1;
       break label$15;
      }
      $3_1 = 0;
     }
     if (!$7_1) {
      break label$16
     }
     label$28 : {
      label$29 : {
       $5_1 = HEAP32[($2_1 + 28 | 0) >> 2] | 0;
       $4_1 = ($5_1 << 2 | 0) + 69576 | 0;
       if (($2_1 | 0) != (HEAP32[$4_1 >> 2] | 0 | 0)) {
        break label$29
       }
       HEAP32[$4_1 >> 2] = $3_1;
       if ($3_1) {
        break label$28
       }
       HEAP32[(0 + 69276 | 0) >> 2] = (HEAP32[(0 + 69276 | 0) >> 2] | 0) & (__wasm_rotl_i32(-2 | 0, $5_1 | 0) | 0) | 0;
       break label$16;
      }
      HEAP32[($7_1 + ((HEAP32[($7_1 + 16 | 0) >> 2] | 0 | 0) == ($2_1 | 0) ? 16 : 20) | 0) >> 2] = $3_1;
      if (!$3_1) {
       break label$16
      }
     }
     HEAP32[($3_1 + 24 | 0) >> 2] = $7_1;
     label$30 : {
      $4_1 = HEAP32[($2_1 + 16 | 0) >> 2] | 0;
      if (!$4_1) {
       break label$30
      }
      HEAP32[($3_1 + 16 | 0) >> 2] = $4_1;
      HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
     }
     $4_1 = HEAP32[($2_1 + 20 | 0) >> 2] | 0;
     if (!$4_1) {
      break label$16
     }
     HEAP32[($3_1 + 20 | 0) >> 2] = $4_1;
     HEAP32[($4_1 + 24 | 0) >> 2] = $3_1;
    }
    HEAP32[($0_1 + 4 | 0) >> 2] = $1_1 | 1 | 0;
    HEAP32[($0_1 + $1_1 | 0) >> 2] = $1_1;
    if (($0_1 | 0) != (HEAP32[(0 + 69292 | 0) >> 2] | 0 | 0)) {
     break label$15
    }
    HEAP32[(0 + 69280 | 0) >> 2] = $1_1;
    return;
   }
   label$31 : {
    if ($1_1 >>> 0 > 255 >>> 0) {
     break label$31
    }
    $3_1 = ($1_1 & -8 | 0) + 69312 | 0;
    label$32 : {
     label$33 : {
      $4_1 = HEAP32[(0 + 69272 | 0) >> 2] | 0;
      $1_1 = 1 << ($1_1 >>> 3 | 0) | 0;
      if ($4_1 & $1_1 | 0) {
       break label$33
      }
      HEAP32[(0 + 69272 | 0) >> 2] = $4_1 | $1_1 | 0;
      $1_1 = $3_1;
      break label$32;
     }
     $1_1 = HEAP32[($3_1 + 8 | 0) >> 2] | 0;
    }
    HEAP32[($3_1 + 8 | 0) >> 2] = $0_1;
    HEAP32[($1_1 + 12 | 0) >> 2] = $0_1;
    HEAP32[($0_1 + 12 | 0) >> 2] = $3_1;
    HEAP32[($0_1 + 8 | 0) >> 2] = $1_1;
    return;
   }
   $3_1 = 31;
   label$34 : {
    if ($1_1 >>> 0 > 16777215 >>> 0) {
     break label$34
    }
    $3_1 = Math_clz32($1_1 >>> 8 | 0);
    $3_1 = ((($1_1 >>> (38 - $3_1 | 0) | 0) & 1 | 0) - ($3_1 << 1 | 0) | 0) + 62 | 0;
   }
   HEAP32[($0_1 + 28 | 0) >> 2] = $3_1;
   HEAP32[($0_1 + 16 | 0) >> 2] = 0;
   HEAP32[($0_1 + 20 | 0) >> 2] = 0;
   $4_1 = ($3_1 << 2 | 0) + 69576 | 0;
   label$35 : {
    label$36 : {
     label$37 : {
      $5_1 = HEAP32[(0 + 69276 | 0) >> 2] | 0;
      $2_1 = 1 << $3_1 | 0;
      if ($5_1 & $2_1 | 0) {
       break label$37
      }
      HEAP32[(0 + 69276 | 0) >> 2] = $5_1 | $2_1 | 0;
      HEAP32[$4_1 >> 2] = $0_1;
      HEAP32[($0_1 + 24 | 0) >> 2] = $4_1;
      break label$36;
     }
     $3_1 = $1_1 << (($3_1 | 0) == (31 | 0) ? 0 : 25 - ($3_1 >>> 1 | 0) | 0) | 0;
     $5_1 = HEAP32[$4_1 >> 2] | 0;
     label$38 : while (1) {
      $4_1 = $5_1;
      if (((HEAP32[($4_1 + 4 | 0) >> 2] | 0) & -8 | 0 | 0) == ($1_1 | 0)) {
       break label$35
      }
      $5_1 = $3_1 >>> 29 | 0;
      $3_1 = $3_1 << 1 | 0;
      $2_1 = ($4_1 + ($5_1 & 4 | 0) | 0) + 16 | 0;
      $5_1 = HEAP32[$2_1 >> 2] | 0;
      if ($5_1) {
       continue label$38
      }
      break label$38;
     };
     HEAP32[$2_1 >> 2] = $0_1;
     HEAP32[($0_1 + 24 | 0) >> 2] = $4_1;
    }
    HEAP32[($0_1 + 12 | 0) >> 2] = $0_1;
    HEAP32[($0_1 + 8 | 0) >> 2] = $0_1;
    return;
   }
   $1_1 = HEAP32[($4_1 + 8 | 0) >> 2] | 0;
   HEAP32[($1_1 + 12 | 0) >> 2] = $0_1;
   HEAP32[($4_1 + 8 | 0) >> 2] = $0_1;
   HEAP32[($0_1 + 24 | 0) >> 2] = 0;
   HEAP32[($0_1 + 12 | 0) >> 2] = $4_1;
   HEAP32[($0_1 + 8 | 0) >> 2] = $1_1;
  }
 }
 
 function $85($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$5 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, i64toi32_i32$0 = 0, $10$hi = 0, $10_1 = 0, $6_1 = 0, $9$hi = 0, $7_1 = 0, $5_1 = 0, $9_1 = 0, $12$hi = 0, $12_1 = 0, i64toi32_i32$6 = 0, $8_1 = 0, $11_1 = 0, $11$hi = 0, $139 = 0, $140 = 0, $141 = 0, $142 = 0, $143 = 0, $144 = 0, $145 = 0, $146 = 0, $147 = 0, $148 = 0, $149 = 0, $150 = 0, $151 = 0, $152 = 0, $153 = 0, $154 = 0, $155 = 0, $156 = 0, $157 = 0, $158 = 0, $159 = 0, $20_1 = 0, $25_1 = 0, $30_1 = 0, $34_1 = 0, $40_1 = 0, $48_1 = 0, $50_1 = 0, $58_1 = 0, $58$hi = 0, $64_1 = 0, $64$hi = 0, $68_1 = 0, $68$hi = 0, $78_1 = 0, $78$hi = 0, $106_1 = 0, $109 = 0, $136 = 0, $137 = 0, $137$hi = 0, $138 = 0, $138$hi = 0, $145$hi = 0, $148$hi = 0, $168 = 0, $169 = 0, $169$hi = 0, $170 = 0, $170$hi = 0, $177$hi = 0, $180$hi = 0, $193 = 0, $193$hi = 0, $195$hi = 0, $199 = 0, $199$hi = 0, $201$hi = 0, $228 = 0, $228$hi = 0, $230 = 0, $230$hi = 0, $234 = 0, $234$hi = 0, $236 = 0, $237$hi = 0, $251 = 0, $251$hi = 0, $254 = 0, $254$hi = 0, $262$hi = 0, $265 = 0, $266$hi = 0, $271 = 0, $272 = 0, $272$hi = 0, $273 = 0, $273$hi = 0, $280$hi = 0, $283$hi = 0, $298 = 0, $298$hi = 0, $304 = 0, $305$hi = 0, $311 = 0, $311$hi = 0, $313$hi = 0, $314 = 0, $314$hi = 0, $316 = 0, $316$hi = 0, $343 = 0, $343$hi = 0, $345 = 0, $345$hi = 0, $349 = 0, $349$hi = 0, $351 = 0, $352$hi = 0, $358 = 0, $358$hi = 0, $360$hi = 0, $364 = 0, $364$hi = 0, $367 = 0, $367$hi = 0, $368$hi = 0, $377 = 0, $377$hi = 0, $381$hi = 0, $385 = 0, $386$hi = 0, $389 = 0, $389$hi = 0, $392 = 0, $392$hi = 0, $396 = 0, $397$hi = 0, $400 = 0, $400$hi = 0, $406 = 0, $407$hi = 0, $411 = 0, $412$hi = 0, $415 = 0, $415$hi = 0, $421 = 0, $422$hi = 0, $426 = 0, $427$hi = 0;
  $5_1 = global$0 - 112 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 2147483647;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $9_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $9$hi = i64toi32_i32$1;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$1 = $1$hi;
     $6_1 = !($1_1 | i64toi32_i32$1 | 0);
     $20_1 = $6_1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = 2147483647;
     i64toi32_i32$3 = -1;
     i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
     $10_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
     $10$hi = i64toi32_i32$2;
     i64toi32_i32$1 = $10_1;
     i64toi32_i32$0 = -2147418112;
     i64toi32_i32$3 = 0;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     i64toi32_i32$2 = i64toi32_i32$4;
     i64toi32_i32$1 = -2147418112;
     i64toi32_i32$3 = 0;
     $25_1 = i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$2 = $10$hi;
     if (!($10_1 | i64toi32_i32$2 | 0) ? $20_1 : $25_1) {
      break label$3
     }
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$1 = 0;
     $30_1 = (i64toi32_i32$3 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$5 | 0) | 0;
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$1 = $9_1;
     i64toi32_i32$2 = -2147418112;
     i64toi32_i32$5 = 0;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $11_1 = i64toi32_i32$0;
     $11$hi = i64toi32_i32$4;
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$1 = -2147418112;
     i64toi32_i32$5 = 0;
     $34_1 = i64toi32_i32$4 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$4;
     i64toi32_i32$3 = i64toi32_i32$4;
     i64toi32_i32$5 = i64toi32_i32$0;
     i64toi32_i32$4 = -2147418112;
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$5 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) | 0 ? $30_1 : $34_1) {
      break label$2
     }
    }
    label$4 : {
     i64toi32_i32$5 = $10$hi;
     i64toi32_i32$1 = $10_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$4 = 0;
     $40_1 = i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$1 = i64toi32_i32$5;
     i64toi32_i32$1 = i64toi32_i32$5;
     i64toi32_i32$4 = $10_1;
     i64toi32_i32$5 = 2147418112;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) | 0 ? $6_1 : $40_1) {
      break label$4
     }
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$1 = 32768;
     i64toi32_i32$5 = 0;
     i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     $4_1 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     $3_1 = $1_1;
     $3$hi = i64toi32_i32$1;
     break label$1;
    }
    label$5 : {
     i64toi32_i32$1 = $3$hi;
     $48_1 = !($3_1 | i64toi32_i32$1 | 0);
     i64toi32_i32$1 = $9$hi;
     i64toi32_i32$4 = $9_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$5 = 0;
     $50_1 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$5 = $9_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$5 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) | 0 ? $48_1 : $50_1) {
      break label$5
     }
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$4 = 32768;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
     $4_1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     $4$hi = i64toi32_i32$4;
     break label$1;
    }
    label$6 : {
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$4 = $10$hi;
     i64toi32_i32$5 = $10_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$1 = 0;
     i64toi32_i32$3 = i64toi32_i32$4 ^ i64toi32_i32$3 | 0;
     $58_1 = i64toi32_i32$5 ^ i64toi32_i32$1 | 0;
     $58$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$5 = $58$hi;
     i64toi32_i32$1 = $58_1;
     i64toi32_i32$5 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$3 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$5 | 0) != (i64toi32_i32$4 | 0) | 0) {
      break label$6
     }
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$1 = $3_1;
     i64toi32_i32$5 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$5 = i64toi32_i32$3 ^ i64toi32_i32$5 | 0;
     $64_1 = i64toi32_i32$1 ^ i64toi32_i32$4 | 0;
     $64$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$4 = $2_1;
     i64toi32_i32$1 = i64toi32_i32$5 ^ i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 ^ i64toi32_i32$4 | 0;
     i64toi32_i32$3 = -2147483648;
     i64toi32_i32$4 = 0;
     i64toi32_i32$3 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
     $68_1 = i64toi32_i32$5 ^ i64toi32_i32$4 | 0;
     $68$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $64$hi;
     i64toi32_i32$1 = $64_1;
     i64toi32_i32$5 = $68$hi;
     i64toi32_i32$4 = $68_1;
     i64toi32_i32$5 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
     $6_1 = !(i64toi32_i32$1 | i64toi32_i32$4 | 0 | i64toi32_i32$5 | 0);
     i64toi32_i32$2 = $6_1;
     i64toi32_i32$5 = 2147450880;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$4 = i64toi32_i32$2 ? 0 : $2_1;
     i64toi32_i32$3 = i64toi32_i32$2 ? i64toi32_i32$5 : i64toi32_i32$1;
     $4_1 = i64toi32_i32$4;
     $4$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$3 = 0;
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$5 = i64toi32_i32$2 ? 0 : $1_1;
     i64toi32_i32$2 = i64toi32_i32$2 ? i64toi32_i32$3 : i64toi32_i32$4;
     $3_1 = i64toi32_i32$5;
     $3$hi = i64toi32_i32$2;
     break label$1;
    }
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = $9$hi;
    i64toi32_i32$1 = $9_1;
    i64toi32_i32$5 = 2147418112;
    i64toi32_i32$3 = 0;
    i64toi32_i32$5 = i64toi32_i32$2 ^ i64toi32_i32$5 | 0;
    $78_1 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
    $78$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$2 = $3_1;
    i64toi32_i32$1 = $78$hi;
    i64toi32_i32$3 = $78_1;
    i64toi32_i32$1 = i64toi32_i32$5 | i64toi32_i32$1 | 0;
    if (!(i64toi32_i32$2 | i64toi32_i32$3 | 0 | i64toi32_i32$1 | 0)) {
     break label$1
    }
    label$7 : {
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $10$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$5 = $1_1;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$3 = $10_1;
     i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
     i64toi32_i32$5 = 0;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$5 | 0) | 0) {
      break label$7
     }
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $9$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$5 = $9_1;
     i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | 0) {
      break label$1
     }
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$5 = $3_1;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$3 = $1_1;
     i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
     $3_1 = i64toi32_i32$5 & i64toi32_i32$3 | 0;
     $3$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$1 = $4_1;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
     $4_1 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
     $4$hi = i64toi32_i32$5;
     break label$1;
    }
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$2 = $3_1;
    i64toi32_i32$1 = $9$hi;
    i64toi32_i32$3 = $9_1;
    i64toi32_i32$1 = i64toi32_i32$5 | i64toi32_i32$1 | 0;
    if (!!(i64toi32_i32$2 | i64toi32_i32$3 | 0 | i64toi32_i32$1 | 0)) {
     break label$2
    }
    i64toi32_i32$1 = $1$hi;
    $3_1 = $1_1;
    $3$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $2$hi;
    $4_1 = $2_1;
    $4$hi = i64toi32_i32$1;
    break label$1;
   }
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$5 = $3_1;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$3 = $1_1;
   $106_1 = i64toi32_i32$1 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0;
   i64toi32_i32$5 = $9$hi;
   i64toi32_i32$5 = $10$hi;
   i64toi32_i32$5 = $9$hi;
   i64toi32_i32$3 = $9_1;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$2 = $10_1;
   $109 = i64toi32_i32$5 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$5;
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$3 = i64toi32_i32$5;
   i64toi32_i32$2 = $9_1;
   i64toi32_i32$5 = i64toi32_i32$1;
   i64toi32_i32$1 = $10_1;
   $7_1 = (i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) | 0 ? $106_1 : $109;
   i64toi32_i32$4 = $7_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$5 = i64toi32_i32$4 ? $3_1 : $1_1;
   i64toi32_i32$1 = i64toi32_i32$4 ? i64toi32_i32$2 : i64toi32_i32$3;
   $9_1 = i64toi32_i32$5;
   $9$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$3 = i64toi32_i32$4;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$2 = i64toi32_i32$4 ? $4_1 : $2_1;
   i64toi32_i32$4 = i64toi32_i32$4 ? i64toi32_i32$1 : i64toi32_i32$5;
   $11_1 = i64toi32_i32$2;
   $11$hi = i64toi32_i32$4;
   i64toi32_i32$3 = i64toi32_i32$2;
   i64toi32_i32$2 = 65535;
   i64toi32_i32$1 = -1;
   i64toi32_i32$2 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
   $10_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $10$hi = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$5;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$5 = $7_1;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$3 = $4$hi;
   i64toi32_i32$1 = i64toi32_i32$5 ? $2_1 : $4_1;
   i64toi32_i32$4 = i64toi32_i32$5 ? i64toi32_i32$2 : i64toi32_i32$3;
   $12_1 = i64toi32_i32$1;
   $12$hi = i64toi32_i32$4;
   i64toi32_i32$5 = i64toi32_i32$1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$2 = 48;
   i64toi32_i32$3 = i64toi32_i32$2 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $139 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
    $139 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
   }
   $8_1 = $139 & 32767 | 0;
   label$8 : {
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$4 = $11_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$2 = 48;
    i64toi32_i32$3 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$5 = 0;
     $140 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
    } else {
     i64toi32_i32$5 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
     $140 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$3 | 0) | 0;
    }
    $6_1 = $140 & 32767 | 0;
    if ($6_1) {
     break label$8
    }
    $136 = $5_1 + 96 | 0;
    i64toi32_i32$5 = $9$hi;
    $137 = $9_1;
    $137$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $10$hi;
    $138 = $10_1;
    $138$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$5 = $10$hi;
    $6_1 = !($10_1 | i64toi32_i32$5 | 0);
    i64toi32_i32$3 = $6_1;
    i64toi32_i32$5 = $9$hi;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$2 = i64toi32_i32$3 ? $9_1 : $10_1;
    i64toi32_i32$1 = i64toi32_i32$3 ? i64toi32_i32$5 : i64toi32_i32$4;
    i64toi32_i32$5 = Math_clz32(i64toi32_i32$1);
    i64toi32_i32$3 = 0;
    if ((i64toi32_i32$5 | 0) == (32 | 0)) {
     $141 = Math_clz32(i64toi32_i32$2) + 32 | 0
    } else {
     $141 = i64toi32_i32$5
    }
    $145$hi = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    $148$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $145$hi;
    i64toi32_i32$2 = $141;
    i64toi32_i32$1 = $148$hi;
    i64toi32_i32$5 = $6_1 << 6 | 0;
    i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
    }
    $6_1 = i64toi32_i32$4;
    i64toi32_i32$0 = $137$hi;
    i64toi32_i32$2 = $138$hi;
    $86($136 | 0, $137 | 0, i64toi32_i32$0 | 0, $138 | 0, i64toi32_i32$2 | 0, i64toi32_i32$4 + -15 | 0 | 0);
    $6_1 = 16 - i64toi32_i32$4 | 0;
    i64toi32_i32$3 = $5_1 + 104 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$2;
    $10$hi = i64toi32_i32$0;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 96 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 100 | 0) >> 2] | 0;
    $9_1 = i64toi32_i32$0;
    $9$hi = i64toi32_i32$2;
   }
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$1 = $7_1;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$5 = i64toi32_i32$1 ? $1_1 : $3_1;
   i64toi32_i32$3 = i64toi32_i32$1 ? i64toi32_i32$2 : i64toi32_i32$0;
   $3_1 = i64toi32_i32$5;
   $3$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $12$hi;
   i64toi32_i32$1 = $12_1;
   i64toi32_i32$5 = 65535;
   i64toi32_i32$2 = -1;
   i64toi32_i32$5 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
   $1_1 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
   $1$hi = i64toi32_i32$5;
   label$9 : {
    if ($8_1) {
     break label$9
    }
    $168 = $5_1 + 80 | 0;
    i64toi32_i32$5 = $3$hi;
    $169 = $3_1;
    $169$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $1$hi;
    $170 = $1_1;
    $170$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $1$hi;
    $7_1 = !($1_1 | i64toi32_i32$5 | 0);
    i64toi32_i32$0 = $7_1;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$2 = i64toi32_i32$0 ? $3_1 : $1_1;
    i64toi32_i32$3 = i64toi32_i32$0 ? i64toi32_i32$5 : i64toi32_i32$1;
    i64toi32_i32$5 = Math_clz32(i64toi32_i32$3);
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$5 | 0) == (32 | 0)) {
     $142 = Math_clz32(i64toi32_i32$2) + 32 | 0
    } else {
     $142 = i64toi32_i32$5
    }
    $177$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $180$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $177$hi;
    i64toi32_i32$2 = $142;
    i64toi32_i32$3 = $180$hi;
    i64toi32_i32$5 = $7_1 << 6 | 0;
    i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $7_1 = i64toi32_i32$1;
    i64toi32_i32$4 = $169$hi;
    i64toi32_i32$2 = $170$hi;
    $86($168 | 0, $169 | 0, i64toi32_i32$4 | 0, $170 | 0, i64toi32_i32$2 | 0, i64toi32_i32$1 + -15 | 0 | 0);
    $8_1 = 16 - i64toi32_i32$1 | 0;
    i64toi32_i32$0 = $5_1 + 88 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
    $1_1 = i64toi32_i32$2;
    $1$hi = i64toi32_i32$4;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 80 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 84 | 0) >> 2] | 0;
    $3_1 = i64toi32_i32$4;
    $3$hi = i64toi32_i32$2;
   }
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$4 = 0;
   i64toi32_i32$5 = 3;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
    $143 = 0;
   } else {
    i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$3 | 0) | 0;
    $143 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
   }
   $193 = $143;
   $193$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $3$hi;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 61;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $144 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
    $144 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$3 | 0) | 0;
   }
   $195$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $193$hi;
   i64toi32_i32$4 = $193;
   i64toi32_i32$2 = $195$hi;
   i64toi32_i32$5 = $144;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
   i64toi32_i32$4 = 524288;
   i64toi32_i32$5 = 0;
   i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
   $1_1 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
   $1$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $10$hi;
   i64toi32_i32$2 = $10_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 3;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $145 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$3 | 0) | 0;
    $145 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
   }
   $199 = $145;
   $199$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $9$hi;
   i64toi32_i32$4 = $9_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$5 = 61;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $146 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
    $146 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$3 | 0) | 0;
   }
   $201$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $199$hi;
   i64toi32_i32$0 = $199;
   i64toi32_i32$4 = $201$hi;
   i64toi32_i32$5 = $146;
   i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
   $12_1 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
   $12$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $3$hi;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 3;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $147 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$3 | 0) | 0;
    $147 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
   }
   $10_1 = $147;
   $10$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$4 = $4_1;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$5 = $2_1;
   i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
   $3_1 = i64toi32_i32$4 ^ i64toi32_i32$5 | 0;
   $3$hi = i64toi32_i32$2;
   label$10 : {
    if (($6_1 | 0) == ($8_1 | 0)) {
     break label$10
    }
    label$11 : {
     $7_1 = $6_1 - $8_1 | 0;
     if ($7_1 >>> 0 <= 127 >>> 0) {
      break label$11
     }
     i64toi32_i32$2 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$2;
     i64toi32_i32$2 = 0;
     $10_1 = 1;
     $10$hi = i64toi32_i32$2;
     break label$10;
    }
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$4 = $1$hi;
    $86($5_1 + 64 | 0 | 0, $10_1 | 0, i64toi32_i32$2 | 0, $1_1 | 0, i64toi32_i32$4 | 0, 128 - $7_1 | 0 | 0);
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$4 = i64toi32_i32$2;
    i64toi32_i32$2 = $1$hi;
    $96($5_1 + 48 | 0 | 0, $10_1 | 0, i64toi32_i32$4 | 0, $1_1 | 0, i64toi32_i32$2 | 0, $7_1 | 0);
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 48 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 52 | 0) >> 2] | 0;
    $228 = i64toi32_i32$2;
    $228$hi = i64toi32_i32$4;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 64 | 0) >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 68 | 0) >> 2] | 0;
    $230 = i64toi32_i32$4;
    $230$hi = i64toi32_i32$2;
    i64toi32_i32$0 = (i64toi32_i32$0 + 64 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
    $234 = i64toi32_i32$2;
    $234$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $230$hi;
    i64toi32_i32$0 = $230;
    i64toi32_i32$2 = $234$hi;
    i64toi32_i32$5 = $234;
    i64toi32_i32$2 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 | i64toi32_i32$5 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = 0;
    $236 = (i64toi32_i32$4 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$0 | 0) | 0;
    i64toi32_i32$4 = 0;
    $237$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $228$hi;
    i64toi32_i32$5 = $228;
    i64toi32_i32$2 = $237$hi;
    i64toi32_i32$0 = $236;
    i64toi32_i32$2 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
    $10_1 = i64toi32_i32$5 | i64toi32_i32$0 | 0;
    $10$hi = i64toi32_i32$2;
    i64toi32_i32$4 = ($5_1 + 48 | 0) + 8 | 0;
    i64toi32_i32$2 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $1_1 = i64toi32_i32$2;
    $1$hi = i64toi32_i32$5;
   }
   i64toi32_i32$5 = $12$hi;
   i64toi32_i32$4 = $12_1;
   i64toi32_i32$2 = 524288;
   i64toi32_i32$0 = 0;
   i64toi32_i32$2 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
   $12_1 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
   $12$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $9$hi;
   i64toi32_i32$5 = $9_1;
   i64toi32_i32$4 = 0;
   i64toi32_i32$0 = 3;
   i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$5 << i64toi32_i32$3 | 0;
    $148 = 0;
   } else {
    i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$3 | 0) | 0;
    $148 = i64toi32_i32$5 << i64toi32_i32$3 | 0;
   }
   $9_1 = $148;
   $9$hi = i64toi32_i32$4;
   label$12 : {
    label$13 : {
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$2 = $3_1;
     i64toi32_i32$5 = -1;
     i64toi32_i32$0 = -1;
     if ((i64toi32_i32$4 | 0) > (i64toi32_i32$5 | 0)) {
      $149 = 1
     } else {
      if ((i64toi32_i32$4 | 0) >= (i64toi32_i32$5 | 0)) {
       if (i64toi32_i32$2 >>> 0 <= i64toi32_i32$0 >>> 0) {
        $150 = 0
       } else {
        $150 = 1
       }
       $151 = $150;
      } else {
       $151 = 0
      }
      $149 = $151;
     }
     if ($149) {
      break label$13
     }
     i64toi32_i32$2 = 0;
     $3_1 = 0;
     $3$hi = i64toi32_i32$2;
     i64toi32_i32$2 = 0;
     $4_1 = 0;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$0 = $9_1;
     i64toi32_i32$4 = $10$hi;
     i64toi32_i32$5 = $10_1;
     i64toi32_i32$4 = i64toi32_i32$2 ^ i64toi32_i32$4 | 0;
     $251 = i64toi32_i32$0 ^ i64toi32_i32$5 | 0;
     $251$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $12$hi;
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$4 = $12$hi;
     i64toi32_i32$2 = $12_1;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$5 = $1_1;
     i64toi32_i32$0 = i64toi32_i32$4 ^ i64toi32_i32$0 | 0;
     $254 = i64toi32_i32$2 ^ i64toi32_i32$5 | 0;
     $254$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $251$hi;
     i64toi32_i32$4 = $251;
     i64toi32_i32$2 = $254$hi;
     i64toi32_i32$5 = $254;
     i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     if (!(i64toi32_i32$4 | i64toi32_i32$5 | 0 | i64toi32_i32$2 | 0)) {
      break label$1
     }
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = $9$hi;
     i64toi32_i32$0 = $9_1;
     i64toi32_i32$4 = $10$hi;
     i64toi32_i32$5 = $10_1;
     i64toi32_i32$3 = i64toi32_i32$0 - i64toi32_i32$5 | 0;
     i64toi32_i32$6 = i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0;
     i64toi32_i32$1 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$2 - i64toi32_i32$1 | 0;
     $2_1 = i64toi32_i32$3;
     $2$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $12$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $12$hi;
     i64toi32_i32$2 = $12_1;
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$5 = $1_1;
     i64toi32_i32$4 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
     i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0;
     i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$0 | 0;
     i64toi32_i32$3 = i64toi32_i32$1 - i64toi32_i32$3 | 0;
     $262$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = $9$hi;
     i64toi32_i32$1 = $9_1;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$5 = $10_1;
     $265 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$1 = 0;
     $266$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $262$hi;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$3 = $266$hi;
     i64toi32_i32$2 = $265;
     i64toi32_i32$0 = i64toi32_i32$5 - i64toi32_i32$2 | 0;
     i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0;
     i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$3 | 0;
     i64toi32_i32$4 = i64toi32_i32$1 - i64toi32_i32$4 | 0;
     $4_1 = i64toi32_i32$0;
     $4$hi = i64toi32_i32$4;
     i64toi32_i32$1 = i64toi32_i32$0;
     i64toi32_i32$5 = 524287;
     i64toi32_i32$2 = -1;
     if (i64toi32_i32$4 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0) {
      break label$12
     }
     $271 = $5_1 + 32 | 0;
     i64toi32_i32$1 = $2$hi;
     $272 = $2_1;
     $272$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$4;
     $273 = i64toi32_i32$0;
     $273$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = i64toi32_i32$4;
     $7_1 = !(i64toi32_i32$0 | i64toi32_i32$1 | 0);
     i64toi32_i32$3 = $7_1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$5 = i64toi32_i32$3 ? $2_1 : i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$3 ? i64toi32_i32$1 : i64toi32_i32$4;
     i64toi32_i32$1 = Math_clz32(i64toi32_i32$2);
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) == (32 | 0)) {
      $152 = Math_clz32(i64toi32_i32$5) + 32 | 0
     } else {
      $152 = i64toi32_i32$1
     }
     $280$hi = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     $283$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $280$hi;
     i64toi32_i32$5 = $152;
     i64toi32_i32$2 = $283$hi;
     i64toi32_i32$1 = $7_1 << 6 | 0;
     i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $7_1 = i64toi32_i32$4 + -12 | 0;
     i64toi32_i32$0 = $272$hi;
     i64toi32_i32$5 = $273$hi;
     $86($271 | 0, $272 | 0, i64toi32_i32$0 | 0, $273 | 0, i64toi32_i32$5 | 0, $7_1 | 0);
     $6_1 = $6_1 - $7_1 | 0;
     i64toi32_i32$3 = $5_1 + 40 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$3 >> 2] | 0;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
     $4_1 = i64toi32_i32$5;
     $4$hi = i64toi32_i32$0;
     i64toi32_i32$3 = $5_1;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 32 | 0) >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 36 | 0) >> 2] | 0;
     $2_1 = i64toi32_i32$0;
     $2$hi = i64toi32_i32$5;
     break label$12;
    }
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$5 = $12$hi;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$0 = $12$hi;
    i64toi32_i32$1 = $12_1;
    i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
    i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $298 = i64toi32_i32$2;
    $298$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$4 = $9$hi;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$5 = $10_1;
    i64toi32_i32$3 = $9$hi;
    i64toi32_i32$1 = $9_1;
    i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
    i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
    }
    $2_1 = i64toi32_i32$0;
    $2$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$4 = i64toi32_i32$0;
    i64toi32_i32$5 = $10$hi;
    i64toi32_i32$1 = $10_1;
    $304 = i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
    i64toi32_i32$4 = 0;
    $305$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $298$hi;
    i64toi32_i32$1 = $298;
    i64toi32_i32$2 = $305$hi;
    i64toi32_i32$5 = $304;
    i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
    i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
    }
    $4_1 = i64toi32_i32$3;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$4 = i64toi32_i32$3;
    i64toi32_i32$1 = 1048576;
    i64toi32_i32$5 = 0;
    i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    if (!(i64toi32_i32$4 & i64toi32_i32$5 | 0 | i64toi32_i32$1 | 0)) {
     break label$12
    }
    i64toi32_i32$1 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = 0;
     $153 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$4 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
     $153 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$2 | 0) | 0;
    }
    $311 = $153;
    $311$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = 63;
    i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
     $154 = 0;
    } else {
     i64toi32_i32$0 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$2 | 0) | 0;
     $154 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
    }
    $313$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $311$hi;
    i64toi32_i32$4 = $311;
    i64toi32_i32$1 = $313$hi;
    i64toi32_i32$5 = $154;
    i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $314 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
    $314$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $10$hi;
    i64toi32_i32$0 = $10_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$4 = i64toi32_i32$1 & i64toi32_i32$4 | 0;
    $316 = i64toi32_i32$0 & i64toi32_i32$5 | 0;
    $316$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $314$hi;
    i64toi32_i32$1 = $314;
    i64toi32_i32$0 = $316$hi;
    i64toi32_i32$5 = $316;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
    $2_1 = i64toi32_i32$1 | i64toi32_i32$5 | 0;
    $2$hi = i64toi32_i32$0;
    $6_1 = $6_1 + 1 | 0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$4 = $4_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $155 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
     $155 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$2 | 0) | 0;
    }
    $4_1 = $155;
    $4$hi = i64toi32_i32$1;
   }
   i64toi32_i32$1 = $11$hi;
   i64toi32_i32$0 = $11_1;
   i64toi32_i32$4 = -2147483648;
   i64toi32_i32$5 = 0;
   i64toi32_i32$4 = i64toi32_i32$1 & i64toi32_i32$4 | 0;
   $10_1 = i64toi32_i32$0 & i64toi32_i32$5 | 0;
   $10$hi = i64toi32_i32$4;
   label$14 : {
    if (($6_1 | 0) < (32767 | 0)) {
     break label$14
    }
    i64toi32_i32$1 = $10_1;
    i64toi32_i32$0 = 2147418112;
    i64toi32_i32$5 = 0;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
    $4_1 = i64toi32_i32$1 | i64toi32_i32$5 | 0;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $3_1 = 0;
    $3$hi = i64toi32_i32$0;
    break label$1;
   }
   $7_1 = 0;
   label$15 : {
    label$16 : {
     if (($6_1 | 0) <= (0 | 0)) {
      break label$16
     }
     $7_1 = $6_1;
     break label$15;
    }
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$1 = $4$hi;
    $86($5_1 + 16 | 0 | 0, $2_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$1 | 0, $6_1 + 127 | 0 | 0);
    i64toi32_i32$1 = i64toi32_i32$0;
    i64toi32_i32$1 = $4$hi;
    i64toi32_i32$1 = i64toi32_i32$0;
    i64toi32_i32$0 = $4$hi;
    $96($5_1 | 0, $2_1 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$0 | 0, 1 - $6_1 | 0 | 0);
    i64toi32_i32$4 = $5_1;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $343 = i64toi32_i32$0;
    $343$hi = i64toi32_i32$1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 16 | 0) >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 20 | 0) >> 2] | 0;
    $345 = i64toi32_i32$1;
    $345$hi = i64toi32_i32$0;
    i64toi32_i32$4 = (i64toi32_i32$4 + 16 | 0) + 8 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $349 = i64toi32_i32$0;
    $349$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $345$hi;
    i64toi32_i32$4 = $345;
    i64toi32_i32$0 = $349$hi;
    i64toi32_i32$5 = $349;
    i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
    i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 0;
    $351 = (i64toi32_i32$1 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$4 | 0) | 0;
    i64toi32_i32$1 = 0;
    $352$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $343$hi;
    i64toi32_i32$5 = $343;
    i64toi32_i32$0 = $352$hi;
    i64toi32_i32$4 = $351;
    i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
    $2_1 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
    $2$hi = i64toi32_i32$0;
    i64toi32_i32$1 = $5_1 + 8 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$1 >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$0;
    $4$hi = i64toi32_i32$5;
   }
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 3;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $156 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
    $156 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$2 | 0) | 0;
   }
   $358 = $156;
   $358$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$5 = $4_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 61;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
    $157 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$2 | 0) | 0;
    $157 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
   }
   $360$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $358$hi;
   i64toi32_i32$0 = $358;
   i64toi32_i32$5 = $360$hi;
   i64toi32_i32$4 = $157;
   i64toi32_i32$5 = i64toi32_i32$1 | i64toi32_i32$5 | 0;
   $3_1 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
   $3$hi = i64toi32_i32$5;
   i64toi32_i32$5 = 0;
   i64toi32_i32$1 = $7_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 48;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
    $158 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$2 | 0) | 0;
    $158 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
   }
   $364 = $158;
   $364$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$5 = $4_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 3;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $159 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
    $159 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$2 | 0) | 0;
   }
   i64toi32_i32$0 = $159;
   i64toi32_i32$5 = 65535;
   i64toi32_i32$4 = -1;
   i64toi32_i32$5 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
   $367 = i64toi32_i32$0 & i64toi32_i32$4 | 0;
   $367$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $364$hi;
   i64toi32_i32$1 = $364;
   i64toi32_i32$0 = $367$hi;
   i64toi32_i32$4 = $367;
   i64toi32_i32$0 = i64toi32_i32$5 | i64toi32_i32$0 | 0;
   $368$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $10$hi;
   i64toi32_i32$0 = $368$hi;
   i64toi32_i32$5 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$4 = $10_1;
   i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $4_1 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
   $4$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $2$hi;
   $6_1 = $2_1 & 7 | 0;
   label$17 : {
    label$18 : {
     label$19 : {
      switch ($94() | 0 | 0) {
      case 0:
       label$22 : {
        if (($6_1 | 0) == (4 | 0)) {
         break label$22
        }
        i64toi32_i32$1 = $4$hi;
        $377 = $4_1;
        $377$hi = i64toi32_i32$1;
        i64toi32_i32$1 = $3$hi;
        i64toi32_i32$1 = 0;
        $381$hi = i64toi32_i32$1;
        i64toi32_i32$1 = $3$hi;
        i64toi32_i32$0 = $3_1;
        i64toi32_i32$5 = $381$hi;
        i64toi32_i32$4 = $6_1 >>> 0 > 4 >>> 0;
        i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
        i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
        if (i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0) {
         i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
        }
        $10_1 = i64toi32_i32$2;
        $10$hi = i64toi32_i32$3;
        i64toi32_i32$3 = $3$hi;
        i64toi32_i32$3 = $10$hi;
        i64toi32_i32$1 = i64toi32_i32$2;
        i64toi32_i32$0 = $3$hi;
        i64toi32_i32$4 = $3_1;
        $385 = i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
        i64toi32_i32$1 = 0;
        $386$hi = i64toi32_i32$1;
        i64toi32_i32$1 = $377$hi;
        i64toi32_i32$4 = $377;
        i64toi32_i32$3 = $386$hi;
        i64toi32_i32$0 = $385;
        i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
        i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
        if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) {
         i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
        }
        $4_1 = i64toi32_i32$5;
        $4$hi = i64toi32_i32$2;
        i64toi32_i32$2 = $10$hi;
        $3_1 = $10_1;
        $3$hi = i64toi32_i32$2;
        break label$18;
       }
       i64toi32_i32$2 = $4$hi;
       $389 = $4_1;
       $389$hi = i64toi32_i32$2;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$1 = $3_1;
       i64toi32_i32$4 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$4 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
       $392 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
       $392$hi = i64toi32_i32$4;
       i64toi32_i32$4 = i64toi32_i32$2;
       i64toi32_i32$2 = i64toi32_i32$1;
       i64toi32_i32$1 = $392$hi;
       i64toi32_i32$0 = $392;
       i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
       i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
       if (i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0) {
        i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
       }
       $10_1 = i64toi32_i32$3;
       $10$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $3$hi;
       i64toi32_i32$5 = $10$hi;
       i64toi32_i32$4 = i64toi32_i32$3;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$0 = $3_1;
       $396 = i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
       i64toi32_i32$4 = 0;
       $397$hi = i64toi32_i32$4;
       i64toi32_i32$4 = $389$hi;
       i64toi32_i32$0 = $389;
       i64toi32_i32$5 = $397$hi;
       i64toi32_i32$2 = $396;
       i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
       i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
       if (i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0) {
        i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
       }
       $4_1 = i64toi32_i32$1;
       $4$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $10$hi;
       $3_1 = $10_1;
       $3$hi = i64toi32_i32$3;
       break label$17;
      case 1:
       i64toi32_i32$3 = $4$hi;
       $400 = $4_1;
       $400$hi = i64toi32_i32$3;
       i64toi32_i32$3 = $3$hi;
       i64toi32_i32$3 = $10$hi;
       i64toi32_i32$4 = $10_1;
       i64toi32_i32$0 = 0;
       i64toi32_i32$2 = 0;
       $406 = ((i64toi32_i32$4 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0) & ($6_1 | 0) != (0 | 0) | 0;
       i64toi32_i32$4 = 0;
       $407$hi = i64toi32_i32$4;
       i64toi32_i32$4 = $3$hi;
       i64toi32_i32$2 = $3_1;
       i64toi32_i32$3 = $407$hi;
       i64toi32_i32$0 = $406;
       i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
       i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
       if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) {
        i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
       }
       $10_1 = i64toi32_i32$5;
       $10$hi = i64toi32_i32$1;
       i64toi32_i32$1 = $3$hi;
       i64toi32_i32$1 = $10$hi;
       i64toi32_i32$4 = i64toi32_i32$5;
       i64toi32_i32$2 = $3$hi;
       i64toi32_i32$0 = $3_1;
       $411 = i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
       i64toi32_i32$4 = 0;
       $412$hi = i64toi32_i32$4;
       i64toi32_i32$4 = $400$hi;
       i64toi32_i32$0 = $400;
       i64toi32_i32$1 = $412$hi;
       i64toi32_i32$2 = $411;
       i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
       i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
       if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
        i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
       }
       $4_1 = i64toi32_i32$3;
       $4$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $10$hi;
       $3_1 = $10_1;
       $3$hi = i64toi32_i32$5;
       break label$18;
      case 2:
       break label$19;
      default:
       break label$18;
      };
     }
     i64toi32_i32$5 = $4$hi;
     $415 = $4_1;
     $415$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$5 = $10$hi;
     $421 = !($10_1 | i64toi32_i32$5 | 0) & ($6_1 | 0) != (0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $422$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$4 = $3_1;
     i64toi32_i32$0 = $422$hi;
     i64toi32_i32$2 = $421;
     i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $10_1 = i64toi32_i32$1;
     $10$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$5 = i64toi32_i32$1;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$2 = $3_1;
     $426 = i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $427$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $415$hi;
     i64toi32_i32$2 = $415;
     i64toi32_i32$3 = $427$hi;
     i64toi32_i32$4 = $426;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $4_1 = i64toi32_i32$0;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $10$hi;
     $3_1 = $10_1;
     $3$hi = i64toi32_i32$1;
    }
    if (!$6_1) {
     break label$1
    }
   }
   $95() | 0;
  }
  i64toi32_i32$1 = $3$hi;
  i64toi32_i32$2 = $0_1;
  HEAP32[i64toi32_i32$2 >> 2] = $3_1;
  HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] = $4_1;
  HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] = i64toi32_i32$1;
  global$0 = $5_1 + 112 | 0;
 }
 
 function $86($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$4 = 0, i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$3 = 0, $4$hi = 0, $18_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $11$hi = 0, $18$hi = 0, $19_1 = 0, $19$hi = 0, $4_1 = 0, $24$hi = 0;
  label$1 : {
   label$2 : {
    if (!($3_1 & 64 | 0)) {
     break label$2
    }
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = 0;
    $11$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$3 = $3_1 + -64 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
     $18_1 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
     $18_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
    }
    $2_1 = $18_1;
    $2$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $1_1 = 0;
    $1$hi = i64toi32_i32$1;
    break label$1;
   }
   if (!$3_1) {
    break label$1
   }
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = 0;
   $18$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = $18$hi;
   i64toi32_i32$3 = 64 - $3_1 | 0;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $20_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
    $20_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
   }
   $19_1 = $20_1;
   $19$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = 0;
   $4_1 = $3_1;
   $4$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$3 = $3_1;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
    $21_1 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
    $21_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
   }
   $24$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $19$hi;
   i64toi32_i32$2 = $19_1;
   i64toi32_i32$1 = $24$hi;
   i64toi32_i32$3 = $21_1;
   i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $2_1 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   $2$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$3 = $4_1;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    $22_1 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
    $22_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   }
   $1_1 = $22_1;
   $1$hi = i64toi32_i32$2;
  }
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$0 = $0_1;
  HEAP32[i64toi32_i32$0 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$2;
  i64toi32_i32$2 = $2$hi;
  HEAP32[(i64toi32_i32$0 + 8 | 0) >> 2] = $2_1;
  HEAP32[(i64toi32_i32$0 + 12 | 0) >> 2] = i64toi32_i32$2;
 }
 
 function $87($0_1, $0$hi, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, $4_1 = 0, $5_1 = 0, $6_1 = 0, $5$hi = 0, $6$hi = 0, $35_1 = 0, $36_1 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $41_1 = 0, $42_1 = 0, $43_1 = 0, $44_1 = 0, $8_1 = 0, $12_1 = 0, $17_1 = 0, $21_1 = 0, $27_1 = 0, $27$hi = 0, $30_1 = 0, $30$hi = 0, $40_1 = 0, $50_1 = 0, $50$hi = 0, $53_1 = 0, $53$hi = 0, $58_1 = 0, $68_1 = 0, $68$hi = 0, $71_1 = 0, $71$hi = 0;
  $4_1 = 1;
  label$1 : {
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 0;
   $8_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | 0;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = 2147483647;
   i64toi32_i32$1 = -1;
   i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
   $5_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$2 = $5_1;
   i64toi32_i32$3 = 2147418112;
   i64toi32_i32$1 = 0;
   $12_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$1 = $5_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$3 = 0;
   if ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0 ? $8_1 : $12_1) {
    break label$1
   }
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 0;
   $17_1 = (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$1 = 2147483647;
   i64toi32_i32$2 = -1;
   i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $6_1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
   $6$hi = i64toi32_i32$1;
   i64toi32_i32$3 = $6_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$2 = 0;
   $21_1 = i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$2 = $6_1;
   i64toi32_i32$1 = 2147418112;
   i64toi32_i32$0 = 0;
   if ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) | 0 ? $17_1 : $21_1) {
    break label$1
   }
   label$2 : {
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
    $27_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $27$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$3 = $5$hi;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$2 = $6_1;
    i64toi32_i32$0 = $5$hi;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $30_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    $30$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $27$hi;
    i64toi32_i32$3 = $27_1;
    i64toi32_i32$2 = $30$hi;
    i64toi32_i32$1 = $30_1;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    if (!!(i64toi32_i32$3 | i64toi32_i32$1 | 0 | i64toi32_i32$2 | 0)) {
     break label$2
    }
    return 0 | 0;
   }
   label$3 : {
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$0 = $3_1;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$1 = $1_1;
    i64toi32_i32$3 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 0;
    if ((i64toi32_i32$3 | 0) < (i64toi32_i32$0 | 0)) {
     $35_1 = 1
    } else {
     if ((i64toi32_i32$3 | 0) <= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$1 >>> 0) {
       $36_1 = 0
      } else {
       $36_1 = 1
      }
      $37_1 = $36_1;
     } else {
      $37_1 = 0
     }
     $35_1 = $37_1;
    }
    if ($35_1) {
     break label$3
    }
    $4_1 = -1;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$0 = $2_1;
    $40_1 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$3 = $3_1;
    if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) {
     $38_1 = 1
    } else {
     if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
      if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$3 >>> 0) {
       $39_1 = 0
      } else {
       $39_1 = 1
      }
      $41_1 = $39_1;
     } else {
      $41_1 = 0
     }
     $38_1 = $41_1;
    }
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$2 = $3_1;
    if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0 ? $40_1 : $38_1) {
     break label$1
    }
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$1 = $2_1;
    i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
    $50_1 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
    $50$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
    $53_1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
    $53$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $50$hi;
    i64toi32_i32$0 = $50_1;
    i64toi32_i32$3 = $53$hi;
    i64toi32_i32$1 = $53_1;
    i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 0;
    return (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0 | 0;
   }
   $4_1 = -1;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$1 = $0_1;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$0 = $2_1;
   $58_1 = i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$3 = $3_1;
   if ((i64toi32_i32$1 | 0) > (i64toi32_i32$2 | 0)) {
    $42_1 = 1
   } else {
    if ((i64toi32_i32$1 | 0) >= (i64toi32_i32$2 | 0)) {
     if (i64toi32_i32$0 >>> 0 <= i64toi32_i32$3 >>> 0) {
      $43_1 = 0
     } else {
      $43_1 = 1
     }
     $44_1 = $43_1;
    } else {
     $44_1 = 0
    }
    $42_1 = $44_1;
   }
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$2 = $3_1;
   if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0 ? $58_1 : $42_1) {
    break label$1
   }
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
   $68_1 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
   $68$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$1 = $3_1;
   i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
   $71_1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
   $71$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $68$hi;
   i64toi32_i32$0 = $68_1;
   i64toi32_i32$3 = $71$hi;
   i64toi32_i32$1 = $71_1;
   i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 0;
   $4_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0;
  }
  return $4_1 | 0;
 }
 
 function $88($0_1, $0$hi, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, $5_1 = 0, $6_1 = 0, $4_1 = 0, $5$hi = 0, $6$hi = 0, $35_1 = 0, $36_1 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $41_1 = 0, $42_1 = 0, $43_1 = 0, $44_1 = 0, $8_1 = 0, $12_1 = 0, $17_1 = 0, $21_1 = 0, $27_1 = 0, $27$hi = 0, $30_1 = 0, $30$hi = 0, $40_1 = 0, $50_1 = 0, $50$hi = 0, $53_1 = 0, $53$hi = 0, $58_1 = 0, $68_1 = 0, $68$hi = 0, $71_1 = 0, $71$hi = 0;
  $4_1 = -1;
  label$1 : {
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 0;
   $8_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$1 | 0) | 0;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = 2147483647;
   i64toi32_i32$1 = -1;
   i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
   $5_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$2 = $5_1;
   i64toi32_i32$3 = 2147418112;
   i64toi32_i32$1 = 0;
   $12_1 = i64toi32_i32$0 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$1 = $5_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$3 = 0;
   if ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) | 0 ? $8_1 : $12_1) {
    break label$1
   }
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 0;
   $17_1 = (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$1 = 2147483647;
   i64toi32_i32$2 = -1;
   i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $6_1 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
   $6$hi = i64toi32_i32$1;
   i64toi32_i32$3 = $6_1;
   i64toi32_i32$0 = 2147418112;
   i64toi32_i32$2 = 0;
   $21_1 = i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$2 = $6_1;
   i64toi32_i32$1 = 2147418112;
   i64toi32_i32$0 = 0;
   if ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) | 0 ? $17_1 : $21_1) {
    break label$1
   }
   label$2 : {
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
    $27_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $27$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$3 = $5$hi;
    i64toi32_i32$3 = $6$hi;
    i64toi32_i32$2 = $6_1;
    i64toi32_i32$0 = $5$hi;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $30_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    $30$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $27$hi;
    i64toi32_i32$3 = $27_1;
    i64toi32_i32$2 = $30$hi;
    i64toi32_i32$1 = $30_1;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    if (!!(i64toi32_i32$3 | i64toi32_i32$1 | 0 | i64toi32_i32$2 | 0)) {
     break label$2
    }
    return 0 | 0;
   }
   label$3 : {
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$0 = $3_1;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$1 = $1_1;
    i64toi32_i32$3 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 0;
    if ((i64toi32_i32$3 | 0) < (i64toi32_i32$0 | 0)) {
     $35_1 = 1
    } else {
     if ((i64toi32_i32$3 | 0) <= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$2 >>> 0 >= i64toi32_i32$1 >>> 0) {
       $36_1 = 0
      } else {
       $36_1 = 1
      }
      $37_1 = $36_1;
     } else {
      $37_1 = 0
     }
     $35_1 = $37_1;
    }
    if ($35_1) {
     break label$3
    }
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$0 = $2_1;
    $40_1 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$3 = $3_1;
    if ((i64toi32_i32$1 | 0) < (i64toi32_i32$2 | 0)) {
     $38_1 = 1
    } else {
     if ((i64toi32_i32$1 | 0) <= (i64toi32_i32$2 | 0)) {
      if (i64toi32_i32$0 >>> 0 >= i64toi32_i32$3 >>> 0) {
       $39_1 = 0
      } else {
       $39_1 = 1
      }
      $41_1 = $39_1;
     } else {
      $41_1 = 0
     }
     $38_1 = $41_1;
    }
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$1 = $3$hi;
    i64toi32_i32$2 = $3_1;
    if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0 ? $40_1 : $38_1) {
     break label$1
    }
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$3 = $0$hi;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$1 = $2_1;
    i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
    $50_1 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
    $50$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
    $53_1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
    $53$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $50$hi;
    i64toi32_i32$0 = $50_1;
    i64toi32_i32$3 = $53$hi;
    i64toi32_i32$1 = $53_1;
    i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    i64toi32_i32$0 = 0;
    i64toi32_i32$1 = 0;
    return (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0 | 0;
   }
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$1 = $0_1;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$0 = $2_1;
   $58_1 = i64toi32_i32$2 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$3 = $3_1;
   if ((i64toi32_i32$1 | 0) > (i64toi32_i32$2 | 0)) {
    $42_1 = 1
   } else {
    if ((i64toi32_i32$1 | 0) >= (i64toi32_i32$2 | 0)) {
     if (i64toi32_i32$0 >>> 0 <= i64toi32_i32$3 >>> 0) {
      $43_1 = 0
     } else {
      $43_1 = 1
     }
     $44_1 = $43_1;
    } else {
     $44_1 = 0
    }
    $42_1 = $44_1;
   }
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$2 = $3_1;
   if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0 ? $58_1 : $42_1) {
    break label$1
   }
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$2 = $0_1;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$0 = i64toi32_i32$3 ^ i64toi32_i32$0 | 0;
   $68_1 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
   $68$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$2 = $3$hi;
   i64toi32_i32$1 = $3_1;
   i64toi32_i32$2 = i64toi32_i32$0 ^ i64toi32_i32$2 | 0;
   $71_1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
   $71$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $68$hi;
   i64toi32_i32$0 = $68_1;
   i64toi32_i32$3 = $71$hi;
   i64toi32_i32$1 = $71_1;
   i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 0;
   $4_1 = (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0;
  }
  return $4_1 | 0;
 }
 
 function $89($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$3 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$4 = 0, $5_1 = 0, $11$hi = 0, i64toi32_i32$6 = 0, $11_1 = 0, $10$hi = 0, $13$hi = 0, $10_1 = 0, $16$hi = 0, $12$hi = 0, $13_1 = 0, $17$hi = 0, $21$hi = 0, $12_1 = 0, $6_1 = 0, $16_1 = 0, $21_1 = 0, $14$hi = 0, $15$hi = 0, $8_1 = 0, $17_1 = 0, $18$hi = 0, $14_1 = 0, $15_1 = 0, $18_1 = 0, $22_1 = 0, $22$hi = 0, $24$hi = 0, $9_1 = 0, $19_1 = 0, $19$hi = 0, $322 = 0, $323 = 0, $7_1 = 0, $324 = 0, $325 = 0, $326 = 0, $327 = 0, $328 = 0, $329 = 0, $331 = 0, $332 = 0, $333 = 0, $334 = 0, $336 = 0, $337 = 0, $338 = 0, $339 = 0, $341 = 0, $342 = 0, $344 = 0, $345 = 0, $20_1 = 0, $20$hi = 0, $346 = 0, $347 = 0, $348 = 0, $350 = 0, $351 = 0, $352 = 0, $353 = 0, $355 = 0, $23_1 = 0, $23$hi = 0, $356 = 0, $357 = 0, $358 = 0, $359 = 0, $24_1 = 0, $360 = 0, $362 = 0, $363 = 0, $364 = 0, $365 = 0, $368 = 0, $369 = 0, $371 = 0, $372 = 0, $374 = 0, $375 = 0, $376 = 0, $377 = 0, $378 = 0, $380 = 0, $381 = 0, $382 = 0, $51_1 = 0, $55_1 = 0, $62_1 = 0, $66_1 = 0, $75_1 = 0, $75$hi = 0, $80_1 = 0, $80$hi = 0, $88_1 = 0, $88$hi = 0, $110 = 0, $111 = 0, $111$hi = 0, $112 = 0, $112$hi = 0, $119$hi = 0, $122$hi = 0, $137 = 0, $138 = 0, $138$hi = 0, $139 = 0, $139$hi = 0, $146$hi = 0, $149$hi = 0, $164 = 0, $166 = 0, $166$hi = 0, $170$hi = 0, $181 = 0, $181$hi = 0, $182$hi = 0, $185 = 0, $188 = 0, $188$hi = 0, $193$hi = 0, $203 = 0, $203$hi = 0, $204$hi = 0, $206 = 0, $209 = 0, $209$hi = 0, $214$hi = 0, $224 = 0, $224$hi = 0, $225$hi = 0, $227 = 0, $230 = 0, $230$hi = 0, $235$hi = 0, $245 = 0, $245$hi = 0, $246$hi = 0, $248 = 0, $249 = 0, $249$hi = 0, $252 = 0, $252$hi = 0, $257$hi = 0, $262 = 0, $264$hi = 0, $267 = 0, $268 = 0, $268$hi = 0, $272 = 0, $272$hi = 0, $279 = 0, $279$hi = 0, $283 = 0, $284$hi = 0, $285$hi = 0, $287 = 0, $288$hi = 0, $289$hi = 0, $290$hi = 0, $294$hi = 0, $305 = 0, $305$hi = 0, $308 = 0, $308$hi = 0, $314$hi = 0, $315 = 0, $315$hi = 0, $321 = 0, $321$hi = 0, $330 = 0, $330$hi = 0, $335 = 0, $335$hi = 0, $340 = 0, $340$hi = 0, $342$hi = 0, $343 = 0, $343$hi = 0, $345$hi = 0, $346$hi = 0, $349 = 0, $350$hi = 0, $351$hi = 0, $354 = 0, $355$hi = 0, $361 = 0, $361$hi = 0, $366 = 0, $366$hi = 0, $367 = 0, $367$hi = 0, $370 = 0, $370$hi = 0, $373 = 0, $373$hi = 0, $375$hi = 0, $379 = 0, $379$hi = 0, $383 = 0, $384$hi = 0, $385$hi = 0, $388 = 0, $388$hi = 0, $389 = 0, $389$hi = 0, $396 = 0, $396$hi = 0, $402 = 0, $402$hi = 0, $404$hi = 0, $405 = 0, $405$hi = 0, $406 = 0, $406$hi = 0, $407 = 0, $407$hi = 0, $409$hi = 0, $413 = 0, $414$hi = 0, $415 = 0, $415$hi = 0, $416 = 0, $416$hi = 0, $425 = 0, $425$hi = 0, $429 = 0, $430 = 0, $430$hi = 0, $436 = 0, $436$hi = 0, $440 = 0, $441$hi = 0, $442$hi = 0, $446 = 0, $447$hi = 0, $448 = 0, $448$hi = 0, $449 = 0, $449$hi = 0, $456 = 0, $456$hi = 0, $461 = 0, $461$hi = 0, $466 = 0, $466$hi = 0, $469 = 0, $469$hi = 0, $472 = 0, $473$hi = 0, $476 = 0, $477$hi = 0, $478$hi = 0, $481 = 0, $482$hi = 0, $484$hi = 0, $485 = 0, $485$hi = 0, $489 = 0, $490$hi = 0, $491 = 0, $491$hi = 0, $492 = 0, $492$hi = 0, $493 = 0, $493$hi = 0, $500 = 0, $500$hi = 0, $503 = 0, $503$hi = 0, $506 = 0, $508$hi = 0, $509 = 0, $509$hi = 0, $514 = 0, $514$hi = 0, $515 = 0, $515$hi = 0, $517$hi = 0, $518$hi = 0, $520 = 0, $521$hi = 0, $522$hi = 0, $526 = 0, $527$hi = 0, $541$hi = 0, $545 = 0, $545$hi = 0, $546$hi = 0, $550 = 0, $551$hi = 0, $558 = 0, $560 = 0, $560$hi = 0, $562$hi = 0, $564 = 0, $564$hi = 0, $571$hi = 0, $575 = 0, $575$hi = 0, $576$hi = 0, $580 = 0, $581$hi = 0, $595 = 0, $595$hi = 0, $597$hi = 0, $601$hi = 0, $603 = 0, $603$hi = 0, $636 = 0, $636$hi = 0, $641 = 0, $641$hi = 0, $645$hi = 0, $646 = 0, $646$hi = 0, $647 = 0, $647$hi = 0, $650 = 0, $650$hi = 0, $654 = 0, $655$hi = 0, $667 = 0, $667$hi = 0, $668 = 0, $668$hi = 0, $676 = 0, $680 = 0, $681$hi = 0, $685 = 0, $689 = 0, $690$hi = 0, $694 = 0, $695$hi = 0, $697 = 0, $697$hi = 0, $700 = 0, $703 = 0, $703$hi = 0, $704 = 0, $711 = 0, $716 = 0, $717$hi = 0, $721 = 0, $722$hi = 0, $724 = 0, $724$hi = 0, $727 = 0, $730 = 0, $730$hi = 0, $731 = 0, $737 = 0, $742 = 0, $743$hi = 0, $747 = 0, $748$hi = 0, $749$hi = 0;
  $5_1 = global$0 - 336 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $10_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $10$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$0 = $2_1;
  i64toi32_i32$2 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  $11_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $11$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$2 = i64toi32_i32$1;
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$1 = $4_1;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$3 = $2_1;
  i64toi32_i32$0 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
  i64toi32_i32$2 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
  i64toi32_i32$1 = -2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $12_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $12$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  i64toi32_i32$0 = $4_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = 0;
   $322 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   $322 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
  }
  $6_1 = $322 & 32767 | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = 48;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = 0;
      $323 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
      $323 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
     }
     $7_1 = $323 & 32767 | 0;
     if (($7_1 + -32767 | 0) >>> 0 < -32766 >>> 0) {
      break label$3
     }
     $8_1 = 0;
     if (($6_1 + -32767 | 0) >>> 0 > -32767 >>> 0) {
      break label$2
     }
    }
    label$4 : {
     i64toi32_i32$0 = $1$hi;
     $51_1 = !($1_1 | i64toi32_i32$0 | 0);
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$1 = 2147483647;
     i64toi32_i32$3 = -1;
     i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
     $13_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
     $13$hi = i64toi32_i32$1;
     i64toi32_i32$0 = $13_1;
     i64toi32_i32$2 = 2147418112;
     i64toi32_i32$3 = 0;
     $55_1 = i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$1;
     i64toi32_i32$3 = $13_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$2 = 0;
     if ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) | 0 ? $51_1 : $55_1) {
      break label$4
     }
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$0 = 32768;
     i64toi32_i32$1 = 0;
     i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
     $12_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     $12$hi = i64toi32_i32$0;
     break label$1;
    }
    label$5 : {
     i64toi32_i32$0 = $3$hi;
     $62_1 = !($3_1 | i64toi32_i32$0 | 0);
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$2 = 2147483647;
     i64toi32_i32$1 = -1;
     i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$2 | 0;
     $2_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
     $2$hi = i64toi32_i32$2;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$1 = 0;
     $66_1 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$2 = 2147418112;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) | 0 ? $62_1 : $66_1) {
      break label$5
     }
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$0 = 32768;
     i64toi32_i32$2 = 0;
     i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $12_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     $12$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $3$hi;
     $1_1 = $3_1;
     $1$hi = i64toi32_i32$0;
     break label$1;
    }
    label$6 : {
     i64toi32_i32$0 = $1$hi;
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$1 = $13_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$2 = 0;
     i64toi32_i32$3 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
     $75_1 = i64toi32_i32$1 ^ i64toi32_i32$2 | 0;
     $75$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$1 = $75$hi;
     i64toi32_i32$2 = $75_1;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$2 = 0;
     if ((i64toi32_i32$3 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$0 | 0) | 0) {
      break label$6
     }
     label$7 : {
      i64toi32_i32$3 = $3$hi;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$2 = $2_1;
      i64toi32_i32$1 = 2147418112;
      i64toi32_i32$0 = 0;
      i64toi32_i32$1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
      $80_1 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
      $80$hi = i64toi32_i32$1;
      i64toi32_i32$1 = $3$hi;
      i64toi32_i32$3 = $3_1;
      i64toi32_i32$2 = $80$hi;
      i64toi32_i32$0 = $80_1;
      i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
      if (!!(i64toi32_i32$3 | i64toi32_i32$0 | 0 | i64toi32_i32$2 | 0)) {
       break label$7
      }
      i64toi32_i32$2 = 0;
      $1_1 = 0;
      $1$hi = i64toi32_i32$2;
      i64toi32_i32$2 = 2147450880;
      $12_1 = 0;
      $12$hi = i64toi32_i32$2;
      break label$1;
     }
     i64toi32_i32$2 = $12$hi;
     i64toi32_i32$1 = $12_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
     $12_1 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $12$hi = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$3;
     break label$1;
    }
    label$8 : {
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
     $88_1 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
     $88$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$2 = $88$hi;
     i64toi32_i32$0 = $88_1;
     i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | 0) {
      break label$8
     }
     i64toi32_i32$1 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$1;
     break label$1;
    }
    label$9 : {
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $13$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$2 = $13$hi;
     i64toi32_i32$3 = $13_1;
     i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$0 | 0) | 0) {
      break label$9
     }
     i64toi32_i32$1 = $12$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$3 = $3_1;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
     i64toi32_i32$4 = !(i64toi32_i32$3 | i64toi32_i32$0 | 0 | i64toi32_i32$2 | 0);
     i64toi32_i32$2 = 2147450880;
     i64toi32_i32$3 = $12$hi;
     i64toi32_i32$0 = i64toi32_i32$4 ? 0 : $12_1;
     i64toi32_i32$1 = i64toi32_i32$4 ? i64toi32_i32$2 : i64toi32_i32$3;
     $12_1 = i64toi32_i32$0;
     $12$hi = i64toi32_i32$1;
     i64toi32_i32$1 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$1;
     break label$1;
    }
    label$10 : {
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$4 = $3_1;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
     i64toi32_i32$4 = 0;
     i64toi32_i32$2 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$4 | 0) | 0) {
      break label$10
     }
     i64toi32_i32$1 = $12$hi;
     i64toi32_i32$2 = $12_1;
     i64toi32_i32$0 = 2147418112;
     i64toi32_i32$4 = 0;
     i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $12_1 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
     $12$hi = i64toi32_i32$0;
     i64toi32_i32$0 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$0;
     break label$1;
    }
    $8_1 = 0;
    label$11 : {
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$1 = $13_1;
     i64toi32_i32$2 = 65535;
     i64toi32_i32$4 = -1;
     if (i64toi32_i32$0 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0) {
      break label$11
     }
     $110 = $5_1 + 320 | 0;
     i64toi32_i32$1 = $1$hi;
     $111 = $1_1;
     $111$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $11$hi;
     $112 = $11_1;
     $112$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $11$hi;
     $8_1 = !($11_1 | i64toi32_i32$1 | 0);
     i64toi32_i32$3 = $8_1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$0 = $11$hi;
     i64toi32_i32$2 = i64toi32_i32$3 ? $1_1 : $11_1;
     i64toi32_i32$4 = i64toi32_i32$3 ? i64toi32_i32$1 : i64toi32_i32$0;
     i64toi32_i32$1 = Math_clz32(i64toi32_i32$4);
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$1 | 0) == (32 | 0)) {
      $324 = Math_clz32(i64toi32_i32$2) + 32 | 0
     } else {
      $324 = i64toi32_i32$1
     }
     $119$hi = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     $122$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $119$hi;
     i64toi32_i32$2 = $324;
     i64toi32_i32$4 = $122$hi;
     i64toi32_i32$1 = $8_1 << 6 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $8_1 = i64toi32_i32$0;
     i64toi32_i32$5 = $111$hi;
     i64toi32_i32$2 = $112$hi;
     $86($110 | 0, $111 | 0, i64toi32_i32$5 | 0, $112 | 0, i64toi32_i32$2 | 0, i64toi32_i32$0 + -15 | 0 | 0);
     $8_1 = 16 - i64toi32_i32$0 | 0;
     i64toi32_i32$3 = $5_1 + 328 | 0;
     i64toi32_i32$2 = HEAP32[i64toi32_i32$3 >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
     $11_1 = i64toi32_i32$2;
     $11$hi = i64toi32_i32$5;
     i64toi32_i32$3 = $5_1;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 320 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 324 | 0) >> 2] | 0;
     $1_1 = i64toi32_i32$5;
     $1$hi = i64toi32_i32$2;
    }
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$5 = 65535;
    i64toi32_i32$1 = -1;
    if (i64toi32_i32$2 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0) {
     break label$2
    }
    $137 = $5_1 + 304 | 0;
    i64toi32_i32$3 = $3$hi;
    $138 = $3_1;
    $138$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $10$hi;
    $139 = $10_1;
    $139$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$3 = $10$hi;
    $9_1 = !($10_1 | i64toi32_i32$3 | 0);
    i64toi32_i32$4 = $9_1;
    i64toi32_i32$3 = $3$hi;
    i64toi32_i32$2 = $10$hi;
    i64toi32_i32$5 = i64toi32_i32$4 ? $3_1 : $10_1;
    i64toi32_i32$1 = i64toi32_i32$4 ? i64toi32_i32$3 : i64toi32_i32$2;
    i64toi32_i32$3 = Math_clz32(i64toi32_i32$1);
    i64toi32_i32$4 = 0;
    if ((i64toi32_i32$3 | 0) == (32 | 0)) {
     $325 = Math_clz32(i64toi32_i32$5) + 32 | 0
    } else {
     $325 = i64toi32_i32$3
    }
    $146$hi = i64toi32_i32$4;
    i64toi32_i32$4 = 0;
    $149$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $146$hi;
    i64toi32_i32$5 = $325;
    i64toi32_i32$1 = $149$hi;
    i64toi32_i32$3 = $9_1 << 6 | 0;
    i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
    i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
    }
    $9_1 = i64toi32_i32$2;
    i64toi32_i32$0 = $138$hi;
    i64toi32_i32$5 = $139$hi;
    $86($137 | 0, $138 | 0, i64toi32_i32$0 | 0, $139 | 0, i64toi32_i32$5 | 0, i64toi32_i32$2 + -15 | 0 | 0);
    $8_1 = (i64toi32_i32$2 + $8_1 | 0) + -16 | 0;
    i64toi32_i32$4 = $5_1 + 312 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$5;
    $10$hi = i64toi32_i32$0;
    i64toi32_i32$4 = $5_1;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$4 + 304 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 308 | 0) >> 2] | 0;
    $3_1 = i64toi32_i32$0;
    $3$hi = i64toi32_i32$5;
   }
   $164 = $5_1 + 288 | 0;
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$4 = $3_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$3 = 49;
   i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $326 = i64toi32_i32$5 >>> i64toi32_i32$1 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$5 >>> i64toi32_i32$1 | 0;
    $326 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$1 | 0) | 0;
   }
   $166 = $326;
   $166$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $10$hi;
   i64toi32_i32$5 = $10_1;
   i64toi32_i32$4 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$4 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
   $14_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $14$hi = i64toi32_i32$4;
   i64toi32_i32$0 = $14_1;
   i64toi32_i32$5 = 0;
   i64toi32_i32$3 = 15;
   i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$0 << i64toi32_i32$1 | 0;
    $327 = 0;
   } else {
    i64toi32_i32$5 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$1 | 0) | 0;
    $327 = i64toi32_i32$0 << i64toi32_i32$1 | 0;
   }
   $170$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $166$hi;
   i64toi32_i32$4 = $166;
   i64toi32_i32$0 = $170$hi;
   i64toi32_i32$3 = $327;
   i64toi32_i32$0 = i64toi32_i32$5 | i64toi32_i32$0 | 0;
   $2_1 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
   $2$hi = i64toi32_i32$0;
   i64toi32_i32$0 = 1963258675;
   i64toi32_i32$5 = 0;
   i64toi32_i32$4 = $2$hi;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$1 = i64toi32_i32$5 - i64toi32_i32$3 | 0;
   i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0;
   i64toi32_i32$2 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
   i64toi32_i32$2 = i64toi32_i32$0 - i64toi32_i32$2 | 0;
   $4_1 = i64toi32_i32$1;
   $4$hi = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$4;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$3 = 0;
   $98($164 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0, i64toi32_i32$1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$3 | 0);
   i64toi32_i32$5 = ($5_1 + 288 | 0) + 8 | 0;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $181 = i64toi32_i32$3;
   $181$hi = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 0;
   i64toi32_i32$3 = $181$hi;
   i64toi32_i32$2 = $181;
   i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$2 | 0;
   i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0;
   i64toi32_i32$1 = i64toi32_i32$6 + i64toi32_i32$3 | 0;
   i64toi32_i32$1 = i64toi32_i32$0 - i64toi32_i32$1 | 0;
   $182$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$1 = $182$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$2 = 0;
   $98($5_1 + 272 | 0 | 0, i64toi32_i32$4 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$5 | 0, $4_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$2 | 0);
   $185 = $5_1 + 256 | 0;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 272 | 0) >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 276 | 0) >> 2] | 0;
   i64toi32_i32$5 = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$1 = 63;
   i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $328 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
    $328 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
   }
   $188 = $328;
   $188$hi = i64toi32_i32$2;
   i64toi32_i32$0 = ($5_1 + 272 | 0) + 8 | 0;
   i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$1 = 1;
   i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
    $329 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
    $329 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
   }
   $193$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $188$hi;
   i64toi32_i32$5 = $188;
   i64toi32_i32$0 = $193$hi;
   i64toi32_i32$1 = $329;
   i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
   $4_1 = i64toi32_i32$5 | i64toi32_i32$1 | 0;
   $4$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$1 = 0;
   $98($185 | 0, $4_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$5 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0);
   i64toi32_i32$1 = i64toi32_i32$0;
   i64toi32_i32$5 = ($5_1 + 256 | 0) + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $203 = i64toi32_i32$1;
   $203$hi = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$5 = 0;
   i64toi32_i32$1 = $203$hi;
   i64toi32_i32$0 = $203;
   i64toi32_i32$3 = i64toi32_i32$5 - i64toi32_i32$0 | 0;
   i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0;
   i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$1 | 0;
   i64toi32_i32$4 = i64toi32_i32$2 - i64toi32_i32$4 | 0;
   $204$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$2 = $204$hi;
   i64toi32_i32$0 = 0;
   $98($5_1 + 240 | 0 | 0, $4_1 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$5 | 0, i64toi32_i32$3 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0);
   $206 = $5_1 + 224 | 0;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 240 | 0) >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 244 | 0) >> 2] | 0;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 63;
   i64toi32_i32$1 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $331 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
    $331 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
   }
   $209 = $331;
   $209$hi = i64toi32_i32$0;
   i64toi32_i32$2 = ($5_1 + 240 | 0) + 8 | 0;
   i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = 1;
   i64toi32_i32$1 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$1 | 0;
    $332 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$1 | 0) | 0;
    $332 = i64toi32_i32$2 << i64toi32_i32$1 | 0;
   }
   $214$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $209$hi;
   i64toi32_i32$5 = $209;
   i64toi32_i32$2 = $214$hi;
   i64toi32_i32$4 = $332;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   $4_1 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
   $4$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$4 = 0;
   $98($206 | 0, $4_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$5 | 0, $2_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$4 | 0);
   i64toi32_i32$4 = i64toi32_i32$2;
   i64toi32_i32$5 = ($5_1 + 224 | 0) + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $224 = i64toi32_i32$4;
   $224$hi = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 0;
   i64toi32_i32$4 = $224$hi;
   i64toi32_i32$2 = $224;
   i64toi32_i32$1 = i64toi32_i32$5 - i64toi32_i32$2 | 0;
   i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0;
   i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
   i64toi32_i32$3 = i64toi32_i32$0 - i64toi32_i32$3 | 0;
   $225$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = $225$hi;
   i64toi32_i32$2 = 0;
   $98($5_1 + 208 | 0 | 0, $4_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$5 | 0, i64toi32_i32$1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$2 | 0);
   $227 = $5_1 + 192 | 0;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 208 | 0) >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 212 | 0) >> 2] | 0;
   i64toi32_i32$5 = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 63;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $333 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    $333 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$4 | 0) | 0;
   }
   $230 = $333;
   $230$hi = i64toi32_i32$2;
   i64toi32_i32$0 = ($5_1 + 208 | 0) + 8 | 0;
   i64toi32_i32$2 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 1;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    $334 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$4 | 0) | 0;
    $334 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   }
   $235$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $230$hi;
   i64toi32_i32$5 = $230;
   i64toi32_i32$0 = $235$hi;
   i64toi32_i32$3 = $334;
   i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
   $4_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $4$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$3 = 0;
   $98($227 | 0, $4_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$5 | 0, $2_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0);
   i64toi32_i32$3 = i64toi32_i32$0;
   i64toi32_i32$5 = ($5_1 + 192 | 0) + 8 | 0;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $245 = i64toi32_i32$3;
   $245$hi = i64toi32_i32$2;
   i64toi32_i32$2 = 0;
   i64toi32_i32$5 = 0;
   i64toi32_i32$3 = $245$hi;
   i64toi32_i32$0 = $245;
   i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$0 | 0;
   i64toi32_i32$6 = i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0;
   i64toi32_i32$1 = i64toi32_i32$6 + i64toi32_i32$3 | 0;
   i64toi32_i32$1 = i64toi32_i32$2 - i64toi32_i32$1 | 0;
   $246$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$5 = 0;
   i64toi32_i32$2 = $246$hi;
   i64toi32_i32$0 = 0;
   $98($5_1 + 176 | 0 | 0, $4_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$5 | 0, i64toi32_i32$4 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0);
   $248 = $5_1 + 160 | 0;
   i64toi32_i32$0 = $2$hi;
   $249 = $2_1;
   $249$hi = i64toi32_i32$0;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 176 | 0) >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$5 + 180 | 0) >> 2] | 0;
   i64toi32_i32$5 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 63;
   i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $336 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
    $336 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
   }
   $252 = $336;
   $252$hi = i64toi32_i32$0;
   i64toi32_i32$2 = ($5_1 + 176 | 0) + 8 | 0;
   i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 1;
   i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $337 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
    $337 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
   }
   $257$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $252$hi;
   i64toi32_i32$5 = $252;
   i64toi32_i32$2 = $257$hi;
   i64toi32_i32$1 = $337;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   i64toi32_i32$0 = i64toi32_i32$5 | i64toi32_i32$1 | 0;
   i64toi32_i32$5 = -1;
   i64toi32_i32$1 = -1;
   i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
   i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $4_1 = i64toi32_i32$3;
   $4$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $249$hi;
   i64toi32_i32$0 = 0;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$1 = 0;
   $98($248 | 0, $249 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$0 | 0, i64toi32_i32$3 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$1 | 0);
   $262 = $5_1 + 144 | 0;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$4 = 15;
   i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
    $338 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$5 | 0) | 0;
    $338 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
   }
   $264$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$2 = $264$hi;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$4 = 0;
   $98($262 | 0, $338 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$4 | 0);
   $267 = $5_1 + 112 | 0;
   i64toi32_i32$4 = i64toi32_i32$1;
   $268 = $4_1;
   $268$hi = i64toi32_i32$1;
   i64toi32_i32$0 = ($5_1 + 160 | 0) + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   $272 = i64toi32_i32$4;
   $272$hi = i64toi32_i32$1;
   i64toi32_i32$0 = $5_1;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 160 | 0) >> 2] | 0;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 164 | 0) >> 2] | 0;
   $10_1 = i64toi32_i32$1;
   $10$hi = i64toi32_i32$4;
   i64toi32_i32$0 = (i64toi32_i32$0 + 144 | 0) + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   $279 = i64toi32_i32$4;
   $279$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$0 = $10_1;
   i64toi32_i32$4 = $279$hi;
   i64toi32_i32$2 = $279;
   i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
   i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
   if (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
   }
   $2_1 = i64toi32_i32$5;
   $2$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $10$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$1 = i64toi32_i32$5;
   i64toi32_i32$0 = $10$hi;
   i64toi32_i32$2 = $10_1;
   $283 = i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$1 = 0;
   $284$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $272$hi;
   i64toi32_i32$2 = $272;
   i64toi32_i32$3 = $284$hi;
   i64toi32_i32$0 = $283;
   i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
   i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
   }
   $285$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$0 = 1;
   $287 = i64toi32_i32$5 >>> 0 > i64toi32_i32$2 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$1 = 0;
   $288$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $285$hi;
   i64toi32_i32$0 = i64toi32_i32$4;
   i64toi32_i32$5 = $288$hi;
   i64toi32_i32$2 = $287;
   i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $289$hi = i64toi32_i32$4;
   i64toi32_i32$4 = 0;
   i64toi32_i32$1 = 0;
   i64toi32_i32$0 = $289$hi;
   i64toi32_i32$2 = i64toi32_i32$3;
   i64toi32_i32$5 = i64toi32_i32$1 - i64toi32_i32$3 | 0;
   i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0;
   i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$0 | 0;
   i64toi32_i32$3 = i64toi32_i32$4 - i64toi32_i32$3 | 0;
   $290$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $268$hi;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = $290$hi;
   i64toi32_i32$2 = 0;
   $98($267 | 0, $268 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$1 | 0, i64toi32_i32$5 | 0, i64toi32_i32$4 | 0, 0 | 0, i64toi32_i32$2 | 0);
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = 0;
   i64toi32_i32$1 = 1;
   i64toi32_i32$4 = $2$hi;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$0 = i64toi32_i32$1 - i64toi32_i32$3 | 0;
   i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0;
   i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
   i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
   $294$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$5 = $294$hi;
   i64toi32_i32$1 = 0;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$3 = 0;
   $98($5_1 + 128 | 0 | 0, i64toi32_i32$0 | 0, i64toi32_i32$5 | 0, 0 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$2 | 0, 0 | 0, i64toi32_i32$3 | 0);
   $6_1 = $8_1 + ($7_1 - $6_1 | 0) | 0;
   label$12 : {
    label$13 : {
     i64toi32_i32$1 = $5_1;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 112 | 0) >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 116 | 0) >> 2] | 0;
     $15_1 = i64toi32_i32$3;
     $15$hi = i64toi32_i32$2;
     i64toi32_i32$1 = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = 1;
     i64toi32_i32$4 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
      $339 = 0;
     } else {
      i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
      $339 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     }
     $16_1 = $339;
     $16$hi = i64toi32_i32$3;
     $305 = $16_1;
     $305$hi = i64toi32_i32$3;
     i64toi32_i32$2 = $5_1;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 128 | 0) >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 132 | 0) >> 2] | 0;
     i64toi32_i32$2 = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = 63;
     i64toi32_i32$4 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = 0;
      $341 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
      $341 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
     }
     $308 = $341;
     $308$hi = i64toi32_i32$3;
     i64toi32_i32$1 = ($5_1 + 128 | 0) + 8 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$1 >> 2] | 0;
     i64toi32_i32$2 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
     $17_1 = i64toi32_i32$3;
     $17$hi = i64toi32_i32$2;
     i64toi32_i32$1 = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = 1;
     i64toi32_i32$4 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
      $342 = 0;
     } else {
      i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
      $342 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
     }
     $314$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $308$hi;
     i64toi32_i32$2 = $308;
     i64toi32_i32$1 = $314$hi;
     i64toi32_i32$5 = $342;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     $315 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
     $315$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $305$hi;
     i64toi32_i32$3 = $305;
     i64toi32_i32$2 = $315$hi;
     i64toi32_i32$5 = $315;
     i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $13_1 = i64toi32_i32$4;
     $13$hi = i64toi32_i32$0;
     i64toi32_i32$1 = i64toi32_i32$4;
     i64toi32_i32$3 = -1;
     i64toi32_i32$5 = -13927;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $18_1 = i64toi32_i32$2;
     $18$hi = i64toi32_i32$4;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$1 = 0;
     i64toi32_i32$5 = 32;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $344 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
      $344 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$3 | 0) | 0;
     }
     $2_1 = $344;
     $2$hi = i64toi32_i32$1;
     $321 = $2_1;
     $321$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $11$hi;
     i64toi32_i32$4 = $11_1;
     i64toi32_i32$0 = 65536;
     i64toi32_i32$5 = 0;
     i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $19_1 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
     $19$hi = i64toi32_i32$0;
     i64toi32_i32$1 = $19_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$5 = 1;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
      $345 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$3 | 0) | 0;
      $345 = i64toi32_i32$1 << i64toi32_i32$3 | 0;
     }
     $20_1 = $345;
     $20$hi = i64toi32_i32$4;
     i64toi32_i32$0 = $20_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$5 = 32;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $346 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
      $346 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$3 | 0) | 0;
     }
     $4_1 = $346;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $321$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = __wasm_i64_mul($321 | 0, i64toi32_i32$1 | 0, $4_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
     $21_1 = i64toi32_i32$0;
     $21$hi = i64toi32_i32$1;
     $330 = i64toi32_i32$0;
     $330$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$5 = 1;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$4 << i64toi32_i32$3 | 0;
      $347 = 0;
     } else {
      i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$3 | 0) | 0;
      $347 = i64toi32_i32$4 << i64toi32_i32$3 | 0;
     }
     $22_1 = $347;
     $22$hi = i64toi32_i32$0;
     i64toi32_i32$1 = $22_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$5 = 32;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = 0;
      $348 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
     } else {
      i64toi32_i32$4 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
      $348 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$3 | 0) | 0;
     }
     $10_1 = $348;
     $10$hi = i64toi32_i32$4;
     $335 = $10_1;
     $335$hi = i64toi32_i32$4;
     i64toi32_i32$0 = ($5_1 + 112 | 0) + 8 | 0;
     i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$4 = 0;
     i64toi32_i32$5 = 1;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
      $350 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$3 | 0) | 0;
      $350 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
     }
     $340 = $350;
     $340$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $15$hi;
     i64toi32_i32$1 = $15_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$5 = 63;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = 0;
      $351 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
     } else {
      i64toi32_i32$0 = i64toi32_i32$4 >>> i64toi32_i32$3 | 0;
      $351 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$3 | 0) | 0;
     }
     $342$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $340$hi;
     i64toi32_i32$4 = $340;
     i64toi32_i32$1 = $342$hi;
     i64toi32_i32$5 = $351;
     i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
     $343 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
     $343$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $17$hi;
     i64toi32_i32$0 = $17_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$5 = 63;
     i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = 0;
      $352 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
     } else {
      i64toi32_i32$4 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
      $352 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$3 | 0) | 0;
     }
     $345$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $343$hi;
     i64toi32_i32$1 = $343;
     i64toi32_i32$0 = $345$hi;
     i64toi32_i32$5 = $352;
     i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $346$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $13$hi;
     i64toi32_i32$2 = $16$hi;
     i64toi32_i32$2 = $13$hi;
     i64toi32_i32$4 = $13_1;
     i64toi32_i32$1 = $16$hi;
     i64toi32_i32$5 = $16_1;
     $349 = i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $350$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $346$hi;
     i64toi32_i32$5 = i64toi32_i32$3;
     i64toi32_i32$2 = $350$hi;
     i64toi32_i32$1 = $349;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $351$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$3 = $13$hi;
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$4 = $18_1;
     i64toi32_i32$5 = $13$hi;
     i64toi32_i32$1 = $13_1;
     $354 = i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $355$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $351$hi;
     i64toi32_i32$1 = i64toi32_i32$0;
     i64toi32_i32$3 = $355$hi;
     i64toi32_i32$5 = $354;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
     i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     i64toi32_i32$4 = i64toi32_i32$2;
     i64toi32_i32$1 = -1;
     i64toi32_i32$5 = -1;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $15_1 = i64toi32_i32$3;
     $15$hi = i64toi32_i32$2;
     i64toi32_i32$0 = i64toi32_i32$3;
     i64toi32_i32$4 = 0;
     i64toi32_i32$5 = 32;
     i64toi32_i32$1 = i64toi32_i32$5 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = 0;
      $353 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
     } else {
      i64toi32_i32$4 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
      $353 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$1 | 0) | 0;
     }
     $13_1 = $353;
     $13$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $335$hi;
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$0 = __wasm_i64_mul($335 | 0, i64toi32_i32$4 | 0, $13_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
     $361 = i64toi32_i32$0;
     $361$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $330$hi;
     i64toi32_i32$2 = $330;
     i64toi32_i32$0 = $361$hi;
     i64toi32_i32$5 = $361;
     i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $16_1 = i64toi32_i32$1;
     $16$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$3 = $16$hi;
     i64toi32_i32$4 = i64toi32_i32$1;
     i64toi32_i32$2 = $21$hi;
     i64toi32_i32$5 = $21_1;
     i64toi32_i32$4 = 0;
     $366 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     $366$hi = i64toi32_i32$4;
     i64toi32_i32$4 = i64toi32_i32$3;
     $367 = i64toi32_i32$1;
     $367$hi = i64toi32_i32$3;
     i64toi32_i32$4 = $15$hi;
     i64toi32_i32$5 = $15_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$2 = -1;
     i64toi32_i32$3 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
     $15_1 = i64toi32_i32$5 & i64toi32_i32$2 | 0;
     $15$hi = i64toi32_i32$3;
     $370 = $15_1;
     $370$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = 63;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = 0;
      $355 = i64toi32_i32$3 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$5 = i64toi32_i32$3 >>> i64toi32_i32$0 | 0;
      $355 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$0 | 0) | 0;
     }
     $23_1 = $355;
     $23$hi = i64toi32_i32$5;
     $373 = $23_1;
     $373$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $11$hi;
     i64toi32_i32$3 = $11_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$2 = 1;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
      $356 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$0 | 0) | 0;
      $356 = i64toi32_i32$3 << i64toi32_i32$0 | 0;
     }
     $375$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $373$hi;
     i64toi32_i32$5 = $373;
     i64toi32_i32$3 = $375$hi;
     i64toi32_i32$2 = $356;
     i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
     i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = -1;
     i64toi32_i32$5 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
     $11_1 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
     $11$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $370$hi;
     i64toi32_i32$4 = $11$hi;
     i64toi32_i32$4 = __wasm_i64_mul($370 | 0, i64toi32_i32$5 | 0, $11_1 | 0, i64toi32_i32$4 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $379 = i64toi32_i32$4;
     $379$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $367$hi;
     i64toi32_i32$3 = $367;
     i64toi32_i32$4 = $379$hi;
     i64toi32_i32$2 = $379;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $17_1 = i64toi32_i32$0;
     $17$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $16$hi;
     i64toi32_i32$1 = $17$hi;
     i64toi32_i32$5 = i64toi32_i32$0;
     i64toi32_i32$3 = $16$hi;
     i64toi32_i32$2 = $16_1;
     $383 = i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $384$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $366$hi;
     i64toi32_i32$2 = $366;
     i64toi32_i32$1 = $384$hi;
     i64toi32_i32$3 = $383;
     i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $385$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = __wasm_i64_mul($13_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
     $388 = i64toi32_i32$2;
     $388$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $385$hi;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$2 = $388$hi;
     i64toi32_i32$3 = $388;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $389 = i64toi32_i32$1;
     $389$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $15$hi;
     i64toi32_i32$4 = $4$hi;
     i64toi32_i32$4 = $15$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = __wasm_i64_mul($15_1 | 0, i64toi32_i32$4 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
     $21_1 = i64toi32_i32$5;
     $21$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $11$hi;
     i64toi32_i32$4 = $13$hi;
     i64toi32_i32$4 = $11$hi;
     i64toi32_i32$5 = $13$hi;
     i64toi32_i32$5 = __wasm_i64_mul($11_1 | 0, i64toi32_i32$4 | 0, $13_1 | 0, i64toi32_i32$5 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
     $396 = i64toi32_i32$5;
     $396$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $21$hi;
     i64toi32_i32$0 = $21_1;
     i64toi32_i32$5 = $396$hi;
     i64toi32_i32$3 = $396;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $16_1 = i64toi32_i32$2;
     $16$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $21$hi;
     i64toi32_i32$1 = $16$hi;
     i64toi32_i32$4 = i64toi32_i32$2;
     i64toi32_i32$0 = $21$hi;
     i64toi32_i32$3 = $21_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$3 = i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$1 = 0;
     i64toi32_i32$0 = 32;
     i64toi32_i32$5 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
      $357 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$5 | 0) | 0;
      $357 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     }
     $402 = $357;
     $402$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $16$hi;
     i64toi32_i32$4 = $16_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 32;
     i64toi32_i32$5 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = 0;
      $358 = i64toi32_i32$1 >>> i64toi32_i32$5 | 0;
     } else {
      i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$5 | 0;
      $358 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$5 | 0) | 0;
     }
     $404$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $402$hi;
     i64toi32_i32$1 = $402;
     i64toi32_i32$4 = $404$hi;
     i64toi32_i32$0 = $358;
     i64toi32_i32$4 = i64toi32_i32$3 | i64toi32_i32$4 | 0;
     $405 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $405$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $389$hi;
     i64toi32_i32$3 = $389;
     i64toi32_i32$1 = $405$hi;
     i64toi32_i32$0 = $405;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $406 = i64toi32_i32$5;
     $406$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $17$hi;
     $407 = $17_1;
     $407$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $16$hi;
     i64toi32_i32$4 = $16_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 32;
     i64toi32_i32$1 = i64toi32_i32$0 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$4 << i64toi32_i32$1 | 0;
      $359 = 0;
     } else {
      i64toi32_i32$3 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$1 | 0) | 0;
      $359 = i64toi32_i32$4 << i64toi32_i32$1 | 0;
     }
     $409$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $407$hi;
     i64toi32_i32$2 = $407;
     i64toi32_i32$4 = $409$hi;
     i64toi32_i32$0 = $359;
     i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $16_1 = i64toi32_i32$1;
     $16$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $17$hi;
     i64toi32_i32$5 = $16$hi;
     i64toi32_i32$3 = i64toi32_i32$1;
     i64toi32_i32$2 = $17$hi;
     i64toi32_i32$0 = $17_1;
     $413 = i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $414$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $406$hi;
     i64toi32_i32$0 = $406;
     i64toi32_i32$5 = $414$hi;
     i64toi32_i32$2 = $413;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $415 = i64toi32_i32$4;
     $415$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $16$hi;
     $416 = $16_1;
     $416$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $18$hi;
     i64toi32_i32$3 = $18_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$2 = -1;
     i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
     $18_1 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
     $18$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $11$hi;
     i64toi32_i32$0 = $18$hi;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$3 = __wasm_i64_mul($18_1 | 0, i64toi32_i32$0 | 0, $11_1 | 0, i64toi32_i32$3 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
     $21_1 = i64toi32_i32$3;
     $21$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$0 = $10$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$0 | 0, $10_1 | 0, i64toi32_i32$3 | 0) | 0;
     i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
     $425 = i64toi32_i32$3;
     $425$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $21$hi;
     i64toi32_i32$1 = $21_1;
     i64toi32_i32$3 = $425$hi;
     i64toi32_i32$2 = $425;
     i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $17_1 = i64toi32_i32$5;
     $17$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $21$hi;
     i64toi32_i32$4 = $17$hi;
     i64toi32_i32$0 = i64toi32_i32$5;
     i64toi32_i32$1 = $21$hi;
     i64toi32_i32$2 = $21_1;
     $429 = i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $430 = $429;
     $430$hi = i64toi32_i32$0;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$0 = $15$hi;
     i64toi32_i32$0 = $22$hi;
     i64toi32_i32$2 = $22_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = -2;
     i64toi32_i32$4 = i64toi32_i32$0 & i64toi32_i32$4 | 0;
     $21_1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
     $21$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $15$hi;
     i64toi32_i32$2 = $21$hi;
     i64toi32_i32$2 = __wasm_i64_mul($15_1 | 0, i64toi32_i32$4 | 0, $21_1 | 0, i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
     $436 = i64toi32_i32$2;
     $436$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $17$hi;
     i64toi32_i32$0 = i64toi32_i32$5;
     i64toi32_i32$2 = $436$hi;
     i64toi32_i32$1 = $436;
     i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $24_1 = i64toi32_i32$3;
     $24$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $17$hi;
     i64toi32_i32$5 = $24$hi;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$0 = $17$hi;
     i64toi32_i32$1 = $17_1;
     $440 = i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $441$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $430$hi;
     i64toi32_i32$1 = $430;
     i64toi32_i32$5 = $441$hi;
     i64toi32_i32$0 = $440;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $442$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $416$hi;
     i64toi32_i32$4 = $416;
     i64toi32_i32$1 = $442$hi;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $17_1 = i64toi32_i32$5;
     $17$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $16$hi;
     i64toi32_i32$2 = $17$hi;
     i64toi32_i32$3 = i64toi32_i32$5;
     i64toi32_i32$4 = $16$hi;
     i64toi32_i32$0 = $16_1;
     $446 = i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $447$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $415$hi;
     i64toi32_i32$0 = $415;
     i64toi32_i32$2 = $447$hi;
     i64toi32_i32$4 = $446;
     i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $448 = i64toi32_i32$1;
     $448$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $17$hi;
     $449 = $17_1;
     $449$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $18$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $18$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = __wasm_i64_mul($18_1 | 0, i64toi32_i32$5 | 0, $4_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $16_1 = i64toi32_i32$0;
     $16$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $21$hi;
     i64toi32_i32$5 = $13$hi;
     i64toi32_i32$5 = $21$hi;
     i64toi32_i32$0 = $13$hi;
     i64toi32_i32$0 = __wasm_i64_mul($21_1 | 0, i64toi32_i32$5 | 0, $13_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $456 = i64toi32_i32$0;
     $456$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $16$hi;
     i64toi32_i32$3 = $16_1;
     i64toi32_i32$0 = $456$hi;
     i64toi32_i32$4 = $456;
     i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
     }
     $4_1 = i64toi32_i32$2;
     $4$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $11$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$3 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$1 | 0, $11_1 | 0, i64toi32_i32$3 | 0) | 0;
     i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
     $461 = i64toi32_i32$3;
     $461$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$5 = i64toi32_i32$2;
     i64toi32_i32$3 = $461$hi;
     i64toi32_i32$4 = $461;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $11_1 = i64toi32_i32$0;
     $11$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $15$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = $15$hi;
     i64toi32_i32$5 = $10$hi;
     i64toi32_i32$5 = __wasm_i64_mul($15_1 | 0, i64toi32_i32$2 | 0, $10_1 | 0, i64toi32_i32$5 | 0) | 0;
     i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
     $466 = i64toi32_i32$5;
     $466$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$1 = i64toi32_i32$0;
     i64toi32_i32$5 = $466$hi;
     i64toi32_i32$4 = $466;
     i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $13_1 = i64toi32_i32$3;
     $13$hi = i64toi32_i32$0;
     i64toi32_i32$2 = i64toi32_i32$3;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = 32;
     i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $360 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
      $360 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$5 | 0) | 0;
     }
     $469 = $360;
     $469$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$1 = $16$hi;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$0 = $4_1;
     i64toi32_i32$2 = $16$hi;
     i64toi32_i32$4 = $16_1;
     $472 = i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $473$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $11$hi;
     i64toi32_i32$0 = i64toi32_i32$1;
     i64toi32_i32$0 = $11$hi;
     i64toi32_i32$4 = $11_1;
     i64toi32_i32$2 = $4_1;
     $476 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $477$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $473$hi;
     i64toi32_i32$2 = $472;
     i64toi32_i32$0 = $477$hi;
     i64toi32_i32$1 = $476;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $478$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $13$hi;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$3 = $13$hi;
     i64toi32_i32$4 = $13_1;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$1 = $11_1;
     $481 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $482$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $478$hi;
     i64toi32_i32$1 = i64toi32_i32$5;
     i64toi32_i32$3 = $482$hi;
     i64toi32_i32$2 = $481;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     i64toi32_i32$4 = i64toi32_i32$0;
     i64toi32_i32$1 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$3 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
      $362 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
      $362 = i64toi32_i32$4 << i64toi32_i32$3 | 0;
     }
     $484$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $469$hi;
     i64toi32_i32$5 = $469;
     i64toi32_i32$4 = $484$hi;
     i64toi32_i32$2 = $362;
     i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
     $485 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
     $485$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $449$hi;
     i64toi32_i32$1 = $449;
     i64toi32_i32$5 = $485$hi;
     i64toi32_i32$2 = $485;
     i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $4_1 = i64toi32_i32$3;
     $4$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $17$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$1 = $17$hi;
     i64toi32_i32$2 = $17_1;
     $489 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $490$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $448$hi;
     i64toi32_i32$2 = $448;
     i64toi32_i32$0 = $490$hi;
     i64toi32_i32$1 = $489;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $491 = i64toi32_i32$5;
     $491$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $4$hi;
     $492 = $4_1;
     $492$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $24$hi;
     $493 = $24_1;
     $493$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$2 = $21$hi;
     i64toi32_i32$2 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$3 | 0, $21_1 | 0, i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = $18$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = __wasm_i64_mul($18_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $500 = i64toi32_i32$2;
     $500$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$4 = $2_1;
     i64toi32_i32$2 = $500$hi;
     i64toi32_i32$1 = $500;
     i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $11_1 = i64toi32_i32$0;
     $11$hi = i64toi32_i32$5;
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = 32;
     i64toi32_i32$2 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = 0;
      $363 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
     } else {
      i64toi32_i32$4 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
      $363 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$2 | 0) | 0;
     }
     $503 = $363;
     $503$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $11$hi;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$4 = $11$hi;
     i64toi32_i32$5 = $11_1;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$1 = $2_1;
     $506 = i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     i64toi32_i32$1 = $506;
     i64toi32_i32$4 = 0;
     i64toi32_i32$3 = 32;
     i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
      $364 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$2 | 0) | 0;
      $364 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
     }
     $508$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $503$hi;
     i64toi32_i32$5 = $503;
     i64toi32_i32$1 = $508$hi;
     i64toi32_i32$3 = $364;
     i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
     $509 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
     $509$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $493$hi;
     i64toi32_i32$4 = $493;
     i64toi32_i32$5 = $509$hi;
     i64toi32_i32$3 = $509;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $24$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$4 = $24$hi;
     i64toi32_i32$3 = $24_1;
     i64toi32_i32$1 = 0;
     $514 = i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     $514$hi = i64toi32_i32$1;
     i64toi32_i32$1 = i64toi32_i32$0;
     $515 = i64toi32_i32$2;
     $515$hi = i64toi32_i32$0;
     i64toi32_i32$1 = $13$hi;
     i64toi32_i32$3 = $13_1;
     i64toi32_i32$0 = 0;
     i64toi32_i32$4 = 32;
     i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
      $365 = 0;
     } else {
      i64toi32_i32$0 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$5 | 0) | 0;
      $365 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     }
     $517$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $515$hi;
     i64toi32_i32$1 = $515;
     i64toi32_i32$3 = $517$hi;
     i64toi32_i32$4 = $365;
     i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $518$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = $518$hi;
     i64toi32_i32$0 = i64toi32_i32$5;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$4 = $2_1;
     $520 = i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $521$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $514$hi;
     i64toi32_i32$4 = $514;
     i64toi32_i32$2 = $521$hi;
     i64toi32_i32$1 = $520;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $522$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $492$hi;
     i64toi32_i32$0 = $492;
     i64toi32_i32$4 = $522$hi;
     i64toi32_i32$1 = i64toi32_i32$3;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
     i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $4$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$5 = i64toi32_i32$2;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$1 = $4_1;
     $526 = i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $527$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $491$hi;
     i64toi32_i32$1 = $491;
     i64toi32_i32$3 = $527$hi;
     i64toi32_i32$0 = $526;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
     i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $4_1 = i64toi32_i32$4;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$1 = 131071;
     i64toi32_i32$0 = -1;
     if (i64toi32_i32$2 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0) {
      break label$13
     }
     i64toi32_i32$5 = $20$hi;
     i64toi32_i32$5 = $23$hi;
     i64toi32_i32$5 = $20$hi;
     i64toi32_i32$0 = $20_1;
     i64toi32_i32$2 = $23$hi;
     i64toi32_i32$1 = $23_1;
     i64toi32_i32$2 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
     $19_1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
     $19$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$2 = $3$hi;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$1 = $14$hi;
     $98($5_1 + 80 | 0 | 0, $2_1 | 0, i64toi32_i32$2 | 0, i64toi32_i32$4 | 0, i64toi32_i32$0 | 0, $3_1 | 0, i64toi32_i32$5 | 0, $14_1 | 0, i64toi32_i32$1 | 0);
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$0 = $1_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$2 = 49;
     i64toi32_i32$3 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
      $368 = 0;
     } else {
      i64toi32_i32$5 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$3 | 0) | 0;
      $368 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
     }
     $541$hi = i64toi32_i32$5;
     i64toi32_i32$1 = ($5_1 + 80 | 0) + 8 | 0;
     i64toi32_i32$5 = HEAP32[i64toi32_i32$1 >> 2] | 0;
     i64toi32_i32$0 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
     $545 = i64toi32_i32$5;
     $545$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $541$hi;
     i64toi32_i32$1 = $368;
     i64toi32_i32$5 = $545$hi;
     i64toi32_i32$2 = $545;
     i64toi32_i32$3 = i64toi32_i32$1 - i64toi32_i32$2 | 0;
     i64toi32_i32$6 = i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0;
     i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
     i64toi32_i32$4 = i64toi32_i32$0 - i64toi32_i32$4 | 0;
     $546$hi = i64toi32_i32$4;
     i64toi32_i32$0 = $5_1;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 80 | 0) >> 2] | 0;
     i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 84 | 0) >> 2] | 0;
     $1_1 = i64toi32_i32$4;
     $1$hi = i64toi32_i32$1;
     i64toi32_i32$0 = i64toi32_i32$4;
     i64toi32_i32$4 = 0;
     i64toi32_i32$2 = 0;
     $550 = (i64toi32_i32$0 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$4 | 0) | 0;
     i64toi32_i32$0 = 0;
     $551$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $546$hi;
     i64toi32_i32$2 = i64toi32_i32$3;
     i64toi32_i32$1 = $551$hi;
     i64toi32_i32$4 = $550;
     i64toi32_i32$5 = i64toi32_i32$3 - i64toi32_i32$4 | 0;
     i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0;
     i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$0 - i64toi32_i32$3 | 0;
     $10_1 = i64toi32_i32$5;
     $10$hi = i64toi32_i32$3;
     $6_1 = $6_1 + 16382 | 0;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$3 = 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$4 = $1_1;
     i64toi32_i32$1 = i64toi32_i32$0 - i64toi32_i32$4 | 0;
     i64toi32_i32$6 = i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0;
     i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 - i64toi32_i32$5 | 0;
     $11_1 = i64toi32_i32$1;
     $11$hi = i64toi32_i32$5;
     break label$12;
    }
    $558 = $5_1 + 96 | 0;
    i64toi32_i32$5 = $2$hi;
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $369 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
     $369 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$2 | 0) | 0;
    }
    $560 = $369;
    $560$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$5 = $4_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 63;
    i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
     $371 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$2 | 0) | 0;
     $371 = i64toi32_i32$5 << i64toi32_i32$2 | 0;
    }
    $562$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $560$hi;
    i64toi32_i32$0 = $560;
    i64toi32_i32$5 = $562$hi;
    i64toi32_i32$4 = $371;
    i64toi32_i32$5 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
    $2_1 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
    $2$hi = i64toi32_i32$5;
    $564 = $2_1;
    $564$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $372 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
     $372 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$2 | 0) | 0;
    }
    $4_1 = $372;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $3$hi;
    i64toi32_i32$0 = $14$hi;
    i64toi32_i32$0 = $564$hi;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$4 = $14$hi;
    $98($558 | 0, $564 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$3 | 0, $3_1 | 0, i64toi32_i32$5 | 0, $14_1 | 0, i64toi32_i32$4 | 0);
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$0 = 48;
    i64toi32_i32$2 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$3 << i64toi32_i32$2 | 0;
     $374 = 0;
    } else {
     i64toi32_i32$5 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$2 | 0) | 0;
     $374 = i64toi32_i32$3 << i64toi32_i32$2 | 0;
    }
    $571$hi = i64toi32_i32$5;
    i64toi32_i32$4 = ($5_1 + 96 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$4 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
    $575 = i64toi32_i32$5;
    $575$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $571$hi;
    i64toi32_i32$4 = $374;
    i64toi32_i32$5 = $575$hi;
    i64toi32_i32$0 = $575;
    i64toi32_i32$2 = i64toi32_i32$4 - i64toi32_i32$0 | 0;
    i64toi32_i32$6 = i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0;
    i64toi32_i32$1 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
    i64toi32_i32$1 = i64toi32_i32$3 - i64toi32_i32$1 | 0;
    $576$hi = i64toi32_i32$1;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 96 | 0) >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 100 | 0) >> 2] | 0;
    $11_1 = i64toi32_i32$1;
    $11$hi = i64toi32_i32$4;
    i64toi32_i32$3 = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$0 = 0;
    $580 = (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$4 | 0) != (i64toi32_i32$1 | 0) | 0;
    i64toi32_i32$3 = 0;
    $581$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $576$hi;
    i64toi32_i32$0 = i64toi32_i32$2;
    i64toi32_i32$4 = $581$hi;
    i64toi32_i32$1 = $580;
    i64toi32_i32$5 = i64toi32_i32$0 - i64toi32_i32$1 | 0;
    i64toi32_i32$6 = i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0;
    i64toi32_i32$2 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
    i64toi32_i32$2 = i64toi32_i32$3 - i64toi32_i32$2 | 0;
    $10_1 = i64toi32_i32$5;
    $10$hi = i64toi32_i32$2;
    $6_1 = $6_1 + 16383 | 0;
    i64toi32_i32$2 = $11$hi;
    i64toi32_i32$2 = 0;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = $11$hi;
    i64toi32_i32$1 = $11_1;
    i64toi32_i32$4 = i64toi32_i32$3 - i64toi32_i32$1 | 0;
    i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0;
    i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$0 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$5 | 0;
    $11_1 = i64toi32_i32$4;
    $11$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $1$hi;
    $22_1 = $1_1;
    $22$hi = i64toi32_i32$5;
   }
   label$14 : {
    if (($6_1 | 0) < (32767 | 0)) {
     break label$14
    }
    i64toi32_i32$5 = $12$hi;
    i64toi32_i32$2 = $12_1;
    i64toi32_i32$3 = 2147418112;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
    $12_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    $12$hi = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    $1_1 = 0;
    $1$hi = i64toi32_i32$3;
    break label$1;
   }
   label$15 : {
    label$16 : {
     if (($6_1 | 0) < (1 | 0)) {
      break label$16
     }
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$5 = $10_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$1 = 1;
     i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
      $375 = 0;
     } else {
      i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
      $375 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     }
     $595 = $375;
     $595$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$3 = $11_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$1 = 63;
     i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = 0;
      $376 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$5 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
      $376 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
     }
     $597$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $595$hi;
     i64toi32_i32$2 = $595;
     i64toi32_i32$3 = $597$hi;
     i64toi32_i32$1 = $376;
     i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
     $1_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     $1$hi = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = $6_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$1 = 48;
     i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
      $377 = 0;
     } else {
      i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
      $377 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     }
     $601$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$5 = 65535;
     i64toi32_i32$1 = -1;
     i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
     $603 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
     $603$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $601$hi;
     i64toi32_i32$2 = $377;
     i64toi32_i32$3 = $603$hi;
     i64toi32_i32$1 = $603;
     i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
     $10_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     $10$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $11$hi;
     i64toi32_i32$5 = $11_1;
     i64toi32_i32$2 = 0;
     i64toi32_i32$1 = 1;
     i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
      $378 = 0;
     } else {
      i64toi32_i32$2 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
      $378 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     }
     $4_1 = $378;
     $4$hi = i64toi32_i32$2;
     break label$15;
    }
    label$17 : {
     if (($6_1 | 0) > (-113 | 0)) {
      break label$17
     }
     i64toi32_i32$2 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$2;
     break label$1;
    }
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$2 = $4$hi;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$5 = $4$hi;
    $96($5_1 + 64 | 0 | 0, $2_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$5 | 0, 1 - $6_1 | 0 | 0);
    i64toi32_i32$5 = $22$hi;
    i64toi32_i32$5 = $19$hi;
    i64toi32_i32$5 = $22$hi;
    i64toi32_i32$2 = $19$hi;
    $86($5_1 + 48 | 0 | 0, $22_1 | 0, i64toi32_i32$5 | 0, $19_1 | 0, i64toi32_i32$2 | 0, $6_1 + 112 | 0 | 0);
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$2 = $14$hi;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 64 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$3 + 68 | 0) >> 2] | 0;
    $2_1 = i64toi32_i32$2;
    $2$hi = i64toi32_i32$5;
    i64toi32_i32$3 = (i64toi32_i32$3 + 64 | 0) + 8 | 0;
    i64toi32_i32$5 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$2 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$5;
    $10$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $3$hi;
    i64toi32_i32$5 = $14$hi;
    i64toi32_i32$3 = $2$hi;
    i64toi32_i32$1 = $10$hi;
    $98($5_1 + 32 | 0 | 0, $3_1 | 0, i64toi32_i32$2 | 0, $14_1 | 0, i64toi32_i32$5 | 0, $2_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$1 | 0);
    i64toi32_i32$5 = ($5_1 + 48 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    $636 = i64toi32_i32$1;
    $636$hi = i64toi32_i32$3;
    i64toi32_i32$5 = ($5_1 + 32 | 0) + 8 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$5 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
    i64toi32_i32$5 = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = 1;
    i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     $380 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$0 | 0) | 0;
     $380 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
    }
    $641 = $380;
    $641$hi = i64toi32_i32$3;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 32 | 0) >> 2] | 0;
    i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 36 | 0) >> 2] | 0;
    $1_1 = i64toi32_i32$3;
    $1$hi = i64toi32_i32$5;
    i64toi32_i32$1 = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = 63;
    i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $381 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     $381 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$0 | 0) | 0;
    }
    $645$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $641$hi;
    i64toi32_i32$5 = $641;
    i64toi32_i32$1 = $645$hi;
    i64toi32_i32$2 = $381;
    i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
    $646 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
    $646$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $636$hi;
    i64toi32_i32$3 = $636;
    i64toi32_i32$5 = $646$hi;
    i64toi32_i32$2 = $646;
    i64toi32_i32$0 = i64toi32_i32$3 - i64toi32_i32$2 | 0;
    i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0;
    i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$5 | 0;
    i64toi32_i32$4 = i64toi32_i32$1 - i64toi32_i32$4 | 0;
    $647 = i64toi32_i32$0;
    $647$hi = i64toi32_i32$4;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$1 + 48 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$1 + 52 | 0) >> 2] | 0;
    $4_1 = i64toi32_i32$4;
    $4$hi = i64toi32_i32$3;
    $650 = i64toi32_i32$4;
    $650$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$1 = $1_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = 1;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$1 << i64toi32_i32$5 | 0;
     $382 = 0;
    } else {
     i64toi32_i32$4 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$5 | 0) | 0;
     $382 = i64toi32_i32$1 << i64toi32_i32$5 | 0;
    }
    $11_1 = $382;
    $11$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $650$hi;
    i64toi32_i32$3 = $650;
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$2 = $11_1;
    $654 = i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
    i64toi32_i32$3 = 0;
    $655$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $647$hi;
    i64toi32_i32$2 = $647;
    i64toi32_i32$4 = $655$hi;
    i64toi32_i32$1 = $654;
    i64toi32_i32$5 = i64toi32_i32$2 - i64toi32_i32$1 | 0;
    i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0;
    i64toi32_i32$0 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
    i64toi32_i32$0 = i64toi32_i32$3 - i64toi32_i32$0 | 0;
    $1_1 = i64toi32_i32$5;
    $1$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$0 = $11$hi;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$2 = $11$hi;
    i64toi32_i32$1 = $11_1;
    i64toi32_i32$4 = i64toi32_i32$3 - i64toi32_i32$1 | 0;
    i64toi32_i32$6 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0;
    i64toi32_i32$5 = i64toi32_i32$6 + i64toi32_i32$2 | 0;
    i64toi32_i32$5 = i64toi32_i32$0 - i64toi32_i32$5 | 0;
    $4_1 = i64toi32_i32$4;
    $4$hi = i64toi32_i32$5;
   }
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$5 = $14$hi;
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$3 = $14$hi;
   i64toi32_i32$0 = 0;
   i64toi32_i32$1 = 0;
   $98($5_1 + 16 | 0 | 0, $3_1 | 0, i64toi32_i32$5 | 0, $14_1 | 0, i64toi32_i32$3 | 0, 3 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0);
   i64toi32_i32$1 = i64toi32_i32$5;
   i64toi32_i32$1 = i64toi32_i32$3;
   i64toi32_i32$1 = i64toi32_i32$5;
   i64toi32_i32$0 = i64toi32_i32$3;
   i64toi32_i32$3 = 0;
   i64toi32_i32$5 = 0;
   $98($5_1 | 0, $3_1 | 0, i64toi32_i32$1 | 0, $14_1 | 0, i64toi32_i32$0 | 0, 5 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$5 | 0);
   i64toi32_i32$5 = $10$hi;
   $667 = $10_1;
   $667$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $2$hi;
   $668 = $2_1;
   $668$hi = i64toi32_i32$5;
   i64toi32_i32$0 = $2_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = 1;
   i64toi32_i32$3 = i64toi32_i32$5 & i64toi32_i32$3 | 0;
   $11_1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
   $11$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $4$hi;
   i64toi32_i32$3 = $11$hi;
   i64toi32_i32$5 = $11_1;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$1 = $4_1;
   i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
   i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $4_1 = i64toi32_i32$2;
   $4$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $3$hi;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$3 = i64toi32_i32$2;
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$1 = $3_1;
   $676 = i64toi32_i32$4 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$1 >>> 0 | 0) | 0;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$3 = i64toi32_i32$4;
   i64toi32_i32$3 = $11$hi;
   i64toi32_i32$3 = i64toi32_i32$4;
   i64toi32_i32$1 = i64toi32_i32$2;
   i64toi32_i32$4 = $11$hi;
   i64toi32_i32$5 = $11_1;
   $680 = i64toi32_i32$3 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
   i64toi32_i32$1 = 0;
   $681$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$5 = $1_1;
   i64toi32_i32$3 = $681$hi;
   i64toi32_i32$4 = $680;
   i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
   i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
   }
   $1_1 = i64toi32_i32$0;
   $1$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $14$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$1 = i64toi32_i32$0;
   i64toi32_i32$5 = $14$hi;
   i64toi32_i32$4 = $14_1;
   $685 = i64toi32_i32$2 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$0 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0;
   i64toi32_i32$1 = i64toi32_i32$2;
   i64toi32_i32$1 = i64toi32_i32$5;
   i64toi32_i32$1 = i64toi32_i32$2;
   i64toi32_i32$4 = i64toi32_i32$0;
   i64toi32_i32$2 = i64toi32_i32$5;
   i64toi32_i32$5 = $14_1;
   $689 = (i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) | 0 ? $676 : $685;
   i64toi32_i32$4 = 0;
   $690$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $668$hi;
   i64toi32_i32$5 = $668;
   i64toi32_i32$1 = $690$hi;
   i64toi32_i32$2 = $689;
   i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
   i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
   }
   $3_1 = i64toi32_i32$3;
   $3$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$4 = i64toi32_i32$3;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$2 = $2_1;
   $694 = i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$4 = 0;
   $695$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $667$hi;
   i64toi32_i32$2 = $667;
   i64toi32_i32$0 = $695$hi;
   i64toi32_i32$5 = $694;
   i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
   i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
   }
   $2_1 = i64toi32_i32$1;
   $2$hi = i64toi32_i32$3;
   $697 = i64toi32_i32$1;
   $697$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$4 = i64toi32_i32$1;
   i64toi32_i32$2 = 2147418112;
   i64toi32_i32$5 = 0;
   $700 = i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$5 + 16 | 0) >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$5 + 20 | 0) >> 2] | 0;
   $703 = i64toi32_i32$4;
   $703$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $4$hi;
   i64toi32_i32$5 = $4_1;
   i64toi32_i32$4 = $703$hi;
   i64toi32_i32$2 = $703;
   $704 = i64toi32_i32$3 >>> 0 > i64toi32_i32$4 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0;
   i64toi32_i32$5 = $1$hi;
   i64toi32_i32$2 = ($5_1 + 16 | 0) + 8 | 0;
   i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   $2_1 = i64toi32_i32$5;
   $2$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$2 = $1_1;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$4 = $2_1;
   $711 = i64toi32_i32$3 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$3;
   i64toi32_i32$2 = i64toi32_i32$5;
   i64toi32_i32$2 = i64toi32_i32$3;
   i64toi32_i32$4 = $1_1;
   i64toi32_i32$3 = i64toi32_i32$5;
   i64toi32_i32$5 = $2_1;
   $716 = $700 & ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) | 0 ? $704 : $711) | 0;
   i64toi32_i32$4 = 0;
   $717$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $3$hi;
   i64toi32_i32$5 = $3_1;
   i64toi32_i32$2 = $717$hi;
   i64toi32_i32$3 = $716;
   i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
   i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
   }
   $2_1 = i64toi32_i32$0;
   $2$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$4 = i64toi32_i32$0;
   i64toi32_i32$5 = $3$hi;
   i64toi32_i32$3 = $3_1;
   $721 = i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
   i64toi32_i32$4 = 0;
   $722$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $697$hi;
   i64toi32_i32$3 = $697;
   i64toi32_i32$1 = $722$hi;
   i64toi32_i32$5 = $721;
   i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
   i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
   if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
   }
   $3_1 = i64toi32_i32$2;
   $3$hi = i64toi32_i32$0;
   $724 = i64toi32_i32$2;
   $724$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $2$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$4 = i64toi32_i32$2;
   i64toi32_i32$3 = 2147418112;
   i64toi32_i32$5 = 0;
   $727 = i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $730 = i64toi32_i32$4;
   $730$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$5 = $4_1;
   i64toi32_i32$4 = $730$hi;
   i64toi32_i32$3 = $730;
   $731 = i64toi32_i32$0 >>> 0 > i64toi32_i32$4 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0;
   i64toi32_i32$5 = $1$hi;
   i64toi32_i32$3 = $5_1 + 8 | 0;
   i64toi32_i32$5 = HEAP32[i64toi32_i32$3 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
   $4_1 = i64toi32_i32$5;
   $4$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$4 = $4_1;
   $737 = i64toi32_i32$0 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$0;
   i64toi32_i32$3 = i64toi32_i32$5;
   i64toi32_i32$3 = i64toi32_i32$0;
   i64toi32_i32$4 = $1_1;
   i64toi32_i32$0 = i64toi32_i32$5;
   i64toi32_i32$5 = $4_1;
   $742 = $727 & ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) | 0 ? $731 : $737) | 0;
   i64toi32_i32$4 = 0;
   $743$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $2$hi;
   i64toi32_i32$5 = $2_1;
   i64toi32_i32$3 = $743$hi;
   i64toi32_i32$0 = $742;
   i64toi32_i32$1 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
   i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
   if (i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
   }
   $1_1 = i64toi32_i32$1;
   $1$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$4 = i64toi32_i32$1;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$0 = $2_1;
   $747 = i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
   i64toi32_i32$4 = 0;
   $748$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $724$hi;
   i64toi32_i32$0 = $724;
   i64toi32_i32$2 = $748$hi;
   i64toi32_i32$5 = $747;
   i64toi32_i32$3 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
   i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
   }
   $749$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $12$hi;
   i64toi32_i32$1 = $749$hi;
   i64toi32_i32$4 = i64toi32_i32$3;
   i64toi32_i32$0 = $12$hi;
   i64toi32_i32$5 = $12_1;
   i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
   $12_1 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
   $12$hi = i64toi32_i32$0;
  }
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$4 = $0_1;
  HEAP32[i64toi32_i32$4 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] = i64toi32_i32$0;
  i64toi32_i32$0 = $12$hi;
  HEAP32[(i64toi32_i32$4 + 8 | 0) >> 2] = $12_1;
  HEAP32[(i64toi32_i32$4 + 12 | 0) >> 2] = i64toi32_i32$0;
  global$0 = $5_1 + 336 | 0;
 }
 
 function $90($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = +$1_1;
  var i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, i64toi32_i32$5 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$2 = 0, $5_1 = 0, $5$hi = 0, $2_1 = 0, $4_1 = 0, $6_1 = 0, $6$hi = 0, $4$hi = 0, $26_1 = 0, $27_1 = 0, $28_1 = 0, $29_1 = 0, $30_1 = 0, $3_1 = 0, $31_1 = 0, $32_1 = 0, $33_1 = 0, $33$hi = 0, $37_1 = 0, $50_1 = 0, $50$hi = 0, $54$hi = 0, $63_1 = 0, $63$hi = 0, $64_1 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    wasm2js_scratch_store_f64(+$1_1);
    i64toi32_i32$0 = wasm2js_scratch_load_i32(1 | 0) | 0;
    $4_1 = wasm2js_scratch_load_i32(0 | 0) | 0;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$1 = 2147483647;
    i64toi32_i32$3 = -1;
    i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    $5_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
    $5$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$2 = -1048576;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    i64toi32_i32$1 = i64toi32_i32$4;
    i64toi32_i32$0 = 2145386495;
    i64toi32_i32$3 = -1;
    if (i64toi32_i32$5 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$4 >>> 0 > i64toi32_i32$3 >>> 0 | 0) | 0) {
     break label$2
    }
    i64toi32_i32$1 = $5$hi;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$0 = 60;
    i64toi32_i32$2 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$3 << i64toi32_i32$2 | 0;
     $26_1 = 0;
    } else {
     i64toi32_i32$5 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$2 | 0) | 0;
     $26_1 = i64toi32_i32$3 << i64toi32_i32$2 | 0;
    }
    $6_1 = $26_1;
    $6$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $5$hi;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$0 = 4;
    i64toi32_i32$2 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $27_1 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$5 >>> i64toi32_i32$2 | 0;
     $27_1 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$2 | 0) | 0;
    }
    i64toi32_i32$5 = $27_1;
    i64toi32_i32$1 = 1006632960;
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $5_1 = i64toi32_i32$2;
    $5$hi = i64toi32_i32$4;
    break label$1;
   }
   label$3 : {
    i64toi32_i32$4 = $5$hi;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$5 = 2146435072;
    i64toi32_i32$0 = 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0) {
     break label$3
    }
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$0 = $4_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$5 = 60;
    i64toi32_i32$1 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$0 << i64toi32_i32$1 | 0;
     $28_1 = 0;
    } else {
     i64toi32_i32$4 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$1 | 0) | 0;
     $28_1 = i64toi32_i32$0 << i64toi32_i32$1 | 0;
    }
    $6_1 = $28_1;
    $6$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = 4;
    i64toi32_i32$1 = i64toi32_i32$5 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $29_1 = i64toi32_i32$4 >>> i64toi32_i32$1 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$4 >>> i64toi32_i32$1 | 0;
     $29_1 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$1 | 0) | 0;
    }
    i64toi32_i32$4 = $29_1;
    i64toi32_i32$3 = 2147418112;
    i64toi32_i32$5 = 0;
    i64toi32_i32$3 = i64toi32_i32$0 | i64toi32_i32$3 | 0;
    $5_1 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
    $5$hi = i64toi32_i32$3;
    break label$1;
   }
   label$4 : {
    i64toi32_i32$3 = $5$hi;
    if (!!($5_1 | i64toi32_i32$3 | 0)) {
     break label$4
    }
    i64toi32_i32$3 = 0;
    $6_1 = 0;
    $6$hi = i64toi32_i32$3;
    i64toi32_i32$3 = 0;
    $5_1 = 0;
    $5$hi = i64toi32_i32$3;
    break label$1;
   }
   $32_1 = $2_1;
   i64toi32_i32$3 = $5$hi;
   $33_1 = $5_1;
   $33$hi = i64toi32_i32$3;
   $37_1 = Math_clz32($5_1) + 32 | 0;
   i64toi32_i32$0 = $5_1;
   i64toi32_i32$4 = 0;
   i64toi32_i32$5 = 32;
   i64toi32_i32$1 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$4 = 0;
    $30_1 = i64toi32_i32$3 >>> i64toi32_i32$1 | 0;
   } else {
    i64toi32_i32$4 = i64toi32_i32$3 >>> i64toi32_i32$1 | 0;
    $30_1 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$1 | 0) | 0;
   }
   i64toi32_i32$4 = $5$hi;
   i64toi32_i32$3 = $5_1;
   i64toi32_i32$0 = 1;
   i64toi32_i32$5 = 0;
   $3_1 = i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0 ? $37_1 : Math_clz32($30_1);
   i64toi32_i32$3 = $33$hi;
   i64toi32_i32$4 = 0;
   $86($32_1 | 0, $33_1 | 0, i64toi32_i32$3 | 0, 0 | 0, i64toi32_i32$4 | 0, $3_1 + 49 | 0 | 0);
   i64toi32_i32$5 = $2_1 + 8 | 0;
   i64toi32_i32$4 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   i64toi32_i32$5 = i64toi32_i32$4;
   i64toi32_i32$4 = 65536;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = i64toi32_i32$3 ^ i64toi32_i32$4 | 0;
   $50_1 = i64toi32_i32$5 ^ i64toi32_i32$0 | 0;
   $50$hi = i64toi32_i32$4;
   i64toi32_i32$4 = 0;
   i64toi32_i32$3 = 15372 - $3_1 | 0;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = 48;
   i64toi32_i32$1 = i64toi32_i32$0 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$3 << i64toi32_i32$1 | 0;
    $31_1 = 0;
   } else {
    i64toi32_i32$5 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$1 | 0) | 0;
    $31_1 = i64toi32_i32$3 << i64toi32_i32$1 | 0;
   }
   $54$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $50$hi;
   i64toi32_i32$4 = $50_1;
   i64toi32_i32$3 = $54$hi;
   i64toi32_i32$0 = $31_1;
   i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $5_1 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
   $5$hi = i64toi32_i32$3;
   i64toi32_i32$5 = $2_1;
   i64toi32_i32$3 = HEAP32[i64toi32_i32$5 >> 2] | 0;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] | 0;
   $6_1 = i64toi32_i32$3;
   $6$hi = i64toi32_i32$4;
  }
  i64toi32_i32$4 = $6$hi;
  i64toi32_i32$3 = $0_1;
  HEAP32[i64toi32_i32$3 >> 2] = $6_1;
  HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] = i64toi32_i32$4;
  i64toi32_i32$4 = $5$hi;
  i64toi32_i32$4 = $4$hi;
  i64toi32_i32$5 = $4_1;
  i64toi32_i32$3 = -2147483648;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
  $63_1 = i64toi32_i32$5 & i64toi32_i32$0 | 0;
  $63$hi = i64toi32_i32$3;
  i64toi32_i32$3 = $5$hi;
  i64toi32_i32$4 = $5_1;
  i64toi32_i32$5 = $63$hi;
  i64toi32_i32$0 = $63_1;
  i64toi32_i32$5 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
  $64_1 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
  i64toi32_i32$4 = $0_1;
  HEAP32[(i64toi32_i32$4 + 8 | 0) >> 2] = $64_1;
  HEAP32[(i64toi32_i32$4 + 12 | 0) >> 2] = i64toi32_i32$5;
  global$0 = $2_1 + 16 | 0;
 }
 
 function $91($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = Math_fround($1_1);
  var i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, $4_1 = 0, i64toi32_i32$4 = 0, $2_1 = 0, $5_1 = 0, $5$hi = 0, $6_1 = 0, $6$hi = 0, $3_1 = 0, $24_1 = 0, $25_1 = 0, $26_1 = 0, $27_1 = 0, $30_1 = 0, $38_1 = 0, $38$hi = 0, $42$hi = 0, $48_1 = 0, $49_1 = 0, $49$hi = 0, $53$hi = 0, $54_1 = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    $3_1 = (wasm2js_scratch_store_f32($1_1), wasm2js_scratch_load_i32(2));
    $4_1 = $3_1 & 2147483647 | 0;
    if (($4_1 + -8388608 | 0) >>> 0 > 2130706431 >>> 0) {
     break label$2
    }
    i64toi32_i32$0 = 0;
    i64toi32_i32$2 = $4_1;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 25;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
     $24_1 = 0;
    } else {
     i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$4 | 0) | 0;
     $24_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
    }
    i64toi32_i32$0 = $24_1;
    i64toi32_i32$2 = 1065353216;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $5_1 = i64toi32_i32$4;
    $5$hi = i64toi32_i32$5;
    i64toi32_i32$5 = 0;
    $6_1 = 0;
    $6$hi = i64toi32_i32$5;
    break label$1;
   }
   label$3 : {
    if ($4_1 >>> 0 < 2139095040 >>> 0) {
     break label$3
    }
    i64toi32_i32$5 = 0;
    i64toi32_i32$1 = $3_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$3 = 25;
    i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
     $25_1 = 0;
    } else {
     i64toi32_i32$0 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$2 | 0) | 0;
     $25_1 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
    }
    i64toi32_i32$5 = $25_1;
    i64toi32_i32$1 = 2147418112;
    i64toi32_i32$3 = 0;
    i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
    $5_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
    $5$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $6_1 = 0;
    $6$hi = i64toi32_i32$1;
    break label$1;
   }
   label$4 : {
    if ($4_1) {
     break label$4
    }
    i64toi32_i32$1 = 0;
    $6_1 = 0;
    $6$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $5_1 = 0;
    $5$hi = i64toi32_i32$1;
    break label$1;
   }
   i64toi32_i32$1 = 0;
   $30_1 = $4_1;
   $4_1 = Math_clz32($4_1);
   i64toi32_i32$5 = 0;
   $86($2_1 | 0, $30_1 | 0, i64toi32_i32$1 | 0, 0 | 0, i64toi32_i32$5 | 0, $4_1 + 81 | 0 | 0);
   i64toi32_i32$0 = $2_1 + 8 | 0;
   i64toi32_i32$5 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   i64toi32_i32$0 = i64toi32_i32$5;
   i64toi32_i32$5 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$5 = i64toi32_i32$1 ^ i64toi32_i32$5 | 0;
   $38_1 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
   $38$hi = i64toi32_i32$5;
   i64toi32_i32$5 = 0;
   i64toi32_i32$1 = 16265 - $4_1 | 0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$3 = 48;
   i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
    $26_1 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$2 | 0) | 0;
    $26_1 = i64toi32_i32$1 << i64toi32_i32$2 | 0;
   }
   $42$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $38$hi;
   i64toi32_i32$5 = $38_1;
   i64toi32_i32$1 = $42$hi;
   i64toi32_i32$3 = $26_1;
   i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $5_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $5$hi = i64toi32_i32$1;
   i64toi32_i32$0 = $2_1;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$0 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
   $6_1 = i64toi32_i32$1;
   $6$hi = i64toi32_i32$5;
  }
  i64toi32_i32$5 = $6$hi;
  i64toi32_i32$1 = $0_1;
  HEAP32[i64toi32_i32$1 >> 2] = $6_1;
  HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] = i64toi32_i32$5;
  $48_1 = i64toi32_i32$1;
  i64toi32_i32$5 = $5$hi;
  $49_1 = $5_1;
  $49$hi = i64toi32_i32$5;
  i64toi32_i32$5 = 0;
  i64toi32_i32$0 = $3_1 & -2147483648 | 0;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
   $27_1 = 0;
  } else {
   i64toi32_i32$1 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$2 | 0) | 0;
   $27_1 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
  }
  $53$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $49$hi;
  i64toi32_i32$5 = $49_1;
  i64toi32_i32$0 = $53$hi;
  i64toi32_i32$3 = $27_1;
  i64toi32_i32$0 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
  $54_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
  i64toi32_i32$5 = $48_1;
  HEAP32[(i64toi32_i32$5 + 8 | 0) >> 2] = $54_1;
  HEAP32[(i64toi32_i32$5 + 12 | 0) >> 2] = i64toi32_i32$0;
  global$0 = $2_1 + 16 | 0;
 }
 
 function $92($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$5 = 0, i64toi32_i32$3 = 0, $3_1 = 0, i64toi32_i32$4 = 0, $2_1 = 0, $4_1 = 0, $4$hi = 0, $5_1 = 0, $5$hi = 0, $21_1 = 0, $22_1 = 0, $19_1 = 0, $27_1 = 0, $27$hi = 0, $31$hi = 0, $32_1 = 0, $32$hi = 0, $36$hi = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    if ($1_1) {
     break label$2
    }
    i64toi32_i32$0 = 0;
    $4_1 = 0;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $5_1 = 0;
    $5$hi = i64toi32_i32$0;
    break label$1;
   }
   $3_1 = $1_1 >> 31 | 0;
   $3_1 = ($1_1 ^ $3_1 | 0) - $3_1 | 0;
   i64toi32_i32$0 = 0;
   $19_1 = $3_1;
   $3_1 = Math_clz32($3_1);
   i64toi32_i32$1 = 0;
   $86($2_1 | 0, $19_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0, $3_1 + 81 | 0 | 0);
   i64toi32_i32$2 = $2_1 + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   i64toi32_i32$2 = i64toi32_i32$1;
   i64toi32_i32$1 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
   $27_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
   $27$hi = i64toi32_i32$1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$0 = 16414 - $3_1 | 0;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 48;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    $21_1 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
    $21_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   }
   $31$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $27$hi;
   i64toi32_i32$1 = $27_1;
   i64toi32_i32$0 = $31$hi;
   i64toi32_i32$3 = $21_1;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
   }
   $32_1 = i64toi32_i32$4;
   $32$hi = i64toi32_i32$5;
   i64toi32_i32$5 = 0;
   i64toi32_i32$2 = $1_1 & -2147483648 | 0;
   i64toi32_i32$1 = 0;
   i64toi32_i32$3 = 32;
   i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$0 | 0;
    $22_1 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$0 | 0) | 0;
    $22_1 = i64toi32_i32$2 << i64toi32_i32$0 | 0;
   }
   $36$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $32$hi;
   i64toi32_i32$5 = $32_1;
   i64toi32_i32$2 = $36$hi;
   i64toi32_i32$3 = $22_1;
   i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$2 | 0;
   $5_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $5$hi = i64toi32_i32$2;
   i64toi32_i32$1 = $2_1;
   i64toi32_i32$2 = HEAP32[i64toi32_i32$1 >> 2] | 0;
   i64toi32_i32$5 = HEAP32[(i64toi32_i32$1 + 4 | 0) >> 2] | 0;
   $4_1 = i64toi32_i32$2;
   $4$hi = i64toi32_i32$5;
  }
  i64toi32_i32$5 = $4$hi;
  i64toi32_i32$2 = $0_1;
  HEAP32[i64toi32_i32$2 >> 2] = $4_1;
  HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] = i64toi32_i32$5;
  i64toi32_i32$5 = $5$hi;
  HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] = $5_1;
  HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] = i64toi32_i32$5;
  global$0 = $2_1 + 16 | 0;
 }
 
 function $93($0_1, $1_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$5 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $2_1 = 0, $3_1 = 0, $3$hi = 0, $4_1 = 0, $4$hi = 0, $17_1 = 0, $11_1 = 0, $20_1 = 0, $20$hi = 0, $24$hi = 0;
  $2_1 = global$0 - 16 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    if ($1_1) {
     break label$2
    }
    i64toi32_i32$0 = 0;
    $3_1 = 0;
    $3$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $4_1 = 0;
    $4$hi = i64toi32_i32$0;
    break label$1;
   }
   i64toi32_i32$0 = 0;
   $11_1 = $1_1;
   $1_1 = Math_clz32($1_1);
   i64toi32_i32$1 = 0;
   $86($2_1 | 0, $11_1 | 0, i64toi32_i32$0 | 0, 0 | 0, i64toi32_i32$1 | 0, 112 - ($1_1 ^ 31 | 0) | 0 | 0);
   i64toi32_i32$2 = $2_1 + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   i64toi32_i32$2 = i64toi32_i32$1;
   i64toi32_i32$1 = 65536;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
   $20_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
   $20$hi = i64toi32_i32$1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$0 = 16414 - $1_1 | 0;
   i64toi32_i32$2 = 0;
   i64toi32_i32$3 = 48;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    $17_1 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
    $17_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   }
   $24$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $20$hi;
   i64toi32_i32$1 = $20_1;
   i64toi32_i32$0 = $24$hi;
   i64toi32_i32$3 = $17_1;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
   }
   $4_1 = i64toi32_i32$4;
   $4$hi = i64toi32_i32$5;
   i64toi32_i32$2 = $2_1;
   i64toi32_i32$5 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$1 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   $3_1 = i64toi32_i32$5;
   $3$hi = i64toi32_i32$1;
  }
  i64toi32_i32$1 = $3$hi;
  i64toi32_i32$5 = $0_1;
  HEAP32[i64toi32_i32$5 >> 2] = $3_1;
  HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] = i64toi32_i32$1;
  i64toi32_i32$1 = $4$hi;
  HEAP32[(i64toi32_i32$5 + 8 | 0) >> 2] = $4_1;
  HEAP32[(i64toi32_i32$5 + 12 | 0) >> 2] = i64toi32_i32$1;
  global$0 = $2_1 + 16 | 0;
 }
 
 function $94() {
  return 0 | 0;
 }
 
 function $95() {
  return 0 | 0;
 }
 
 function $96($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$4 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $4$hi = 0, $18_1 = 0, $20_1 = 0, $21_1 = 0, $22_1 = 0, $11$hi = 0, $18$hi = 0, $19_1 = 0, $19$hi = 0, $4_1 = 0, $24$hi = 0;
  label$1 : {
   label$2 : {
    if (!($3_1 & 64 | 0)) {
     break label$2
    }
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$0 = 0;
    $11$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$2 = $2_1;
    i64toi32_i32$1 = $11$hi;
    i64toi32_i32$3 = $3_1 + -64 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $18_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     $18_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
    }
    $1_1 = $18_1;
    $1$hi = i64toi32_i32$1;
    i64toi32_i32$1 = 0;
    $2_1 = 0;
    $2$hi = i64toi32_i32$1;
    break label$1;
   }
   if (!$3_1) {
    break label$1
   }
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = 0;
   $18$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$0 = $2_1;
   i64toi32_i32$2 = $18$hi;
   i64toi32_i32$3 = 64 - $3_1 | 0;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
    $20_1 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
    $20_1 = i64toi32_i32$0 << i64toi32_i32$4 | 0;
   }
   $19_1 = $20_1;
   $19$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = 0;
   $4_1 = $3_1;
   $4$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$1 = $1_1;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$3 = $3_1;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $21_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
    $21_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
   }
   $24$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $19$hi;
   i64toi32_i32$2 = $19_1;
   i64toi32_i32$1 = $24$hi;
   i64toi32_i32$3 = $21_1;
   i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $1_1 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   $1$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$0 = $2_1;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$3 = $4_1;
   i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $22_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
    $22_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
   }
   $2_1 = $22_1;
   $2$hi = i64toi32_i32$2;
  }
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$0 = $0_1;
  HEAP32[i64toi32_i32$0 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$2;
  i64toi32_i32$2 = $2$hi;
  HEAP32[(i64toi32_i32$0 + 8 | 0) >> 2] = $2_1;
  HEAP32[(i64toi32_i32$0 + 12 | 0) >> 2] = i64toi32_i32$2;
 }
 
 function $97($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$3 = 0, i64toi32_i32$2 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$4 = 0, $14$hi = 0, $5_1 = 0, $11$hi = 0, $11_1 = 0, $14_1 = 0, $10$hi = 0, $12$hi = 0, $6_1 = 0, $18$hi = 0, $12_1 = 0, $10_1 = 0, $8_1 = 0, $15$hi = 0, $18_1 = 0, $7_1 = 0, $16$hi = 0, $17$hi = 0, $20$hi = 0, $13_1 = 0, $13$hi = 0, $16_1 = 0, $17_1 = 0, $20_1 = 0, $15_1 = 0, $21$hi = 0, $9_1 = 0, $19$hi = 0, $22$hi = 0, $23$hi = 0, $24$hi = 0, $220 = 0, $221 = 0, $223 = 0, $224 = 0, $226 = 0, $228 = 0, $229 = 0, $230 = 0, $231 = 0, $232 = 0, $19_1 = 0, $233 = 0, $234 = 0, $21_1 = 0, $235 = 0, $237 = 0, $22_1 = 0, $239 = 0, $240 = 0, $24_1 = 0, $241 = 0, $242 = 0, $243 = 0, $245 = 0, $246 = 0, $247 = 0, $248 = 0, $250 = 0, $251 = 0, $252 = 0, $253 = 0, $254 = 0, $255 = 0, $256 = 0, $257 = 0, $258 = 0, $53_1 = 0, $57_1 = 0, $64_1 = 0, $68_1 = 0, $77_1 = 0, $77$hi = 0, $89_1 = 0, $89$hi = 0, $111 = 0, $112 = 0, $112$hi = 0, $113 = 0, $113$hi = 0, $120$hi = 0, $123$hi = 0, $140 = 0, $141 = 0, $141$hi = 0, $142 = 0, $142$hi = 0, $149$hi = 0, $152$hi = 0, $170 = 0, $170$hi = 0, $175 = 0, $175$hi = 0, $182 = 0, $182$hi = 0, $189 = 0, $189$hi = 0, $194 = 0, $194$hi = 0, $203 = 0, $203$hi = 0, $205 = 0, $205$hi = 0, $207 = 0, $207$hi = 0, $215 = 0, $215$hi = 0, $217 = 0, $217$hi = 0, $219 = 0, $219$hi = 0, $222 = 0, $224$hi = 0, $225 = 0, $225$hi = 0, $227 = 0, $227$hi = 0, $236 = 0, $236$hi = 0, $238 = 0, $238$hi = 0, $244 = 0, $244$hi = 0, $249 = 0, $249$hi = 0, $252$hi = 0, $23_1 = 0, $268 = 0, $268$hi = 0, $272 = 0, $273 = 0, $273$hi = 0, $277 = 0, $277$hi = 0, $281 = 0, $282$hi = 0, $283$hi = 0, $286 = 0, $286$hi = 0, $287 = 0, $287$hi = 0, $288 = 0, $288$hi = 0, $291 = 0, $292$hi = 0, $295 = 0, $296$hi = 0, $297$hi = 0, $301 = 0, $302$hi = 0, $303 = 0, $303$hi = 0, $310 = 0, $310$hi = 0, $314 = 0, $316 = 0, $316$hi = 0, $318$hi = 0, $319 = 0, $319$hi = 0, $320 = 0, $320$hi = 0, $321 = 0, $321$hi = 0, $323$hi = 0, $327 = 0, $328$hi = 0, $329 = 0, $329$hi = 0, $330 = 0, $330$hi = 0, $332 = 0, $332$hi = 0, $335 = 0, $336$hi = 0, $339 = 0, $340$hi = 0, $341$hi = 0, $344 = 0, $345$hi = 0, $347$hi = 0, $348 = 0, $348$hi = 0, $352 = 0, $353$hi = 0, $354 = 0, $354$hi = 0, $355 = 0, $355$hi = 0, $358 = 0, $359$hi = 0, $362 = 0, $363$hi = 0, $364$hi = 0, $368 = 0, $369$hi = 0, $379 = 0, $379$hi = 0, $381$hi = 0, $384 = 0, $384$hi = 0, $386$hi = 0, $390 = 0, $390$hi = 0, $392$hi = 0, $426 = 0, $426$hi = 0, $428 = 0, $428$hi = 0, $429 = 0, $429$hi = 0, $431 = 0, $431$hi = 0, $435 = 0, $435$hi = 0, $437 = 0, $438$hi = 0, $443 = 0, $443$hi = 0, $447 = 0, $447$hi = 0, $456$hi = 0, $458 = 0, $458$hi = 0, $464 = 0, $470 = 0, $470$hi = 0, $474 = 0, $475$hi = 0, $479 = 0, $479$hi = 0, $483 = 0, $483$hi = 0, $486 = 0, $486$hi = 0, $490 = 0, $491$hi = 0;
  $5_1 = global$0 - 96 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $10_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $10$hi = i64toi32_i32$1;
  i64toi32_i32$1 = i64toi32_i32$0;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = i64toi32_i32$0;
  i64toi32_i32$0 = i64toi32_i32$2;
  i64toi32_i32$2 = $2$hi;
  i64toi32_i32$3 = $2_1;
  i64toi32_i32$2 = i64toi32_i32$1 ^ i64toi32_i32$2 | 0;
  i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
  i64toi32_i32$0 = -2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
  $11_1 = i64toi32_i32$1 & i64toi32_i32$3 | 0;
  $11$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$2 = $2_1;
  i64toi32_i32$1 = 65535;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
  $12_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
  $12$hi = i64toi32_i32$1;
  i64toi32_i32$0 = $12_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = 0;
   $220 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   $220 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
  }
  $13_1 = $220;
  $13$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$1 = $4_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 48;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = 0;
   $221 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   $221 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$4 | 0) | 0;
  }
  $6_1 = $221 & 32767 | 0;
  label$1 : {
   label$2 : {
    label$3 : {
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$3 = 48;
     i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $223 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
      $223 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
     }
     $7_1 = $223 & 32767 | 0;
     if (($7_1 + -32767 | 0) >>> 0 < -32766 >>> 0) {
      break label$3
     }
     $8_1 = 0;
     if (($6_1 + -32767 | 0) >>> 0 > -32767 >>> 0) {
      break label$2
     }
    }
    label$4 : {
     i64toi32_i32$1 = $1$hi;
     $53_1 = !($1_1 | i64toi32_i32$1 | 0);
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$2 = 2147483647;
     i64toi32_i32$3 = -1;
     i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
     $14_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
     $14$hi = i64toi32_i32$2;
     i64toi32_i32$1 = $14_1;
     i64toi32_i32$0 = 2147418112;
     i64toi32_i32$3 = 0;
     $57_1 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$1 = i64toi32_i32$2;
     i64toi32_i32$3 = $14_1;
     i64toi32_i32$2 = 2147418112;
     i64toi32_i32$0 = 0;
     if ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$2 | 0) | 0 ? $53_1 : $57_1) {
      break label$4
     }
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$0 = $2_1;
     i64toi32_i32$1 = 32768;
     i64toi32_i32$2 = 0;
     i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     $11_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     $11$hi = i64toi32_i32$1;
     break label$1;
    }
    label$5 : {
     i64toi32_i32$1 = $3$hi;
     $64_1 = !($3_1 | i64toi32_i32$1 | 0);
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$0 = 2147483647;
     i64toi32_i32$2 = -1;
     i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
     $2_1 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$1 = $2_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$2 = 0;
     $68_1 = i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$1 = i64toi32_i32$0;
     i64toi32_i32$1 = i64toi32_i32$0;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$0 = 2147418112;
     i64toi32_i32$3 = 0;
     if ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$0 | 0) | 0 ? $64_1 : $68_1) {
      break label$5
     }
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$3 = $4_1;
     i64toi32_i32$1 = 32768;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     $11_1 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
     $11$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $3$hi;
     $1_1 = $3_1;
     $1$hi = i64toi32_i32$1;
     break label$1;
    }
    label$6 : {
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $14$hi;
     i64toi32_i32$2 = $14_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$0 = 0;
     i64toi32_i32$3 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
     $77_1 = i64toi32_i32$2 ^ i64toi32_i32$0 | 0;
     $77$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$1 = $1_1;
     i64toi32_i32$2 = $77$hi;
     i64toi32_i32$0 = $77_1;
     i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     i64toi32_i32$1 = 0;
     i64toi32_i32$0 = 0;
     if ((i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$1 | 0) | 0) {
      break label$6
     }
     label$7 : {
      i64toi32_i32$3 = $3$hi;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = $3$hi;
      i64toi32_i32$0 = $3_1;
      i64toi32_i32$2 = $2$hi;
      i64toi32_i32$1 = $2_1;
      i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
      if (!!(i64toi32_i32$0 | i64toi32_i32$1 | 0 | i64toi32_i32$2 | 0)) {
       break label$7
      }
      i64toi32_i32$2 = 2147450880;
      $11_1 = 0;
      $11$hi = i64toi32_i32$2;
      i64toi32_i32$2 = 0;
      $1_1 = 0;
      $1$hi = i64toi32_i32$2;
      break label$1;
     }
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$3 = $11_1;
     i64toi32_i32$0 = 2147418112;
     i64toi32_i32$1 = 0;
     i64toi32_i32$0 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     $11_1 = i64toi32_i32$3 | i64toi32_i32$1 | 0;
     $11$hi = i64toi32_i32$0;
     i64toi32_i32$0 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$0;
     break label$1;
    }
    label$8 : {
     i64toi32_i32$0 = $3$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$3 = 2147418112;
     i64toi32_i32$1 = 0;
     i64toi32_i32$3 = i64toi32_i32$0 ^ i64toi32_i32$3 | 0;
     $89_1 = i64toi32_i32$2 ^ i64toi32_i32$1 | 0;
     $89$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$0 = $3_1;
     i64toi32_i32$2 = $89$hi;
     i64toi32_i32$1 = $89_1;
     i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     i64toi32_i32$3 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = 0;
     if ((i64toi32_i32$3 | 0) != (i64toi32_i32$1 | 0) | (i64toi32_i32$2 | 0) != (i64toi32_i32$0 | 0) | 0) {
      break label$8
     }
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$3 = $14$hi;
     i64toi32_i32$3 = $1$hi;
     i64toi32_i32$1 = $1_1;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$0 = $14_1;
     i64toi32_i32$2 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
     $2_1 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
     $2$hi = i64toi32_i32$2;
     i64toi32_i32$2 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$2;
     label$9 : {
      i64toi32_i32$2 = $2$hi;
      if (!!($2_1 | i64toi32_i32$2 | 0)) {
       break label$9
      }
      i64toi32_i32$2 = 2147450880;
      $11_1 = 0;
      $11$hi = i64toi32_i32$2;
      break label$1;
     }
     i64toi32_i32$2 = $11$hi;
     i64toi32_i32$3 = $11_1;
     i64toi32_i32$1 = 2147418112;
     i64toi32_i32$0 = 0;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
     $11_1 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
     $11$hi = i64toi32_i32$1;
     break label$1;
    }
    label$10 : {
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$1 = $14$hi;
     i64toi32_i32$1 = $1$hi;
     i64toi32_i32$2 = $1_1;
     i64toi32_i32$3 = $14$hi;
     i64toi32_i32$0 = $14_1;
     i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$0 | 0;
     i64toi32_i32$2 = 0;
     i64toi32_i32$0 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$0 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$2 | 0) | 0) {
      break label$10
     }
     i64toi32_i32$1 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$1;
     break label$1;
    }
    label$11 : {
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$1 = $2$hi;
     i64toi32_i32$1 = $3$hi;
     i64toi32_i32$0 = $3_1;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$2 = $2_1;
     i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
     i64toi32_i32$0 = 0;
     i64toi32_i32$2 = 0;
     if ((i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | (i64toi32_i32$3 | 0) != (i64toi32_i32$0 | 0) | 0) {
      break label$11
     }
     i64toi32_i32$1 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$1;
     break label$1;
    }
    $8_1 = 0;
    label$12 : {
     i64toi32_i32$1 = $14$hi;
     i64toi32_i32$2 = $14_1;
     i64toi32_i32$3 = 65535;
     i64toi32_i32$0 = -1;
     if (i64toi32_i32$1 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$1 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$2 >>> 0 > i64toi32_i32$0 >>> 0 | 0) | 0) {
      break label$12
     }
     $111 = $5_1 + 80 | 0;
     i64toi32_i32$2 = $1$hi;
     $112 = $1_1;
     $112$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $12$hi;
     $113 = $12_1;
     $113$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$2 = $12$hi;
     $8_1 = !($12_1 | i64toi32_i32$2 | 0);
     i64toi32_i32$4 = $8_1;
     i64toi32_i32$2 = $1$hi;
     i64toi32_i32$1 = $12$hi;
     i64toi32_i32$3 = i64toi32_i32$4 ? $1_1 : $12_1;
     i64toi32_i32$0 = i64toi32_i32$4 ? i64toi32_i32$2 : i64toi32_i32$1;
     i64toi32_i32$2 = Math_clz32(i64toi32_i32$0);
     i64toi32_i32$4 = 0;
     if ((i64toi32_i32$2 | 0) == (32 | 0)) {
      $224 = Math_clz32(i64toi32_i32$3) + 32 | 0
     } else {
      $224 = i64toi32_i32$2
     }
     $120$hi = i64toi32_i32$4;
     i64toi32_i32$4 = 0;
     $123$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $120$hi;
     i64toi32_i32$3 = $224;
     i64toi32_i32$0 = $123$hi;
     i64toi32_i32$2 = $8_1 << 6 | 0;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $8_1 = i64toi32_i32$1;
     i64toi32_i32$5 = $112$hi;
     i64toi32_i32$3 = $113$hi;
     $86($111 | 0, $112 | 0, i64toi32_i32$5 | 0, $113 | 0, i64toi32_i32$3 | 0, i64toi32_i32$1 + -15 | 0 | 0);
     $8_1 = 16 - i64toi32_i32$1 | 0;
     i64toi32_i32$4 = $5_1 + 88 | 0;
     i64toi32_i32$3 = HEAP32[i64toi32_i32$4 >> 2] | 0;
     i64toi32_i32$5 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
     $12_1 = i64toi32_i32$3;
     $12$hi = i64toi32_i32$5;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$3 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$3 = 0;
      $226 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$3 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
      $226 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$0 | 0) | 0;
     }
     $13_1 = $226;
     $13$hi = i64toi32_i32$3;
     i64toi32_i32$5 = $5_1;
     i64toi32_i32$3 = HEAP32[(i64toi32_i32$5 + 80 | 0) >> 2] | 0;
     i64toi32_i32$4 = HEAP32[(i64toi32_i32$5 + 84 | 0) >> 2] | 0;
     $1_1 = i64toi32_i32$3;
     $1$hi = i64toi32_i32$4;
    }
    i64toi32_i32$4 = $2$hi;
    i64toi32_i32$5 = $2_1;
    i64toi32_i32$3 = 65535;
    i64toi32_i32$2 = -1;
    if (i64toi32_i32$4 >>> 0 > i64toi32_i32$3 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$5 >>> 0 > i64toi32_i32$2 >>> 0 | 0) | 0) {
     break label$2
    }
    $140 = $5_1 + 64 | 0;
    i64toi32_i32$5 = $3$hi;
    $141 = $3_1;
    $141$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $10$hi;
    $142 = $10_1;
    $142$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$5 = $10$hi;
    $9_1 = !($10_1 | i64toi32_i32$5 | 0);
    i64toi32_i32$0 = $9_1;
    i64toi32_i32$5 = $3$hi;
    i64toi32_i32$4 = $10$hi;
    i64toi32_i32$3 = i64toi32_i32$0 ? $3_1 : $10_1;
    i64toi32_i32$2 = i64toi32_i32$0 ? i64toi32_i32$5 : i64toi32_i32$4;
    i64toi32_i32$5 = Math_clz32(i64toi32_i32$2);
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$5 | 0) == (32 | 0)) {
     $228 = Math_clz32(i64toi32_i32$3) + 32 | 0
    } else {
     $228 = i64toi32_i32$5
    }
    $149$hi = i64toi32_i32$0;
    i64toi32_i32$0 = 0;
    $152$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $149$hi;
    i64toi32_i32$3 = $228;
    i64toi32_i32$2 = $152$hi;
    i64toi32_i32$5 = $9_1 << 6 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
    i64toi32_i32$1 = i64toi32_i32$0 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
    }
    $9_1 = i64toi32_i32$4;
    i64toi32_i32$1 = $141$hi;
    i64toi32_i32$3 = $142$hi;
    $86($140 | 0, $141 | 0, i64toi32_i32$1 | 0, $142 | 0, i64toi32_i32$3 | 0, i64toi32_i32$4 + -15 | 0 | 0);
    $8_1 = ($8_1 - i64toi32_i32$4 | 0) + 16 | 0;
    i64toi32_i32$0 = $5_1 + 72 | 0;
    i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
    $10_1 = i64toi32_i32$3;
    $10$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$0 + 64 | 0) >> 2] | 0;
    i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 68 | 0) >> 2] | 0;
    $3_1 = i64toi32_i32$1;
    $3$hi = i64toi32_i32$3;
   }
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$0 = $3_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 15;
   i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
    $229 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$2 | 0) | 0;
    $229 = i64toi32_i32$0 << i64toi32_i32$2 | 0;
   }
   $14_1 = $229;
   $14$hi = i64toi32_i32$1;
   i64toi32_i32$3 = $14_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = -32768;
   i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
   $2_1 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
   $2$hi = i64toi32_i32$0;
   $170 = $2_1;
   $170$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$1 = $1_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$5 = 32;
   i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = 0;
    $230 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
   } else {
    i64toi32_i32$3 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
    $230 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$2 | 0) | 0;
   }
   $4_1 = $230;
   $4$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $170$hi;
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$1 = __wasm_i64_mul($170 | 0, i64toi32_i32$3 | 0, $4_1 | 0, i64toi32_i32$1 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
   $15_1 = i64toi32_i32$1;
   $15$hi = i64toi32_i32$3;
   $175 = i64toi32_i32$1;
   $175$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $14$hi;
   i64toi32_i32$0 = $14_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 32;
   i64toi32_i32$2 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $231 = i64toi32_i32$3 >>> i64toi32_i32$2 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$3 >>> i64toi32_i32$2 | 0;
    $231 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$2 | 0) | 0;
   }
   $14_1 = $231;
   $14$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$3 = $1_1;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = -1;
   i64toi32_i32$0 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
   $1_1 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
   $1$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $14$hi;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$3 = __wasm_i64_mul($14_1 | 0, i64toi32_i32$0 | 0, $1_1 | 0, i64toi32_i32$3 | 0) | 0;
   i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
   $182 = i64toi32_i32$3;
   $182$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $175$hi;
   i64toi32_i32$1 = $175;
   i64toi32_i32$3 = $182$hi;
   i64toi32_i32$5 = $182;
   i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
   i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
   if (i64toi32_i32$2 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $16_1 = i64toi32_i32$2;
   $16$hi = i64toi32_i32$4;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 32;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $232 = 0;
   } else {
    i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$3 | 0) | 0;
    $232 = i64toi32_i32$0 << i64toi32_i32$3 | 0;
   }
   $17_1 = $232;
   $17$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$0 = $1$hi;
   i64toi32_i32$0 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$1 | 0, $1_1 | 0, i64toi32_i32$0 | 0) | 0;
   i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
   $189 = i64toi32_i32$0;
   $189$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $17$hi;
   i64toi32_i32$4 = $17_1;
   i64toi32_i32$0 = $189$hi;
   i64toi32_i32$5 = $189;
   i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
   i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
   }
   $18_1 = i64toi32_i32$3;
   $18$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $17$hi;
   i64toi32_i32$2 = $18$hi;
   i64toi32_i32$1 = i64toi32_i32$3;
   i64toi32_i32$4 = $17$hi;
   i64toi32_i32$5 = $17_1;
   i64toi32_i32$1 = 0;
   $194 = i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
   $194$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $2$hi;
   i64toi32_i32$1 = $12$hi;
   i64toi32_i32$5 = $12_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$4 = -1;
   i64toi32_i32$2 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
   $12_1 = i64toi32_i32$5 & i64toi32_i32$4 | 0;
   $12$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$5 = $12$hi;
   i64toi32_i32$5 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$2 | 0, $12_1 | 0, i64toi32_i32$5 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
   $19_1 = i64toi32_i32$5;
   $19$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $14$hi;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$2 = $14$hi;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$5 = __wasm_i64_mul($14_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
   i64toi32_i32$2 = i64toi32_i32$HIGH_BITS;
   $203 = i64toi32_i32$5;
   $203$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $19$hi;
   i64toi32_i32$1 = $19_1;
   i64toi32_i32$5 = $203$hi;
   i64toi32_i32$4 = $203;
   i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
   i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
   }
   $17_1 = i64toi32_i32$0;
   $17$hi = i64toi32_i32$3;
   $205 = i64toi32_i32$0;
   $205$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $3$hi;
   i64toi32_i32$2 = $3_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = 49;
   i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $233 = i64toi32_i32$3 >>> i64toi32_i32$5 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$3 >>> i64toi32_i32$5 | 0;
    $233 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$5 | 0) | 0;
   }
   $207 = $233;
   $207$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $10$hi;
   i64toi32_i32$3 = $10_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$4 = 15;
   i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
    $234 = 0;
   } else {
    i64toi32_i32$2 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$5 | 0) | 0;
    $234 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
   }
   $20_1 = $234;
   $20$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $207$hi;
   i64toi32_i32$1 = $207;
   i64toi32_i32$3 = $20$hi;
   i64toi32_i32$4 = $20_1;
   i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
   i64toi32_i32$2 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
   i64toi32_i32$1 = 0;
   i64toi32_i32$4 = -1;
   i64toi32_i32$1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
   $3_1 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
   $3$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $1$hi;
   i64toi32_i32$1 = $3$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$1 | 0, $1_1 | 0, i64toi32_i32$2 | 0) | 0;
   i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
   $215 = i64toi32_i32$2;
   $215$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $205$hi;
   i64toi32_i32$3 = $205;
   i64toi32_i32$2 = $215$hi;
   i64toi32_i32$4 = $215;
   i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
   if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
   }
   $21_1 = i64toi32_i32$5;
   $21$hi = i64toi32_i32$0;
   $217 = i64toi32_i32$5;
   $217$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $16$hi;
   i64toi32_i32$1 = $16_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$4 = 32;
   i64toi32_i32$2 = i64toi32_i32$4 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = 0;
    $235 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
   } else {
    i64toi32_i32$3 = i64toi32_i32$0 >>> i64toi32_i32$2 | 0;
    $235 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$2 | 0) | 0;
   }
   $219 = $235;
   $219$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $16$hi;
   i64toi32_i32$3 = $15$hi;
   i64toi32_i32$3 = $16$hi;
   i64toi32_i32$0 = $16_1;
   i64toi32_i32$1 = $15$hi;
   i64toi32_i32$4 = $15_1;
   $222 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$4 = $222;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = 32;
   i64toi32_i32$2 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$4 << i64toi32_i32$2 | 0;
    $237 = 0;
   } else {
    i64toi32_i32$3 = ((1 << i64toi32_i32$2 | 0) - 1 | 0) & (i64toi32_i32$4 >>> (32 - i64toi32_i32$2 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$2 | 0) | 0;
    $237 = i64toi32_i32$4 << i64toi32_i32$2 | 0;
   }
   $224$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $219$hi;
   i64toi32_i32$0 = $219;
   i64toi32_i32$4 = $224$hi;
   i64toi32_i32$1 = $237;
   i64toi32_i32$4 = i64toi32_i32$3 | i64toi32_i32$4 | 0;
   $225 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
   $225$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $217$hi;
   i64toi32_i32$3 = $217;
   i64toi32_i32$0 = $225$hi;
   i64toi32_i32$1 = $225;
   i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
   i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
   }
   $16_1 = i64toi32_i32$2;
   $16$hi = i64toi32_i32$5;
   $227 = i64toi32_i32$2;
   $227$hi = i64toi32_i32$5;
   i64toi32_i32$5 = $2$hi;
   i64toi32_i32$5 = $13$hi;
   i64toi32_i32$4 = $13_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = 65536;
   i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $10_1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
   $10$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$4 = $10$hi;
   i64toi32_i32$4 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$4 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
   $22_1 = i64toi32_i32$4;
   $22$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $14$hi;
   i64toi32_i32$3 = $12$hi;
   i64toi32_i32$3 = $14$hi;
   i64toi32_i32$4 = $12$hi;
   i64toi32_i32$4 = __wasm_i64_mul($14_1 | 0, i64toi32_i32$3 | 0, $12_1 | 0, i64toi32_i32$4 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
   $236 = i64toi32_i32$4;
   $236$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $22$hi;
   i64toi32_i32$5 = $22_1;
   i64toi32_i32$4 = $236$hi;
   i64toi32_i32$1 = $236;
   i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
   i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
   }
   $13_1 = i64toi32_i32$0;
   $13$hi = i64toi32_i32$2;
   $238 = i64toi32_i32$0;
   $238$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $20$hi;
   i64toi32_i32$3 = $20_1;
   i64toi32_i32$5 = 0;
   i64toi32_i32$1 = 32;
   i64toi32_i32$4 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$5 = 0;
    $239 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
   } else {
    i64toi32_i32$5 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
    $239 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
   }
   i64toi32_i32$2 = $239;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = -2147483648;
   i64toi32_i32$3 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
   $2_1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
   $2$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$3 = $2$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$2 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$3 | 0, $1_1 | 0, i64toi32_i32$2 | 0) | 0;
   i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
   $244 = i64toi32_i32$2;
   $244$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $238$hi;
   i64toi32_i32$5 = $238;
   i64toi32_i32$2 = $244$hi;
   i64toi32_i32$1 = $244;
   i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
   i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
   if (i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
   }
   $15_1 = i64toi32_i32$4;
   $15$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$0 = $4$hi;
   i64toi32_i32$0 = $3$hi;
   i64toi32_i32$5 = $4$hi;
   i64toi32_i32$5 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
   i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
   $249 = i64toi32_i32$5;
   $249$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $15$hi;
   i64toi32_i32$3 = i64toi32_i32$4;
   i64toi32_i32$5 = $249$hi;
   i64toi32_i32$1 = $249;
   i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$1 | 0;
   i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
   if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $20_1 = i64toi32_i32$2;
   $20$hi = i64toi32_i32$4;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$3 = 0;
   i64toi32_i32$1 = 32;
   i64toi32_i32$5 = i64toi32_i32$1 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$5 | 0;
    $240 = 0;
   } else {
    i64toi32_i32$3 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$5 | 0) | 0;
    $240 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
   }
   $252$hi = i64toi32_i32$3;
   i64toi32_i32$3 = $227$hi;
   i64toi32_i32$4 = $227;
   i64toi32_i32$0 = $252$hi;
   i64toi32_i32$1 = $240;
   i64toi32_i32$5 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
   i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
   if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
   }
   $23_1 = i64toi32_i32$5;
   $23$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $194$hi;
   i64toi32_i32$3 = $194;
   i64toi32_i32$4 = $23$hi;
   i64toi32_i32$1 = i64toi32_i32$5;
   i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
   i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
    i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
   }
   $1_1 = i64toi32_i32$0;
   $1$hi = i64toi32_i32$5;
   $6_1 = (($7_1 + $6_1 | 0) + $8_1 | 0) + -16383 | 0;
   label$13 : {
    label$14 : {
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$3 = $4$hi;
     i64toi32_i32$3 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$5 | 0, $4_1 | 0, i64toi32_i32$3 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $24_1 = i64toi32_i32$3;
     $24$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $14$hi;
     i64toi32_i32$5 = $10$hi;
     i64toi32_i32$5 = $14$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = __wasm_i64_mul($14_1 | 0, i64toi32_i32$5 | 0, $10_1 | 0, i64toi32_i32$3 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $268 = i64toi32_i32$3;
     $268$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $24$hi;
     i64toi32_i32$2 = $24_1;
     i64toi32_i32$3 = $268$hi;
     i64toi32_i32$1 = $268;
     i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     i64toi32_i32$0 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $4_1 = i64toi32_i32$4;
     $4$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $24$hi;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$2 = $24$hi;
     i64toi32_i32$1 = $24_1;
     $272 = i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $273 = $272;
     $273$hi = i64toi32_i32$5;
     i64toi32_i32$5 = i64toi32_i32$0;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$5 = $12$hi;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$0 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$5 | 0, $12_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$5 = i64toi32_i32$HIGH_BITS;
     $277 = i64toi32_i32$0;
     $277$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$1 = i64toi32_i32$4;
     i64toi32_i32$0 = $277$hi;
     i64toi32_i32$2 = $277;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $14_1 = i64toi32_i32$3;
     $14$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $4$hi;
     i64toi32_i32$4 = $14$hi;
     i64toi32_i32$5 = i64toi32_i32$3;
     i64toi32_i32$1 = $4$hi;
     i64toi32_i32$2 = $4_1;
     $281 = i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $282$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $273$hi;
     i64toi32_i32$2 = $273;
     i64toi32_i32$4 = $282$hi;
     i64toi32_i32$1 = $281;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $283$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$2 = $10$hi;
     i64toi32_i32$2 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$2 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $286 = i64toi32_i32$2;
     $286$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $283$hi;
     i64toi32_i32$5 = i64toi32_i32$0;
     i64toi32_i32$2 = $286$hi;
     i64toi32_i32$1 = $286;
     i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     i64toi32_i32$0 = i64toi32_i32$3 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $287 = i64toi32_i32$4;
     $287$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $14$hi;
     $288 = $14_1;
     $288$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $17$hi;
     i64toi32_i32$0 = $19$hi;
     i64toi32_i32$0 = $17$hi;
     i64toi32_i32$3 = $17_1;
     i64toi32_i32$5 = $19$hi;
     i64toi32_i32$1 = $19_1;
     $291 = i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     $292$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$3 = i64toi32_i32$0;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$1 = $21_1;
     i64toi32_i32$5 = $17_1;
     $295 = i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
     i64toi32_i32$1 = 0;
     $296$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $292$hi;
     i64toi32_i32$5 = $291;
     i64toi32_i32$3 = $296$hi;
     i64toi32_i32$0 = $295;
     i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
     i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
     }
     $297$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $288$hi;
     i64toi32_i32$1 = $288;
     i64toi32_i32$5 = $297$hi;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $4_1 = i64toi32_i32$3;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $14$hi;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$1 = $14$hi;
     i64toi32_i32$0 = $14_1;
     $301 = i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$0 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $302$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $287$hi;
     i64toi32_i32$0 = $287;
     i64toi32_i32$2 = $302$hi;
     i64toi32_i32$1 = $301;
     i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $303 = i64toi32_i32$5;
     $303$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$3 = $10$hi;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$0 = $10$hi;
     i64toi32_i32$0 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$3 | 0, $10_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $3_1 = i64toi32_i32$0;
     $3$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$3 = $12$hi;
     i64toi32_i32$3 = $2$hi;
     i64toi32_i32$0 = $12$hi;
     i64toi32_i32$0 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$3 | 0, $12_1 | 0, i64toi32_i32$0 | 0) | 0;
     i64toi32_i32$3 = i64toi32_i32$HIGH_BITS;
     $310 = i64toi32_i32$0;
     $310$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $3$hi;
     i64toi32_i32$4 = $3_1;
     i64toi32_i32$0 = $310$hi;
     i64toi32_i32$1 = $310;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$3 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $3$hi;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$3 = i64toi32_i32$2;
     i64toi32_i32$4 = $3$hi;
     i64toi32_i32$1 = $3_1;
     $314 = i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$3 = 0;
     i64toi32_i32$1 = $314;
     i64toi32_i32$5 = 0;
     i64toi32_i32$4 = 32;
     i64toi32_i32$0 = i64toi32_i32$4 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$1 << i64toi32_i32$0 | 0;
      $241 = 0;
     } else {
      i64toi32_i32$5 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$0 | 0) | 0;
      $241 = i64toi32_i32$1 << i64toi32_i32$0 | 0;
     }
     $316 = $241;
     $316$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = 32;
     i64toi32_i32$0 = i64toi32_i32$4 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = 0;
      $242 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$1 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
      $242 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
     }
     $318$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $316$hi;
     i64toi32_i32$5 = $316;
     i64toi32_i32$3 = $318$hi;
     i64toi32_i32$4 = $242;
     i64toi32_i32$3 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
     $319 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
     $319$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $303$hi;
     i64toi32_i32$1 = $303;
     i64toi32_i32$5 = $319$hi;
     i64toi32_i32$4 = $319;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
     i64toi32_i32$2 = i64toi32_i32$3 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $320 = i64toi32_i32$0;
     $320$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $4$hi;
     $321 = $4_1;
     $321$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $2$hi;
     i64toi32_i32$3 = $2_1;
     i64toi32_i32$1 = 0;
     i64toi32_i32$4 = 32;
     i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
      i64toi32_i32$1 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
      $243 = 0;
     } else {
      i64toi32_i32$1 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$5 | 0) | 0;
      $243 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     }
     $323$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $321$hi;
     i64toi32_i32$2 = $321;
     i64toi32_i32$3 = $323$hi;
     i64toi32_i32$4 = $243;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $2_1 = i64toi32_i32$5;
     $2$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $4$hi;
     i64toi32_i32$0 = $2$hi;
     i64toi32_i32$1 = i64toi32_i32$5;
     i64toi32_i32$2 = $4$hi;
     i64toi32_i32$4 = $4_1;
     $327 = i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$1 = 0;
     $328$hi = i64toi32_i32$1;
     i64toi32_i32$1 = $320$hi;
     i64toi32_i32$4 = $320;
     i64toi32_i32$0 = $328$hi;
     i64toi32_i32$2 = $327;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $329 = i64toi32_i32$3;
     $329$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $2$hi;
     $330 = $2_1;
     $330$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $20$hi;
     i64toi32_i32$1 = $20_1;
     i64toi32_i32$4 = 0;
     i64toi32_i32$2 = 32;
     i64toi32_i32$0 = i64toi32_i32$2 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = 0;
      $245 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     } else {
      i64toi32_i32$4 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
      $245 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$0 | 0) | 0;
     }
     $332 = $245;
     $332$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $13$hi;
     i64toi32_i32$4 = $22$hi;
     i64toi32_i32$4 = $13$hi;
     i64toi32_i32$5 = $13_1;
     i64toi32_i32$1 = $22$hi;
     i64toi32_i32$2 = $22_1;
     $335 = i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0;
     i64toi32_i32$5 = 0;
     $336$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $15$hi;
     i64toi32_i32$5 = i64toi32_i32$4;
     i64toi32_i32$5 = $15$hi;
     i64toi32_i32$2 = $15_1;
     i64toi32_i32$1 = $13_1;
     $339 = i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $340$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $336$hi;
     i64toi32_i32$1 = $335;
     i64toi32_i32$5 = $340$hi;
     i64toi32_i32$4 = $339;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $341$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $20$hi;
     i64toi32_i32$3 = $15$hi;
     i64toi32_i32$3 = $20$hi;
     i64toi32_i32$2 = $20_1;
     i64toi32_i32$1 = $15$hi;
     i64toi32_i32$4 = $15_1;
     $344 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $345$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $341$hi;
     i64toi32_i32$4 = i64toi32_i32$0;
     i64toi32_i32$3 = $345$hi;
     i64toi32_i32$1 = $344;
     i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     i64toi32_i32$2 = i64toi32_i32$5;
     i64toi32_i32$4 = 0;
     i64toi32_i32$1 = 32;
     i64toi32_i32$3 = i64toi32_i32$1 & 31 | 0;
     if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
      i64toi32_i32$4 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
      $246 = 0;
     } else {
      i64toi32_i32$4 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$3 | 0) | 0;
      $246 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
     }
     $347$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $332$hi;
     i64toi32_i32$0 = $332;
     i64toi32_i32$2 = $347$hi;
     i64toi32_i32$1 = $246;
     i64toi32_i32$2 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
     $348 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
     $348$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $330$hi;
     i64toi32_i32$4 = $330;
     i64toi32_i32$0 = $348$hi;
     i64toi32_i32$1 = $348;
     i64toi32_i32$3 = i64toi32_i32$4 + i64toi32_i32$1 | 0;
     i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$0 | 0;
     if (i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $4_1 = i64toi32_i32$3;
     $4$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$2 = i64toi32_i32$3;
     i64toi32_i32$4 = $2$hi;
     i64toi32_i32$1 = $2_1;
     $352 = i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $353$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $329$hi;
     i64toi32_i32$1 = $329;
     i64toi32_i32$5 = $353$hi;
     i64toi32_i32$4 = $352;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
     i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
     }
     $354 = i64toi32_i32$0;
     $354$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $4$hi;
     $355 = $4_1;
     $355$hi = i64toi32_i32$3;
     i64toi32_i32$3 = $16$hi;
     i64toi32_i32$3 = $21$hi;
     i64toi32_i32$3 = $16$hi;
     i64toi32_i32$2 = $16_1;
     i64toi32_i32$1 = $21$hi;
     i64toi32_i32$4 = $21_1;
     $358 = i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$4 >>> 0 | 0) | 0;
     i64toi32_i32$2 = 0;
     $359$hi = i64toi32_i32$2;
     i64toi32_i32$2 = $23$hi;
     i64toi32_i32$2 = i64toi32_i32$3;
     i64toi32_i32$2 = $23$hi;
     i64toi32_i32$4 = $23_1;
     i64toi32_i32$1 = $16_1;
     $362 = i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$4 = 0;
     $363$hi = i64toi32_i32$4;
     i64toi32_i32$4 = $359$hi;
     i64toi32_i32$1 = $358;
     i64toi32_i32$2 = $363$hi;
     i64toi32_i32$3 = $362;
     i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
     if (i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
     }
     $364$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $355$hi;
     i64toi32_i32$4 = $355;
     i64toi32_i32$1 = $364$hi;
     i64toi32_i32$3 = i64toi32_i32$5;
     i64toi32_i32$2 = i64toi32_i32$4 + i64toi32_i32$3 | 0;
     i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
     if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
     }
     $2_1 = i64toi32_i32$2;
     $2$hi = i64toi32_i32$5;
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$5 = $2$hi;
     i64toi32_i32$0 = i64toi32_i32$2;
     i64toi32_i32$4 = $4$hi;
     i64toi32_i32$3 = $4_1;
     $368 = i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
     i64toi32_i32$0 = 0;
     $369$hi = i64toi32_i32$0;
     i64toi32_i32$0 = $354$hi;
     i64toi32_i32$3 = $354;
     i64toi32_i32$5 = $369$hi;
     i64toi32_i32$4 = $368;
     i64toi32_i32$1 = i64toi32_i32$3 + i64toi32_i32$4 | 0;
     i64toi32_i32$2 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
     if (i64toi32_i32$1 >>> 0 < i64toi32_i32$4 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $4_1 = i64toi32_i32$1;
     $4$hi = i64toi32_i32$2;
     i64toi32_i32$0 = i64toi32_i32$1;
     i64toi32_i32$3 = 65536;
     i64toi32_i32$4 = 0;
     i64toi32_i32$3 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
     if (!(i64toi32_i32$0 & i64toi32_i32$4 | 0 | i64toi32_i32$3 | 0)) {
      break label$14
     }
     $6_1 = $6_1 + 1 | 0;
     break label$13;
    }
    i64toi32_i32$3 = $18$hi;
    i64toi32_i32$2 = $18_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$4 = 63;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $247 = i64toi32_i32$3 >>> i64toi32_i32$5 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$3 >>> i64toi32_i32$5 | 0;
     $247 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$5 | 0) | 0;
    }
    $3_1 = $247;
    $3$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     $248 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$5 | 0) | 0;
     $248 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
    }
    $379 = $248;
    $379$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 63;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $250 = i64toi32_i32$2 >>> i64toi32_i32$5 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$2 >>> i64toi32_i32$5 | 0;
     $250 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$5 | 0) | 0;
    }
    $381$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $379$hi;
    i64toi32_i32$2 = $379;
    i64toi32_i32$0 = $381$hi;
    i64toi32_i32$4 = $250;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $4_1 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $2$hi;
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     $251 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$5 | 0) | 0;
     $251 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
    }
    $384 = $251;
    $384$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 63;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $252 = i64toi32_i32$2 >>> i64toi32_i32$5 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$2 >>> i64toi32_i32$5 | 0;
     $252 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$5 | 0) | 0;
    }
    $386$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $384$hi;
    i64toi32_i32$2 = $384;
    i64toi32_i32$0 = $386$hi;
    i64toi32_i32$4 = $252;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $2_1 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
    $2$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $18$hi;
    i64toi32_i32$3 = $18_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
     $253 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$5 | 0) | 0;
     $253 = i64toi32_i32$3 << i64toi32_i32$5 | 0;
    }
    $18_1 = $253;
    $18$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $3$hi;
    $390 = $3_1;
    $390$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $1$hi;
    i64toi32_i32$0 = $1_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 1;
    i64toi32_i32$5 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
     $254 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$5 | 0) | 0;
     $254 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
    }
    $392$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $390$hi;
    i64toi32_i32$2 = $390;
    i64toi32_i32$0 = $392$hi;
    i64toi32_i32$4 = $254;
    i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    $1_1 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
    $1$hi = i64toi32_i32$0;
   }
   label$15 : {
    if (($6_1 | 0) < (32767 | 0)) {
     break label$15
    }
    i64toi32_i32$0 = $11$hi;
    i64toi32_i32$3 = $11_1;
    i64toi32_i32$2 = 2147418112;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    $11_1 = i64toi32_i32$3 | i64toi32_i32$4 | 0;
    $11$hi = i64toi32_i32$2;
    i64toi32_i32$2 = 0;
    $1_1 = 0;
    $1$hi = i64toi32_i32$2;
    break label$1;
   }
   label$16 : {
    label$17 : {
     if (($6_1 | 0) > (0 | 0)) {
      break label$17
     }
     label$18 : {
      $7_1 = 1 - $6_1 | 0;
      if ($7_1 >>> 0 > 127 >>> 0) {
       break label$18
      }
      i64toi32_i32$2 = $18$hi;
      i64toi32_i32$2 = $1$hi;
      $6_1 = $6_1 + 127 | 0;
      i64toi32_i32$2 = $18$hi;
      i64toi32_i32$3 = $1$hi;
      $86($5_1 + 48 | 0 | 0, $18_1 | 0, i64toi32_i32$2 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $6_1 | 0);
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = $4$hi;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$2 = $4$hi;
      $86($5_1 + 32 | 0 | 0, $2_1 | 0, i64toi32_i32$3 | 0, $4_1 | 0, i64toi32_i32$2 | 0, $6_1 | 0);
      i64toi32_i32$2 = $18$hi;
      i64toi32_i32$2 = $1$hi;
      i64toi32_i32$2 = $18$hi;
      i64toi32_i32$3 = $1$hi;
      $96($5_1 + 16 | 0 | 0, $18_1 | 0, i64toi32_i32$2 | 0, $1_1 | 0, i64toi32_i32$3 | 0, $7_1 | 0);
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$3 = $4$hi;
      i64toi32_i32$3 = $2$hi;
      i64toi32_i32$2 = $4$hi;
      $96($5_1 | 0, $2_1 | 0, i64toi32_i32$3 | 0, $4_1 | 0, i64toi32_i32$2 | 0, $7_1 | 0);
      i64toi32_i32$0 = $5_1;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 32 | 0) >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 36 | 0) >> 2] | 0;
      $426 = i64toi32_i32$2;
      $426$hi = i64toi32_i32$3;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 16 | 0) >> 2] | 0;
      i64toi32_i32$2 = HEAP32[(i64toi32_i32$0 + 20 | 0) >> 2] | 0;
      $428 = i64toi32_i32$3;
      $428$hi = i64toi32_i32$2;
      i64toi32_i32$2 = $426$hi;
      i64toi32_i32$0 = $426;
      i64toi32_i32$3 = $428$hi;
      i64toi32_i32$4 = $428;
      i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
      $429 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
      $429$hi = i64toi32_i32$3;
      i64toi32_i32$2 = $5_1;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 48 | 0) >> 2] | 0;
      i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 52 | 0) >> 2] | 0;
      $431 = i64toi32_i32$3;
      $431$hi = i64toi32_i32$0;
      i64toi32_i32$2 = (i64toi32_i32$2 + 48 | 0) + 8 | 0;
      i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
      $435 = i64toi32_i32$0;
      $435$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $431$hi;
      i64toi32_i32$2 = $431;
      i64toi32_i32$0 = $435$hi;
      i64toi32_i32$4 = $435;
      i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
      i64toi32_i32$3 = i64toi32_i32$2 | i64toi32_i32$4 | 0;
      i64toi32_i32$2 = 0;
      i64toi32_i32$4 = 0;
      $437 = (i64toi32_i32$3 | 0) != (i64toi32_i32$4 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$2 | 0) | 0;
      i64toi32_i32$3 = 0;
      $438$hi = i64toi32_i32$3;
      i64toi32_i32$3 = $429$hi;
      i64toi32_i32$4 = $429;
      i64toi32_i32$0 = $438$hi;
      i64toi32_i32$2 = $437;
      i64toi32_i32$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
      $18_1 = i64toi32_i32$4 | i64toi32_i32$2 | 0;
      $18$hi = i64toi32_i32$0;
      i64toi32_i32$3 = ($5_1 + 32 | 0) + 8 | 0;
      i64toi32_i32$0 = HEAP32[i64toi32_i32$3 >> 2] | 0;
      i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
      $443 = i64toi32_i32$0;
      $443$hi = i64toi32_i32$4;
      i64toi32_i32$3 = ($5_1 + 16 | 0) + 8 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$3 >> 2] | 0;
      i64toi32_i32$0 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
      $447 = i64toi32_i32$4;
      $447$hi = i64toi32_i32$0;
      i64toi32_i32$0 = $443$hi;
      i64toi32_i32$3 = $443;
      i64toi32_i32$4 = $447$hi;
      i64toi32_i32$2 = $447;
      i64toi32_i32$4 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
      $1_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
      $1$hi = i64toi32_i32$4;
      i64toi32_i32$0 = $5_1 + 8 | 0;
      i64toi32_i32$4 = HEAP32[i64toi32_i32$0 >> 2] | 0;
      i64toi32_i32$3 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
      $4_1 = i64toi32_i32$4;
      $4$hi = i64toi32_i32$3;
      i64toi32_i32$0 = $5_1;
      i64toi32_i32$3 = HEAP32[i64toi32_i32$0 >> 2] | 0;
      i64toi32_i32$4 = HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] | 0;
      $2_1 = i64toi32_i32$3;
      $2$hi = i64toi32_i32$4;
      break label$16;
     }
     i64toi32_i32$4 = 0;
     $1_1 = 0;
     $1$hi = i64toi32_i32$4;
     break label$1;
    }
    i64toi32_i32$4 = 0;
    i64toi32_i32$0 = $6_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = 48;
    i64toi32_i32$5 = i64toi32_i32$2 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$2 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
     $255 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$5 | 0) - 1 | 0) & (i64toi32_i32$0 >>> (32 - i64toi32_i32$5 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$5 | 0) | 0;
     $255 = i64toi32_i32$0 << i64toi32_i32$5 | 0;
    }
    $456$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $4$hi;
    i64toi32_i32$4 = $4_1;
    i64toi32_i32$0 = 65535;
    i64toi32_i32$2 = -1;
    i64toi32_i32$0 = i64toi32_i32$3 & i64toi32_i32$0 | 0;
    $458 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
    $458$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $456$hi;
    i64toi32_i32$3 = $255;
    i64toi32_i32$4 = $458$hi;
    i64toi32_i32$2 = $458;
    i64toi32_i32$4 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
    $4_1 = i64toi32_i32$3 | i64toi32_i32$2 | 0;
    $4$hi = i64toi32_i32$4;
   }
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$4 = $11$hi;
   i64toi32_i32$4 = $4$hi;
   i64toi32_i32$0 = $4_1;
   i64toi32_i32$3 = $11$hi;
   i64toi32_i32$2 = $11_1;
   i64toi32_i32$3 = i64toi32_i32$4 | i64toi32_i32$3 | 0;
   $11_1 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   $11$hi = i64toi32_i32$3;
   label$19 : {
    i64toi32_i32$3 = $18$hi;
    $464 = !($18_1 | i64toi32_i32$3 | 0);
    i64toi32_i32$3 = $1$hi;
    i64toi32_i32$4 = $1_1;
    i64toi32_i32$0 = -1;
    i64toi32_i32$2 = -1;
    if ((i64toi32_i32$3 | 0) > (i64toi32_i32$0 | 0)) {
     $256 = 1
    } else {
     if ((i64toi32_i32$3 | 0) >= (i64toi32_i32$0 | 0)) {
      if (i64toi32_i32$4 >>> 0 <= i64toi32_i32$2 >>> 0) {
       $257 = 0
      } else {
       $257 = 1
      }
      $258 = $257;
     } else {
      $258 = 0
     }
     $256 = $258;
    }
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$3 = -2147483648;
    i64toi32_i32$0 = 0;
    if ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) | 0 ? $464 : $256) {
     break label$19
    }
    i64toi32_i32$2 = $11$hi;
    $470 = $11_1;
    $470$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $2$hi;
    i64toi32_i32$0 = $2_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$3 = 1;
    i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$4 | 0;
    if (i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
    }
    $1_1 = i64toi32_i32$5;
    $1$hi = i64toi32_i32$1;
    $474 = !(i64toi32_i32$5 | i64toi32_i32$1 | 0);
    i64toi32_i32$1 = 0;
    $475$hi = i64toi32_i32$1;
    i64toi32_i32$1 = $470$hi;
    i64toi32_i32$2 = $470;
    i64toi32_i32$0 = $475$hi;
    i64toi32_i32$3 = $474;
    i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $11_1 = i64toi32_i32$4;
    $11$hi = i64toi32_i32$5;
    break label$1;
   }
   label$20 : {
    i64toi32_i32$5 = $18$hi;
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$1 = $1_1;
    i64toi32_i32$2 = -2147483648;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = i64toi32_i32$5 ^ i64toi32_i32$2 | 0;
    $479 = i64toi32_i32$1 ^ i64toi32_i32$3 | 0;
    $479$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $18$hi;
    i64toi32_i32$5 = $18_1;
    i64toi32_i32$1 = $479$hi;
    i64toi32_i32$3 = $479;
    i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
    i64toi32_i32$2 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
    i64toi32_i32$5 = 0;
    i64toi32_i32$3 = 0;
    if ((i64toi32_i32$2 | 0) == (i64toi32_i32$3 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) | 0) {
     break label$20
    }
    i64toi32_i32$2 = $2$hi;
    $1_1 = $2_1;
    $1$hi = i64toi32_i32$2;
    break label$1;
   }
   i64toi32_i32$2 = $11$hi;
   $483 = $11_1;
   $483$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$3 = $2_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 1;
   i64toi32_i32$1 = i64toi32_i32$2 & i64toi32_i32$1 | 0;
   $486 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
   $486$hi = i64toi32_i32$1;
   i64toi32_i32$1 = i64toi32_i32$2;
   i64toi32_i32$2 = i64toi32_i32$3;
   i64toi32_i32$3 = $486$hi;
   i64toi32_i32$5 = $486;
   i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
   i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0) {
    i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
   }
   $1_1 = i64toi32_i32$0;
   $1$hi = i64toi32_i32$4;
   i64toi32_i32$4 = $2$hi;
   i64toi32_i32$4 = $1$hi;
   i64toi32_i32$1 = i64toi32_i32$0;
   i64toi32_i32$2 = $2$hi;
   i64toi32_i32$5 = $2_1;
   $490 = i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
   i64toi32_i32$1 = 0;
   $491$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $483$hi;
   i64toi32_i32$5 = $483;
   i64toi32_i32$4 = $491$hi;
   i64toi32_i32$2 = $490;
   i64toi32_i32$3 = i64toi32_i32$5 + i64toi32_i32$2 | 0;
   i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$4 | 0;
   if (i64toi32_i32$3 >>> 0 < i64toi32_i32$2 >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
   }
   $11_1 = i64toi32_i32$3;
   $11$hi = i64toi32_i32$0;
  }
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$5 = $0_1;
  HEAP32[i64toi32_i32$5 >> 2] = $1_1;
  HEAP32[(i64toi32_i32$5 + 4 | 0) >> 2] = i64toi32_i32$0;
  i64toi32_i32$0 = $11$hi;
  HEAP32[(i64toi32_i32$5 + 8 | 0) >> 2] = $11_1;
  HEAP32[(i64toi32_i32$5 + 12 | 0) >> 2] = i64toi32_i32$0;
  global$0 = $5_1 + 96 | 0;
 }
 
 function $98($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$1 = 0, i64toi32_i32$5 = 0, i64toi32_i32$4 = 0, i64toi32_i32$3 = 0, $46_1 = 0, $48_1 = 0, $49_1 = 0, $50_1 = 0, $53_1 = 0, $54_1 = 0, $6_1 = 0, $9_1 = 0, $9$hi = 0, $12_1 = 0, $12$hi = 0, $13_1 = 0, $13$hi = 0, $16_1 = 0, $16$hi = 0, $20_1 = 0, $20$hi = 0, $21_1 = 0, $21$hi = 0, $5_1 = 0, $5$hi = 0, $30$hi = 0, $33_1 = 0, $33$hi = 0, $36$hi = 0, $37_1 = 0, $37$hi = 0, $39_1 = 0, $39$hi = 0, $42_1 = 0, $42$hi = 0, $45$hi = 0, $47_1 = 0, $49$hi = 0, $51_1 = 0, $51$hi = 0, $52_1 = 0;
  $6_1 = $0_1;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$1 = __wasm_i64_mul($4_1 | 0, i64toi32_i32$0 | 0, $1_1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  $9_1 = i64toi32_i32$1;
  $9$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$1 = $3$hi;
  i64toi32_i32$1 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$0 | 0, $3_1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  $12_1 = i64toi32_i32$1;
  $12$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $9$hi;
  i64toi32_i32$2 = $9_1;
  i64toi32_i32$1 = $12$hi;
  i64toi32_i32$3 = $12_1;
  i64toi32_i32$4 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
  i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$1 | 0;
  if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
  }
  $13_1 = i64toi32_i32$4;
  $13$hi = i64toi32_i32$5;
  i64toi32_i32$5 = $3$hi;
  i64toi32_i32$0 = $3_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = 0;
   $46_1 = i64toi32_i32$5 >>> i64toi32_i32$1 | 0;
  } else {
   i64toi32_i32$2 = i64toi32_i32$5 >>> i64toi32_i32$1 | 0;
   $46_1 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$1 | 0) | 0;
  }
  $2_1 = $46_1;
  $2$hi = i64toi32_i32$2;
  $16_1 = $2_1;
  $16$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$5 = $1_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = 0;
   $48_1 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
  } else {
   i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$1 | 0;
   $48_1 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
  }
  $4_1 = $48_1;
  $4$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $16$hi;
  i64toi32_i32$5 = $4$hi;
  i64toi32_i32$5 = __wasm_i64_mul($16_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$5 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  $20_1 = i64toi32_i32$5;
  $20$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $13$hi;
  i64toi32_i32$2 = $13_1;
  i64toi32_i32$5 = $20$hi;
  i64toi32_i32$3 = $20_1;
  i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
  i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$5 | 0;
  if (i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
  }
  $21_1 = i64toi32_i32$1;
  $21$hi = i64toi32_i32$4;
  i64toi32_i32$4 = $3$hi;
  i64toi32_i32$0 = $3_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = -1;
  i64toi32_i32$2 = i64toi32_i32$4 & i64toi32_i32$2 | 0;
  $3_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $3$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $1$hi;
  i64toi32_i32$4 = $1_1;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = -1;
  i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
  $1_1 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
  $1$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$4 = $1$hi;
  i64toi32_i32$4 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$0 | 0, $1_1 | 0, i64toi32_i32$4 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  $5_1 = i64toi32_i32$4;
  $5$hi = i64toi32_i32$0;
  i64toi32_i32$2 = i64toi32_i32$4;
  i64toi32_i32$4 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$5 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$4 = 0;
   $49_1 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
  } else {
   i64toi32_i32$4 = i64toi32_i32$0 >>> i64toi32_i32$5 | 0;
   $49_1 = (((1 << i64toi32_i32$5 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$5 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$5 | 0) | 0;
  }
  $30$hi = i64toi32_i32$4;
  i64toi32_i32$4 = $3$hi;
  i64toi32_i32$4 = $4$hi;
  i64toi32_i32$4 = $3$hi;
  i64toi32_i32$2 = $4$hi;
  i64toi32_i32$2 = __wasm_i64_mul($3_1 | 0, i64toi32_i32$4 | 0, $4_1 | 0, i64toi32_i32$2 | 0) | 0;
  i64toi32_i32$4 = i64toi32_i32$HIGH_BITS;
  $33_1 = i64toi32_i32$2;
  $33$hi = i64toi32_i32$4;
  i64toi32_i32$4 = $30$hi;
  i64toi32_i32$0 = $49_1;
  i64toi32_i32$2 = $33$hi;
  i64toi32_i32$3 = $33_1;
  i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
  i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
  if (i64toi32_i32$5 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
  }
  $3_1 = i64toi32_i32$5;
  $3$hi = i64toi32_i32$1;
  i64toi32_i32$4 = i64toi32_i32$5;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$2 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = 0;
   $50_1 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
  } else {
   i64toi32_i32$0 = i64toi32_i32$1 >>> i64toi32_i32$2 | 0;
   $50_1 = (((1 << i64toi32_i32$2 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$2 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$2 | 0) | 0;
  }
  $36$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $21$hi;
  i64toi32_i32$1 = $21_1;
  i64toi32_i32$4 = $36$hi;
  i64toi32_i32$3 = $50_1;
  i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
  i64toi32_i32$5 = i64toi32_i32$0 + i64toi32_i32$4 | 0;
  if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
  }
  $37_1 = i64toi32_i32$2;
  $37$hi = i64toi32_i32$5;
  i64toi32_i32$5 = $3$hi;
  i64toi32_i32$0 = $3_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = -1;
  i64toi32_i32$1 = i64toi32_i32$5 & i64toi32_i32$1 | 0;
  $39_1 = i64toi32_i32$0 & i64toi32_i32$3 | 0;
  $39$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$1 = $2$hi;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = __wasm_i64_mul($2_1 | 0, i64toi32_i32$1 | 0, $1_1 | 0, i64toi32_i32$0 | 0) | 0;
  i64toi32_i32$1 = i64toi32_i32$HIGH_BITS;
  $42_1 = i64toi32_i32$0;
  $42$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $39$hi;
  i64toi32_i32$5 = $39_1;
  i64toi32_i32$0 = $42$hi;
  i64toi32_i32$3 = $42_1;
  i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
  i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
  if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
  }
  $1_1 = i64toi32_i32$4;
  $1$hi = i64toi32_i32$2;
  i64toi32_i32$1 = i64toi32_i32$4;
  i64toi32_i32$5 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$5 = 0;
   $53_1 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
  } else {
   i64toi32_i32$5 = i64toi32_i32$2 >>> i64toi32_i32$0 | 0;
   $53_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$1 >>> i64toi32_i32$0 | 0) | 0;
  }
  $45$hi = i64toi32_i32$5;
  i64toi32_i32$5 = $37$hi;
  i64toi32_i32$2 = $37_1;
  i64toi32_i32$1 = $45$hi;
  i64toi32_i32$3 = $53_1;
  i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
  i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$1 | 0;
  if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) {
   i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
  }
  i64toi32_i32$2 = $6_1;
  HEAP32[(i64toi32_i32$2 + 8 | 0) >> 2] = i64toi32_i32$0;
  HEAP32[(i64toi32_i32$2 + 12 | 0) >> 2] = i64toi32_i32$4;
  $47_1 = $0_1;
  i64toi32_i32$4 = $1$hi;
  i64toi32_i32$5 = $1_1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$1 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$1 | 0;
   $54_1 = 0;
  } else {
   i64toi32_i32$2 = ((1 << i64toi32_i32$1 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$1 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$1 | 0) | 0;
   $54_1 = i64toi32_i32$5 << i64toi32_i32$1 | 0;
  }
  $49$hi = i64toi32_i32$2;
  i64toi32_i32$2 = $5$hi;
  i64toi32_i32$4 = $5_1;
  i64toi32_i32$5 = 0;
  i64toi32_i32$3 = -1;
  i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
  $51_1 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
  $51$hi = i64toi32_i32$5;
  i64toi32_i32$5 = $49$hi;
  i64toi32_i32$2 = $54_1;
  i64toi32_i32$4 = $51$hi;
  i64toi32_i32$3 = $51_1;
  i64toi32_i32$4 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
  $52_1 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
  i64toi32_i32$2 = $47_1;
  HEAP32[i64toi32_i32$2 >> 2] = $52_1;
  HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] = i64toi32_i32$4;
 }
 
 function $99($0_1, $1_1, $1$hi, $2_1, $2$hi, $3_1, $3$hi, $4_1, $4$hi) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $2$hi = $2$hi | 0;
  $3_1 = $3_1 | 0;
  $3$hi = $3$hi | 0;
  $4_1 = $4_1 | 0;
  $4$hi = $4$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, $5_1 = 0, $14_1 = 0, $14$hi = 0, $20_1 = 0;
  $5_1 = global$0 - 16 | 0;
  global$0 = $5_1;
  i64toi32_i32$0 = $1$hi;
  i64toi32_i32$0 = $2$hi;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$0 = $4$hi;
  i64toi32_i32$2 = $4_1;
  i64toi32_i32$1 = -2147483648;
  i64toi32_i32$3 = 0;
  i64toi32_i32$1 = i64toi32_i32$0 ^ i64toi32_i32$1 | 0;
  $14_1 = i64toi32_i32$2 ^ i64toi32_i32$3 | 0;
  $14$hi = i64toi32_i32$1;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$2 = $2$hi;
  i64toi32_i32$0 = $3$hi;
  i64toi32_i32$3 = $14$hi;
  $85($5_1 | 0, $1_1 | 0, i64toi32_i32$1 | 0, $2_1 | 0, i64toi32_i32$2 | 0, $3_1 | 0, i64toi32_i32$0 | 0, $14_1 | 0, i64toi32_i32$3 | 0);
  i64toi32_i32$2 = $5_1;
  i64toi32_i32$3 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $4_1 = i64toi32_i32$3;
  $4$hi = i64toi32_i32$0;
  i64toi32_i32$2 = i64toi32_i32$2 + 8 | 0;
  i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
  i64toi32_i32$3 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
  $20_1 = i64toi32_i32$0;
  i64toi32_i32$0 = $0_1;
  HEAP32[(i64toi32_i32$0 + 8 | 0) >> 2] = $20_1;
  HEAP32[(i64toi32_i32$0 + 12 | 0) >> 2] = i64toi32_i32$3;
  i64toi32_i32$3 = $4$hi;
  HEAP32[i64toi32_i32$0 >> 2] = $4_1;
  HEAP32[(i64toi32_i32$0 + 4 | 0) >> 2] = i64toi32_i32$3;
  global$0 = $5_1 + 16 | 0;
 }
 
 function $100($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$2 = 0, i64toi32_i32$4 = 0, i64toi32_i32$5 = 0, i64toi32_i32$3 = 0, i64toi32_i32$1 = 0, $4_1 = 0, $4$hi = 0, $5$hi = 0, $5_1 = 0, $2_1 = 0, $3_1 = 0, $44_1 = 0, $45_1 = 0, $46_1 = 0, $47_1 = 0, $48_1 = 0, $49_1 = 0, $50_1 = 0, $12_1 = 0, $12$hi = 0, $14$hi = 0, $17_1 = 0, $17$hi = 0, $19$hi = 0, $33_1 = 0, $33$hi = 0, $36_1 = 0, $38_1 = 0, $43_1 = 0, $43$hi = 0, $45$hi = 0, $73_1 = 0, $73$hi = 0, $77$hi = 0, $80_1 = 0, $80$hi = 0, $82_1 = 0, $82$hi = 0, $86_1 = 0, $86$hi = 0, $88_1 = 0, $89$hi = 0, $98$hi = 0, $105_1 = 0, $105$hi = 0;
  $2_1 = global$0 - 32 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$1 = 2147483647;
    i64toi32_i32$3 = -1;
    i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    $4_1 = i64toi32_i32$2 & i64toi32_i32$3 | 0;
    $4$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $4_1;
    i64toi32_i32$2 = -1006698496;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $12_1 = i64toi32_i32$4;
    $12$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $4$hi;
    i64toi32_i32$1 = $4_1;
    i64toi32_i32$0 = -1140785152;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
    i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $14$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $12$hi;
    i64toi32_i32$5 = $12_1;
    i64toi32_i32$1 = $14$hi;
    i64toi32_i32$3 = i64toi32_i32$2;
    if (i64toi32_i32$4 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$5 >>> 0 >= i64toi32_i32$2 >>> 0 | 0) | 0) {
     break label$2
    }
    i64toi32_i32$5 = $0$hi;
    i64toi32_i32$3 = $0_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$1 = 60;
    i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = 0;
     $44_1 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
    } else {
     i64toi32_i32$4 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     $44_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
    }
    $17_1 = $44_1;
    $17$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $1$hi;
    i64toi32_i32$5 = $1_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$1 = 4;
    i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
     $45_1 = 0;
    } else {
     i64toi32_i32$3 = ((1 << i64toi32_i32$0 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$0 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$0 | 0) | 0;
     $45_1 = i64toi32_i32$5 << i64toi32_i32$0 | 0;
    }
    $19$hi = i64toi32_i32$3;
    i64toi32_i32$3 = $17$hi;
    i64toi32_i32$4 = $17_1;
    i64toi32_i32$5 = $19$hi;
    i64toi32_i32$1 = $45_1;
    i64toi32_i32$5 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
    $4_1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
    $4$hi = i64toi32_i32$5;
    label$3 : {
     i64toi32_i32$5 = $0$hi;
     i64toi32_i32$3 = $0_1;
     i64toi32_i32$4 = 268435455;
     i64toi32_i32$1 = -1;
     i64toi32_i32$4 = i64toi32_i32$5 & i64toi32_i32$4 | 0;
     $0_1 = i64toi32_i32$3 & i64toi32_i32$1 | 0;
     $0$hi = i64toi32_i32$4;
     i64toi32_i32$5 = $0_1;
     i64toi32_i32$3 = 134217728;
     i64toi32_i32$1 = 1;
     if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) & i64toi32_i32$5 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0) {
      break label$3
     }
     i64toi32_i32$5 = $4$hi;
     i64toi32_i32$1 = $4_1;
     i64toi32_i32$4 = 1073741824;
     i64toi32_i32$3 = 1;
     i64toi32_i32$0 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
     i64toi32_i32$2 = i64toi32_i32$5 + i64toi32_i32$4 | 0;
     if (i64toi32_i32$0 >>> 0 < i64toi32_i32$3 >>> 0) {
      i64toi32_i32$2 = i64toi32_i32$2 + 1 | 0
     }
     $5_1 = i64toi32_i32$0;
     $5$hi = i64toi32_i32$2;
     break label$1;
    }
    i64toi32_i32$2 = $4$hi;
    i64toi32_i32$5 = $4_1;
    i64toi32_i32$1 = 1073741824;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$3 | 0;
    i64toi32_i32$0 = i64toi32_i32$2 + i64toi32_i32$1 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$0 = i64toi32_i32$0 + 1 | 0
    }
    $5_1 = i64toi32_i32$4;
    $5$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $0$hi;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$5 = 134217728;
    i64toi32_i32$3 = 0;
    if ((i64toi32_i32$2 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$5 | 0) | 0) {
     break label$1
    }
    i64toi32_i32$2 = $5$hi;
    i64toi32_i32$2 = $4$hi;
    i64toi32_i32$3 = $4_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$0 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
    $33_1 = i64toi32_i32$3 & i64toi32_i32$5 | 0;
    $33$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $5$hi;
    i64toi32_i32$2 = i64toi32_i32$4;
    i64toi32_i32$3 = $33$hi;
    i64toi32_i32$5 = $33_1;
    i64toi32_i32$1 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    if (i64toi32_i32$1 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $5_1 = i64toi32_i32$1;
    $5$hi = i64toi32_i32$4;
    break label$1;
   }
   label$4 : {
    i64toi32_i32$4 = $0$hi;
    $36_1 = !($0_1 | i64toi32_i32$4 | 0);
    i64toi32_i32$4 = $4$hi;
    i64toi32_i32$0 = $4_1;
    i64toi32_i32$2 = 2147418112;
    i64toi32_i32$5 = 0;
    $38_1 = i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$2 | 0) & i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | 0) | 0;
    i64toi32_i32$0 = i64toi32_i32$4;
    i64toi32_i32$0 = i64toi32_i32$4;
    i64toi32_i32$5 = $4_1;
    i64toi32_i32$4 = 2147418112;
    i64toi32_i32$2 = 0;
    if ((i64toi32_i32$5 | 0) == (i64toi32_i32$2 | 0) & (i64toi32_i32$0 | 0) == (i64toi32_i32$4 | 0) | 0 ? $36_1 : $38_1) {
     break label$4
    }
    i64toi32_i32$5 = $0$hi;
    i64toi32_i32$2 = $0_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$4 = 60;
    i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$0 = 0;
     $46_1 = i64toi32_i32$5 >>> i64toi32_i32$3 | 0;
    } else {
     i64toi32_i32$0 = i64toi32_i32$5 >>> i64toi32_i32$3 | 0;
     $46_1 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$3 | 0) | 0;
    }
    $43_1 = $46_1;
    $43$hi = i64toi32_i32$0;
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$5 = $1_1;
    i64toi32_i32$2 = 0;
    i64toi32_i32$4 = 4;
    i64toi32_i32$3 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$3 | 0;
     $47_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$0 << i64toi32_i32$3 | 0) | 0;
     $47_1 = i64toi32_i32$5 << i64toi32_i32$3 | 0;
    }
    $45$hi = i64toi32_i32$2;
    i64toi32_i32$2 = $43$hi;
    i64toi32_i32$0 = $43_1;
    i64toi32_i32$5 = $45$hi;
    i64toi32_i32$4 = $47_1;
    i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$4 | 0;
    i64toi32_i32$0 = 524287;
    i64toi32_i32$4 = -1;
    i64toi32_i32$0 = i64toi32_i32$5 & i64toi32_i32$0 | 0;
    i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
    i64toi32_i32$2 = 2146959360;
    i64toi32_i32$4 = 0;
    i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
    $5_1 = i64toi32_i32$5 | i64toi32_i32$4 | 0;
    $5$hi = i64toi32_i32$2;
    break label$1;
   }
   i64toi32_i32$2 = 2146435072;
   $5_1 = 0;
   $5$hi = i64toi32_i32$2;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$0 = $4_1;
   i64toi32_i32$5 = 1140785151;
   i64toi32_i32$4 = -1;
   if (i64toi32_i32$2 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$0 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0) {
    break label$1
   }
   i64toi32_i32$0 = 0;
   $5_1 = 0;
   $5$hi = i64toi32_i32$0;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$0 = i64toi32_i32$2;
   i64toi32_i32$4 = $4_1;
   i64toi32_i32$2 = 0;
   i64toi32_i32$5 = 48;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$2 = 0;
    $48_1 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$2 = i64toi32_i32$0 >>> i64toi32_i32$3 | 0;
    $48_1 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$3 | 0) | 0;
   }
   $3_1 = $48_1;
   if ($3_1 >>> 0 < 15249 >>> 0) {
    break label$1
   }
   i64toi32_i32$2 = $0$hi;
   i64toi32_i32$2 = $1$hi;
   i64toi32_i32$0 = $1_1;
   i64toi32_i32$4 = 65535;
   i64toi32_i32$5 = -1;
   i64toi32_i32$4 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
   i64toi32_i32$2 = i64toi32_i32$0 & i64toi32_i32$5 | 0;
   i64toi32_i32$0 = 65536;
   i64toi32_i32$5 = 0;
   i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
   $4_1 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
   $4$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $0$hi;
   i64toi32_i32$2 = $4$hi;
   $86($2_1 + 16 | 0 | 0, $0_1 | 0, i64toi32_i32$0 | 0, $4_1 | 0, i64toi32_i32$2 | 0, $3_1 + -15233 | 0 | 0);
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$2 = $4$hi;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$0 = $4$hi;
   $96($2_1 | 0, $0_1 | 0, i64toi32_i32$2 | 0, $4_1 | 0, i64toi32_i32$0 | 0, 15361 - $3_1 | 0 | 0);
   i64toi32_i32$4 = $2_1;
   i64toi32_i32$0 = HEAP32[i64toi32_i32$4 >> 2] | 0;
   i64toi32_i32$2 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
   $4_1 = i64toi32_i32$0;
   $4$hi = i64toi32_i32$2;
   i64toi32_i32$4 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 60;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = 0;
    $49_1 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
   } else {
    i64toi32_i32$0 = i64toi32_i32$2 >>> i64toi32_i32$3 | 0;
    $49_1 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$3 | 0) | 0;
   }
   $73_1 = $49_1;
   $73$hi = i64toi32_i32$0;
   i64toi32_i32$2 = $2_1 + 8 | 0;
   i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
   i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
   i64toi32_i32$2 = i64toi32_i32$0;
   i64toi32_i32$0 = 0;
   i64toi32_i32$5 = 4;
   i64toi32_i32$3 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$0 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
    $50_1 = 0;
   } else {
    i64toi32_i32$0 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$4 << i64toi32_i32$3 | 0) | 0;
    $50_1 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
   }
   $77$hi = i64toi32_i32$0;
   i64toi32_i32$0 = $73$hi;
   i64toi32_i32$4 = $73_1;
   i64toi32_i32$2 = $77$hi;
   i64toi32_i32$5 = $50_1;
   i64toi32_i32$2 = i64toi32_i32$0 | i64toi32_i32$2 | 0;
   $5_1 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
   $5$hi = i64toi32_i32$2;
   label$5 : {
    i64toi32_i32$2 = $4$hi;
    i64toi32_i32$0 = $4_1;
    i64toi32_i32$4 = 268435455;
    i64toi32_i32$5 = -1;
    i64toi32_i32$4 = i64toi32_i32$2 & i64toi32_i32$4 | 0;
    $80_1 = i64toi32_i32$0 & i64toi32_i32$5 | 0;
    $80$hi = i64toi32_i32$4;
    i64toi32_i32$2 = $2_1;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 16 | 0) >> 2] | 0;
    i64toi32_i32$0 = HEAP32[(i64toi32_i32$2 + 20 | 0) >> 2] | 0;
    $82_1 = i64toi32_i32$4;
    $82$hi = i64toi32_i32$0;
    i64toi32_i32$2 = (i64toi32_i32$2 + 16 | 0) + 8 | 0;
    i64toi32_i32$0 = HEAP32[i64toi32_i32$2 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$2 + 4 | 0) >> 2] | 0;
    $86_1 = i64toi32_i32$0;
    $86$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $82$hi;
    i64toi32_i32$2 = $82_1;
    i64toi32_i32$0 = $86$hi;
    i64toi32_i32$5 = $86_1;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
    i64toi32_i32$4 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$5 = 0;
    $88_1 = (i64toi32_i32$4 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$0 | 0) != (i64toi32_i32$2 | 0) | 0;
    i64toi32_i32$4 = 0;
    $89$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $80$hi;
    i64toi32_i32$5 = $80_1;
    i64toi32_i32$0 = $89$hi;
    i64toi32_i32$2 = $88_1;
    i64toi32_i32$0 = i64toi32_i32$4 | i64toi32_i32$0 | 0;
    $4_1 = i64toi32_i32$5 | i64toi32_i32$2 | 0;
    $4$hi = i64toi32_i32$0;
    i64toi32_i32$4 = $4_1;
    i64toi32_i32$5 = 134217728;
    i64toi32_i32$2 = 1;
    if (i64toi32_i32$0 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$0 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$2 >>> 0 | 0) | 0) {
     break label$5
    }
    i64toi32_i32$4 = $5$hi;
    i64toi32_i32$2 = $5_1;
    i64toi32_i32$0 = 0;
    i64toi32_i32$5 = 1;
    i64toi32_i32$3 = i64toi32_i32$2 + i64toi32_i32$5 | 0;
    i64toi32_i32$1 = i64toi32_i32$4 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0) {
     i64toi32_i32$1 = i64toi32_i32$1 + 1 | 0
    }
    $5_1 = i64toi32_i32$3;
    $5$hi = i64toi32_i32$1;
    break label$1;
   }
   i64toi32_i32$1 = $4$hi;
   i64toi32_i32$4 = $4_1;
   i64toi32_i32$2 = 134217728;
   i64toi32_i32$5 = 0;
   if ((i64toi32_i32$4 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$2 | 0) | 0) {
    break label$1
   }
   i64toi32_i32$4 = $5$hi;
   i64toi32_i32$5 = $5_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$2 = 1;
   i64toi32_i32$1 = i64toi32_i32$4 & i64toi32_i32$1 | 0;
   $98$hi = i64toi32_i32$1;
   i64toi32_i32$1 = i64toi32_i32$4;
   i64toi32_i32$1 = $98$hi;
   i64toi32_i32$4 = i64toi32_i32$5 & i64toi32_i32$2 | 0;
   i64toi32_i32$5 = $5$hi;
   i64toi32_i32$2 = $5_1;
   i64toi32_i32$0 = i64toi32_i32$4 + i64toi32_i32$2 | 0;
   i64toi32_i32$3 = i64toi32_i32$1 + i64toi32_i32$5 | 0;
   if (i64toi32_i32$0 >>> 0 < i64toi32_i32$2 >>> 0) {
    i64toi32_i32$3 = i64toi32_i32$3 + 1 | 0
   }
   $5_1 = i64toi32_i32$0;
   $5$hi = i64toi32_i32$3;
  }
  global$0 = $2_1 + 32 | 0;
  i64toi32_i32$3 = $5$hi;
  i64toi32_i32$3 = $1$hi;
  i64toi32_i32$1 = $1_1;
  i64toi32_i32$4 = -2147483648;
  i64toi32_i32$2 = 0;
  i64toi32_i32$4 = i64toi32_i32$3 & i64toi32_i32$4 | 0;
  $105_1 = i64toi32_i32$1 & i64toi32_i32$2 | 0;
  $105$hi = i64toi32_i32$4;
  i64toi32_i32$4 = $5$hi;
  i64toi32_i32$3 = $5_1;
  i64toi32_i32$1 = $105$hi;
  i64toi32_i32$2 = $105_1;
  i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
  wasm2js_scratch_store_i32(0 | 0, i64toi32_i32$3 | i64toi32_i32$2 | 0 | 0);
  wasm2js_scratch_store_i32(1 | 0, i64toi32_i32$1 | 0);
  return +(+wasm2js_scratch_load_f64());
 }
 
 function $101($0_1, $0$hi, $1_1, $1$hi) {
  $0_1 = $0_1 | 0;
  $0$hi = $0$hi | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  var i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, i64toi32_i32$5 = 0, i64toi32_i32$0 = 0, $5_1 = 0, $5$hi = 0, $4_1 = 0, $3_1 = 0, $2_1 = 0, i64toi32_i32$2 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $40_1 = 0, $41_1 = 0, $12_1 = 0, $12$hi = 0, $14$hi = 0, $20_1 = 0, $24_1 = 0, $34_1 = 0, $34$hi = 0, $42_1 = 0, $44_1 = 0, $81_1 = 0, $81$hi = 0, $83_1 = 0, $83$hi = 0, $87_1 = 0, $87$hi = 0, $89_1 = 0, $90$hi = 0, $93_1 = 0, $97_1 = 0, $105_1 = 0, $105$hi = 0, $114 = 0;
  $2_1 = global$0 - 32 | 0;
  global$0 = $2_1;
  label$1 : {
   label$2 : {
    i64toi32_i32$0 = $1$hi;
    i64toi32_i32$2 = $1_1;
    i64toi32_i32$1 = 2147483647;
    i64toi32_i32$3 = -1;
    i64toi32_i32$1 = i64toi32_i32$0 & i64toi32_i32$1 | 0;
    $5_1 = $1_1 & i64toi32_i32$3 | 0;
    $5$hi = i64toi32_i32$1;
    i64toi32_i32$0 = $5_1;
    i64toi32_i32$2 = -1065418752;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = i64toi32_i32$0 + i64toi32_i32$3 | 0;
    i64toi32_i32$5 = i64toi32_i32$1 + i64toi32_i32$2 | 0;
    if (i64toi32_i32$4 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
    }
    $12_1 = i64toi32_i32$4;
    $12$hi = i64toi32_i32$5;
    i64toi32_i32$5 = $5$hi;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$0 = -1082064896;
    i64toi32_i32$3 = 0;
    i64toi32_i32$2 = i64toi32_i32$1 + i64toi32_i32$3 | 0;
    i64toi32_i32$4 = i64toi32_i32$5 + i64toi32_i32$0 | 0;
    if (i64toi32_i32$2 >>> 0 < i64toi32_i32$3 >>> 0) {
     i64toi32_i32$4 = i64toi32_i32$4 + 1 | 0
    }
    $14$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $12$hi;
    i64toi32_i32$5 = $12_1;
    i64toi32_i32$1 = $14$hi;
    i64toi32_i32$3 = i64toi32_i32$2;
    if (i64toi32_i32$4 >>> 0 > i64toi32_i32$1 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$1 | 0) & i64toi32_i32$5 >>> 0 >= i64toi32_i32$3 >>> 0 | 0) | 0) {
     break label$2
    }
    i64toi32_i32$5 = $1$hi;
    i64toi32_i32$3 = $1_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$1 = 25;
    i64toi32_i32$0 = i64toi32_i32$1 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$1 & 63 | 0) >>> 0) {
     i64toi32_i32$4 = 0;
     $37_1 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
    } else {
     i64toi32_i32$4 = i64toi32_i32$5 >>> i64toi32_i32$0 | 0;
     $37_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$5 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$0 | 0) | 0;
    }
    $3_1 = $37_1;
    label$3 : {
     i64toi32_i32$4 = $0$hi;
     $20_1 = !($0_1 | i64toi32_i32$4 | 0);
     i64toi32_i32$4 = $1$hi;
     i64toi32_i32$5 = $1_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$1 = 33554431;
     i64toi32_i32$3 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
     $5_1 = i64toi32_i32$5 & i64toi32_i32$1 | 0;
     $5$hi = i64toi32_i32$3;
     i64toi32_i32$4 = $5_1;
     i64toi32_i32$5 = 0;
     i64toi32_i32$1 = 16777216;
     $24_1 = i64toi32_i32$3 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$4 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$4 = i64toi32_i32$3;
     i64toi32_i32$1 = $5_1;
     i64toi32_i32$3 = 0;
     i64toi32_i32$5 = 16777216;
     if ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$4 | 0) == (i64toi32_i32$3 | 0) | 0 ? $20_1 : $24_1) {
      break label$3
     }
     $4_1 = $3_1 + 1073741825 | 0;
     break label$1;
    }
    $4_1 = $3_1 + 1073741824 | 0;
    i64toi32_i32$1 = $0$hi;
    i64toi32_i32$1 = $5$hi;
    i64toi32_i32$5 = $5_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$3 = 16777216;
    i64toi32_i32$4 = i64toi32_i32$1 ^ i64toi32_i32$4 | 0;
    $34_1 = i64toi32_i32$5 ^ i64toi32_i32$3 | 0;
    $34$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $0$hi;
    i64toi32_i32$1 = $0_1;
    i64toi32_i32$5 = $34$hi;
    i64toi32_i32$3 = $34_1;
    i64toi32_i32$5 = i64toi32_i32$4 | i64toi32_i32$5 | 0;
    i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$3 | 0;
    i64toi32_i32$1 = 0;
    i64toi32_i32$3 = 0;
    if ((i64toi32_i32$4 | 0) != (i64toi32_i32$3 | 0) | (i64toi32_i32$5 | 0) != (i64toi32_i32$1 | 0) | 0) {
     break label$1
    }
    $4_1 = $4_1 + ($3_1 & 1 | 0) | 0;
    break label$1;
   }
   label$4 : {
    i64toi32_i32$4 = $0$hi;
    $42_1 = !($0_1 | i64toi32_i32$4 | 0);
    i64toi32_i32$4 = $5$hi;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$5 = 2147418112;
    i64toi32_i32$1 = 0;
    $44_1 = i64toi32_i32$4 >>> 0 < i64toi32_i32$5 >>> 0 | ((i64toi32_i32$4 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$3 >>> 0 < i64toi32_i32$1 >>> 0 | 0) | 0;
    i64toi32_i32$3 = i64toi32_i32$4;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$4 = 2147418112;
    i64toi32_i32$5 = 0;
    if ((i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) & (i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) | 0 ? $42_1 : $44_1) {
     break label$4
    }
    i64toi32_i32$1 = $1$hi;
    i64toi32_i32$5 = $1_1;
    i64toi32_i32$3 = 0;
    i64toi32_i32$4 = 25;
    i64toi32_i32$0 = i64toi32_i32$4 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$4 & 63 | 0) >>> 0) {
     i64toi32_i32$3 = 0;
     $38_1 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
    } else {
     i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
     $38_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$0 | 0) | 0;
    }
    $4_1 = $38_1 & 4194303 | 0 | 2143289344 | 0;
    break label$1;
   }
   $4_1 = 2139095040;
   i64toi32_i32$3 = $5$hi;
   i64toi32_i32$1 = $5_1;
   i64toi32_i32$5 = 1082064895;
   i64toi32_i32$4 = -1;
   if (i64toi32_i32$3 >>> 0 > i64toi32_i32$5 >>> 0 | ((i64toi32_i32$3 | 0) == (i64toi32_i32$5 | 0) & i64toi32_i32$1 >>> 0 > i64toi32_i32$4 >>> 0 | 0) | 0) {
    break label$1
   }
   $4_1 = 0;
   i64toi32_i32$1 = i64toi32_i32$3;
   i64toi32_i32$4 = $5_1;
   i64toi32_i32$3 = 0;
   i64toi32_i32$5 = 48;
   i64toi32_i32$0 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$3 = 0;
    $39_1 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
   } else {
    i64toi32_i32$3 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
    $39_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$0 | 0) | 0;
   }
   $3_1 = $39_1;
   if ($3_1 >>> 0 < 16145 >>> 0) {
    break label$1
   }
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = $1$hi;
   i64toi32_i32$1 = $1_1;
   i64toi32_i32$4 = 65535;
   i64toi32_i32$5 = -1;
   i64toi32_i32$4 = i64toi32_i32$3 & i64toi32_i32$4 | 0;
   i64toi32_i32$3 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
   i64toi32_i32$1 = 65536;
   i64toi32_i32$5 = 0;
   i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
   $5_1 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
   $5$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $0$hi;
   i64toi32_i32$3 = $5$hi;
   $86($2_1 + 16 | 0 | 0, $0_1 | 0, i64toi32_i32$1 | 0, $5_1 | 0, i64toi32_i32$3 | 0, $3_1 + -16129 | 0 | 0);
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$3 = $5$hi;
   i64toi32_i32$3 = i64toi32_i32$1;
   i64toi32_i32$1 = $5$hi;
   $96($2_1 | 0, $0_1 | 0, i64toi32_i32$3 | 0, $5_1 | 0, i64toi32_i32$1 | 0, 16257 - $3_1 | 0 | 0);
   i64toi32_i32$4 = $2_1 + 8 | 0;
   i64toi32_i32$1 = HEAP32[i64toi32_i32$4 >> 2] | 0;
   i64toi32_i32$3 = HEAP32[(i64toi32_i32$4 + 4 | 0) >> 2] | 0;
   $5_1 = i64toi32_i32$1;
   $5$hi = i64toi32_i32$3;
   i64toi32_i32$4 = i64toi32_i32$1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 25;
   i64toi32_i32$0 = i64toi32_i32$5 & 31 | 0;
   if (32 >>> 0 <= (i64toi32_i32$5 & 63 | 0) >>> 0) {
    i64toi32_i32$1 = 0;
    $40_1 = i64toi32_i32$3 >>> i64toi32_i32$0 | 0;
   } else {
    i64toi32_i32$1 = i64toi32_i32$3 >>> i64toi32_i32$0 | 0;
    $40_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$4 >>> i64toi32_i32$0 | 0) | 0;
   }
   $4_1 = $40_1;
   label$5 : {
    i64toi32_i32$3 = $2_1;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $81_1 = i64toi32_i32$1;
    $81$hi = i64toi32_i32$4;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 16 | 0) >> 2] | 0;
    i64toi32_i32$1 = HEAP32[(i64toi32_i32$3 + 20 | 0) >> 2] | 0;
    $83_1 = i64toi32_i32$4;
    $83$hi = i64toi32_i32$1;
    i64toi32_i32$3 = (i64toi32_i32$3 + 16 | 0) + 8 | 0;
    i64toi32_i32$1 = HEAP32[i64toi32_i32$3 >> 2] | 0;
    i64toi32_i32$4 = HEAP32[(i64toi32_i32$3 + 4 | 0) >> 2] | 0;
    $87_1 = i64toi32_i32$1;
    $87$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $83$hi;
    i64toi32_i32$3 = $83_1;
    i64toi32_i32$1 = $87$hi;
    i64toi32_i32$5 = $87_1;
    i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
    i64toi32_i32$4 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
    i64toi32_i32$3 = 0;
    i64toi32_i32$5 = 0;
    $89_1 = (i64toi32_i32$4 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$1 | 0) != (i64toi32_i32$3 | 0) | 0;
    i64toi32_i32$4 = 0;
    $90$hi = i64toi32_i32$4;
    i64toi32_i32$4 = $81$hi;
    i64toi32_i32$5 = $81_1;
    i64toi32_i32$1 = $90$hi;
    i64toi32_i32$3 = $89_1;
    i64toi32_i32$1 = i64toi32_i32$4 | i64toi32_i32$1 | 0;
    $0_1 = i64toi32_i32$5 | i64toi32_i32$3 | 0;
    $0$hi = i64toi32_i32$1;
    $93_1 = !($0_1 | i64toi32_i32$1 | 0);
    i64toi32_i32$1 = $5$hi;
    i64toi32_i32$4 = $5_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$3 = 33554431;
    i64toi32_i32$5 = i64toi32_i32$1 & i64toi32_i32$5 | 0;
    $5_1 = i64toi32_i32$4 & i64toi32_i32$3 | 0;
    $5$hi = i64toi32_i32$5;
    i64toi32_i32$1 = $5_1;
    i64toi32_i32$4 = 0;
    i64toi32_i32$3 = 16777216;
    $97_1 = i64toi32_i32$5 >>> 0 < i64toi32_i32$4 >>> 0 | ((i64toi32_i32$5 | 0) == (i64toi32_i32$4 | 0) & i64toi32_i32$1 >>> 0 < i64toi32_i32$3 >>> 0 | 0) | 0;
    i64toi32_i32$1 = i64toi32_i32$5;
    i64toi32_i32$3 = $5_1;
    i64toi32_i32$5 = 0;
    i64toi32_i32$4 = 16777216;
    if ((i64toi32_i32$3 | 0) == (i64toi32_i32$4 | 0) & (i64toi32_i32$1 | 0) == (i64toi32_i32$5 | 0) | 0 ? $93_1 : $97_1) {
     break label$5
    }
    $4_1 = $4_1 + 1 | 0;
    break label$1;
   }
   i64toi32_i32$3 = $0$hi;
   i64toi32_i32$3 = $5$hi;
   i64toi32_i32$4 = $5_1;
   i64toi32_i32$1 = 0;
   i64toi32_i32$5 = 16777216;
   i64toi32_i32$1 = i64toi32_i32$3 ^ i64toi32_i32$1 | 0;
   $105_1 = i64toi32_i32$4 ^ i64toi32_i32$5 | 0;
   $105$hi = i64toi32_i32$1;
   i64toi32_i32$1 = $0$hi;
   i64toi32_i32$3 = $0_1;
   i64toi32_i32$4 = $105$hi;
   i64toi32_i32$5 = $105_1;
   i64toi32_i32$4 = i64toi32_i32$1 | i64toi32_i32$4 | 0;
   i64toi32_i32$1 = i64toi32_i32$3 | i64toi32_i32$5 | 0;
   i64toi32_i32$3 = 0;
   i64toi32_i32$5 = 0;
   if ((i64toi32_i32$1 | 0) != (i64toi32_i32$5 | 0) | (i64toi32_i32$4 | 0) != (i64toi32_i32$3 | 0) | 0) {
    break label$1
   }
   $4_1 = ($4_1 & 1 | 0) + $4_1 | 0;
  }
  global$0 = $2_1 + 32 | 0;
  $114 = $4_1;
  i64toi32_i32$1 = $1$hi;
  i64toi32_i32$5 = $1_1;
  i64toi32_i32$4 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$0 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$4 = 0;
   $41_1 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
  } else {
   i64toi32_i32$4 = i64toi32_i32$1 >>> i64toi32_i32$0 | 0;
   $41_1 = (((1 << i64toi32_i32$0 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$0 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$0 | 0) | 0;
  }
  return Math_fround((wasm2js_scratch_store_i32(2, $114 | ($41_1 & -2147483648 | 0) | 0), wasm2js_scratch_load_f32()));
 }
 
 function $102() {
  global$2 = 65536;
  global$1 = (0 + 15 | 0) & -16 | 0;
 }
 
 function $103() {
  return global$0 - global$1 | 0 | 0;
 }
 
 function $104() {
  return global$2 | 0;
 }
 
 function $105() {
  return global$1 | 0;
 }
 
 function $106() {
  return global$0 | 0;
 }
 
 function $107($0_1) {
  $0_1 = $0_1 | 0;
  global$0 = $0_1;
 }
 
 function $108() {
  return global$0 | 0;
 }
 
 function legalfunc$fimport$4($0_1, $1_1, $1$hi, $2_1, $3_1) {
  $0_1 = $0_1 | 0;
  $1_1 = $1_1 | 0;
  $1$hi = $1$hi | 0;
  $2_1 = $2_1 | 0;
  $3_1 = $3_1 | 0;
  var i64toi32_i32$4 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, i64toi32_i32$3 = 0, $12_1 = 0, $4_1 = 0, $6_1 = 0, i64toi32_i32$2 = 0;
  $4_1 = $0_1;
  i64toi32_i32$0 = $1$hi;
  $6_1 = $1_1;
  i64toi32_i32$2 = $1_1;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $12_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $12_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  return legalimport$fimport$4($4_1 | 0, $6_1 | 0, $12_1 | 0, $2_1 | 0, $3_1 | 0) | 0 | 0;
 }
 
 function _ZN17compiler_builtins3int3mul3Mul3mul17h070e9a1c69faec5bE(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$4 = 0, i64toi32_i32$0 = 0, i64toi32_i32$1 = 0, var$2 = 0, i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, var$3 = 0, var$4 = 0, var$5 = 0, $21_1 = 0, $22_1 = 0, var$6 = 0, $24_1 = 0, $17_1 = 0, $18_1 = 0, $23_1 = 0, $29_1 = 0, $45_1 = 0, $56$hi = 0, $62$hi = 0;
  i64toi32_i32$0 = var$1$hi;
  var$2 = var$1;
  var$4 = var$2 >>> 16 | 0;
  i64toi32_i32$0 = var$0$hi;
  var$3 = var$0;
  var$5 = var$3 >>> 16 | 0;
  $17_1 = Math_imul(var$4, var$5);
  $18_1 = var$2;
  i64toi32_i32$2 = var$3;
  i64toi32_i32$1 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$1 = 0;
   $21_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
   $21_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
  }
  $23_1 = $17_1 + Math_imul($18_1, $21_1) | 0;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$0 = var$1;
  i64toi32_i32$2 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$2 = 0;
   $22_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
  } else {
   i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
   $22_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
  }
  $29_1 = $23_1 + Math_imul($22_1, var$3) | 0;
  var$2 = var$2 & 65535 | 0;
  var$3 = var$3 & 65535 | 0;
  var$6 = Math_imul(var$2, var$3);
  var$2 = (var$6 >>> 16 | 0) + Math_imul(var$2, var$5) | 0;
  $45_1 = $29_1 + (var$2 >>> 16 | 0) | 0;
  var$2 = (var$2 & 65535 | 0) + Math_imul(var$4, var$3) | 0;
  i64toi32_i32$2 = 0;
  i64toi32_i32$1 = $45_1 + (var$2 >>> 16 | 0) | 0;
  i64toi32_i32$0 = 0;
  i64toi32_i32$3 = 32;
  i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
  if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
   i64toi32_i32$0 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
   $24_1 = 0;
  } else {
   i64toi32_i32$0 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$1 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$2 << i64toi32_i32$4 | 0) | 0;
   $24_1 = i64toi32_i32$1 << i64toi32_i32$4 | 0;
  }
  $56$hi = i64toi32_i32$0;
  i64toi32_i32$0 = 0;
  $62$hi = i64toi32_i32$0;
  i64toi32_i32$0 = $56$hi;
  i64toi32_i32$2 = $24_1;
  i64toi32_i32$1 = $62$hi;
  i64toi32_i32$3 = var$2 << 16 | 0 | (var$6 & 65535 | 0) | 0;
  i64toi32_i32$1 = i64toi32_i32$0 | i64toi32_i32$1 | 0;
  i64toi32_i32$2 = i64toi32_i32$2 | i64toi32_i32$3 | 0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
  return i64toi32_i32$2 | 0;
 }
 
 function _ZN17compiler_builtins3int4udiv10divmod_u6417h6026910b5ed08e40E(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$2 = 0, i64toi32_i32$3 = 0, i64toi32_i32$4 = 0, i64toi32_i32$1 = 0, i64toi32_i32$0 = 0, i64toi32_i32$5 = 0, var$2 = 0, var$3 = 0, var$4 = 0, var$5 = 0, var$5$hi = 0, var$6 = 0, var$6$hi = 0, i64toi32_i32$6 = 0, $37_1 = 0, $38_1 = 0, $39_1 = 0, $40_1 = 0, $41_1 = 0, $42_1 = 0, $43_1 = 0, $44_1 = 0, var$8$hi = 0, $45_1 = 0, $46_1 = 0, $47_1 = 0, $48_1 = 0, var$7$hi = 0, $49_1 = 0, $63$hi = 0, $65_1 = 0, $65$hi = 0, $120$hi = 0, $129$hi = 0, $134$hi = 0, var$8 = 0, $140 = 0, $140$hi = 0, $142$hi = 0, $144 = 0, $144$hi = 0, $151 = 0, $151$hi = 0, $154$hi = 0, var$7 = 0, $165$hi = 0;
  label$1 : {
   label$2 : {
    label$3 : {
     label$4 : {
      label$5 : {
       label$6 : {
        label$7 : {
         label$8 : {
          label$9 : {
           label$10 : {
            label$11 : {
             i64toi32_i32$0 = var$0$hi;
             i64toi32_i32$2 = var$0;
             i64toi32_i32$1 = 0;
             i64toi32_i32$3 = 32;
             i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
             if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
              i64toi32_i32$1 = 0;
              $37_1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
             } else {
              i64toi32_i32$1 = i64toi32_i32$0 >>> i64toi32_i32$4 | 0;
              $37_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$0 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
             }
             var$2 = $37_1;
             if (var$2) {
              i64toi32_i32$1 = var$1$hi;
              var$3 = var$1;
              if (!var$3) {
               break label$11
              }
              i64toi32_i32$0 = var$3;
              i64toi32_i32$2 = 0;
              i64toi32_i32$3 = 32;
              i64toi32_i32$4 = i64toi32_i32$3 & 31 | 0;
              if (32 >>> 0 <= (i64toi32_i32$3 & 63 | 0) >>> 0) {
               i64toi32_i32$2 = 0;
               $38_1 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
              } else {
               i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$4 | 0;
               $38_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$0 >>> i64toi32_i32$4 | 0) | 0;
              }
              var$4 = $38_1;
              if (!var$4) {
               break label$9
              }
              var$2 = Math_clz32(var$4) - Math_clz32(var$2) | 0;
              if (var$2 >>> 0 <= 31 >>> 0) {
               break label$8
              }
              break label$2;
             }
             i64toi32_i32$2 = var$1$hi;
             i64toi32_i32$1 = var$1;
             i64toi32_i32$0 = 1;
             i64toi32_i32$3 = 0;
             if (i64toi32_i32$2 >>> 0 > i64toi32_i32$0 >>> 0 | ((i64toi32_i32$2 | 0) == (i64toi32_i32$0 | 0) & i64toi32_i32$1 >>> 0 >= i64toi32_i32$3 >>> 0 | 0) | 0) {
              break label$2
             }
             i64toi32_i32$1 = var$0$hi;
             var$2 = var$0;
             i64toi32_i32$1 = i64toi32_i32$2;
             i64toi32_i32$1 = i64toi32_i32$2;
             var$3 = var$1;
             var$2 = (var$2 >>> 0) / (var$3 >>> 0) | 0;
             i64toi32_i32$1 = 0;
             __wasm_intrinsics_temp_i64 = var$0 - Math_imul(var$2, var$3) | 0;
             __wasm_intrinsics_temp_i64$hi = i64toi32_i32$1;
             i64toi32_i32$1 = 0;
             i64toi32_i32$2 = var$2;
             i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
             return i64toi32_i32$2 | 0;
            }
            i64toi32_i32$2 = var$1$hi;
            i64toi32_i32$3 = var$1;
            i64toi32_i32$1 = 0;
            i64toi32_i32$0 = 32;
            i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
            if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
             i64toi32_i32$1 = 0;
             $39_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
            } else {
             i64toi32_i32$1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
             $39_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
            }
            var$3 = $39_1;
            i64toi32_i32$1 = var$0$hi;
            if (!var$0) {
             break label$7
            }
            if (!var$3) {
             break label$6
            }
            var$4 = var$3 + -1 | 0;
            if (var$4 & var$3 | 0) {
             break label$6
            }
            i64toi32_i32$1 = 0;
            i64toi32_i32$2 = var$4 & var$2 | 0;
            i64toi32_i32$3 = 0;
            i64toi32_i32$0 = 32;
            i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
            if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
             i64toi32_i32$3 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
             $40_1 = 0;
            } else {
             i64toi32_i32$3 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
             $40_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
            }
            $63$hi = i64toi32_i32$3;
            i64toi32_i32$3 = var$0$hi;
            i64toi32_i32$1 = var$0;
            i64toi32_i32$2 = 0;
            i64toi32_i32$0 = -1;
            i64toi32_i32$2 = i64toi32_i32$3 & i64toi32_i32$2 | 0;
            $65_1 = i64toi32_i32$1 & i64toi32_i32$0 | 0;
            $65$hi = i64toi32_i32$2;
            i64toi32_i32$2 = $63$hi;
            i64toi32_i32$3 = $40_1;
            i64toi32_i32$1 = $65$hi;
            i64toi32_i32$0 = $65_1;
            i64toi32_i32$1 = i64toi32_i32$2 | i64toi32_i32$1 | 0;
            __wasm_intrinsics_temp_i64 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
            __wasm_intrinsics_temp_i64$hi = i64toi32_i32$1;
            i64toi32_i32$1 = 0;
            i64toi32_i32$3 = var$2 >>> ((__wasm_ctz_i32(var$3 | 0) | 0) & 31 | 0) | 0;
            i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
            return i64toi32_i32$3 | 0;
           }
          }
          var$4 = var$3 + -1 | 0;
          if (!(var$4 & var$3 | 0)) {
           break label$5
          }
          var$2 = (Math_clz32(var$3) + 33 | 0) - Math_clz32(var$2) | 0;
          var$3 = 0 - var$2 | 0;
          break label$3;
         }
         var$3 = 63 - var$2 | 0;
         var$2 = var$2 + 1 | 0;
         break label$3;
        }
        var$4 = (var$2 >>> 0) / (var$3 >>> 0) | 0;
        i64toi32_i32$3 = 0;
        i64toi32_i32$2 = var$2 - Math_imul(var$4, var$3) | 0;
        i64toi32_i32$1 = 0;
        i64toi32_i32$0 = 32;
        i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
        if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
         i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
         $41_1 = 0;
        } else {
         i64toi32_i32$1 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
         $41_1 = i64toi32_i32$2 << i64toi32_i32$4 | 0;
        }
        __wasm_intrinsics_temp_i64 = $41_1;
        __wasm_intrinsics_temp_i64$hi = i64toi32_i32$1;
        i64toi32_i32$1 = 0;
        i64toi32_i32$2 = var$4;
        i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
        return i64toi32_i32$2 | 0;
       }
       var$2 = Math_clz32(var$3) - Math_clz32(var$2) | 0;
       if (var$2 >>> 0 < 31 >>> 0) {
        break label$4
       }
       break label$2;
      }
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$2 = 0;
      __wasm_intrinsics_temp_i64 = var$4 & var$0 | 0;
      __wasm_intrinsics_temp_i64$hi = i64toi32_i32$2;
      if ((var$3 | 0) == (1 | 0)) {
       break label$1
      }
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$2 = 0;
      $120$hi = i64toi32_i32$2;
      i64toi32_i32$2 = var$0$hi;
      i64toi32_i32$3 = var$0;
      i64toi32_i32$1 = $120$hi;
      i64toi32_i32$0 = __wasm_ctz_i32(var$3 | 0) | 0;
      i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
      if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
       i64toi32_i32$1 = 0;
       $42_1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
      } else {
       i64toi32_i32$1 = i64toi32_i32$2 >>> i64toi32_i32$4 | 0;
       $42_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$2 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$3 >>> i64toi32_i32$4 | 0) | 0;
      }
      i64toi32_i32$3 = $42_1;
      i64toi32_i32$HIGH_BITS = i64toi32_i32$1;
      return i64toi32_i32$3 | 0;
     }
     var$3 = 63 - var$2 | 0;
     var$2 = var$2 + 1 | 0;
    }
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$3 = 0;
    $129$hi = i64toi32_i32$3;
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$2 = var$0;
    i64toi32_i32$1 = $129$hi;
    i64toi32_i32$0 = var$2 & 63 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$1 = 0;
     $43_1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
    } else {
     i64toi32_i32$1 = i64toi32_i32$3 >>> i64toi32_i32$4 | 0;
     $43_1 = (((1 << i64toi32_i32$4 | 0) - 1 | 0) & i64toi32_i32$3 | 0) << (32 - i64toi32_i32$4 | 0) | 0 | (i64toi32_i32$2 >>> i64toi32_i32$4 | 0) | 0;
    }
    var$5 = $43_1;
    var$5$hi = i64toi32_i32$1;
    i64toi32_i32$1 = var$0$hi;
    i64toi32_i32$1 = 0;
    $134$hi = i64toi32_i32$1;
    i64toi32_i32$1 = var$0$hi;
    i64toi32_i32$3 = var$0;
    i64toi32_i32$2 = $134$hi;
    i64toi32_i32$0 = var$3 & 63 | 0;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
     $44_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$3 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$1 << i64toi32_i32$4 | 0) | 0;
     $44_1 = i64toi32_i32$3 << i64toi32_i32$4 | 0;
    }
    var$0 = $44_1;
    var$0$hi = i64toi32_i32$2;
    label$13 : {
     if (var$2) {
      i64toi32_i32$2 = var$1$hi;
      i64toi32_i32$1 = var$1;
      i64toi32_i32$3 = -1;
      i64toi32_i32$0 = -1;
      i64toi32_i32$4 = i64toi32_i32$1 + i64toi32_i32$0 | 0;
      i64toi32_i32$5 = i64toi32_i32$2 + i64toi32_i32$3 | 0;
      if (i64toi32_i32$4 >>> 0 < i64toi32_i32$0 >>> 0) {
       i64toi32_i32$5 = i64toi32_i32$5 + 1 | 0
      }
      var$8 = i64toi32_i32$4;
      var$8$hi = i64toi32_i32$5;
      label$15 : while (1) {
       i64toi32_i32$5 = var$5$hi;
       i64toi32_i32$2 = var$5;
       i64toi32_i32$1 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$1 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
        $45_1 = 0;
       } else {
        i64toi32_i32$1 = ((1 << i64toi32_i32$3 | 0) - 1 | 0) & (i64toi32_i32$2 >>> (32 - i64toi32_i32$3 | 0) | 0) | 0 | (i64toi32_i32$5 << i64toi32_i32$3 | 0) | 0;
        $45_1 = i64toi32_i32$2 << i64toi32_i32$3 | 0;
       }
       $140 = $45_1;
       $140$hi = i64toi32_i32$1;
       i64toi32_i32$1 = var$0$hi;
       i64toi32_i32$5 = var$0;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 63;
       i64toi32_i32$3 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = 0;
        $46_1 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
       } else {
        i64toi32_i32$2 = i64toi32_i32$1 >>> i64toi32_i32$3 | 0;
        $46_1 = (((1 << i64toi32_i32$3 | 0) - 1 | 0) & i64toi32_i32$1 | 0) << (32 - i64toi32_i32$3 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$3 | 0) | 0;
       }
       $142$hi = i64toi32_i32$2;
       i64toi32_i32$2 = $140$hi;
       i64toi32_i32$1 = $140;
       i64toi32_i32$5 = $142$hi;
       i64toi32_i32$0 = $46_1;
       i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
       var$5 = i64toi32_i32$1 | i64toi32_i32$0 | 0;
       var$5$hi = i64toi32_i32$5;
       $144 = var$5;
       $144$hi = i64toi32_i32$5;
       i64toi32_i32$5 = var$8$hi;
       i64toi32_i32$5 = var$5$hi;
       i64toi32_i32$5 = var$8$hi;
       i64toi32_i32$2 = var$8;
       i64toi32_i32$1 = var$5$hi;
       i64toi32_i32$0 = var$5;
       i64toi32_i32$3 = i64toi32_i32$2 - i64toi32_i32$0 | 0;
       i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0;
       i64toi32_i32$4 = i64toi32_i32$6 + i64toi32_i32$1 | 0;
       i64toi32_i32$4 = i64toi32_i32$5 - i64toi32_i32$4 | 0;
       i64toi32_i32$5 = i64toi32_i32$3;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 63;
       i64toi32_i32$1 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = i64toi32_i32$4 >> 31 | 0;
        $47_1 = i64toi32_i32$4 >> i64toi32_i32$1 | 0;
       } else {
        i64toi32_i32$2 = i64toi32_i32$4 >> i64toi32_i32$1 | 0;
        $47_1 = (((1 << i64toi32_i32$1 | 0) - 1 | 0) & i64toi32_i32$4 | 0) << (32 - i64toi32_i32$1 | 0) | 0 | (i64toi32_i32$5 >>> i64toi32_i32$1 | 0) | 0;
       }
       var$6 = $47_1;
       var$6$hi = i64toi32_i32$2;
       i64toi32_i32$2 = var$1$hi;
       i64toi32_i32$2 = var$6$hi;
       i64toi32_i32$4 = var$6;
       i64toi32_i32$5 = var$1$hi;
       i64toi32_i32$0 = var$1;
       i64toi32_i32$5 = i64toi32_i32$2 & i64toi32_i32$5 | 0;
       $151 = i64toi32_i32$4 & i64toi32_i32$0 | 0;
       $151$hi = i64toi32_i32$5;
       i64toi32_i32$5 = $144$hi;
       i64toi32_i32$2 = $144;
       i64toi32_i32$4 = $151$hi;
       i64toi32_i32$0 = $151;
       i64toi32_i32$1 = i64toi32_i32$2 - i64toi32_i32$0 | 0;
       i64toi32_i32$6 = i64toi32_i32$2 >>> 0 < i64toi32_i32$0 >>> 0;
       i64toi32_i32$3 = i64toi32_i32$6 + i64toi32_i32$4 | 0;
       i64toi32_i32$3 = i64toi32_i32$5 - i64toi32_i32$3 | 0;
       var$5 = i64toi32_i32$1;
       var$5$hi = i64toi32_i32$3;
       i64toi32_i32$3 = var$0$hi;
       i64toi32_i32$5 = var$0;
       i64toi32_i32$2 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
       if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
        i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
        $48_1 = 0;
       } else {
        i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
        $48_1 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
       }
       $154$hi = i64toi32_i32$2;
       i64toi32_i32$2 = var$7$hi;
       i64toi32_i32$2 = $154$hi;
       i64toi32_i32$3 = $48_1;
       i64toi32_i32$5 = var$7$hi;
       i64toi32_i32$0 = var$7;
       i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
       var$0 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
       var$0$hi = i64toi32_i32$5;
       i64toi32_i32$5 = var$6$hi;
       i64toi32_i32$2 = var$6;
       i64toi32_i32$3 = 0;
       i64toi32_i32$0 = 1;
       i64toi32_i32$3 = i64toi32_i32$5 & i64toi32_i32$3 | 0;
       var$6 = i64toi32_i32$2 & i64toi32_i32$0 | 0;
       var$6$hi = i64toi32_i32$3;
       var$7 = var$6;
       var$7$hi = i64toi32_i32$3;
       var$2 = var$2 + -1 | 0;
       if (var$2) {
        continue label$15
       }
       break label$15;
      };
      break label$13;
     }
    }
    i64toi32_i32$3 = var$5$hi;
    __wasm_intrinsics_temp_i64 = var$5;
    __wasm_intrinsics_temp_i64$hi = i64toi32_i32$3;
    i64toi32_i32$3 = var$0$hi;
    i64toi32_i32$5 = var$0;
    i64toi32_i32$2 = 0;
    i64toi32_i32$0 = 1;
    i64toi32_i32$4 = i64toi32_i32$0 & 31 | 0;
    if (32 >>> 0 <= (i64toi32_i32$0 & 63 | 0) >>> 0) {
     i64toi32_i32$2 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
     $49_1 = 0;
    } else {
     i64toi32_i32$2 = ((1 << i64toi32_i32$4 | 0) - 1 | 0) & (i64toi32_i32$5 >>> (32 - i64toi32_i32$4 | 0) | 0) | 0 | (i64toi32_i32$3 << i64toi32_i32$4 | 0) | 0;
     $49_1 = i64toi32_i32$5 << i64toi32_i32$4 | 0;
    }
    $165$hi = i64toi32_i32$2;
    i64toi32_i32$2 = var$6$hi;
    i64toi32_i32$2 = $165$hi;
    i64toi32_i32$3 = $49_1;
    i64toi32_i32$5 = var$6$hi;
    i64toi32_i32$0 = var$6;
    i64toi32_i32$5 = i64toi32_i32$2 | i64toi32_i32$5 | 0;
    i64toi32_i32$3 = i64toi32_i32$3 | i64toi32_i32$0 | 0;
    i64toi32_i32$HIGH_BITS = i64toi32_i32$5;
    return i64toi32_i32$3 | 0;
   }
   i64toi32_i32$3 = var$0$hi;
   __wasm_intrinsics_temp_i64 = var$0;
   __wasm_intrinsics_temp_i64$hi = i64toi32_i32$3;
   i64toi32_i32$3 = 0;
   var$0 = 0;
   var$0$hi = i64toi32_i32$3;
  }
  i64toi32_i32$3 = var$0$hi;
  i64toi32_i32$5 = var$0;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$3;
  return i64toi32_i32$5 | 0;
 }
 
 function __wasm_ctz_i32(var$0) {
  var$0 = var$0 | 0;
  if (var$0) {
   return 31 - Math_clz32((var$0 + -1 | 0) ^ var$0 | 0) | 0 | 0
  }
  return 32 | 0;
 }
 
 function __wasm_i64_mul(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$0 = var$1$hi;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$1 = _ZN17compiler_builtins3int3mul3Mul3mul17h070e9a1c69faec5bE(var$0 | 0, i64toi32_i32$0 | 0, var$1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$1 | 0;
 }
 
 function __wasm_i64_udiv(var$0, var$0$hi, var$1, var$1$hi) {
  var$0 = var$0 | 0;
  var$0$hi = var$0$hi | 0;
  var$1 = var$1 | 0;
  var$1$hi = var$1$hi | 0;
  var i64toi32_i32$0 = 0, i64toi32_i32$1 = 0;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$0 = var$1$hi;
  i64toi32_i32$0 = var$0$hi;
  i64toi32_i32$1 = var$1$hi;
  i64toi32_i32$1 = _ZN17compiler_builtins3int4udiv10divmod_u6417h6026910b5ed08e40E(var$0 | 0, i64toi32_i32$0 | 0, var$1 | 0, i64toi32_i32$1 | 0) | 0;
  i64toi32_i32$0 = i64toi32_i32$HIGH_BITS;
  i64toi32_i32$HIGH_BITS = i64toi32_i32$0;
  return i64toi32_i32$1 | 0;
 }
 
 function __wasm_rotl_i32(var$0, var$1) {
  var$0 = var$0 | 0;
  var$1 = var$1 | 0;
  var var$2 = 0;
  var$2 = var$1 & 31 | 0;
  var$1 = (0 - var$1 | 0) & 31 | 0;
  return ((-1 >>> var$2 | 0) & var$0 | 0) << var$2 | 0 | (((-1 << var$1 | 0) & var$0 | 0) >>> var$1 | 0) | 0 | 0;
 }
 
 // EMSCRIPTEN_END_FUNCS
;
 bufferView = HEAPU8;
 initActiveSegments(imports);
 var FUNCTION_TABLE = Table([null, $0, $11, $10, $12, $39, $40, $43, $44, $46]);
 function __wasm_memory_size() {
  return buffer.byteLength / 65536 | 0;
 }
 
 return {
  "memory": Object.create(Object.prototype, {
   "grow": {
    
   }, 
   "buffer": {
    "get": function () {
     return buffer;
    }
    
   }
  }), 
  "__indirect_function_table": FUNCTION_TABLE, 
  "_start": $3, 
  "emscripten_stack_init": $102, 
  "emscripten_stack_get_free": $103, 
  "emscripten_stack_get_base": $104, 
  "emscripten_stack_get_end": $105, 
  "stackSave": $106, 
  "stackRestore": $107, 
  "emscripten_stack_get_current": $108
 };
}

  return asmFunc(info);
}

)(info);
  },

  instantiate: /** @suppress{checkTypes} */ function(binary, info) {
    return {
      then: function(ok) {
        var module = new WebAssembly.Module(binary);
        ok({
          'instance': new WebAssembly.Instance(module, info)
        });
        // Emulate a simple WebAssembly.instantiate(..).then(()=>{}).catch(()=>{}) syntax.
        return { catch: function() {} };
      }
    };
  },

  RuntimeError: Error
};

// We don't need to actually download a wasm binary, mark it as present but empty.
wasmBinary = [];
