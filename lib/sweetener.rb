require 'sugar-attributes'

module Sweetener
  class << self
    def included(base)
      base.extend(SugarAttributes)
      extend_option_parser_for_sugar!
    end

    private

    def extend_option_parser_for_sugar!
      Shoes::OPTS.instance_eval do
        on("--sugar-bundle-id [ID]", "Set the Sugar bundle ID.") do |v|
          Shoes.sugar_bundle_id = v
        end

        on("--sugar-activity-id [ID]", "Set the Sugar activity ID.") do |v|
          Shoes.sugar_activity_id = v
        end
      end
    end
  end
end

Shoes.send(:include, Sweetener)
