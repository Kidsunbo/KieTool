/**
 * Autogenerated by Thrift Compiler (0.13.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef ToolLogistic_H
#define ToolLogistic_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "tool_logistic_types.h"

namespace KieShop { namespace tool {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class ToolLogisticIf {
 public:
  virtual ~ToolLogisticIf() {}
  virtual void getShardingKey(ShardingKeyResponse& _return, const ShardingKeyRequest& req) = 0;
  virtual void getSnowFlake(SnowFlakeResponse& _return, const SnowFlakeRequest& req) = 0;
};

class ToolLogisticIfFactory {
 public:
  typedef ToolLogisticIf Handler;

  virtual ~ToolLogisticIfFactory() {}

  virtual ToolLogisticIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(ToolLogisticIf* /* handler */) = 0;
};

class ToolLogisticIfSingletonFactory : virtual public ToolLogisticIfFactory {
 public:
  ToolLogisticIfSingletonFactory(const ::std::shared_ptr<ToolLogisticIf>& iface) : iface_(iface) {}
  virtual ~ToolLogisticIfSingletonFactory() {}

  virtual ToolLogisticIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(ToolLogisticIf* /* handler */) {}

 protected:
  ::std::shared_ptr<ToolLogisticIf> iface_;
};

class ToolLogisticNull : virtual public ToolLogisticIf {
 public:
  virtual ~ToolLogisticNull() {}
  void getShardingKey(ShardingKeyResponse& /* _return */, const ShardingKeyRequest& /* req */) {
    return;
  }
  void getSnowFlake(SnowFlakeResponse& /* _return */, const SnowFlakeRequest& /* req */) {
    return;
  }
};

typedef struct _ToolLogistic_getShardingKey_args__isset {
  _ToolLogistic_getShardingKey_args__isset() : req(false) {}
  bool req :1;
} _ToolLogistic_getShardingKey_args__isset;

class ToolLogistic_getShardingKey_args {
 public:

  ToolLogistic_getShardingKey_args(const ToolLogistic_getShardingKey_args&);
  ToolLogistic_getShardingKey_args& operator=(const ToolLogistic_getShardingKey_args&);
  ToolLogistic_getShardingKey_args() {
  }

  virtual ~ToolLogistic_getShardingKey_args() noexcept;
  ShardingKeyRequest req;

  _ToolLogistic_getShardingKey_args__isset __isset;

  void __set_req(const ShardingKeyRequest& val);

