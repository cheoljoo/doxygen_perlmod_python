$doxydocs=
{
  classes => [
    {
      name => 'android::BnInterface',
      kind => 'class',
      derived => [
        {
          name => 'BnRegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'BnRegionManagerService',
      kind => 'class',
      base => [
        {
          name => 'android::BnInterface',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'onTransact',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BnRegionManagerService'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'onTransact',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'onTransact function for the '
                },
                {
                  type => 'url',
                  link => 'classBnRegionManagerService',
                  content => 'BnRegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'code',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'operation code in binder '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'data',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'data parcel in binder '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'reply',
                          dir => 'in,out'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'reply packet in binder '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'flags',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'flags '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'status_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'It returns the status of onTransact function. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual android::status_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'code',
                type => 'uint32_t'
              },
              {
                declaration_name => 'data',
                type => 'const android::Parcel &'
              },
              {
                declaration_name => 'reply',
                type => 'android::Parcel *'
              },
              {
                declaration_name => 'flags',
                type => 'uint32_t'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'BnSystemPostReceiver',
      kind => 'class',
      derived => [
        {
          name => 'RegionInputManager::systemPostReceiver',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'android::BpInterface',
      kind => 'class',
      derived => [
        {
          name => 'BpRegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'BpRegionManagerService',
      kind => 'class',
      base => [
        {
          name => 'android::BpInterface',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'BpRegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getLogLevel',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getMcfgRegion',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getNADRegion',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getNADRevision',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getNADType',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'getVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'setLogLevel',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'setLogLevelAsDefault',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        },
        {
          name => 'setVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BpRegionManagerService'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'BpRegionManagerService',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the constructor of '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'impl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android binder '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'impl',
                type => 'const android::sp< android::IBinder > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevel',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevel sets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - each module can set log level separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t : set log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevelAsDefault',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevelAsDefault sets the log level according to perf and debug mode. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - set log level as default log level according to perf and debug mode'
                },
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getLogLevel',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'getLogLevel gets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - get log level of each module separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t& : get log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get boot mode information in hal system. This api get the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get nation information in hal system. This api get the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : region information from NAD related to mcfg(modem config) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : get variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Receives the delete request for the created file and deletes the specified file. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set boot mode information in hal system. This api set the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set nation information in hal system. This api set the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : set variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder in the '
                },
                {
                  type => 'url',
                  link => 'classBpRegionManagerService',
                  content => 'BpRegionManagerService'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If it is successful, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'android::IBinder::DeathRecipient',
      kind => 'class',
      derived => [
        {
          name => 'RegionInputManager::ServiceDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'EnvironmentVariant',
      kind => 'class',
      base => [
        {
          name => 'android::RefBase',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'EnvironmentVariant.h'
      },
      all_members => [
        {
          name => 'btPresent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'countryEquipment',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'ecu',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'EnvironmentVariant',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'EnvironmentVariant',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getBtPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getCountryEquipment',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getEcu',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getHousingVariant',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getHwVar',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getMobilePresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getMobileStandard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getModelYear',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getRevision',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getV2xPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getV2xType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'getWlanPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'housingVariant',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'hwVar',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'init',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'mobilePresent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'mobileStandard',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'modelYear',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'operator=',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'readFromParcel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'revision',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'setData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'setDataFormat',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'setTo',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'toString',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'toString',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'v2xPresent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'v2xType',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'wlanPresent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'EnvironmentVariant'
        },
        {
          name => 'writeToParcel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        },
        {
          name => '~EnvironmentVariant',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'EnvironmentVariant'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'EnvironmentVariant',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'constructor of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'EnvironmentVariant',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'copy operator of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'other',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'classEnvironmentVariant',
                          content => 'EnvironmentVariant'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'other',
                type => 'const EnvironmentVariant &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~EnvironmentVariant',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'destructor of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {},
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'operator=',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => '= operator of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'other',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'classEnvironmentVariant',
                          content => 'EnvironmentVariant'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'EnvironmentVariant'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'EnvironmentVariant &',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'other',
                type => 'const EnvironmentVariant &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setTo',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is for setting to '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'other',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'classEnvironmentVariant',
                          content => 'EnvironmentVariant'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'other',
                type => 'const EnvironmentVariant &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'writeToParcel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for writing parcel of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'parcel',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android Parcel '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parcel',
                type => 'android::Parcel *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'readFromParcel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for reading from parcel of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'parcel',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android Parcel '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parcel',
                type => 'const android::Parcel &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'toString',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is a function that displays data in the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'toString',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is a function that displays data by a specific name in the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'from',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'printing data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'from',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getEcu',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting Ecu of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'std::string'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'std::string',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getV2xPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting V2xPresent of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getWlanPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting WlanPresent of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getBtPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting BtPresent of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHwVar',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting HwVar of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'std::string'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'std::string',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getRevision',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting Revision of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'std::string'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'std::string',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getModelYear',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting ModelYear of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHousingVariant',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting HousingVariant of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMobileStandard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting MobileStandard of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getCountryEquipment',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting CountryEquipment of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getV2xType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting V2xType of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMobilePresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is for getting MobilePresent of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'int8_t'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'int8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setDataFormat',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'function for setting data into '
                },
                {
                  type => 'url',
                  link => 'structEnvironmentVariantDataFormat',
                  content => 'EnvironmentVariantDataFormat'
                },
                {
                  type => 'text',
                  content => ' structure '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'df',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'structEnvironmentVariantDataFormat',
                          content => 'EnvironmentVariantDataFormat'
                        },
                        {
                          type => 'text',
                          content => ' structure '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mecu',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mv2xPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mwlanPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mbtPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mhwVar',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mrevision',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmodelYear',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mhousingVariant',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmobileStandard',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mcountryEquipment',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mv2xType',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmobilePresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'df',
                type => 'EnvironmentVariantDataFormat &'
              },
              {
                declaration_name => 'mecu',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mhwVar',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mrevision',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mmodelYear',
                type => 'int8_t'
              },
              {
                declaration_name => 'mhousingVariant',
                type => 'int8_t'
              },
              {
                declaration_name => 'mmobileStandard',
                type => 'int8_t'
              },
              {
                declaration_name => 'mcountryEquipment',
                type => 'int8_t'
              },
              {
                declaration_name => 'mv2xType',
                type => 'int8_t'
              },
              {
                declaration_name => 'mmobilePresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mv2xPresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mwlanPresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mbtPresent',
                type => 'int8_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is function for setting data of the '
                },
                {
                  type => 'url',
                  link => 'classEnvironmentVariant',
                  content => 'EnvironmentVariant'
                },
                {
                  type => 'text',
                  content => ' data class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mecu',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mv2xPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mwlanPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mbtPresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mhwVar',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mrevision',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmodelYear',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mhousingVariant',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmobileStandard',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mcountryEquipment',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mv2xType',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'mmobilePresent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'linebreak'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mecu',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mhwVar',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mrevision',
                type => 'const std::string &'
              },
              {
                declaration_name => 'mmodelYear',
                type => 'int8_t'
              },
              {
                declaration_name => 'mhousingVariant',
                type => 'int8_t'
              },
              {
                declaration_name => 'mmobileStandard',
                type => 'int8_t'
              },
              {
                declaration_name => 'mcountryEquipment',
                type => 'int8_t'
              },
              {
                declaration_name => 'mv2xType',
                type => 'int8_t'
              },
              {
                declaration_name => 'mmobilePresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mv2xPresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mwlanPresent',
                type => 'int8_t'
              },
              {
                declaration_name => 'mbtPresent',
                type => 'int8_t'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'init',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'ecu',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'hwVar',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'revision',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'modelYear',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'housingVariant',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'mobileStandard',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'countryEquipment',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'v2xType',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'mobilePresent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'v2xPresent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'wlanPresent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'btPresent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'data class : '
          },
          {
            type => 'url',
            link => 'classEnvironmentVariant',
            content => 'EnvironmentVariant'
          },
          {
            type => 'text',
            content => ' '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'url',
            link => 'classEnvironmentVariant',
            content => 'EnvironmentVariant'
          },
          {
            type => 'text',
            content => ' class '
          }
        ]
      }
    },
    {
      name => 'EnvironmentVariantDataFormat',
      kind => 'struct',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'EnvironmentVariant.h'
      },
      all_members => [
        {
          name => 'btPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'countryEquipment',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'ecu',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'housingVariant',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'hwVar',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'mobilePresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'mobileStandard',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'modelYear',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'revision',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'v2xPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'v2xType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        },
        {
          name => 'wlanPresent',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'EnvironmentVariantDataFormat'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'ecu',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'hwVar',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'revision',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::string'
          },
          {
            kind => 'variable',
            name => 'modelYear',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'housingVariant',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'mobileStandard',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'countryEquipment',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'v2xType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'mobilePresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'v2xPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'wlanPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          },
          {
            kind => 'variable',
            name => 'btPresent',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int8_t'
          }
        ]
      },
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            attention => [
              {
                type => 'text',
                content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
              }
            ]
          },
          {
            author => [
              {
                type => 'url',
                content => 'logan.kim@lge.com'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '2023.07.13 '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => '3.0.00 '
              }
            ]
          }
        ]
      }
    },
    {
      name => 'sl::Handler',
      kind => 'class',
      derived => [
        {
          name => 'RegionInputManager::RegionHandler',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'android::IInterface',
      kind => 'class',
      derived => [
        {
          name => 'IRegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'IRegionManagerService',
      kind => 'class',
      base => [
        {
          name => 'android::IInterface',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'IRegionManagerService.h'
      },
      all_members => [
        {
          name => 'DECLARE_META_INTERFACE',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getLogLevel',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getMcfgRegion',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getNADRegion',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getNADRevision',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getNADType',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getNation',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'getVariantData',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'setLogLevel',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'setLogLevelAsDefault',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        },
        {
          name => 'setVariantData',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'IRegionManagerService'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'DECLARE_META_INTERFACE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'RegionManagerService'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevel',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevel sets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - each module can set log level separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t : set log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevelAsDefault',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevelAsDefault sets the log level according to perf and debug mode. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - set log level as default log level according to perf and debug mode'
                },
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getLogLevel',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'getLogLevel gets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - get log level of each module separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t& : get log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get boot mode information in hal system. This api get the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get boot mode information in hal system. This api get the boot mode information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get nation information in hal system. This api get the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get nation information in hal system. This api get the nation information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : region information from NAD related to mcfg(modem config) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == region information from NAD related to mcfg(modem config) ==
    App -> BpRegionManagerService : getMcfgRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETMCFGREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETMCFGREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getMcfgRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. ==
    App -> BpRegionManagerService : getNADRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. ==
    App -> BpRegionManagerService : getNADRevision(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREVISION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREVISION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRevision(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. ==
    App -> BpRegionManagerService : getNADType(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADTYPE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADTYPE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADType(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. ==
    App -> BpRegionManagerService : getNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : get variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == get variant data ==
    App -> BpRegionManagerService : getVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Receives the delete request for the created file and deletes the specified file. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Receives the delete request for the created file and deletes the specified file. ==
    App -> BpRegionManagerService : memoryFileDelete(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_MEMORYFILEDELETE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_MEMORYFILEDELETE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : memoryFileDelete(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set boot mode information in hal system. This api set the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set boot mode information in hal system. This api set the boot mode information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set nation information in hal system. This api set the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set nation information in hal system. This api set the nation information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : set variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == set variant data ==
    App -> BpRegionManagerService : setVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'If Apps or other services need to control REGION, It could be obatined by these API. To use these API, APP or Service, You Should get IRegionManaerService. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            note => [
              {
                type => 'text',
                content => 'regionManagerService service name is '
              },
              {
                type => 'style',
                style => 'bold',
                enable => 'yes'
              },
              {
                type => 'text',
                content => 'Region_SRV_NAME'
              },
              {
                type => 'style',
                style => 'bold',
                enable => 'no'
              },
              {
                type => 'text',
                content => ' (="service_layer.regionManagerService") '
              }
            ]
          }
        ]
      }
    },
    {
      name => 'RegionManager::ManagerDeathRecipient',
      kind => 'class',
      base => [
        {
          name => 'android::IBinder::DeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'binderDied',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManager::ManagerDeathRecipient'
        },
        {
          name => 'ManagerDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager::ManagerDeathRecipient'
        },
        {
          name => 'mParent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager::ManagerDeathRecipient'
        },
        {
          name => '~ManagerDeathRecipient',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManager::ManagerDeathRecipient'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ManagerDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor of DeathRecipient. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'parent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'regionManager '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parent',
                type => 'RegionManager &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~ManagerDeathRecipient',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the destructor of DeathRecipient. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'binderDied',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is called when binder is died. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'IBinder '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mParent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionManager &'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService::ReceiverDeathRecipient',
      kind => 'class',
      base => [
        {
          name => 'android::IBinder::DeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'binderDied',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ReceiverDeathRecipient'
        },
        {
          name => 'mParent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService::ReceiverDeathRecipient'
        },
        {
          name => 'ReceiverDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService::ReceiverDeathRecipient'
        },
        {
          name => '~ReceiverDeathRecipient',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ReceiverDeathRecipient'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ReceiverDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor of ReceiverDeathRecipient. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'parent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'classRegionManagerService',
                          content => 'RegionManagerService'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parent',
                type => 'RegionManagerService &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~ReceiverDeathRecipient',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the destructor of ReceiverDeathRecipient. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'binderDied',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function is called when binder is died. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'IBinder '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mParent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionManagerService &'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'android::RefBase',
      kind => 'class',
      derived => [
        {
          name => 'EnvironmentVariant',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'RegionExtBase',
          virtualness => 'virtual',
          protection => 'public'
        },
        {
          name => 'RegionInputManager',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'RegionManager',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionExtBase',
      kind => 'class',
      base => [
        {
          name => 'android::RefBase',
          virtualness => 'virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'RegionExtBase.h'
      },
      all_members => [
        {
          name => 'getHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getHwRevision',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getMcfgRegionId',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getNadType',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getRegionId',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'getVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'handleBootComplete',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'init',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'mVariantData',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionExtBase'
        },
        {
          name => 'RegionExtBase',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => 'setVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        },
        {
          name => '~RegionExtBase',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionExtBase'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'RegionExtBase',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => '~RegionExtBase',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'init',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'looper',
                type => 'android::sp< sl::SLLooper > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleBootComplete',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getNadType',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getRegionId',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHwRevision',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegionId',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual android::sp< EnvironmentVariant >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'data',
                type => 'const android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mVariantData',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< EnvironmentVariant >'
          }
        ]
      },
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            attention => [
              {
                type => 'text',
                content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
              }
            ]
          },
          {
            author => [
              {
                type => 'url',
                content => 'logan.kim@lge.com'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '2021.09.30 '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => '1.0.00 '
              }
            ]
          },
          {
            see => [
              {
                type => 'text',
                content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> "This is intended design" '
              }
            ]
          }
        ]
      }
    },
    {
      name => 'RegionInputManager::RegionHandler',
      kind => 'class',
      base => [
        {
          name => 'sl::Handler',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'handleMessage',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::RegionHandler'
        },
        {
          name => 'mRegionInputMgr',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager::RegionHandler'
        },
        {
          name => 'RegionHandler',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager::RegionHandler'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'RegionHandler',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1RegionHandler',
                  content => 'RegionHandler'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'looper',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android SLLooper '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'outer',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'url',
                          link => 'classRegionInputManager',
                          content => 'RegionInputManager'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'looper',
                type => 'android::sp< sl::SLLooper > &'
              },
              {
                declaration_name => 'outer',
                type => 'RegionInputManager &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handleMessage',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the handle function of the input manager. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'msg',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Message for handler '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'msg',
                type => 'const android::sp< sl::Message > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mRegionInputMgr',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionInputManager &'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionInputManager',
      kind => 'class',
      base => [
        {
          name => 'android::RefBase',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
        {
          name => 'RegionInputManager::RegionHandler'
        },
        {
          name => 'RegionInputManager::RegionInputMgrTimer'
        },
        {
          name => 'RegionInputManager::ServiceDeathRecipient'
        },
        {
          name => 'RegionInputManager::systemPostReceiver'
        }
      ],
      includes => {
        local => 'no',
        name => 'RegionInputManager.h'
      },
      all_members => [
        {
          name => 'connectToAppMgr',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'createVariantImpl',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getHwRevision',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getMcfgRegionId',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getNadType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getRegionId',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'getVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'handleBootComplete',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'init',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'm_regionVariant',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'm_WatcdogTimer',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mAppManager',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mBinderDiedLock',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mDLextlib',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'mMyHandler',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mRegionInputMgrTimer',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mRegionMgrService',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mServiceDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'mSystemPostReceiver',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager'
        },
        {
          name => 'onServiceBinderDied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'RegionInputManager',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => 'setVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        },
        {
          name => '~RegionInputManager',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'onServiceBinderDied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When the services are died, it is where you put the code to reconnect. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'who generates Dead state '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'RegionInputManager',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is a function for the constructor of the input manager class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mRegionMgrService',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android::sp<RegionManagerService> '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 2-10-2 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mRegionMgrService',
                type => 'android::sp< RegionManagerService >'
              }
            ]
          },
          {
            kind => 'function',
            name => '~RegionInputManager',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is a function for the destructor of the input manager class. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'init',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is a function for the initialization of the input manager. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'handleBootComplete',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getNadType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getRegionId',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHwRevision',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegionId',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< EnvironmentVariant >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'data',
                type => 'const android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'connectToAppMgr',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When appmgr service is died, it is where you put the code to reconnect. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'createVariantImpl',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'void'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mRegionMgrService',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< RegionManagerService >'
          },
          {
            kind => 'variable',
            name => 'mMyHandler',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< RegionHandler >'
          },
          {
            kind => 'variable',
            name => 'mBinderDiedLock',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::Mutex'
          },
          {
            kind => 'variable',
            name => 'mAppManager',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< ApplicationManager >'
          },
          {
            kind => 'variable',
            name => 'mSystemPostReceiver',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< ISystemPostReceiver >'
          },
          {
            kind => 'variable',
            name => 'm_WatcdogTimer',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Timer *'
          },
          {
            kind => 'variable',
            name => 'mRegionInputMgrTimer',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionInputMgrTimer *'
          },
          {
            kind => 'variable',
            name => 'mServiceDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< ServiceDeathRecipient >'
          },
          {
            kind => 'variable',
            name => 'mDLextlib',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void *'
          },
          {
            kind => 'variable',
            name => 'm_regionVariant',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionExtBase *'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'url',
            link => 'classRegionInputManager',
            content => 'RegionInputManager'
          },
          {
            type => 'text',
            content => ' is Receiver class with msgHandler and relations with another Tiger Manager. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is process how to run operations in '
          },
          {
            type => 'url',
            link => 'classRegionInputManager',
            content => 'RegionInputManager'
          },
          {
            type => 'text',
            content => ' class. '
          },
          {
            type => 'plantuml',
            content => '   RegionManagerService -> RegionInputManager : init()
   RegionManagerService -> RegionInputManager : onStart()
   RegionInputManager -> ServiceDeathRecipient : mServiceDeathRecipient - contructor Death
   RegionInputManager -> RegionHandler : mMyHandler - looper of MSG
   loop each Modules (ex. app , audio , HMI , vif Manager) until all Modules are alive
     RegionInputManager -> RegionInputManager : connectToAppMgr()
     alt each module  manager is alive
       RegionInputManager <-> binder : register Death Recipient / ex. mAppManager
     else
       RegionInputManager -> RegionHandler : handleMessage   ex. MSG_CONNECT_TO_APPMGR
     end
   end
   RegionInputManager -> RegionInputMgrTimer : mRegionInputMgrTimer - timer
   RegionInputManager -> RegionInputMgrTimer : watchDog start
   OtherService -> RegionHandler : handleMessage - ex. DID_WORK_FOR_DEFINE_0
   alt death of related service module (ex. app, audio, HMI, vif etc)
     OtherService -> binder : Death
     binder -> RegionInputManager : onServiceBinderDied
     loop Died Module (ex. app , audio , HMI , vif Manager) until Died Module is alive
       RegionInputManager -> RegionInputManager : ex. connectToAPPMg()
       alt each module manager is alive
         RegionInputManager <-> binder : register Death Recipient / ex. mAppManager
       else
         RegionInputManager -> RegionHandler : handleMessage  ex. MSG_CONNECT_TO_APPMGR
       end
     end
   end'
          },
          {
            type => 'text',
            content => ' '
          }
        ]
      }
    },
    {
      name => 'RegionInputManager::RegionInputMgrTimer',
      kind => 'class',
      base => [
        {
          name => 'TimerTimeoutHandler',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'handlerFunction',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::RegionInputMgrTimer'
        },
        {
          name => 'mHandler',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager::RegionInputMgrTimer'
        },
        {
          name => 'REGION_WATCHDOG_TIMER',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager::RegionInputMgrTimer'
        },
        {
          name => 'RegionInputMgrTimer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager::RegionInputMgrTimer'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'RegionInputMgrTimer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1RegionInputMgrTimer',
                  content => 'RegionInputMgrTimer'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'handler',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android '
                        },
                        {
                          type => 'url',
                          link => 'classRegionInputManager_1_1RegionHandler',
                          content => 'RegionHandler'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'handler',
                type => 'android::sp< RegionInputManager::RegionHandler >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handlerFunction',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the virtual handle function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1RegionInputMgrTimer',
                  content => 'RegionInputMgrTimer'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'timer_id',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'timer id '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'timer_id',
                type => 'int'
              }
            ]
          }
        ]
      },
      public_static_members => {
        members => [
          {
            kind => 'variable',
            name => 'REGION_WATCHDOG_TIMER',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static const uint32_t',
            initializer => '= 1'
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mHandler',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< RegionInputManager::RegionHandler >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManager',
      kind => 'class',
      base => [
        {
          name => 'android::RefBase',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
        {
          name => 'RegionManager::ManagerDeathRecipient'
        }
      ],
      all_members => [
        {
          name => 'DEBUG',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getLogLevel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getMcfgRegion',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getNADRegion',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getNADRevision',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getNADType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'getService',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'getVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'instance',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'mDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'mInstance',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'mRegionService',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'mToken',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'onBinderDied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'RegionManager',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManager'
        },
        {
          name => 'reregisterReceiver',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'setLogLevel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'setLogLevelAsDefault',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => 'setVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManager'
        },
        {
          name => '~RegionManager',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManager'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => '~RegionManager',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'destructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'reregisterReceiver',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to reregister receiver for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is reregistered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevel sets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - each module can set log level separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t : set log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevelAsDefault',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevelAsDefault sets the log level according to perf and debug mode. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - set log level as default log level according to perf and debug mode'
                },
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getLogLevel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'getLogLevel gets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - get log level of each module separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t& : get log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'boot Mode to get information by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getHalSystemBootMode in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'nation to get information by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getHalSystemNation in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'region from NAD related to mcfg '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getMcfgRegion in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'enum variable of region to be get by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getNADRegion in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'enum variable of revision to be get by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getNADRevision in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'enum variable of type to be get by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getNADType in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'nation to get parsed information by reference '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getNation in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'to be get as variant data '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for getVariantData in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'to delete file path information '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for memoryFileDelete in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'boot Mode to be set '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for setHalSystemBootMode in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'nation to be set '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for setHalSystemNation in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'to be set as variant data '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function for setVariantData in the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If this function works successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'onBinderDied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to get service for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'who sends Death state. '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          }
        ]
      },
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'instance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'instance function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'RegionManager*'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'static RegionManager *',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'RegionManager',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'constructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getService',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'get service for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManager',
                  content => 'RegionManager'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'android::sp<IRegionManagerService>'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'android::sp< IRegionManagerService >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mToken',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< android::IBinder >'
          },
          {
            kind => 'variable',
            name => 'mDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< ManagerDeathRecipient >'
          },
          {
            kind => 'variable',
            name => 'mRegionService',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< IRegionManagerService >'
          }
        ]
      },
      private_static_members => {
        members => [
          {
            kind => 'variable',
            name => 'DEBUG',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static bool'
          },
          {
            kind => 'variable',
            name => 'mInstance',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static RegionManager *',
            initializer => '= NULL'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService',
      kind => 'class',
      base => [
        {
          name => 'SystemService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
        {
          name => 'RegionManagerService::ReceiverDeathRecipient'
        },
        {
          name => 'RegionManagerService::ServiceStub'
        }
      ],
      includes => {
        local => 'no',
        name => 'RegionManagerService.h'
      },
      all_members => [
        {
          name => 'dump',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getLogLevel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getMcfgRegion',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getModuleID',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getNADRegion',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getNADRevision',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getNADType',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getServiceName',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'getVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'instantiate',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'isApplicationExecuted',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'mBootCompleted',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'mReceiverDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService'
        },
        {
          name => 'mReceiverLock',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService'
        },
        {
          name => 'mRegionInputMgr',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService'
        },
        {
          name => 'onInit',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'onReceiverBinderDied',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'onStart',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'onStop',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'RegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'setLogLevel',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'setLogLevelAsDefault',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => 'setVariantData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        },
        {
          name => '~RegionManagerService',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'RegionManagerService',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the constructor function of '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => '~RegionManagerService',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the destructor function of '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getModuleID',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function gets module ID. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'MODULE_REGION'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'module ID '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'onInit',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to onInit for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'bool'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual bool',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'instantiate',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to instantiate for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'onStart',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to onStart for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'E_OK is returned if this function works properly, otherwise return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'onStop',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to onStop for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'E_OK is returned if this function works properly, otherwise return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'dump',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to dump for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'Data',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'data for dump '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'E_OK is returned if this function works properly, otherwise return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                definition_name => 'Data',
                type => 'LogOutput &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'isApplicationExecuted',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to check registered receivers for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'id',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'application id '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'bool'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'id',
                type => 'appid_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'onReceiverBinderDied',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the function to reconnect registered receivers for the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'who sends death state. '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevel sets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - each module can set log level separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t : set log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == setLogLevel ==
    App -> BpRegionManagerService : setLogLevel(lvl)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_setLogLevel, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_setLogLevel, Parcel >> lvl
    BnRegionManagerService -> ServiceStub : setLogLevel(lvl)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevelAsDefault',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevelAsDefault sets the log level according to perf and debug mode. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - set log level as default log level according to perf and debug mode'
                },
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == setLogLevelAsDefault ==
    App -> BpRegionManagerService : setLogLevelAsDefault()
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_setLogLevelAsDefault, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_setLogLevelAsDefault, Parcel
    BnRegionManagerService -> ServiceStub : setLogLevelAsDefault()
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getLogLevel',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'getLogLevel gets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - get log level of each module separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t& : get log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == getLogLevel ==
    App -> BpRegionManagerService : getLogLevel(lvl)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_getLogLevel, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_getLogLevel, Parcel >> lvl
    BnRegionManagerService -> ServiceStub : getLogLevel(lvl)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get boot mode information in hal system. This api get the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get boot mode information in hal system. This api get the boot mode information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get nation information in hal system. This api get the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get nation information in hal system. This api get the nation information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : region information from NAD related to mcfg(modem config) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == region information from NAD related to mcfg(modem config) ==
    App -> BpRegionManagerService : getMcfgRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETMCFGREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETMCFGREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getMcfgRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. ==
    App -> BpRegionManagerService : getNADRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. ==
    App -> BpRegionManagerService : getNADRevision(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREVISION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREVISION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRevision(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. ==
    App -> BpRegionManagerService : getNADType(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADTYPE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADTYPE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADType(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. ==
    App -> BpRegionManagerService : getNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : get variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == get variant data ==
    App -> BpRegionManagerService : getVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Receives the delete request for the created file and deletes the specified file. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Receives the delete request for the created file and deletes the specified file. ==
    App -> BpRegionManagerService : memoryFileDelete(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_MEMORYFILEDELETE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_MEMORYFILEDELETE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : memoryFileDelete(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set boot mode information in hal system. This api set the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set boot mode information in hal system. This api set the boot mode information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set nation information in hal system. This api set the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set nation information in hal system. This api set the nation information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : set variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == set variant data ==
    App -> BpRegionManagerService : setVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'mBootCompleted',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          }
        ]
      },
      public_static_methods => {
        members => [
          {
            kind => 'function',
            name => 'getServiceName',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This function gets service name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'service_layer.RegionManagerService'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'service name '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'static const int8_t *',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mRegionInputMgr',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 8-0-1 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            type => 'android::sp< RegionInputManager >'
          },
          {
            kind => 'variable',
            name => 'mReceiverLock',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'Mutex'
          },
          {
            kind => 'variable',
            name => 'mReceiverDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< ReceiverDeathRecipient >'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'url',
            link => 'classRegionManagerService',
            content => 'RegionManagerService'
          },
          {
            type => 'text',
            content => ' is class to serive APIs for application and another services. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Basic Process about API using binder '
          },
          {
            type => 'plantuml',
            content => '    box "Application (Proxy)"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native)"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    App -> BpRegionManagerService : API(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_API, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_API, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : API(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
          },
          {
            type => 'text',
            content => ' '
          }
        ]
      }
    },
    {
      name => 'RegionInputManager::ServiceDeathRecipient',
      kind => 'class',
      base => [
        {
          name => 'android::IBinder::DeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'binderDied',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::ServiceDeathRecipient'
        },
        {
          name => 'mParent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager::ServiceDeathRecipient'
        },
        {
          name => 'ServiceDeathRecipient',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager::ServiceDeathRecipient'
        },
        {
          name => '~ServiceDeathRecipient',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::ServiceDeathRecipient'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ServiceDeathRecipient',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1ServiceDeathRecipient',
                  content => 'ServiceDeathRecipient'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'parent',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'url',
                          link => 'classRegionInputManager',
                          content => 'RegionInputManager'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parent',
                type => 'RegionInputManager &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~ServiceDeathRecipient',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the virtual destructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1ServiceDeathRecipient',
                  content => 'ServiceDeathRecipient'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'binderDied',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the binderdied virtual function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1ServiceDeathRecipient',
                  content => 'ServiceDeathRecipient'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'who',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'IBinder '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'who',
                type => 'const android::wp< android::IBinder > &'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mParent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionInputManager &'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService::ServiceStub',
      kind => 'class',
      base => [
        {
          name => 'BnRegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'check_condition_api_ready',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getLogLevel',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getMcfgRegion',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getNADRegion',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getNADRevision',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getNADType',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'getVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'memoryFileDelete',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'mParent',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'onTransact',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'BnRegionManagerService'
        },
        {
          name => 'ServiceStub',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'setHalSystemBootMode',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'setHalSystemNation',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'setLogLevel',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'setLogLevelAsDefault',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        },
        {
          name => 'setVariantData',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionManagerService::ServiceStub'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'ServiceStub',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'parent',
                type => 'RegionManagerService &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevel',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevel sets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - each module can set log level separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t : set log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setLogLevelAsDefault',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'setLogLevelAsDefault sets the log level according to perf and debug mode. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - set log level as default log level according to perf and debug mode'
                },
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'getLogLevel',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'getLogLevel gets the log level for region module separately. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'dynamic log level - get log level of each module separately.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'lvl',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'int32_t& : get log level'
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If success, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'lvl',
                type => 'int32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : This is stub code. Implementation will be in parent class with the function name. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR. '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      private_methods => {
        members => [
          {
            kind => 'function',
            name => 'check_condition_api_ready',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'void'
              }
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mParent',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionManagerService &'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionInputManager::systemPostReceiver',
      kind => 'class',
      base => [
        {
          name => 'BnSystemPostReceiver',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
        {
          name => 'mHandler',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'RegionInputManager::systemPostReceiver'
        },
        {
          name => 'onSystemPostReceived',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::systemPostReceiver'
        },
        {
          name => 'systemPostReceiver',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'RegionInputManager::systemPostReceiver'
        },
        {
          name => '~systemPostReceiver',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'RegionInputManager::systemPostReceiver'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'systemPostReceiver',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the constructor function for the '
                },
                {
                  type => 'url',
                  link => 'classRegionInputManager_1_1systemPostReceiver',
                  content => 'systemPostReceiver'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'handler',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android '
                        },
                        {
                          type => 'url',
                          link => 'classRegionInputManager_1_1RegionHandler',
                          content => 'RegionHandler'
                        },
                        {
                          type => 'text',
                          content => ' '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'handler',
                type => 'android::sp< RegionInputManager::RegionHandler >'
              }
            ]
          },
          {
            kind => 'function',
            name => 'onSystemPostReceived',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the function to receive system post event. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'systemPost',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'android Post '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual bool',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'systemPost',
                type => 'const android::sp< Post > &'
              }
            ]
          },
          {
            kind => 'function',
            name => '~systemPostReceiver',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'This is the virtual destructor function. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'void'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mHandler',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'android::sp< RegionInputManager::RegionHandler >'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'SystemService',
      kind => 'class',
      derived => [
        {
          name => 'RegionManagerService',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'TimerTimeoutHandler',
      kind => 'class',
      derived => [
        {
          name => 'RegionInputManager::RegionInputMgrTimer',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      all_members => [
      ],
      brief => {},
      detailed => {}
    }
  ],
  concepts => [
  ],
  modules => [
  ],
  namespaces => [
    {
      name => 'android',
      namespaces => [
        {
          name => 'android::IBinder'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'android::IBinder',
      brief => {},
      detailed => {}
    },
    {
      name => 'sl',
      brief => {},
      detailed => {}
    },
    {
      name => 'std',
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            attention => [
              {
                type => 'text',
                content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
              }
            ]
          },
          {
            author => [
              {
                type => 'url',
                content => 'logan.kim@lge.com'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '2023.07.13 '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => '3.0.00 '
              }
            ]
          }
        ]
      }
    }
  ],
  files => [
    {
      name => 'EnvironmentVariant.cpp',
      includes => [
        {
          name => 'Log.h'
        },
        {
          name => './include/services/RegionManagerService/EnvironmentVariant.h',
          ref => 'EnvironmentVariant_8h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'LOG_TAG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 This is the '
                    },
                    {
                      type => 'url',
                      link => 'classEnvironmentVariant',
                      content => 'EnvironmentVariant'
                    },
                    {
                      type => 'text',
                      content => ' class. '
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> "This is intended design" '
                    }
                  ]
                }
              ]
            },
            initializer => '"IEnvironmentVariant"'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'EnvironmentVariant.h',
      includes => [
        {
          name => 'string'
        },
        {
          name => 'Typedef.h'
        },
        {
          name => 'utils/Buffer.h'
        },
        {
          name => 'utils/external/mindroid/lang/String.h'
        },
        {
          name => 'Log.h'
        },
        {
          name => 'Error.h'
        },
        {
          name => 'binder/Parcel.h'
        },
        {
          name => 'utils/RefBase.h'
        },
        {
          name => 'EnvironmentVariant.h',
          ref => 'EnvironmentVariant_8h'
        }
      ],
      included_by => [
        {
          name => 'interface/EnvironmentVariant.cpp',
          ref => 'EnvironmentVariant_8cpp'
        },
        {
          name => 'interface/include/services/RegionManagerService/EnvironmentVariant.h',
          ref => 'EnvironmentVariant_8h'
        },
        {
          name => 'interface/include/services/RegionManagerService/RegionCommand.h',
          ref => 'RegionCommand_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'IRegionManagerService.h',
      includes => [
        {
          name => 'binder/IBinder.h'
        },
        {
          name => 'binder/IInterface.h'
        },
        {
          name => 'Typedef.h'
        },
        {
          name => 'RegionCommand.h',
          ref => 'RegionCommand_8h'
        },
        {
          name => 'IRegionManagerServiceType.h',
          ref => 'IRegionManagerServiceType_8h'
        }
      ],
      included_by => [
        {
          name => 'interface/IRegionManagerService.cpp',
          ref => 'IRegionManagerService_8cpp'
        },
        {
          name => 'interface/RegionManager.cpp',
          ref => 'RegionManager_8cpp'
        },
        {
          name => 'interface/include/services/RegionManagerService/RegionManager.h',
          ref => 'RegionManager_8h'
        },
        {
          name => 'service/RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'IRegionManagerServiceType.h',
      includes => [
      ],
      included_by => [
        {
          name => 'interface/RegionManager.cpp',
          ref => 'RegionManager_8cpp'
        },
        {
          name => 'interface/include/services/RegionManagerService/IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        },
        {
          name => 'interface/include/services/RegionManagerService/RegionManager.h',
          ref => 'RegionManager_8h'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'REGION_SRV_NAME',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 '
                    }
                  ]
                }
              ]
            },
            initializer => '"service_layer.RegionManagerService"'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => 'LGE_REGION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'LGE_REGION_NONE',
                initializer => '= 0',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'None Japan '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_JP',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'China '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_CN',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'North America '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_NA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Australia '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_AU',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Saudi '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_SA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'UAE '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_AE',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'India '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_IN',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Bahrain '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_BH',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Qatar '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_QA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Kuwait '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_KW',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'New Zealand '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_NZ',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Korea '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_KR',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Taiwan '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_TW',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Global '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_GLOBAL',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Reserved '
                    }
                  ]
                }
              },
              {
                name => 'LGE_REGION_RESERVE',
                brief => {},
                detailed => {}
              },
              {
                name => 'LGE_REGION_MAX',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'NAD_REGION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NAD_REGION_UKN',
                initializer => '= 0',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Unknown - initial North America '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_NA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Mexico '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_MEX',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'ROW SA '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_ROW_SA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'ROW Europe '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_ROW_EU',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'ROW Korea / Middle East '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_ROW_KRME',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'UDA '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_UDA',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'China '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REGION_CHN',
                brief => {},
                detailed => {}
              },
              {
                name => 'NAD_REGION_MAX',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'NAD_TYPE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NAD_TYPE_UKN',
                initializer => '= 0',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Unknown - initial CSAV type '
                    }
                  ]
                }
              },
              {
                name => 'NAD_TYPE_CSAV',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'NonCSAV type '
                    }
                  ]
                }
              },
              {
                name => 'NAD_TYPE_NON_CSAV',
                brief => {},
                detailed => {}
              },
              {
                name => 'NAD_TYPE_MAX',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'NAD_REVISION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NAD_REVISION_UKN',
                initializer => '= 0',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Unknown - initial Rev A '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_A',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev B '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_B',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev C '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_C',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev D '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_D',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev E '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_E',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev F '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_F',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev G '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_G',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Rev H '
                    }
                  ]
                }
              },
              {
                name => 'NAD_REVISION_H',
                brief => {},
                detailed => {}
              },
              {
                name => 'NAD_REVISION_MAX',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'NAD_MCFG_REGION',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'NAD_MCFG_REGION_UKN',
                initializer => '= 0',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Unknown - initial Korea '
                    }
                  ]
                }
              },
              {
                name => 'NAD_MCFG_REGION_KR',
                brief => {},
                detailed => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'Middle East '
                    }
                  ]
                }
              },
              {
                name => 'NAD_MCFG_REGION_ME',
                brief => {},
                detailed => {}
              },
              {
                name => 'NAD_MCFG_REGION_MAX',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionCommand.h',
      includes => [
        {
          name => 'Typedef.h'
        },
        {
          name => 'utils/Buffer.h'
        },
        {
          name => 'utils/external/mindroid/lang/String.h'
        },
        {
          name => 'Error.h'
        },
        {
          name => 'binder/Parcel.h'
        },
        {
          name => 'utils/RefBase.h'
        },
        {
          name => 'EnvironmentVariant.h',
          ref => 'EnvironmentVariant_8h'
        }
      ],
      included_by => [
        {
          name => 'interface/include/services/RegionManagerService/IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        },
        {
          name => 'service/RegionExtBase.h',
          ref => 'RegionExtBase_8h'
        },
        {
          name => 'service/RegionInputManager.h',
          ref => 'RegionInputManager_8h'
        },
        {
          name => 'service/RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'REGION_SLDD_TEST',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 '
                    }
                  ]
                }
              ]
            }
          },
          {
            kind => 'define',
            name => 'REGION_BOOTING_WAIT_TIME',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '5'
          },
          {
            kind => 'define',
            name => 'REGION_TIME_OUT',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0'
          },
          {
            kind => 'define',
            name => 'REGIONDATA_BUFSIZE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '(4 * 1024)'
          },
          {
            kind => 'define',
            name => 'DID_READ_REQUEST',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x11'
          },
          {
            kind => 'define',
            name => 'DID_WRITE_REQUEST',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x01'
          },
          {
            kind => 'define',
            name => 'DID_READ_RESPONSE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x10'
          },
          {
            kind => 'define',
            name => 'DID_WRITE_RESPONSE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x00'
          },
          {
            kind => 'define',
            name => 'DATA_ID_SIZE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '(2)'
          },
          {
            kind => 'define',
            name => 'DATA_EMPTY_SIZE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '(1)'
          },
          {
            kind => 'define',
            name => 'PAYLOAD_SIZE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '400U'
          },
          {
            kind => 'define',
            name => 'SIGNAL_INTERNAL_REGION_BASE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0001'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_0',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            initializer => '0x0001'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_1',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0002'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_2',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0003'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_3',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0004'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_4',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0005'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_5',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0006'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_6',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0007'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_7',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0008'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_8',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x0009'
          },
          {
            kind => 'define',
            name => 'DID_WORK_FOR_DEFINE_9',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '0x000A'
          },
          {
            kind => 'define',
            name => 'REGIONDATA_HEAD',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 18-2-1 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            initializer => '(offsetof(regionDataFormat, data) )'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManager.h',
      includes => [
        {
          name => 'Error.h'
        },
        {
          name => 'Log.h'
        },
        {
          name => 'utils/SLLooper.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => 'binder/IServiceManager.h'
        },
        {
          name => 'IRegionManagerServiceType.h',
          ref => 'IRegionManagerServiceType_8h'
        },
        {
          name => 'IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        },
        {
          name => 'utils/RefBase.h'
        },
        {
          name => 'list'
        },
        {
          name => 'tuple'
        },
        {
          name => 'vector'
        },
        {
          name => 'algorithm'
        }
      ],
      included_by => [
        {
          name => 'interface/RegionManager.cpp',
          ref => 'RegionManager_8cpp'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'IRegionManagerService.cpp',
      includes => [
        {
          name => 'Log.h'
        },
        {
          name => 'binder/Parcel.h'
        },
        {
          name => './include/services/RegionManagerService/IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        },
        {
          name => 'Typedef.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => 'binder/BinderService.h'
        },
        {
          name => 'utils/RefBase.h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'LOG_TAG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 '
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-0-3 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            initializer => '"IRegionManagerService"'
          },
          {
            kind => 'define',
            name => 'IPC_MAX_READABLE_SIZE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            initializer => '1024000'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => '__unnamed1__',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'OP_REGISTER_RECEIVER',
                initializer => '= android::IBinder::FIRST_CALL_TRANSACTION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_SET_LOG_LEVEL',
                brief => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'dynamic log level : newfunction : setLogLevel '
                    }
                  ]
                },
                detailed => {}
              },
              {
                name => 'OP_SET_LOG_LEVEL_AS_DEFAULT',
                brief => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'dynamic log level : newfunction : setLogLevelAsDefault '
                    }
                  ]
                },
                detailed => {}
              },
              {
                name => 'OP_GET_LOG_LEVEL',
                brief => {
                  doc => [
                    {
                      type => 'parbreak'
                    },
                    {
                      type => 'text',
                      content => 'dynamic log level : newfunction : getLogLevel '
                    }
                  ]
                },
                detailed => {}
              },
              {
                name => 'OP_GETHALSYSTEMBOOTMODE',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETHALSYSTEMNATION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETMCFGREGION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETNADREGION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETNADREVISION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETNADTYPE',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETNATION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_GETVARIANTDATA',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_MEMORYFILEDELETE',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_SETHALSYSTEMBOOTMODE',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_SETHALSYSTEMNATION',
                brief => {},
                detailed => {}
              },
              {
                name => 'OP_SETVARIANTDATA',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'IMPLEMENT_META_INTERFACE',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'RegionManagerService'
              },
              {
                type => '"service_layer.IRegionManagerService"'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManager.cpp',
      includes => [
        {
          name => 'binder/Parcel.h'
        },
        {
          name => 'binder/IServiceManager.h'
        },
        {
          name => 'utils/String16.h'
        },
        {
          name => 'Error.h'
        },
        {
          name => 'Log.h'
        },
        {
          name => 'utils/SLLooper.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => './include/services/RegionManagerService/IRegionManagerServiceType.h',
          ref => 'IRegionManagerServiceType_8h'
        },
        {
          name => './include/services/RegionManagerService/RegionManager.h',
          ref => 'RegionManager_8h'
        },
        {
          name => './include/services/RegionManagerService/IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        },
        {
          name => 'utils/RefBase.h'
        },
        {
          name => 'list'
        },
        {
          name => 'tuple'
        },
        {
          name => 'algorithm'
        },
        {
          name => 'vector'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'LOG_TAG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-0-3 |--> "This is intended design" '
                    }
                  ]
                }
              ]
            },
            initializer => '"RegionManager"'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionExtBase.h',
      includes => [
        {
          name => 'binder/IBinder.h'
        },
        {
          name => 'binder/IInterface.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => 'utils/SLLooper.h'
        },
        {
          name => 'utils/Timer.h'
        },
        {
          name => 'utils/external/mindroid/lang/String.h'
        },
        {
          name => 'utils/Mutex.h'
        },
        {
          name => 'services/RegionManagerService/RegionCommand.h',
          ref => 'RegionCommand_8h'
        },
        {
          name => 'string'
        }
      ],
      included_by => [
        {
          name => 'service/RegionInputManager.h',
          ref => 'RegionInputManager_8h'
        }
      ],
      typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'create_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'RegionExtBase *',
            arguments => '()'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionInputManager.cpp',
      includes => [
        {
          name => 'Log.h'
        },
        {
          name => 'binder/IServiceManager.h'
        },
        {
          name => 'services/ApplicationManagerService/ApplicationManager.h'
        },
        {
          name => 'services/ApplicationManagerService/IApplicationManagerServiceType.h'
        },
        {
          name => 'utils/watchdog/watchdog_client.h'
        },
        {
          name => 'RegionInputManager.h',
          ref => 'RegionInputManager_8h'
        },
        {
          name => 'RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        },
        {
          name => 'dlfcn.h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'LOG_TAG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 '
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> "This is intended design" '
                    }
                  ]
                }
              ]
            },
            initializer => '"RegionInputManager"'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionInputManager.h',
      includes => [
        {
          name => 'binder/IBinder.h'
        },
        {
          name => 'binder/IInterface.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => 'utils/SLLooper.h'
        },
        {
          name => 'utils/Timer.h'
        },
        {
          name => 'utils/external/mindroid/lang/String.h'
        },
        {
          name => 'utils/Mutex.h'
        },
        {
          name => 'services/ApplicationManagerService/ApplicationManager.h'
        },
        {
          name => 'services/RegionManagerService/RegionCommand.h',
          ref => 'RegionCommand_8h'
        },
        {
          name => 'RegionExtBase.h',
          ref => 'RegionExtBase_8h'
        }
      ],
      included_by => [
        {
          name => 'service/RegionInputManager.cpp',
          ref => 'RegionInputManager_8cpp'
        },
        {
          name => 'service/RegionManagerService.cpp',
          ref => 'RegionManagerService_8cpp'
        },
        {
          name => 'service/RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'TIME_SEND_RETRY_DELAY_MS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 This is the Region Input Manager with msg handler and connector of related tiger managers.'
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '   class RegionInputManager
   class RegionHandler
   class sl::Handler
   class android::RefBase
   class RegionInputMgrTimer
   class TimerTimeoutHandler
   class ServiceDeathRecipient
   class android::IBinder::DeathRecipient
   class RegionManagerService

   RegionInputManager *--  RegionManagerService :  >
    RegionInputManager --> android::RefBase
    RegionInputManager *--  RegionHandler : mMyHandler >
    RegionHandler -->  sl::Handler
    RegionInputManager *--  RegionInputMgrTimer : mRegionInputMgrTimer >
    RegionInputMgrTimer --> TimerTimeoutHandler
    RegionInputManager *--  ServiceDeathRecipient : mServiceDeathRecipient >
    ServiceDeathRecipient -->  android::IBinder::DeathRecipient
   class BnSystemPostReceiver
   class SystemPostReceiver
    RegionInputManager *-up-  SystemPostReceiver : mSystemPostReceiver >
    SystemPostReceiver -up-> BnSystemPostReceiver : appmgr'
                },
                {
                  type => 'text',
                  content => ' '
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> "This is intended design" '
                    }
                  ]
                }
              ]
            },
            initializer => '500'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => '__unnamed0__',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            values => [
              {
                name => 'MSG_RECEIVE_BOOT_COMPLETE',
                initializer => '= 1',
                brief => {},
                detailed => {}
              },
              {
                name => 'MSG_RECEIVE_WATCH_DOG',
                brief => {},
                detailed => {}
              },
              {
                name => 'MSG_BOOT_COMPLETE_DID_START',
                brief => {},
                detailed => {}
              },
              {
                name => 'MSG_SIGNAL_INTERNAL_IGNITION2_STATUS',
                brief => {},
                detailed => {}
              },
              {
                name => 'MSG_CONNECT_TO_APPMGR',
                brief => {},
                detailed => {}
              },
              {
                name => 'MSG_RECEIVE_BOOT_COMPLETE_PRE',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService.cpp',
      includes => [
        {
          name => 'Log.h'
        },
        {
          name => 'binder/IPCThreadState.h'
        },
        {
          name => 'binder/IServiceManager.h'
        },
        {
          name => 'RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        },
        {
          name => 'services/ApplicationManagerService/IApplicationManagerService.h'
        },
        {
          name => 'services/ApplicationManagerService/IApplicationManagerServiceType.h'
        },
        {
          name => 'utils/watchdog/watchdog_client.h'
        },
        {
          name => 'RegionInputManager.h',
          ref => 'RegionInputManager_8h'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'LOG_TAG',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00 '
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 16-2-1 |--> "This is intended design" '
                    }
                  ]
                }
              ]
            },
            initializer => '"RegionManagerService"'
          },
          {
            kind => 'define',
            name => 'CHECK_SERVICE_API_READY',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            parameters => [
            ],
            initializer => '    do { \\
        if (check_condition_api_ready() == false) { \\
            LOGW("Who(pid:%d) call me? System is not ready.", android::IPCThreadState::self()->getCallingPid()); \\
        } \\
    } while(0);'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService.h',
      includes => [
        {
          name => 'map'
        },
        {
          name => 'list'
        },
        {
          name => 'vector'
        },
        {
          name => 'tuple'
        },
        {
          name => 'algorithm'
        },
        {
          name => 'Typedef.h'
        },
        {
          name => 'corebase/SystemService.h'
        },
        {
          name => 'RegionInputManager.h',
          ref => 'RegionInputManager_8h'
        },
        {
          name => 'services/RegionManagerService/RegionCommand.h',
          ref => 'RegionCommand_8h'
        },
        {
          name => 'services/RegionManagerService/IRegionManagerService.h',
          ref => 'IRegionManagerService_8h'
        }
      ],
      included_by => [
        {
          name => 'service/RegionInputManager.cpp',
          ref => 'RegionInputManager_8cpp'
        },
        {
          name => 'service/RegionManagerService.cpp',
          ref => 'RegionManagerService_8cpp'
        },
        {
          name => 'service/RegionManagerService_main.cpp',
          ref => 'RegionManagerService__main_8cpp'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'MODULE_REGION_MGR',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  attention => [
                    {
                      type => 'text',
                      content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
                    }
                  ]
                },
                {
                  author => [
                    {
                      type => 'url',
                      content => 'logan.kim@lge.com'
                    },
                    {
                      type => 'text',
                      content => ' '
                    }
                  ]
                },
                {
                  date => [
                    {
                      type => 'text',
                      content => '2023.07.13 '
                    }
                  ]
                },
                {
                  version => [
                    {
                      type => 'text',
                      content => '3.0.00'
                    }
                  ]
                },
                {
                  type => 'text',
                  content => 'This is the Region Manager Service. This class includes all native functions.'
                },
                {
                  type => 'list',
                  style => 'itemized',
                  content => [
                    [
                      {
                        type => 'text',
                        content => 'APIs ( native codes )'
                      }
                    ]
                  ]
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Basic Process about API using binder '
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native)"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    App -> BpRegionManagerService : API(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_API, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_API, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : API(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            initializer => '100'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'RegionManagerService_main.cpp',
      includes => [
        {
          name => 'unistd.h'
        },
        {
          name => 'Log.h'
        },
        {
          name => 'binder/IPCThreadState.h'
        },
        {
          name => 'binder/ProcessState.h'
        },
        {
          name => 'binder/IServiceManager.h'
        },
        {
          name => 'cutils/process_name.h'
        },
        {
          name => 'corebase/SystemService.h'
        },
        {
          name => 'utils/Handler.h'
        },
        {
          name => 'utils/Observer.h'
        },
        {
          name => 'utils/Looper.h'
        },
        {
          name => 'utils/Mutex.h'
        },
        {
          name => 'utils/RefBase.h'
        },
        {
          name => 'RegionManagerService.h',
          ref => 'RegionManagerService_8h'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'It is the main functionfor the '
                },
                {
                  type => 'url',
                  link => 'classRegionManagerService',
                  content => 'RegionManagerService'
                },
                {
                  type => 'text',
                  content => '. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'argc',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'argument count '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'argv',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'argument value lists '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'bool'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'MISRA MISRA C++-2008 Rule 3-9-2 |--> This is intended design '
                    }
                  ]
                }
              ]
            },
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'argc',
                type => 'int'
              },
              {
                declaration_name => 'argv',
                type => 'char **'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  groups => [
    {
      name => 'REGIONMGR',
      title => 'RegionManager',
      groups => [
        {
          title => 'REGIONMGR REGION API'
        },
        {
          title => 'REGIONMGR Callback'
        },
        {
          title => 'REGION receiver Test API list'
        }
      ],
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'url',
            link => 'classRegionManager',
            content => 'RegionManager'
          },
          {
            type => 'text',
            content => ' is. '
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            attention => [
              {
                type => 'text',
                content => 'Copyright (c) 2019 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
              }
            ]
          },
          {
            author => [
              {
                type => 'url',
                content => 'logan.kim@lge.com'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '2023.07.13 '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => '3.0.00'
              }
            ]
          },
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'main is starting routine for Region ManagerService.'
          },
          {
            type => 'list',
            style => 'itemized',
            content => [
              [
                {
                  type => 'text',
                  content => 'Region ManagerService'
                }
              ],
              [
                {
                  type => 'text',
                  content => 'Region Manager'
                }
              ],
              [
                {
                  type => 'text',
                  content => 'Region Sample application'
                }
              ],
              [
                {
                  type => 'text',
                  content => 'Region SLDD'
                }
              ]
            ]
          },
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'this is sequence diagram how to do operations through binder. '
          },
          {
            type => 'plantuml',
            content => '  box "Application"
  participant RegionSampleApplication
  participant BnRegionManagerReceiver
  participant BpRegionManagerService
  end box
  participant Binder
  box "RegionService"
  participant BpRegionManagerReceiver
  participant ServiceStub
  participant BnRegionManagerService
  participant RegionInputManager
  participant RegionHandler
  end box
  box "OtherService"
  participant mVifManager
  end box
  == RegionSampleApplication register to Region and VIF sends msg to RegionSampleApplication ==
    RegionSampleApplication -> BpRegionManagerService : registerReceiver(id,receiver)
    BpRegionManagerService -> Binder : receiver >> remote()->onTransact(OP_REGISTER_RECEIVER, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_RECEIVER, Parcel >> receiver
    BnRegionManagerService -> ServiceStub : registerReceiver(id,receiver)
    note right ServiceStub : mReceivers[id].push_back(receiver)\\nlinkToDeath() : onReceiverBinderDied(delete it from mReceivers when app dies.)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    RegionSampleApplication <- BpRegionManagerService : return E_OK
    mVifManager -> RegionInputManager : mVifManager->onReceive(uint32_t Sigid, android::sp<Buffer>& buf)
    note left RegionInputManager : message->sendToTarget(obtainMessage());
    RegionInputManager -> RegionHandler : handleMessage(msg)
    note right RegionHandler : switch Region_RECEIVE_FROM_VIF
    RegionHandler -> RegionInputManager : messagefromVIF(msg)
    note right RegionInputManager : transferDatabyVIF()
    RegionInputManager -> ServiceStub : queryReceiverByID()
    note right ServiceStub : mReceivers[id].onReceive(data);
    ServiceStub -> BpRegionManagerReceiver : onReceive(data)
    BpRegionManagerReceiver -> Binder : (void)remote()->transact(TRANSACT_ONRECEIVE, data, &reply);
    Binder -> BnRegionManagerReceiver : onTransact(TRANSACT_ONRECEIVE)
    BnRegionManagerReceiver -> RegionSampleApplication : RegionSampleReceiver::onReceive()
    note right RegionSampleApplication : message->sendToTarget(obtainMessage());
    RegionSampleApplication -> RegionSampleApplication : RegionSampleApplication::RegionHandler::handleMessage(msg)'
          },
          {
            type => 'parbreak'
          },
          {
            version => [
              {
                type => 'text',
                content => '1.3 add Low Level Design Documents (This is doxygen comments) '
              }
            ]
          }
        ]
      }
    },
    {
      name => 'REGIONMGR_API',
      title => 'REGIONMGR REGION API',
      functions => {
        members => [
          {
            kind => 'function',
            name => 'getHalSystemBootMode',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get boot mode information in hal system. This api get the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get boot mode information in hal system. This api get the boot mode information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getHalSystemNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get nation information in hal system. This api get the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get nation information in hal system. This api get the nation information via hal_system. ==
    App -> BpRegionManagerService : getHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getMcfgRegion',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : region information from NAD related to mcfg(modem config) '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'mcfgRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'region from NAD related to mcfg '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == region information from NAD related to mcfg(modem config) ==
    App -> BpRegionManagerService : getMcfgRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETMCFGREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETMCFGREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getMcfgRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'mcfgRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRegion',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRegion',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of region to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD region information. This api get the NAD information via Telephony and parse the data and then give NAD region enum value. ==
    App -> BpRegionManagerService : getNADRegion(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREGION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREGION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRegion(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRegion',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADRevision',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadRevision',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of revision to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD HW revision information.This api get the NAD information via Telephony and parse the data and then give NAD HW revision enum value. ==
    App -> BpRegionManagerService : getNADRevision(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADREVISION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADREVISION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADRevision(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadRevision',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNADType',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nadType',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'enum variable of type to be get by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request NAD type information. This api get the NAD information via Telephony and parse the data and then give NAD type enum value. ==
    App -> BpRegionManagerService : getNADType(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNADTYPE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNADTYPE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNADType(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nadType',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'nation',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to get parsed information by reference '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to get parsed nation information in hal system. This api get the parsed nation information via hal_system. ==
    App -> BpRegionManagerService : getNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'nation',
                type => 'uint8_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'getVariantData',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : get variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'out'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be get as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == get variant data ==
    App -> BpRegionManagerService : getVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_GETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_GETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : getVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'memoryFileDelete',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Receives the delete request for the created file and deletes the specified file. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'file_path_length',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Length of file_path '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'file_path',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'to delete file path information '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Receives the delete request for the created file and deletes the specified file. ==
    App -> BpRegionManagerService : memoryFileDelete(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_MEMORYFILEDELETE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_MEMORYFILEDELETE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : memoryFileDelete(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file_path_length',
                type => 'size_t &'
              },
              {
                declaration_name => 'file_path',
                type => 'uint8_t *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemBootMode',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set boot mode information in hal system. This api set the boot mode information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'bootMode',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'boot Mode to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set boot mode information in hal system. This api set the boot mode information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemBootMode(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMBOOTMODE, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemBootMode(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'bootMode',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setHalSystemNation',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : Request to set nation information in hal system. This api set the nation information via hal_system. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'halNation',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'nation to be set '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == Request to set nation information in hal system. This api set the nation information via hal_system. ==
    App -> BpRegionManagerService : setHalSystemNation(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETHALSYSTEMNATION, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETHALSYSTEMNATION, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setHalSystemNation(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'halNation',
                type => 'uint32_t &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'setVariantData',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'API : set variant data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'this funciton will be invoked when application or another services call this function through binder.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'variantData',
                          dir => 'in'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'to be set as variant data '
                        }
                      ]
                    }
                  ]
                },
                {
                  retvals => [
                    {
                      parameters => [
                        {
                          name => 'error_t'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'If the receiver is registered successfully, return E_OK, otherwise, return E_ERROR.'
                        }
                      ]
                    }
                  ]
                },
                {
                  type => 'plantuml',
                  content => '    box "Application (Proxy)\\n Other Services"
    participant App
    participant BpRegionManagerService
    end box
    participant Binder
    box "Service (Native) - API"
    participant BnRegionManagerService
    participant ServiceStub
    end box

    == set variant data ==
    App -> BpRegionManagerService : setVariantData(arguments)
    BpRegionManagerService -> Binder : RegionData >> remote()->onTransact(OP_REGISTER_SETVARIANTDATA, Parcel)
    Binder -> BnRegionManagerService : onTransact(uint32_t code, const Parcel& data,reply)\\n OP_REGISTER_SETVARIANTDATA, Parcel >> arguments
    BnRegionManagerService -> ServiceStub : setVariantData(arguments)
    activate ServiceStub
    BnRegionManagerService <- ServiceStub : return E_OK
    deactivate ServiceStub
    Binder <- BnRegionManagerService : reply->writeInt32
    BpRegionManagerService <- Binder : reply.readInt32()
    App <- BpRegionManagerService : return'
                },
                {
                  type => 'parbreak'
                },
                {
                  see => [
                    {
                      type => 'text',
                      content => 'SRS TIDL-FR-001 |--> Explanation for FR-001 '
                    }
                  ]
                }
              ]
            },
            type => 'virtual error_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'variantData',
                type => 'android::sp< EnvironmentVariant > &'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            attention => [
              {
                type => 'text',
                content => 'Copyright (c) 2015 by LG electronics co, Ltd. All rights reserved. This program or software including the accompanying associated documentation ("Software") is the proprietary software of LG Electronics Inc. and or its licensors, and may only be used, duplicated, modified or distributed pursuant to the terms and conditions of a separate written license agreement between you and LG Electronics Inc. ("Authorized License"). Except as set forth in an Authorized License, LG Electronics Inc. grants no license (express or implied), rights to use, or waiver of any kind with respect to the Software, and LG Electronics Inc. expressly reserves all rights in and to the Software and all intellectual property therein. If you have no Authorized License, then you have no rights to use the Software in any ways, and should immediately notify LG Electronics Inc. and discontinue all use of the Software.'
              }
            ]
          },
          {
            author => [
              {
                type => 'url',
                content => 'logan.kim@lge.com'
              },
              {
                type => 'text',
                content => ' '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '2023.07.13 '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => '3.0.00   '
              }
            ]
          },
          {
            type => 'text',
            content => 'Thease are the REGION APIs '
          }
        ]
      }
    },
    {
      name => 'REGIONMGR_CB',
      title => 'REGIONMGR Callback',
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is the REGION Manager Receiver list. '
          }
        ]
      }
    },
    {
      name => 'REGION_RECEIVER_TEST_API',
      title => 'REGION receiver Test API list',
      brief => {},
      detailed => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'This is the REGION Test API list for receiver. '
          }
        ]
      }
    }
  ],
  pages => [
  ]
};
1;
