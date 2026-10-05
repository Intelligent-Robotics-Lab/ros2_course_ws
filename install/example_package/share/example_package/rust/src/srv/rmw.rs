#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "example_package__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_package__srv__Adder_Request() -> *const std::ffi::c_void;
}

#[link(name = "example_package__rosidl_generator_c")]
extern "C" {
    fn example_package__srv__Adder_Request__init(msg: *mut Adder_Request) -> bool;
    fn example_package__srv__Adder_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Adder_Request>, size: usize) -> bool;
    fn example_package__srv__Adder_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Adder_Request>);
    fn example_package__srv__Adder_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Adder_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Adder_Request>) -> bool;
}

// Corresponds to example_package__srv__Adder_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Adder_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub value1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub value2: f64,

}



impl Default for Adder_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_package__srv__Adder_Request__init(&mut msg as *mut _) {
        panic!("Call to example_package__srv__Adder_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Adder_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Adder_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Adder_Request where Self: Sized {
  const TYPE_NAME: &'static str = "example_package/srv/Adder_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_package__srv__Adder_Request() }
  }
}


#[link(name = "example_package__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__example_package__srv__Adder_Response() -> *const std::ffi::c_void;
}

#[link(name = "example_package__rosidl_generator_c")]
extern "C" {
    fn example_package__srv__Adder_Response__init(msg: *mut Adder_Response) -> bool;
    fn example_package__srv__Adder_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Adder_Response>, size: usize) -> bool;
    fn example_package__srv__Adder_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Adder_Response>);
    fn example_package__srv__Adder_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Adder_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Adder_Response>) -> bool;
}

// Corresponds to example_package__srv__Adder_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Adder_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: f64,

}



impl Default for Adder_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !example_package__srv__Adder_Response__init(&mut msg as *mut _) {
        panic!("Call to example_package__srv__Adder_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Adder_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { example_package__srv__Adder_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Adder_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Adder_Response where Self: Sized {
  const TYPE_NAME: &'static str = "example_package/srv/Adder_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__example_package__srv__Adder_Response() }
  }
}






#[link(name = "example_package__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__example_package__srv__Adder() -> *const std::ffi::c_void;
}

// Corresponds to example_package__srv__Adder
#[allow(missing_docs, non_camel_case_types)]
pub struct Adder;

impl rosidl_runtime_rs::Service for Adder {
    type Request = Adder_Request;
    type Response = Adder_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__example_package__srv__Adder() }
    }
}