  bool operator == (const ToolLogistic_getShardingKey_args & rhs) const
  {
    if (!(req == rhs.req))
      return false;
    return true;
  }
  bool operator != (const ToolLogistic_getShardingKey_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ToolLogistic_getShardingKey_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ToolLogistic_getShardingKey_pargs {
 public:


  virtual ~ToolLogistic_getShardingKey_pargs() noexcept;
  const ShardingKeyRequest* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ToolLogistic_getShardingKey_result__isset {
  _ToolLogistic_getShardingKey_result__isset() : success(false) {}
  bool success :1;
} _ToolLogistic_getShardingKey_result__isset;

class ToolLogistic_getShardingKey_result {
 public:

  ToolLogistic_getShardingKey_result(const ToolLogistic_getShardingKey_result&);
  ToolLogistic_getShardingKey_result& operator=(const ToolLogistic_getShardingKey_result&);
  ToolLogistic_getShardingKey_result() {
  }

  virtual ~ToolLogistic_getShardingKey_result() noexcept;
  ShardingKeyResponse success;

  _ToolLogistic_getShardingKey_result__isset __isset;

  void __set_success(const ShardingKeyResponse& val);

  bool operator == (const ToolLogistic_getShardingKey_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ToolLogistic_getShardingKey_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ToolLogistic_getShardingKey_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ToolLogistic_getShardingKey_presult__isset {
  _ToolLogistic_getShardingKey_presult__isset() : success(false) {}
  bool success :1;
} _ToolLogistic_getShardingKey_presult__isset;

class ToolLogistic_getShardingKey_presult {
 public:


  virtual ~ToolLogistic_getShardingKey_presult() noexcept;
  ShardingKeyResponse* success;

  _ToolLogistic_getShardingKey_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _ToolLogistic_getSnowFlake_args__isset {
  _ToolLogistic_getSnowFlake_args__isset() : req(false) {}
  bool req :1;
} _ToolLogistic_getSnowFlake_args__isset;

class ToolLogistic_getSnowFlake_args {
 public:

  ToolLogistic_getSnowFlake_args(const ToolLogistic_getSnowFlake_args&);
  ToolLogistic_getSnowFlake_args& operator=(const ToolLogistic_getSnowFlake_args&);
  ToolLogistic_getSnowFlake_args() {
  }

  virtual ~ToolLogistic_getSnowFlake_args() noexcept;
  SnowFlakeRequest req;

  _ToolLogistic_getSnowFlake_args__isset __isset;

  void __set_req(const SnowFlakeRequest& val);

  bool operator == (const ToolLogistic_getSnowFlake_args & rhs) const
  {
    if (!(req == rhs.req))
      return false;
    return true;
  }
  bool operator != (const ToolLogistic_getSnowFlake_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ToolLogistic_getSnowFlake_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class ToolLogistic_getSnowFlake_pargs {
 public:


  virtual ~ToolLogistic_getSnowFlake_pargs() noexcept;
  const SnowFlakeRequest* req;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ToolLogistic_getSnowFlake_result__isset {
  _ToolLogistic_getSnowFlake_result__isset() : success(false) {}
  bool success :1;
} _ToolLogistic_getSnowFlake_result__isset;

class ToolLogistic_getSnowFlake_result {
 public:

  ToolLogistic_getSnowFlake_result(const ToolLogistic_getSnowFlake_result&);
  ToolLogistic_getSnowFlake_result& operator=(const ToolLogistic_getSnowFlake_result&);
  ToolLogistic_getSnowFlake_result() {
  }

  virtual ~ToolLogistic_getSnowFlake_result() noexcept;
  SnowFlakeResponse success;

  _ToolLogistic_getSnowFlake_result__isset __isset;

  void __set_success(const SnowFlakeResponse& val);

  bool operator == (const ToolLogistic_getSnowFlake_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const ToolLogistic_getSnowFlake_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ToolLogistic_getSnowFlake_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _ToolLogistic_getSnowFlake_presult__isset {
  _ToolLogistic_getSnowFlake_presult__isset() : success(false) {}
  bool success :1;
} _ToolLogistic_getSnowFlake_presult__isset;

class ToolLogistic_getSnowFlake_presult {
 public:


  virtual ~ToolLogistic_getSnowFlake_presult() noexcept;
  SnowFlakeResponse* success;

  _ToolLogistic_getSnowFlake_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class ToolLogisticClient : virtual public ToolLogisticIf {
 public:
  ToolLogisticClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  ToolLogisticClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getShardingKey(ShardingKeyResponse& _return, const ShardingKeyRequest& req);
  void send_getShardingKey(const ShardingKeyRequest& req);
  void recv_getShardingKey(ShardingKeyResponse& _return);
  void getSnowFlake(SnowFlakeResponse& _return, const SnowFlakeRequest& req);
  void send_getSnowFlake(const SnowFlakeRequest& req);
  void recv_getSnowFlake(SnowFlakeResponse& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class ToolLogisticProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<ToolLogisticIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (ToolLogisticProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getShardingKey(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSnowFlake(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  ToolLogisticProcessor(::std::shared_ptr<ToolLogisticIf> iface) :
    iface_(iface) {
    processMap_["getShardingKey"] = &ToolLogisticProcessor::process_getShardingKey;
    processMap_["getSnowFlake"] = &ToolLogisticProcessor::process_getSnowFlake;
  }

  virtual ~ToolLogisticProcessor() {}
};

class ToolLogisticProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  ToolLogisticProcessorFactory(const ::std::shared_ptr< ToolLogisticIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< ToolLogisticIfFactory > handlerFactory_;
};

class ToolLogisticMultiface : virtual public ToolLogisticIf {
 public:
  ToolLogisticMultiface(std::vector<std::shared_ptr<ToolLogisticIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~ToolLogisticMultiface() {}
 protected:
  std::vector<std::shared_ptr<ToolLogisticIf> > ifaces_;
  ToolLogisticMultiface() {}
  void add(::std::shared_ptr<ToolLogisticIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getShardingKey(ShardingKeyResponse& _return, const ShardingKeyRequest& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getShardingKey(_return, req);
    }
    ifaces_[i]->getShardingKey(_return, req);
    return;
  }

  void getSnowFlake(SnowFlakeResponse& _return, const SnowFlakeRequest& req) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSnowFlake(_return, req);
    }
    ifaces_[i]->getSnowFlake(_return, req);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class ToolLogisticConcurrentClient : virtual public ToolLogisticIf {
 public:
  ToolLogisticConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  ToolLogisticConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getShardingKey(ShardingKeyResponse& _return, const ShardingKeyRequest& req);
  int32_t send_getShardingKey(const ShardingKeyRequest& req);
  void recv_getShardingKey(ShardingKeyResponse& _return, const int32_t seqid);
  void getSnowFlake(SnowFlakeResponse& _return, const SnowFlakeRequest& req);
  int32_t send_getSnowFlake(const SnowFlakeRequest& req);
  void recv_getSnowFlake(SnowFlakeResponse& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}} // namespace

#endif