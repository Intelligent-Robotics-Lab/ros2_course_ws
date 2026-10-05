#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to example_package__srv__Adder_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Adder_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Adder_Request {
  type RmwMsg = super::srv::rmw::Adder_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        value1: msg.value1,
        value2: msg.value2,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      value1: msg.value1,
      value2: msg.value2,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      value1: msg.value1,
      value2: msg.value2,
    }
  }
}


// Corresponds to example_package__srv__Adder_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Adder_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub result: f64,

}



impl Default for Adder_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Adder_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Adder_Response {
  type RmwMsg = super::srv::rmw::Adder_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        result: msg.result,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      result: msg.result,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      result: msg.result,
    }
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


